#include<iostream>
#include<vector>
#include<map>
using namespace std;
void setorder(vector<int>& res)
{
    map<int,int> dic;
    for(int i=0;i<res.size();i++)
    {
        if(dic.count(res[i]))
        {
            int temp=dic[res[i]];
            res[temp]=-1;
            res[i]=-1;
            dic.erase(res[i]);
        }
        else
        {
            dic.insert(pair<int,int>(res[i],i));
        }  
    }
    vector<int> t;
    for(int i=0;i<res.size();i++)
    {
        if(res[i]!=-1)
            t.push_back(res[i]);
    }
    res=t;
}
void sett(vector<int>& res)
    {
        for(int i=1;i<res.size();i++)
        {
            res[i-1]=res[i];
        }
         res.pop_back();
         return;
    }
int main()
{
    int n;
    cin>>n;
    int cnt=0;
    // 摸牌
    vector<int> alice;
    vector<int> bob;
    for(int i=0;i<4*n-2;i++)
    {
        int temp;
        cin>>temp;
        if(i%2==0)
            alice.push_back(temp);
        else
        {
            bob.push_back(temp);
        }
    }
    setorder(alice);
    setorder(bob);
    bool notwin=true;
    while (notwin)
    {
        if(alice.size()==0||bob.size()==0)
        {
            notwin=false;
            break;  
        }
        // playGame;
        if(cnt%2==0)//alice turn;
            {
                cnt++;
                int temp=bob[0];
                alice.push_back(temp);
                setorder(alice);
            }
            else
            {
                cnt++;
                int temp=alice[0];
                bob.push_back(temp);
                setorder(bob);
            }
            if(cnt%2==1)
            {
                sett(bob);
            }
            else
            {
                sett(alice);
            }
    }
    printf("%d",cnt);
    return 0;
}