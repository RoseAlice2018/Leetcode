#include<string>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x<0)
            return false;
        else if(x==0)
            return true;
        else
        {
            string temp=to_string(x);
            int left=0,right=temp.size()-1;
            int tag=1;
            while(left<=right)
            {
                if(temp[left]==temp[right])
                {
                    left++;
                    right--;
                }  else
            {
                tag=0;
                break;
            }
            
            }
          if(tag)
                return true;
            else
            {
                return false;
            }
            
        }
        return true;
    }
};