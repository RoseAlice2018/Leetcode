#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums)
     {
         set<int> dic;
         set<int> res;
         for(int i=0;i<nums.size();i++)
         {
             if(dic.count(nums[i]))
             {
                 res.erase(nums[i]);
             }
             else{
                 dic.insert(nums[i]);
                 res.insert(nums[i]);
             }
         }
         set<int>::iterator it=res.begin();
         return *it;
    }
};