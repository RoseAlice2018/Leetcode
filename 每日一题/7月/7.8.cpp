#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k)
    {
        vector<int> res;
        if(k==0)
            return res;
        set<int> check;
        for(int i=0;i<=k;i++)
        {
            int temp=shorter*(k-i)+longer*i;
            if(check.count(temp))
                ;
            else
            {
                res.push_back(temp);
                check.insert(temp);
            }            
        }
        return res;
    }
};