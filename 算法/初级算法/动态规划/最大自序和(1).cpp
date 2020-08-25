#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums)
     {
        int n=nums.size();
        int pre=max(nums[0],0);
        int maxx=nums[0];
        int nowl;
        for(int i=1;i<nums.size();i++)
        {
            nowl=max(pre+nums[i],nums[i]);
            if(nowl>maxx)
                maxx=nowl;
            pre=nowl;
        }
        return maxx;
    }
};