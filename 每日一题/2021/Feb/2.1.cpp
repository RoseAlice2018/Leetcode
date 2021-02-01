#include <vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        //unordered_set<int> candiesA;
        unordered_set<int> candiesB;
        int sumA=0;
        for(int i=0;i<A.size();i++)
          {
            sumA+=A[i];
          }
        int sumB=0;
        for(int i=0;i<B.size();i++)
          {
            candiesB.insert(B[i]);
            sumB+=B[i];
          }
        vector<int> res;
        for(int i=0;i<A.size();i++)
        {
          int  x = A[i];
          int  m = sumA-x;
          int  y=(sumB-sumA)/2+x;
          if(candiesB.count(y))
          {
              res.push_back(x);
              res.push_back(y);
              return res;
          }
        } 
        return res;       
    }
};
