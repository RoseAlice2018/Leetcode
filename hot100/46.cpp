#include<iostream>
#include<vector>
#include<List>

using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    bool contain(vector<int>&nums,int a)
    {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==a)
                return true;
        }
        return false;
    }
    void trace(vector<int>& nums,vector<int>& temp)
    {
        if(temp.size()==nums.size())
        {
            res.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(contain(temp,nums[i]))
                continue;
            temp.push_back(nums[i]);
            trace(nums,temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> temp;
        trace(nums,temp);
        return res;
    }

};


int squareEx(int a,int n)
{
    if(n==0)
        return 1;
    if(n%2==1)
    {
        //奇数
        return a*squareEx(a,n-1);
    }
    else
    {
        //偶数
        int temp=squareEx(a,n/2);
        return temp*temp;
    }
    
}

int qpow(int a,int n)
{
    int ans=1;
    while (n)
    {
        if(n&1)
            ans*=a;
        a*=a;
        n>>1;
    }
    return ans;    
}