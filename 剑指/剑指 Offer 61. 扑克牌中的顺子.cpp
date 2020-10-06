#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int max=INT_MIN;
        int min=INT_MAX;
       // int tag=0;
        set<int> num;
        for(int i=0;i<nums.size();i++)
           {
               if(num.count(nums[i])&&nums[i]!=0)
                    return false;
                num.insert(nums[i]);
           }
        set<int>::iterator it=num.begin();
        
        for(;it!=num.end();it++)
        {
            if(*it==0)
                ;//skip;
            else
            {
                // if(*it==1)
                // {
                //     //special tackle
                //     tag=1;
                // }
                // else
               // {
                    if(*it>max)
                        max=*it;
                    if(*it<min)
                        min=*it;
              //  }
            }  
        }
        // if(tag)
        // {
        //     if(min>=10)
        //         max=14;
        //     else if(max<=5)
        //         min=1;
        //     else 
        //         return false;
        // }
       
        if(max-min<5)
            return true;
        
        return false;
    }
};