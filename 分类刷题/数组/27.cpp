#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fastindex=0,slowindex=0;
        for(fastindex=0;fastindex<nums.size();)
        {
            if(val!=nums[fastindex])
            {
                nums[slowindex++]=nums[fastindex++];
            }
            else
            {
                fastindex++;
            }
        }
        return slowindex;
    }
};