#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target)
     {
         vector<vector<int>> res;
         vector<int> temp;
        int sum=0;
        int left=1;
        for(int i=1;i<=target/2+1;i++)
        {
            sum+=i;
            if(sum==target)
            {
                //结果
                for(int j=left;j<=i;j++)
                    temp.push_back(j);
                res.push_back(temp);
                temp.clear();                
            }
            else if(sum>target)
            {
                while(sum>target)
                {
                    sum-=left;
                    left++;
                }
                if(sum==target)
                {
                    for(int j=left;j<=i;j++)
                        temp.push_back(j);
                    res.push_back(temp);
                    temp.clear();
                }
            }
        }
        return res;
    }
};