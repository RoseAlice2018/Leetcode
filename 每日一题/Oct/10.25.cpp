#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int longestMountain(vector<int>& A)
     {
         vector<int> dist;
         if(A.size()<=1)
            return 0;
         for(int i=1;i<A.size()-1;i++)
         {
             if(A[i-1]<A[i]&&A[i]>A[i+1])
             {
                 dist.push_back(i);
             }
         }
         if(dist.empty())
            return 0;
        int res=0;
        for(int i=0;i<dist.size();i++)
        {
            int temp=check(A,dist[i]);
            if(temp>res)
                res=temp;
        }
        return res;

    }
    int check(vector<int>& num,int i)
    {
        int left=i-1,right=i+1;
        int res=3;
        while(left>0)
        {
            if(num[left]>num[left-1])
                res++;
            else 
                break;
            left--;
        }
        while(right<num.size()-1)
        {
            if(num[right]>num[right+1])
                res++;
            else 
                break;
            right++;
        }
        return res;
    }

};