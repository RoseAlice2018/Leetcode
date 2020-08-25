#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int maxsum=nums[0],thissum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(thissum>0)
            {
                thissum+=nums[i];
            }
            else 
                thissum=nums[i];
            if(thissum>maxsum)
                maxsum=thissum;
        }
        return maxsum;
        
    }
};