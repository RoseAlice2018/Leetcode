#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
    //o(n^2)
    //   for(int i=0;i<nums.size();i++)
    //   {
    //       for(int j=i+1;j<nums.size();j++)
    //       {
    //           if(nums[i]==nums[j])
    //           {
    //               return true;
    //           }
    //       }
    //   }  
    //   return false;
    //o(nlog)
    if(nums.empty())
        return false;
    int len=nums.size();
    sort(&nums[0],&nums[len]);
    for(int i=0;i<len-1;i++)
    {
        if(nums[i]==nums[i+1])
        {
            return true;
        }
    }
    return false;
    }
};