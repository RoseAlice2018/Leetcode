#include<vector>
#include<random>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int count=0;
    vector<int> first;
    Solution(vector<int>& nums) 
    {
        if(count==0)
        {
            first=nums;
            count++;
        }
        int n=nums.size();
        unordered_set<int> res;
        vector<int> temp;
        while(temp.size()<n)
        {
            int k=rand()%n;
            if(res.count(nums[k]))
            {
                continue;
            }
            else
            {
                res.insert(nums[k]);
                temp.push_back(nums[k]);
            }
        }
        nums=temp;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return first;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n=first.size();
        unordered_set<int> res;
        vector<int> temp;
        while(temp.size()<n)
        {
            int k=rand()%n;
            if(res.count(first[k]))
            {
                continue;
            }
            else
            {
                res.insert(first[k]);
                temp.push_back(first[k]);
            }
        }
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */