#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int index1=0;
        int index2=numbers.size()-1;
        int temp;
        vector<int> res;
        while(index1<index2)
        {
            temp=numbers[index1]+numbers[index2];
            if(temp==target)
            {
                res.push_back(index1+1);
                res.push_back(index2+1);
                return res;
            }
            else if(temp>target)
            {
                index2--;
            }
            else if(temp<target)
            {
                index1++;
            }
        }
        return res;
    }
};