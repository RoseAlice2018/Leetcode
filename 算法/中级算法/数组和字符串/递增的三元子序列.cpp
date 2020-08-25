#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, sec = INT_MAX;     
        for(int n : nums)                       //
        {
            if(n <= first)  first = n;          
            else
            {
                if(n <= sec )   sec = n;        
                else   return true;
            }
        }
        return false;

    }
};
