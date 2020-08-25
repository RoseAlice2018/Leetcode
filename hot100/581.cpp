#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        int size=nums.size();
        vector<int> cop(size);
        copy(nums.begin(),nums.end(),cop.begin());
        sort(cop.begin(),cop.end());
        int left=0;
        int right=size-1;
        int length=size;
        while(cop[left]==nums[left])
        {
            left++;
            length--;
            if(left>size-1)
            {
                return 0;
            }
        }
        while(cop[right]==nums[right])
        {
            right--;
            length--;
            if(right<0)
            {
                return 0;
            }
        }
        return length;
    }
};