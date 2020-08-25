#include<vector>
using namespace std;
class Solution {
public:

    int numPairsDivisibleBy60(vector<int>& time)
     {
         int res[60]={0};
         int count=0;
         for(int i=0;i<time.size();i++)
         {
             res[time[i]%60]++;
         }
         for(int i=1;i<30;i++)
         {
                count+=res[i]*res[60-i];
         }
         //i==0;
         count+=((res[0]*(res[0]-1))/2);
        count+=((res[30]*(res[30]-1))/2);
         
         return count;
    }
};