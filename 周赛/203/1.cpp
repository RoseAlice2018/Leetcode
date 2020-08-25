#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> dic(n+10,0);
        for(int i=0;i<rounds.size()-1;i++)
        {
            int A=rounds[i];
            int B=rounds[i+1];
            if(A>=B)
            {
                for(int m=A+1;m<=n;m++)
                    dic[m]++;
                for(int m=1;m<=B;m++)
                    dic[m]++;
            }
            else if(A<B)
            {
                for(int m=A+1;m<=B;m++)
                {
                    dic[m]++;
                }
            }
        }
        dic[rounds[0]]++;
        int max=0;
        for(int i=1;i<dic.size();i++)
        {
            if(dic[i]>max)
                max=dic[i];
        }
        vector<int> res;
        for(int i=1;i<dic.size();i++)
        {
            if(dic[i]==max)
                res.push_back(i);
        }
        return res;
    }
};