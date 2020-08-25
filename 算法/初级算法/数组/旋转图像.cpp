#include<iostream>
#include<vector>
using namespace std;
class Solution
 {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int l1=matrix.size();
        //transpose matrix
        for(int i=0;i<l1;i++)
        {
            for(int j=i;j<l1;j++)
            {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        // reverse matrix
        for(int i=0;i<l1;i++)
        {
            for(int j=0;j<l1/2;j++)
            {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[i][l1-j-1];
                matrix[i][l1-j-1]=temp;
            }
        }
    }
};