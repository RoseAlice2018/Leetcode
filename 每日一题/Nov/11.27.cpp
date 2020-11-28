#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
    {
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        sort(C.begin(),C.end());
        sort(D.begin(),D.end());
        int res=0;
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<B.size();j++)
            {
                int temp=A[i]+B[j];
                res+=twosum(C,D,-temp);
            }
        }
        return res;     
    }
    int twosum(vector<int>& A,vector<int>& B,int target)
    {
        int left=0,right=A.size()-1;
        int res=0;
        while (left<A.size()&&right>=0)
        {
            if(A[left]+B[right]==target)
            {
                res++;
            }
            else if(A[left]+B[right]>target)
            {
                right--;
            }
            else
            {
                left++;
            }
            
        }
        return res;
        
    }
};