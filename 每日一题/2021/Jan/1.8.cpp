#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k = k % n;
        rotate_one(nums,k);
        return;
    }
    void rotate_one(vector<int>& nums,int k)
    {
        if(k == 0)
            return ;
        int temp=nums[nums.size()-1];
        for(int i=nums.size()-1;i>0;i--)
            nums[i]=nums[i-1];
        nums[0]=temp;
        rotate_one(nums,k-1);
    }
};