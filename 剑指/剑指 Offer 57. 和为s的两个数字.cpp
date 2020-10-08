#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        vector<int> res;
        while(left<=right)
        {
            if(nums[left]+nums[right]==target)
            {
                res.push_back(nums[left]);
                res.push_back(nums[right]);
                return res;
            }
            else if(nums[left]+nums[right]>target)
            {
                right--;
            }
            else{
                left++;
            }
        }
        return res;
    }
};