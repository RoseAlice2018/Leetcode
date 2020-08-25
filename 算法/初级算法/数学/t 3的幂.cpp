class Solution {
public:
    bool isPowerOfThree(int n)
     {
         if(n==1)
            return true;
        return isPowerofThree1(n);        
    }
    bool isPowerofThree1(int n)
    {
        if(n%3!=0)
            return false;
         if(n==3)
            return true;
        else if(n<3)
        {
            return false;
        }
        else
        {
            return isPowerOfThree(n/3);
        } 
    }
};