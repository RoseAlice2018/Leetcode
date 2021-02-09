#include<vector>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) {
        int up=0;
        int down=0;
        int front=INT_MAX;
        int min=0;
        if(nums.size()<=1)
            return true;
        front=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            while(nums[i]>front)
            {
                i++;
                front=nums[i];
                if(i==nums.size())
            }

        }
    }
};