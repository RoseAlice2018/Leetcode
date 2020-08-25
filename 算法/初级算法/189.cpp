#include<vector>
using namespace std;
class Solution {
public:
  
    void rotate(vector<int>& nums, int k)
     {
        while (k>=1)
        {
             int temp=nums[nums.size()-1];
            for(int i=nums.size()-1;i>=1;i--)
                nums[i]=nums[i-1];
            nums[0]=temp;
            k--;
        }        
    }
};