#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
     {
         vector<vector<int>> res;
         int left=newInterval[0];
         int right=newInterval[1];
         bool placed=false;
         for(auto& interval : intervals)
         {
             if(interval[0]>right)
             {
                 if(!placed)
                 {
                     res.push_back({left,right});
                     placed=true;
                 }
                 res.push_back(interval);
             }
             else if(interval[1]<left)
             {
                 res.push_back(interval);
             }
             else
             {
                 left=left>interval[0]?interval[0]:left;
                 right=right<interval[1]?interval[1]:right;
             }
             
         }
         if(!placed)
         {
             res.push_back({left,right});
         }
         return res;
    }
};