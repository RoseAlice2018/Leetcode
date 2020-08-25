#include<math.h>
using namespace std;
class Solution {
public:
    
    int countPrimes(int n) 
    {
        int count=0;
       bool isprime[n+10];
       for(int i=1;i<n+10;i++)
        isprime[i]=true;
       for(int i=2;i<=sqrt(n);i++)
       {
           if(isprime[i])
           {
             for(int j=i*i;j<n;j+=i)
             {
                isprime[j]=false;
            }  
           }   
       }   
       for(int i=2;i<n;i++)
        if(isprime[i]) count++;
        return count;     
    }
    
};