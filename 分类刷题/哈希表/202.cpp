#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> dic{1,4,9,16,25,36,49,64,81};
    bool isHappy(int n) {
        unordered_set<int> dic;
        while(1)
        {
            int temp = counthappy(n);
            n =temp;
            if(temp==1)
            {
                return true;
            }
            if(dic.count(temp))
                return false;
            dic.insert(temp);
        }   
        return false;   
    }
    int counthappy(int n)
    {
        // if(n>=10)
        // {
        //     int res = 0;
        //     while(n>0)
        //     {
        //         int temp = n % 10;
        //         n = (n-temp)/10;
        //         res+=counthappy(temp);
        //     }
        //     return res;
        // }
        // else
        // {
        //     return dic[n-1];
        // }
         int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};