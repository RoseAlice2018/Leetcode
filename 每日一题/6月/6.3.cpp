#include<math.h>
#include<stdlib.h>
using namespace std;
class Solution {
public:
    int test(int N,int K,int W)
    {
        int grade=0;
        int randnumber=0;
        while (grade<K)
        {
             randnumber=rand()%W+1;
            grade+=randnumber;
        }
        if(grade<=N)
            return 1;
        else 
            return 0;        
    }
    double new21Game(int N, int K, int W)
     {
         int number=0;
         for(int i=0;i<100000;i++)
         {
             if(test(N,K,W))
                number++;
         }
         return number*1.0/100000;
    }
};