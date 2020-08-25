#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> res;
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> temp;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            temp[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            int dif=target-nums[i];
            if(temp[dif]&&temp[dif]!=i)
            {
                res.push_back(i);
                res.push_back(temp[dif]);
                return res;
            }
        }
        return res;
    }
};