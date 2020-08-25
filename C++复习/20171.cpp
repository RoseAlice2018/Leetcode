#include<iostream>
using namespace std;
class A
{
    public:
        A(){cout<<"默认构造函数！"<<endl;}
        void outa();
    private:
        int a=0;
};
void A::outa()
{
    cout<<a;
}
int main()
{
    
    A* p=new A();
    p->outa();
    return 0;
}