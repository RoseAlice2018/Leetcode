#include<iostream>
using namespace std;
class A
{
    public:
        virtual ~A(){};
        void f(){g();h();}
        virtual void h()
        {
            cout<<"A::h()"<<endl;
        }
    protected:
        void g(){cout<<"A::g()"<<endl;}

};
class B
{
    public: B(int n):val(n){}
    protected: int val;
};
class C :public A,private B{
    public:
        C(int n1,int n2):num(n1),B(n2){}
        virtual void h()
        {
            cout<<"num="<<num<<endl;
            cout<<"val="<<val<<endl;
        }
        protected:
            void g(){cout<<"C::g()"<<endl;}
        private:
            int num;
};
int main()
{
    C c(1,2);
    c.f();
    return 0;
}