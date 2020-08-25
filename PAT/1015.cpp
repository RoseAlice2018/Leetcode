#include<iostream>
#include<math.h>
#include<string>
using namespace std;
bool isPrime(int a)
{
    if(a==1)
        return false;
    int n=sqrt(a);
    for(int i=2;i<=n;i++)
    {
        if(a%i==0)
            return false;
    }
    return true;
}
int  Reverse(int N,int D)
{
    string temp="";
    while(N>0)
    {
        int t1=N%D;
        temp+=t1+'0';
        N=(N-N%D)/D;
    }
    int res=0;
    int n=temp.size()-1;
    for(int i=0;i<temp.size();i++)
    {
        res+=pow(D,n-i)*(temp[i]-'0');
    }
    return res;
}
int main()
{
    int N,D;
    scanf("%d %d",&N,&D);
    while(N>=0)
    {
        if(isPrime(N))
        {
            int N1=Reverse(N,D);
            if(isPrime(N1))
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
            
        }
        else
        {
            cout<<"No"<<endl;
        }
        scanf("%d%d",&N,&D);
    }
    return 0;
}