#include<vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
         int res;
         if(nums.size()==0)
            return 0;
        else if(nums.size()==1)
            return nums[0];
        int head=0,end=nums.size()-1;
        if(nums[head]<nums[end])
        {
            return nums[head];
        }
        else
        {
            while(end-1>=0&&nums[end-1]<=nums[end])
                end--;
            res=nums[end];
        }
        return res;
    }
};