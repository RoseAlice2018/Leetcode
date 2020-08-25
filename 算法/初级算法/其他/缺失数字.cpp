#include<vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        if(nums.size()==0)
            return 0;
        int temp=(1+nums.size())*nums.size()/2;
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        return temp-sum;
    }
};