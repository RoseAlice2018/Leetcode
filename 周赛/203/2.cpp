#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int count=(piles.size()+1)/3;
        int res=0;
        while (count<piles.size()-1)
        {
            res+=piles[count];
            count+=2;
        }
        return res;
    }
};