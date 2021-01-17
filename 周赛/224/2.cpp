#include<vector>
#include<iostream>
#include<set>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int res=0;
        set<int> dic;
        unordered_map<int,int> mapp;
        for(auto iter : nums)
            dic.insert(iter);
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(i!=j)
                {
                    int temp=nums[i]*nums[j];
                    if(mapp.count(temp))
                        mapp[temp]++;
                    else 
                        mapp[temp]=1;
                }
            }
        }
        for(auto iter : mapp)
        {
            iter.second/=2;
            if(iter.second>1)
            {
                res+=(iter.second*(iter.second-1))/2*8;
            }
        }
        return res;
    }
};