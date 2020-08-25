#include<vector>
using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        vector<int> number;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2!=0)
            {
                number.push_back(i);
            }
        }
        int res=0;
        if(number.size()<k)
            return 0;
        else
        {
            for(int i=0;i<number.size();i++)
            {
                if(i+k>=number.size())
                    break;
                int left=0;
                if(i>0)
                {
                    left=number[i]-number[i-1]-1;
                }
                else
                {
                    left=number[i];
                }
                int right=number[i+k]-number[i+k-1]-1;
                int add=0;
                if(left>1&&right>1)
                {
                   add=pow(2,left+right)/(left-1+right-1);
                }
                else if(left>1)
                {
                    add=pow(2,left+right)/(left-1);
                }
                else if(right>1)
                {
                    add=pow(2,right+left)/(right-1);
                }
                else
                {
                    add=pow(2,left+right);
                }
                res+=add;              
                
            }
            int i=number.size()-k;
            int add=0;
            int left=0;
                if(i>0)
                {
                    left=number[i]-number[i-1]-1;
                }
                else
                {
                    left=number[i];
                }
            int right=nums.size()-number[number.size()-1]-1;
            if(left>1&&right>1)
                {
                   add=pow(2,left+right)/(left-1+right-1);
                }
                else if(left>1)
                {
                    add=pow(2,left+right)/(left-1);
                }
                else if(right>1)
                {
                    add=pow(2,right+left)/(right-1);
                }
                else
                {
                    add=pow(2,left+right);
                }
                res+=add;    
          
        }
        return res;  
    }
};