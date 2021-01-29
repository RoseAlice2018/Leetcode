#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> ret;
        int dp_matrix[m+2][n+2];
            int i=0;          
            int temp=matrix[i][0];
            dp_matrix[i][0]=temp;
            for(int j=1;j<n;j++)
            {
                temp = temp xor matrix[i][j];
                dp_matrix[i][j]=temp;
                ret.push_back(temp);
            }
             temp=matrix[0][i];
            dp_matrix[0][i]=temp;
            for(int j=1;j<m;j++)
            {
                temp = temp xor matrix[j][i];
                dp_matrix[j][i]=temp;
                ret.push_back(temp);
            }

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp_matrix[i][j]=dp_matrix[i-1][j] xor dp_matrix[i][j-1] xor matrix[i][j] xor matrix[i-1][j-1];
                ret.push_back(dp_matrix[i][j]);
            }
        }
        sort(ret.begin(),ret.end());
        return ret[ret.size()-k];
    }
};