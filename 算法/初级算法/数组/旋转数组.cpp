#include<vector>
using namespace std;
class Solution {
public:
    void swap(int& a,int& b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    void rotate(vector<int>& nums, int k)
     {
        if(k>=1)
        {
            rotate(nums,k-1);
            int temp=nums[nums.size()-1];
            for(int i=nums.size()-1;i>=1;i--)
                nums[i]=nums[i-1];
            nums[0]=temp;
            return;
        }
        else
        {
            return;
        }
        
        
        
    }
};