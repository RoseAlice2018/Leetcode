#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findPeak(vector<int>& nums,int left,int right)
    {
        int mid=(right-left)/2+left;
        if(right==left)
        {
            return left;
        } 
        else 
        {
            if(nums[mid]>nums[mid+1])
            {
                return findPeak(nums,left,mid);
            }
            else
            {
                return  findPeak(nums,mid+1,right);
            }
            
        }
        return 0;
    }
    int findPeakElement(vector<int>& nums) 
    {
        return findPeak(nums,0,nums.size()-1);
    }
};