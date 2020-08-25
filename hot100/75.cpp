#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int zero=0,one=0,two=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                zero++;
            else if(nums[i]==1)
                one++;
            else if(nums[i]==2)
                two++;
        }
        int i=0;
        for( i=0;i<zero;i++)
            nums[i]=0;
        for(;i<zero+one;i++)
            nums[i]=1;
        for(;i<nums.size();i++)
            nums[i]=2;
            
    }
};