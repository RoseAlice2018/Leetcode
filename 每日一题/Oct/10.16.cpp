#include<vector>
#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A)
     {
         map<int,int> dic;
         vector<int> res;
         for(int i=0;i<A.size();i++)
         {
             int temp=A[i]>=0?A[i]:-A[i];
             if(dic.count(temp))
             {
                 map<int,int>::iterator it=dic.find(temp);
                 it->second+=1;
             }
            else
            {
                dic.insert(pair<int,int>(temp,1));
            }
         }
         map<int,int>::iterator it=dic.begin();
         for(;it!=dic.end();it++)
            {
                while(it->second--)
                {
                    res.push_back(it->first*it->first);
                }
            }
         return res;
    }
};