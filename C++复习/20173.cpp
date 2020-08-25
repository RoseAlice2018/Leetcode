#include<iostream>
using namespace std;
class Integer
{
    public:
    Integer(int n){num=n;}
    Integer operator%(int m)
    {
        int result=num%m;
        if(result<0)
            result+=abs(m);
        return Integer(result);
    }
    int operator[](int bit)const
    {
        return (num&(1<<bit)==0?0:1);
    }
    operator int() const {return num;}
    private:
    int num;
};
int main()
{
    Integer n1(65);
    Integer n2(-33);
    cout<<int(n1%8)<<endl;
    cout<<int(n1%-8)<<endl;
    cout<<int(n2%8)<<endl;
    cout<<int(n2%-8)<<endl;
    for(int i=7;i>=0;--i)
        cout<<n1[i];
    cout<<endl;
    return 0;
}