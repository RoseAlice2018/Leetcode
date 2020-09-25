
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int temp;
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]!=i){
                if(nums[i]==nums[nums[i]])
                {
                    return nums[i];
                }
                temp=nums[i];
                nums[i]=nums[temp];
                nums[temp]=temp;
            }
        }
        return 0;
    }
};