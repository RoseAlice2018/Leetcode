#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=INT_MIN;
        int thissum=0;
        for(int i=0;i<nums.size();i++)
        {
            thissum+=nums[i];
            if(thissum>maxsum)
                maxsum=thissum;
            if(thissum<=0)
                thissum=0;
        }
        return maxsum;
    }
};