#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A)
     {
         int left=0,right=0;
         for(int i=0;i<A.size();i++)
         {
             if(A[i]%2==0&&i%2==0||(A[i]%2==1&&i%2==1))
                ;
            else if(i%2==0)
            {
                for(int j=i+1;j<A.size();j++)
                {
                    if(A[j]%2==0)
                    {
                        swap(A[i],A[j]);
                    }
                }
            }
            else if(i%2==1)
            {
                for(int j=i+1;j<A.size();j++)
                {
                    if(A[j]%2==1)
                    {
                        swap(A[i],A[j]);
                    }
                }
            }
         }
         return A;
    }
};