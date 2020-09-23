#include<vector>
using namespace std;
class Solution {
public:
    int find(vector<int>& nums,int left,int right)
    {
        if(left>=right)
            return left;
        int mid=(left+right)/2;
        if(nums[mid]==mid)
        {
            return find(nums,mid+1,right);
        }
        else{
            return find(nums,left,mid);
        }
    }
    int missingNumber(vector<int>& nums)
     {
         int res=0;
        res=find(nums,0,nums.size()-1);
        return res;
    }
};