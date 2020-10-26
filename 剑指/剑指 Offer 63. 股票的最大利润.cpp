#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices)
     {
         int res=0;if(prices.size()==0)
            return 0;
         int min=prices[0];
         
         for(int i=0;i<prices.size();i++)
         {
             if(prices[i]<=min)
                min=prices[i];
            else
            {
                res=max(res,prices[i]-min);
            }
            
         }
         return res;
    }
};