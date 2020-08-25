#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
     {
         vector<bool> res;
         int maxcandies=0;
         for(int i=0;i<candies.size();i++)
         {
             if(candies[i]>maxcandies)
                maxcandies=candies[i];
         }
         int minus=0;
         for(int i=0;i<candies.size();i++)
         {
             minus=maxcandies-candies[i];
             if(minus<=extraCandies)
                res.push_back(true);
            else 
                res.push_back(false);
         }
         return res;
    }
};