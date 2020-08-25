#include<vector>
using namespace std;
class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int dp0,dp1;
        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
            {
                dp0=0;//表示第一个不预约
                dp1=nums[i];//表示第一个预约
            }
            else
            {
                int a=max(dp0,dp1);//表示·第i个不约
                int b=dp0+nums[i];//表示第i个约
                dp0=a;
                dp1=b;
            }
            
        }
        return max(dp0,dp1);

    }
};