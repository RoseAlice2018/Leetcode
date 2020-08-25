#include<iostream>
using namespace std;
class A
{
    public:
        A(){cout<<"默认构造函数！"<<endl;}
        A(const A& ){
            cout<<"kaobei"<<endl;
        }
        A& operator=(const A& t){
            cout<<"operator"<<endl;
        }
};
int main()
{
    
    A** px=new A*[5];
    return 0;
}