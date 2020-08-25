#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums)
     {
        int n=nums.size();
        int cnt[n+2]={0};
        for(int i=1;i<=n-1;i++)
        {
            int temp=0;
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j]<=i)
                    temp++;
            }
            cnt[i]=temp;
        }
        for(int i=2;i<n-1;i++)
        {
            if(cnt[i-1]<=i&&cnt[i+1]>i)
                return i;
        }
        if(cnt[1]<=1&&cnt[2]>1)
            return 1;
        else 
            return n-1;

    return 0;
    }
};