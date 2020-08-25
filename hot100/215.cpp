#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int len=nums.size();
        sort(nums.begin(),nums.begin()+len);
        return nums[nums.size()-k];
    }
};