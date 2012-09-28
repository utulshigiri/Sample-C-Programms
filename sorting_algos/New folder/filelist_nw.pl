#!/usr/bin/perl -w
#
# Scripts to print out files from a directory in
# order based on Networker format of name
# 4th position is seconds since epoch
# 6th position is ip address of client for what that's worth
#
# Can specify start and stop dates
# Can specify the number of GiB worth of files to print
#

use strict;
use Time::HiRes;
use Date::Manip;
use Cwd;
use Getopt::Std;

my $src_dir;            # source directory

my $from_date;          # from date
my $to_date;            # to date

my $total_size = 0;     # total data copied
my $current;            # current timestamp
my $gb_limit = 0;       # maximum number of GB to copy

my @file_list;

#select(STDERR);

sub usage {
  print STDERR <<"EOM";

NAME

    $0 Program to print out a list of files in mtime order

SYNOPSIS

    $0 [OPTION] <src_dir>

DESCRIPTION

    -f <from date>
        Copy files modified after <from date>. Default is 1/1/1971.

    -t <to date>
        Copy files modified before <to date>. Default is 12/31/2099.

    -g <GiB limit> 
       Stop copying when the specified number of megabytes is exceeded

EOM
  exit;
}



# parse input arguments
our(%opts);
getopts('f:t:g:', \%opts);

if (defined($opts{'f'})) {
    $from_date = ParseDate($opts{'f'});
} else {
    $from_date = ParseDate("1/1/1970");
}

if (defined($opts{'t'})) {
    $to_date = ParseDate($opts{'t'});
} else {
    $to_date = ParseDate("12/31/2099");
}

if (defined($opts{'g'})) {
    $gb_limit = $opts{'g'};
}

$src_dir = $ARGV[0] or usage();

# initialization
autoflush STDOUT 1;
autoflush STDERR 1;

# Generate list of files in mtime order.
# First cd to src_dir to get file names relative to that dir.
my $wdir = cwd();
chdir($src_dir) or die "cannot cd to $src_dir";
open(LS, "find -L . -type f | xargs ls -lrt --full-time |") || die "cannot list files";
while (<LS>) {
    my @fields = split(/\s+/, $_);
    my %file;
    $file{'name'} = $fields[8];
    $file{'name'} =~ s/\.\///;
    my $date_name = $file{'name'};
    if ($date_name =~ /^.*\S*-\S*-\S*-(\S*)-\S*-\S*$/) {
	my $hex_date = $1; # seconds since epoch in hex
	my $dec_date = hex($hex_date);  # seconds since epoch in decimal
	my $local_time = localtime($dec_date); # human readable version
	#print "$date_name $1 $dec_date $local_time\n";	
	$file{'date'} = ParseDate($local_time);
    } else {
	$file{'date'} = ParseDate("$fields[5] $fields[6] $fields[7]");
    }

    # size in bytes
    $file{'size'} = $fields[4];
    $file{'size'} = int(100 * $file{'size'}) / 100;
    $file{'present'} = 0;
    push @file_list, { %file };
}
close(LS);

# sort the list
@file_list = sort { Date_Cmp($a->{'date'}, $b->{'date'}) } @file_list;

chdir($wdir) or die "cannot cd back to $wdir";

for my $i (0 .. $#file_list) {
  my $src_file = $file_list[$i]{'name'};
  my $src = "$src_dir/$src_file";

  # find size of file
  my $size = $file_list[$i]{'size'};

  # operate only on files dated between from_date and to_date
  $current = $file_list[$i]{'date'};
  next if (Date_Cmp($current, $from_date) < 0 || Date_Cmp($current, $to_date) > 0);
  
  my $size_gib = $size / 1024 / 1024 / 1024;
  printf "$src $file_list[$i]{'date'} %.5f GiB\n", $size_gib;

  $total_size += $size;
  
  if ($gb_limit > 0 && ($total_size / 1024 > $gb_limit)) {
      last;
  }

}

printf STDERR "%.1f GiB total\n", $total_size / 1024 / 1024 / 1024;
