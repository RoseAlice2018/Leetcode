#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target)
     {
       int siz=(int)nums.size();
       if(!siz)
            return -1;
        if(siz==1)
            return nums[0]==target?0:-1;
        int left=0,right=siz-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[0]<=nums[mid])
            {
                if(nums[0]<=target&&nums[mid]>target)
                    right=mid-1;
                else 
                    left=mid+1;
            }
            else 
            {
                if(nums[mid]<target&&nums[right]>=target)
                    left=mid+1;
                else
                {
                    right=mid-1;
                }
                
            }
        }
        return -1;
    }
};