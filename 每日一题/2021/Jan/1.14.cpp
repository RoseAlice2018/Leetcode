#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        int temp=0;
        for(int i=0;i<A.size();i++)
        {
            if(i==0)
                temp=A[i];
            else {
                temp<<=1;
                temp+=A[i];
            }
            temp%=5;
            if(temp==0)
                res.push_back(true);
            else 
                res.push_back(false);
        }
        return res;
    }
};