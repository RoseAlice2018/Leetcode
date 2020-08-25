#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
     {
         vector<int> temp;
         for(int i=0;i<matrix.size();i++)
         {
             for(int j=0;j<matrix[i].size();j++)
             {
                 temp.push_back(matrix[i][j]);
             }
         }
        sort(temp.begin(),temp.end());
        return temp[k-1];
    }
};
