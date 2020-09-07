#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findPeak(vector<int>& nums,int left,int right)
    {
        int mid=(right-left)/2+left;
        if(mid==left)
            return nums[left];
        else 
        {
            if(nums[mid]>nums[mid+1])
            {
                findPeak(nums,left,mid);
            }
            else
            {
                findPeak(nums,mid,right);
            }
            
        }
    }
    int findPeakElement(vector<int>& nums) 
    {
        return findPeak(nums,0,nums.size()-1);
    }
};