#include<vector>
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
    void help(vector<int>& nums,int begin,int end,int& max,stack<int>& maxvalue)
    {
        int i=begin;
        for(i=begin;i<end;i++)
        {
            if(nums[i]>max)
            {
                max=nums[i];
                if(!maxvalue.empty())
                {
                    //clear the stack
                    while(!maxvalue.empty())
                        maxvalue.pop();
                    maxvalue.push(nums[i]);
                }
                maxvalue.push(nums[i]);
            }
            else if(nums[i]==max)
            {
                maxvalue.push(nums[i]);
            }
        }
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        stack<int> maxvalue;
        vector<int> res;
        if(nums.empty())
            return res;
        int max=INT_MIN;
        int min = nums.size()>k ? k : nums.size();
        int i=0;
        help(nums,0,min,max,maxvalue);
        res.push_back(maxvalue.top());
        i=1;
        while(i+k-1<nums.size())
        {
            //the left number
            if(nums[i-1]==max)
            {
                maxvalue.pop();
            }
            if(nums[i+k-1]>max)
            {
                max=nums[i+k-1];
                if(!maxvalue.empty())
                {
                    //clear the stack
                    while(!maxvalue.empty())
                        maxvalue.pop();
                }
                maxvalue.push(max);
            }   
            else if(nums[i+k-1]==max)
            {
                maxvalue.push(nums[i]);
            }
            if(maxvalue.empty()){
                //find the max
                max=INT_MIN;
                help(nums,i,i+k,max,maxvalue);
            }
            res.push_back(maxvalue.top());   
            i++;      
        }
        return res;
    }
};