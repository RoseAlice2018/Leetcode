#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) 
    {
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            char t=labels[i];
            int temp=countlables(edges,labels,t,i);
            res.push_back(temp);
        }
        return res;
    }
    int countlables(vector<vector<int>>& edges,string labels,char label,int position)
    {
        int res=0;
        if(labels[position]==label)
            res++;
        int leftposition;
        int rightposition;
        int count=0;
        for(int i=0;i<edges.size();i++)
        {
            if(edges[i][0]==position&&count==0)
            {
                count++;
                leftposition=edges[i][1];
            }
            else  if(edges[i][0]==position&&count==1)
            {
                count++;
                rightposition=edges[i][1];
            }
            if(count==2)
                break;
        }
        if(count==2)
        {
            res+=countlables(edges,labels,label,leftposition);
            res+=countlables(edges,labels,label,rightposition);
        }
        else if(count==1)
        {
            res+=countlables(edges,labels,label,leftposition);
        }
        else
        {
            return res;
        }
        return res;
    }
};