#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.size()==0)
            return 0;
        sort(nums.begin(),nums.begin()+nums.size());
        int longest=0;
        int count=0;
        vector<int> temp(nums.size());
        for(int i=1;i<nums.size();i++)
        {
            temp[i]=nums[i]-nums[i-1];
        }
        temp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            if(temp[i]==1)
            {
                count++;
                if(count>longest)
                    longest=count;
            }
            else if(temp[i]>1)
            {
                count=1;
                if(count>longest)
                    longest=count;
            }
        }
        return longest;
    }
};