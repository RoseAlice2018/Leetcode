#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    void combinee(vector<int> temp,vector<int>& visit,int n,int k)
    {
        if(k==1)
        {
            for(int i=0;i<n;i++)
            {
                if(visit[i]!=0)// not visited
                {
                    temp.push_back(i+1);
                    res.push_back(temp);
                    temp.pop_back();
                }
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                if(visit[i]!=0)
                {
                    visit[i]=0;
                    temp.push_back(i+1);
                    combinee(temp,visit,n,k-1);
                    temp.pop_back();
                    visit[i]=i+1;
                }
                visit[i]=0;
            }
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> visit;
        for(int i=0;i<n;i++)
            visit.push_back(i+1);
        vector<int> temp;
        combinee(temp,visit,n,k);
        return res;
    }
};