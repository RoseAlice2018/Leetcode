#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> dic;
        for(int i=0;i<nums1.size();i++)
            dic.insert(nums1[i]);
        vector<int> res;
        for(int i=0;i<nums2.size();i++)
        {
            if(dic.count(nums2[i]))
            {
                res.push_back(nums2[i]);
                dic.erase(nums2[i]);
            }
        }
        return res;
    }
};