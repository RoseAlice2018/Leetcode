#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) 
    {
        int highestscore=0;
        int mx=0;
        for(int j=0;j<A.size();j++)
        {
            highestscore=max(highestscore,mx+A[j]-j);
            mx=max(mx,A[j]+j);
        }
        return highestscore;
    }
};