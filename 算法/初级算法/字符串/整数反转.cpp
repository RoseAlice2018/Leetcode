#include<queue>
using namespace std;
class Solution {
public:
    int reverse(int x)
     {
        queue<int> res;
        while(x!=0)
        {
            int temp=x%10;
            res.push(temp);
            x=(x-temp)/10;
        }
        long result=0;
        while(!res.empty())
        {
            result+=pow(10,res.size()-1)*res.front();
            res.pop();            
        }
        if(result>INT32_MAX||result<INT32_MIN)
        {
            return 0;
        }
        else
        {
            return result;
        }
    }
};