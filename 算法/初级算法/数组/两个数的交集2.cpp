#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
     {
         vector<int> res;
         unordered_map<int,int> temp;
         for(int i=0;i<nums1.size();i++)
         {
             if(temp[nums1[i]])
             {
                 temp[nums1[i]]++;
             }
             else
             {
                 temp[nums1[i]]=1;
             }
         }
         for(int i=0;i<nums2.size();i++)
         {
             if(temp[nums2[i]])
             {
                 temp[nums2[i]]--;
                 res.push_back(nums2[i]);
             }             
         }
         return res;
    }
};