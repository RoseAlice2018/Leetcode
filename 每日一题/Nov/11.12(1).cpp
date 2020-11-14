#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A)
     {
         vector<int> ji;
         vector<int> ou;
         for(int i=0;i<A.size();i++)
         {
             if(A[i]%2==0)
                ou.push_back(A[i]);
            else 
                ji.push_back(A[i]);
         }
        for(int i=0,j=0;i<A.size();i+=2,j++)
        {
            A[i]=ou[j];
            A[i+1]=ji[j];
        }
        return A;
    }
};