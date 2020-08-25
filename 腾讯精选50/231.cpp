class Solution {
public:
    bool isPowerOfTwo(int n) 
    {   
        if(n==2||n==1)
            return true;
        if(n%2==0&&n>2)
        {
            return isPowerOfTwo(n/2);
        }
        else
        {
            return false;
        }
        
        
        
    }
};