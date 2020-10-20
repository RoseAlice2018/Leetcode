#include<iostream>
#include<vector>
using namespace std;
//next 数组生成
vector<int> next(string t)
{
    vector<int> next(t.size()+1);
    next[0]=-1;
    next[1]= 0;
    int j=2;
    while(j<=t.size())
    {
        if(next[j-1]!=0&&t[next[j-1]]==t[j-1])
        {
            next[j]=next[j-1]+1;
        }
        else if(t[0]==t[j-1])
        {
            next[j]=1;
        }
        else
        {
            next[j]=0;
        }
        j++;
    }
    return next;
}
int KMP(string s,string t,vector<int>& next_)
{
    //get next
    next_=next(t);
    int index=0;
    int s_size=s.size();
    int t_size=t.size();
    if(s_size<t_size)
    {
        //  此时主串小于子串 不可能出现匹配
        return -1;
    }
    int i=0,j=0;
    while (i<s_size&&j<t_size)
    {
        if(j==-1||s[i]==t[j])
        {
            i++;
            j++;
        }
        else
        {
            j=next_[j];
        }
    }
    if(j>=t_size)
    {
        index=i-j;
        return index;
    }
    else
    {
        return -1;
    }
    
}
int main()
{
    string s,t;
    cin>>s>>t;
    vector<int> next;
    int res=KMP(s,t,next);
    for(int i=1;i<=t.size();i++)
        cout<<next[i]-1<<" ";
    cout<<endl;
    cout<<res;
}
