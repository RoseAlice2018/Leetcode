#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int count=0;
    int hammingWeight(uint32_t n)
     {
         vector<int> res;
         while(n>0)
         {
             int temp=n%2;
             if(temp==1)
                count++;
             res.push_back(temp);
             n=(n-temp)/2;
         }
         return count;
    }
};