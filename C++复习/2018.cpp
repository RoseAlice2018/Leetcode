#include<iostream>
using namespace std;
class A
{
    public:
        A(){f();}
        virtual ~A(){cout<<"~A"<<endl;}
        virtual void f(){cout<<"A::f()"<<endl;g();}
        virtual void g(){cout<<"A::g()"<<endl;k();t();}
        void k(){cout<<"A::k()"<<endl;}
        virtual void t(){cout<<"A::t()"<<endl;}
};
class B:public A
{
    public:
    B(){f();}
     ~B(){cout<<"~B()"<<endl;}
    void f(){cout<<"B::f()"<<endl;g();k();}
    void k(){cout<<"B::k()"<<endl;}
        virtual void t(){cout<<"B::t()"<<endl;}
};
int main()
{
    A* p1=new A();
    cout<<"---------"<<endl;
    p1->f();
    cout<<"----------"<<endl;
    A* p2=new B();
    cout<<"----------"<<endl;
    p2->f();
    cout<<"----------"<<endl;
    delete p2;
    cout<<"----------"<<endl;
    delete p1;

    return 0;
}