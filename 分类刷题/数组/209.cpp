
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left=0,right=0;
        if(nums.size()==0)
            return 0;
        int res=INT_MAX;
        int sum=0;
        int flag = 1;
        while(right<nums.size())
        {
            if(flag == 1)
            {
               sum+=nums[right]; 
            }
            if(sum<s)
            {
                flag = 1;
                right++;
                continue;
            }
            else
            {
                int temp = right-left+1;
                if(temp<res)
                    res=temp;
                sum-=nums[left++];
                flag = 0;
            }
        }
        return res == INT_MAX ? 0 :res;
    }
};