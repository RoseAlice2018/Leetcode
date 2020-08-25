#include<math.h>
using namespace std;
class Solution {
public:
    bool isprime(int n)
    {
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
    int countPrimes(int n) 
    {
       return countPrimes1(n-1);        
    }
    int countPrimes1(int n)
    {
         if(n<=1)
            return 0;
        else if(n==2)
            return 1;
         if(isprime(n))
        {
            return countPrimes1(n-1)+1;
        }
        else
        {
            return countPrimes1(n-1);
        }
    }
};