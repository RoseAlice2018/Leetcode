#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=binarysearch(nums,target,0,nums.size()-1);
        if(n==-1)
        {
            return 0;
        }
        int count=0;
        int left=n-1,right=n;
        while(left>=0&&nums[left]==target)
        {
            left--;
            count++;
        }
        while(right<=nums.size()-1&&nums[right]==target)
        {
            right++;
            count++;
        }
        return count;
    }
private:
    int binarysearch(vector<int>& nums,int target,int left,int right)
    {
        if(left>right)
            return -1;
        int mid=(right+left)/2;
        if(nums[mid]>target)
        {
            return binarysearch(nums,target,left,mid-1);

        }
        else if(nums[mid]<target)
        {
            return binarysearch(nums,target,mid+1,right);
        }
        else{
            return mid;
        }
        return -1;
    }
};