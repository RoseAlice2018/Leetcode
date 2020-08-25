#include<iostream>
#include<math.h>
using namespace std;
class Solution {
public:
    int superpalindromesInRange(string L, string R)
     {
         int count=0;
        double LL=stoi(L,nullptr,10);
        double RR=stoi(R,nullptr,10);
        for(double i=LL;i<=RR;i++)
        {
            if(check(i)&&check(sqrt(i)))
                count++;
        }
        return count;
    }
    bool check(double num)
    {
        string nums=to_string(num);
        for(int i=0;i<nums.length()/2;i++)
        {
            if(nums[i]==nums[nums.length()-i-1])
            ;
            else
            {
                return false;
            }
            
        }
        return true;
    }
};