#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int diff=-1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1])
            {
                diff=i;
            }
        }
        if(diff==-1)
        {
            reverse(nums.rbegin(),nums.rend());
            return;
        }
        
    }
};