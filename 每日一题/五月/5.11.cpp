class Solution {
public:
    double myPow(double x, int n)
     {
         if(n==0)
            return 1.00000;
        long long n1=n;
        double res=1.0;
        if(n>0)
        {
            res=qucikexp(x,n1);
            return res;
        }
        else if(n<=0)
        {
            res=qucikexp(x,-1*n1);
            return 1.0/res;
        }
        return res;
    }
    double qucikexp(double x,long n)
    {
        if(n==0)
            return 1.0;
        double res=qucikexp(x,n/2);
        return n%2==0?res*res:res*res*x;

    }
};