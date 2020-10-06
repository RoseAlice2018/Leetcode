#include<vector>
using namespace std;
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int max=INT_MIN;
        int min=INT_MAX;
        int tag=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                ;//skip;
            else
            {
                if(nums[i]==1)
                {
                    //special tackle
                    tag=1;
                }
                else
                {
                    if(nums[i]>max)
                        max=nums[i];
                    if(nums[i]<min)
                        min=nums[i];
                }
            }  
        }
        if(tag)
        {
            if(min>=10)
                max=14;
            if(max<=5)
                min=1;
        }
       
        if(max-min<5)
            return true;
        
        return false;
    }
};