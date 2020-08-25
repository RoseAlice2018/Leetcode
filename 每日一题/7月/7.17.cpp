#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        return BinarySearch(nums,target,0,nums.size()-1);
    }
    int BinarySearch(vector<int> nums,int target,int left,int right)
    {
        if(left>=right)
        {
            if(nums[left]>=target)
                return left;
            else
            {
                return left+1;
            }
            
        }
        int mid=(right+left)/2;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]>target)
        {
            return BinarySearch(nums,target,left,mid-1);
        }
        else if(nums[mid]<target)
        {
            return BinarySearch(nums,target,mid+1,right);
        }
    }
};