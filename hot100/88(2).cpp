#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
     {
         vector<int> numscopy(nums1);
         int left=0;
         int right=0;
         int count=0;
         while(left<m&&right<n)
         {
             if(numscopy[left]>=nums2[right])
             {
                 nums1[count++]=nums2[right++];
             }
             else
             {
                 nums1[count++]=numscopy[left++];
             }
         }
         while(left<m)
         {
             nums1[count++]=numscopy[left++];
         }
         while(right<n)
         {
             nums1[count++]=nums2[right++];
         }
    }
};