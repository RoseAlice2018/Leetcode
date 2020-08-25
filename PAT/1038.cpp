#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
bool cmp(string& a,string& b)
{
    return a+b<b+a;
}
int main()
{
    int N;
    scanf("%d",&N);
    string str[N];
    for(int i=0;i<N;i++)
        cin>>str[i];
    sort(str,str+N,cmp);
    string s="";
    for(int i=0;i<N;i++)
        s+=str[i];
    int i=0;
    while(i<s.size()&&s[i]=='0')
    {
        ++i;
    }
    if(i==s.size())
        cout<<"0";
    else
    {
        for(int k=i;k<s.size();k++)
            cout<<s[k];
    }
    return 0;
}