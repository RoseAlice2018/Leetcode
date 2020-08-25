#include<vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int num) 
    {
        vector<int> res;
        for(int i=0;i<=num;i++)
            res.push_back(pop_count(i));
        return res;
    }
    int pop_count(int num)
    {
        int res=0;
        while (num!=0)
        {
            num&=num-1;
            res++;
        }
        return res;        
    }
};