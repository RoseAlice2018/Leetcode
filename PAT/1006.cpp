#include<iostream>
#include<algorithm>
using namespace std;
struct user
{
    char ID[16];
    int h;
    int m;
    int s;
    int h1;
    int m1;
    int s1;
};
bool cmp(user a,user b)
{
    if(a.h!=b.h)
    {
        return a.h<b.h;
    }
    else
    {
        if(a.m!=b.m)
        {
            return a.m<b.m;
        }
        else
        {
            if(a.s!=b.s)
            {
                return a.s<b.s;
            }
        }
        
    }
    
}
bool cmp1(user a,user b)
{
    if(a.h1!=b.h1)
    {
        return a.h1>b.h1;
    }
    else
    {
        if(a.m1!=b.m1)
        {
            return a.m1>b.m1;
        }
        else
        {
            if(a.s1!=b.s1)
            {
                return a.s1>b.s1;
            }
        }
        
    }
}
int main()
{
    int N;
    cin>>N;
    user temp[N];
    for(int i=0;i<N;i++)
    {
        scanf("%s %d:%d:%d %d:%d:%d",temp[i].ID,&temp[i].h,&temp[i].m,&temp[i].s,&temp[i].h1,&temp[i].m1,&temp[i].s1);
    }
    //find the earliest one to sign in and the last one sign out
    sort(temp,temp+N,cmp);
    cout<<temp[0].ID<<" ";
    sort(temp,temp+N,cmp1);
    cout<<temp[0].ID;
    return 0;
}