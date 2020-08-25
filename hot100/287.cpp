#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums)
     {
         int len=nums.size();
         sort(nums.begin(),nums.begin()+len);
         for(int i=0;i<nums.size()-1;i++)
         {
             if(nums[i]==nums[i+1])
             {
                 return nums[i];
             }
         }
    return 0;
    }
};