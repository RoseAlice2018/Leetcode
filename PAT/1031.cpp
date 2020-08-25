#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int N=s.length();
    int n1=0,n3=0,n2=0;
    int k=1;
    n1=k;n3=k;
    n2=N+2-2*k;
    for(;(n2=N+2-2*k)&&k<=n2;k++)
    {
       
        if(n2>=3&&n2<=N)
            continue;
        else 
            break;
    }
    k--;
    int space=N-2*k;
    for(int i=0;i<k-1;i++)
    {
        printf("%c",s[i]);
        for(int j=0;j<space;j++)
            printf(" ");
        printf("%c\n",s[N-i-1]);
    }
    for(int i=k-1;i<k-1+N+2-2*k;i++)
    {
        printf("%c",s[i]);
    }
    return 0;
}