#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> storage;
        for(int i=0;i<nums.size();i++)
        {
            if(storage.count(nums[i]))
                return true;
            else
            {
                storage.insert(nums[i]);
            }
        }
        return false;
    }
};