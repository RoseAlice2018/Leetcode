#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) 
    {
        int highestscore=0;
        for(int i=0;i<A.size();i++)
        {
            for(int j=i+1;j<A.size();j++)
            {
                if(A[i]+A[j]-(j-i)>highestscore)
                    highestscore=A[i]+A[j]-(j-i);
            }
        }
        return highestscore;
    }
};