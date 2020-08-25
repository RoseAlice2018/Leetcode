#include<math.h>
class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x<0)
            return false;
        if(x<10&&x>=0)
            return true;
        if(x>=10&&x<100)
        {
            int left=x/10;
            int right=(x-10*left);
            if(left==right)
                return true;
            else
                return false;            
        }
        if(x>100)
        {
            int right=x%10;
            int left=0;
            for(int i=0;i<100;i++)
            {
                if(x<pow(10,i))
                {
                    left=x/(pow(10,i-1));
                    x=x-pow(10,i-1)*left;
                    break;
                }
            }
            x=(x-right)/10;            
            if(right==left)
                return isPalindrome(x);
            else
                return false;            
        }
    }
};