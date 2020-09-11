#include<unordered_set>
using namespace std;
class Solution {
public:
    int change(int n)
    {
        int res=0;
        while(n>0)
        {
            int temp=n%10;
            res+=temp*temp;
            n=(n-temp)/10;
        }
        return res;
    }
    bool isHappy(int n) {
        unordered_set<int> dic;
      while(n!=1)
      {
          if(!dic.count(n))
            dic.insert(n);
            else
            {
                break;
            }
            n=change(n);
      }  
      if(n==1)
        return true;
        else
        {
            return false;
        }
        return false;
    }
};