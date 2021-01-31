
#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<int> candies;
        candies.push_back(0);
        for(int i=1;i<=candiesCount.size();i++)
        {
            candies.push_back(candies[i-1]+candiesCount[i-1]);
        }
        vector<bool> res;
        for(int i=0; i<queries.size();i++){
            int favoritytype = queries[i][0];
            int favoriteday = queries[i][1];
            int dailycaps = queries[i][2];
            if(favoriteday*dailycaps>=candies[favoritytype]&&candies[favoritytype]>=favoriteday)
                res.push_back(true);
            else
            {
                res.push_back(false);
            }
            
        }
        return res;
    }
};