#include<vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        for(int i=digits.size()-1;i>=0;i--)
        {
            int temp=digits[i]+1;
            if(temp>=10)
            {
                digits[i]=0;
            }
            else
            {
                digits[i]=temp;
                return digits;
            }
        }
        vector<int> res;
        res.push_back(1);
        for(int i=0;i<digits.size();i++)
            res.push_back(0);
        return res;
    }
};