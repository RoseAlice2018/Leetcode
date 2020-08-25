#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int key=nums[0];
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==key)
                count++;
            else
            {
                count--;
            }
            if(count<=0)
            {
                key=nums[i+1];
            } 
        }
    return key;
    }
};