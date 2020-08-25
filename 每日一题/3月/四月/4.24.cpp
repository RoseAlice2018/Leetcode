#include<vector>
using namespace std;
class Solution {
public:
    int reversePairs(vector<int>& nums) 
    {
        if(nums.size()<2)
            return 0;
        vector<int> copy(nums.size());
        vector<int> temp(nums.size());
        for(int i=0;i<nums.size();i++)
            copy[i]=nums[i];
        return reversePairs(copy,0,nums.size()-1,temp);
    }
private:
    int reversePairs(vector<int>& nums,int left,int right,vector<int>& temp)
    {
        if(left==right)
            return 0;
        int mid=(right-left)/2+left;
        int leftpairs=reversePairs(nums,left,mid,temp);
        int rightpairs=reversePairs(nums,mid+1,right,temp);
        if(nums[mid]<=nums[mid+1])
            return leftpairs+rightpairs;
        int crosspairs=mergepairs(nums,left,mid,right,temp);
        return leftpairs+rightpairs+crosspairs;
    }
    int mergepairs(vector<int>& nums,int left,int mid,int right,vector<int>& temp)
    {
        for(int i=left;i<=right;i++)
            temp[i]=nums[i];
        int i=left;
        int j=mid+1;
        int count=0;
        for(int k=left;k<=right;k++)
        {
            if(i==mid+1)
            {
                nums[k]=temp[j];
                j++;
            }
            else if(j==right+1)
            {
                nums[k]=temp[i];
                i++;
            }
            else if(temp[i]<=temp[j])
            {
                nums[k]=temp[i];
                i++;
            }
            else
            {
                nums[k]=temp[j];
                j++;
                count+=(mid-i+1);
            }
            
        }
        return count;
    }
    
};