class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange)
     {
         int leftbottle;// empty bottles for exchange
         int res=0;// can have bottle;
         res=numBottles;
         leftbottle=numBottles;
         while(leftbottle>=numExchange)
         {
             int temp=leftbottle%numExchange;
             res+=(leftbottle-temp)/numExchange;
             leftbottle=temp+(leftbottle-temp)/numExchange;
         }
         return res;
    }
};