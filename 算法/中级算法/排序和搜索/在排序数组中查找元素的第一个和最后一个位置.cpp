#include<vector>
using namespace std;
class Solution {
public:
    vector<int> res;
    int l=-1,r=-1;
    void search(vector<int> nums,int target,int left,int right)
    {
        if(left>right)
            return;
        int mid=(right-left)/2+left;
        if(nums[mid]==target)
        {
            if(mid<l||l==-1)
            {
                l=mid;
            }
            if(mid>r||r==-1)
            r=mid;
            if(left<mid)
            {
                search(nums,target,left,mid-1);
            }
            if(right>mid)
            {
                search(nums,target,mid+1,right);
            }
        }
        else
        {
            if(nums[mid]<target)
            {
                search(nums,target,mid+1,right);
            }
            else
            {
                search(nums,target,0,mid-1);
            }
        }    
    }
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        search(nums,target,0,nums.size()-1);
        res.push_back(l);
        res.push_back(r);
        return res;
    }
};