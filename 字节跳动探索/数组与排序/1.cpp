#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool equals(vector<int> p,vector<int> q)
    {
        for(int i=0;i<p.size();i++)
        {
            if(p[i]!=q[i])
                return false;
        }
        return true;
    }
       vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> temp;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            temp[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            int dif=target-nums[i];
            if(temp[dif]&&temp[dif]!=i)
            {
                res.push_back(i);
                res.push_back(temp[dif]);
                return res;
            }
        }
        return res;
    }
    vector<vector<int>> threeSum(vector<int>& nums)
     { 
         vector<vector<int>> res;
         if(nums.size()<3)
            return res;
            int target=0;
         for(int i=0;i<nums.size();i++)
         {
             int temp=target-nums[i];
             
         }
         return res;

    }
};