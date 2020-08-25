#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> res;
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> temp;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            int dif=target-nums[i];
            if(temp[dif])
            {
                res.push_back(i);
                res.push_back(temp[dif]);
                return res;
            }
            temp[nums[i]]=i;
        }
        return res;
    }
};