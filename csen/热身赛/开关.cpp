#include<iostream>
#include<vector>
#include<string>
using namespace std;
void reverse1(string& num,int x,int& count)
{
    for(int i=0;i<=x;i++)
    {
        if(num[i]=='1')
            num[i]='0';
        else
        {
            num[i]='1';
        }   
    }
    count++;
}
int find(string num,int& lastposition)
{
    for(int i=lastposition;i>=0;i--)
    {
        if(num[i]=='1')
         {
        lastposition=i-1;
           return i;
         }
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    string num;
    cin>>num;
    int count=0;
    int lastposition=num.size()-1;
    while(find(num,lastposition)!=-1)
    {
        int temp=find(num,lastposition);
        reverse1(num,temp,count);
    }
    cout<<count;
    return 0;
}