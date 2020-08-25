
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool f(int a)
    {
        int i=0;
        while(a>0)
        {
            i++;
            int temp=a%10;
            a=(a-temp)/10;
        }
        if(i%2==0)
            return true;
        else 
            return false;
    }
    int findNumbers(vector<int>& nums)
     {
         int count=0;
         for(int d:nums)
         {
             if(f(d))
                count++;
         }
         return count;
    }
};