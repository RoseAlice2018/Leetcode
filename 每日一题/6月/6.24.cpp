#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
     {
         sort(nums.begin(),nums.end());
         int dif=INT32_MAX;
         int res=0;
         for(int i=0;i<nums.size()-2;i++)
         {
             int a=nums[i];
             int left=i+1;
             int right=nums.size()-1;
             while(left<right)
             {
                 int b=nums[left];
                 int c=nums[right];
                if(fabs(a+b+c-target)<dif)
                {
                    dif=fabs(a+b+c-target);
                    res=a+b+c;
                    if(dif==0)
                        return target;
                }
                if(a+b+c>target)
                    right--;
                else if(a+b+c<target)
                    left++;
             }
         }
         return res;
    }   
};