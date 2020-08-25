#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        //先顺时针转180°
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1]=temp;
            }
        }
        //逆时针旋转90°
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }

        
    }
};