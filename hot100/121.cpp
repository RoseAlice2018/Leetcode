#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        //暴力算法 超出时间限制
        // int maxprofite=0;
        // for(int i=0;i<prices.size();i++)
        // {
        //     for(int j=i+1;j<prices.size();j++)
        //     {
        //         int temp=prices[j]-prices[i];
        //         if(temp>maxprofite)
        //             maxprofite=temp;
        //     }
        // }
        // return maxprofite;
        int maxprofit=0;
        int minprice=INT32_MAX;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<minprice)
                minprice=prices[i];
            else if(prices[i]-minprice>maxprofit)
                maxprofit=prices[i]-minprice;
        }
        return maxprofit;
    }
};