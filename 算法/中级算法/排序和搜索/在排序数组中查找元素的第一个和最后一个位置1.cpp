#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int Index(vector<int>& nums,int target,bool left)
    {
        int l=0;
        int h=nums.size();
        while (l<h)
        {
            int mid=(l+h)/2;
            if(nums[mid]>target||(left&&target==nums[mid]))
            {
                h=mid;
            }
            else
            {
                l=mid+1;
            }
            
        }
        return l;
        
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int leftIndex=Index(nums,target,true);
        if(leftIndex==nums.size()||nums[leftIndex]!=target)
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        res.push_back(leftIndex);
        int rightIndex=Index(nums,target,false)-1;
        res.push_back(rightIndex);
        return res;
    }
};