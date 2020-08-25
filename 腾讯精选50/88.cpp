#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int adv=nums1.size()-m;
        for(int i=0;i<adv;i++)
            nums1.pop_back();
        for(int i=0;i<n;i++)
            nums1.push_back(nums2[i]);
        sort(&nums1[0],&nums1[m+n]);
        
    }
};