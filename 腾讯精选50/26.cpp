#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int len=nums.size();
        if(nums.size()==0)
        return 0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                len--;
                nums[i]=-1000;// 
            }
        }
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==-1000)
            {
                int j=i+1;
                for(;j<nums.size();j++)
                {
                    if(nums[j]!=-1000)
                    {
                        nums[i]=nums[j];
                        nums[j]=-1000;
                        break;
                    }
                }
            }
        }
        return len;
    }
};
// -1 1 2

// int len=nums.size();
        // for(int i=0;i<nums.size()-1;i++)
        // {
        //     if(nums[i]==nums[i+1])
        //     {
        //         nums[i+1]=-1;
        //         int j;
        //         for( j=i+2;j<nums.size();j++)
        //         {
        //             if(nums[j]==nums[i])
        //                 nums[j]=-1;
        //             else
        //                 break;                    
        //         }
        //         i=j-1;
        //     }
        // }
        // for(int i=0;i<nums.size()-1;i++)
        // {
        //     if(nums[i]==-1)
        //     {
        //         for(int j=i+1;j<nums.size();j++)
        //         {
        //             if(nums[j]!=-1)
        //             {
        //                 nums[i+1]=nums[j];
        //             }
        //         }
        //         int temp=nums[i];
        //         nums[i]=nums[i+1];
        //         nums[i+1]=temp;
        //     }
        // }
        // return len;