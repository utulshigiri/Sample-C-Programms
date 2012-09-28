#include <iostream>

using namespace std;

class A
{
public:
    A() { a_member = 0; }
    virtual int reset() { a_member = 0; }
    void set_a_member( int a ) { a_member = a; }
    int get_a_member() { return a_member; }
protected:
    int a_member;
};

class B : public A
{
public:
    B() : A() { b_member = 0; };
    virtual int reset() { a_member = b_member = 0; }
    virtual void some_virtual_method() { }
    void set_b_member(int b ) { b_member = b; }
    int get_b_member() { return b_member; }
protected:
    int b_member;
};

int main()
{
    B *b = new B;
    A *a = b;

    b->set_b_member( 20 );
    b->set_a_member( 10 );

    a->reset();

    cout << b->get_a_member() << " " << b->get_b_member() <<
        endl;

    return 0;
}
