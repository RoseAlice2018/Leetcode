#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()>0)
        {
            return binaryserach(nums,0,nums.size()-1,target);
        }
        return 0;
    }
    int binaryserach(vector<int>& nums,int left,int right,int target)
    {
        if(left >= right)
        {
            if(target == nums[left])
                return left;
            else if(nums[left]<target)
                return left+1;
            else 
                return left>0?left:0;
        }
        int mid = (right-left)/2+left;
        if(target==nums[mid])
        {
            //find it
            return mid;
        }
        else if(target>nums[mid])
        {
            return binaryserach(nums,mid+1,right,target);
        }
        else if(target<nums[mid])
        {
            return binaryserach(nums,left,mid-1,target);
        }
        return 0;
    }
};