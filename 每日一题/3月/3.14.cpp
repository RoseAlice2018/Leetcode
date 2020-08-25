#include<vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        if(nums.empty())
        {
            return 0;
        }
        else if(nums.size()==1)
        {
            return 1;
        }
        vector<int> res;
        for(int i=0;i<nums.size()-1;i++)
        {
            vector<int> r;
            r.push_back(nums[i]);
            int count=0;
            int temp=nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]>temp)
                {
                    count++;
                    temp=nums[j];
                    r.push_back(temp);
                }
                else 
                {
                    temp=nums[j];
                    if(r.size()>=2)
                    {
                       if(temp>r[r.size()-2])
                        {
                         r.pop_back();
                         r.push_back(temp);
                        }      
                    }
                    else
                    {
                        res.pop_back();
                        res.push_back(nums[j]);
                    }
                    
                             
                }                
            }
            res.push_back(count);
            r.clear();
        }
        int max=res[0];
        for(int i=0;i<res.size();i++)
        {
          if(res[i]>max)
            max=res[i];
        }
        return max;
    }
};