#include<vector>
using namespace std;
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        while(left<right)
        {
            if(nums[left]%2==0&&nums[right]%2==1)
            {
                //swap
                swap(nums[left],nums[right]);
                //
                left++;
                right--;
            }
            else if(nums[left]%2==0&&nums[right]%2==0)
            {
                right--;
            }
            else if(nums[left]%2==1&&nums[right]%2==1)
            {
                left++;
            }
            else
            {
                left++;
                right--;
            }
            
        } 
        return nums;      
    }
    void swap(int& a,int& b)
    {
        int t=a;
        a=b;
        b=t;
    }
};