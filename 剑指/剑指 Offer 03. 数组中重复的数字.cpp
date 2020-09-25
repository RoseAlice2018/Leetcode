#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> dic;
        for(int i=0;i<nums.size();i++)
        {
            if(dic.count(nums[i]))
                return nums[i];
            dic.insert(nums[i]);
        }
        return 0;
    }
};