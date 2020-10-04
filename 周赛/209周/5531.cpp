#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int res=-1;
        sort(nums.begin(),nums.end());
        int max=nums[nums.size()-1];
        int x=1;
        int last=0;
        while(x<=max)
        {
            for(int i=last;i<nums.size();i++)
            {
                if(nums[i]>=x)
                {
                    last=i;
                    int t=nums.size()-i;
                    if(t==x)
                    {
                        return x;
                    }
                    else
                    {
                        break;
                    }
                    
                }
            }
            x++;
        }
        return res;
    }
};