#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        for(int i=0;i<=right;i++)
        {
            if(nums[i]==0)
            {
                int temp=nums[left];
                nums[left]=nums[i];
                nums[i]=temp;
                left++;
            }
            else if(nums[i]==2)
            {
                int temp=nums[right];
                nums[right]=nums[i];
                nums[i]=temp;
                right--;
                i--;
            }
        }
    }
};