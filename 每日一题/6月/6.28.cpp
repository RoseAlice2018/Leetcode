#include<vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums)
     {
         int res=INT32_MAX;
         int start=0,end=0;
         if(nums.size()==0)
            return 0;
         int sum=0;
         while(end<nums.size())
         {
             sum+=nums[end];
             while (sum>=s)
             {
                 int distance=end-start+1;
                 if(distance<res)
                    res=distance;
                 sum-=nums[start];
                    start++;
             }
             end++;
         }
         return res==INT32_MAX?0:res;
    }
};