#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) 
    {
        int count=0;
        for(int i=0;i<A.size();i++)
        {
            int count1=0;
            for(int j=i;j<A.size();j++)
            {
                count1+=A[j];
                if(count1%K==0)
                    count++;
            }
        }
        return count;
    }
};