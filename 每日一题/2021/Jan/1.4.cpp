#include<iostream>
using namespace std;
class Solution {
public:
    int fib(int n) {
        int first=0,second=1;
        if(n==0)
            return first;
        else if(n==1)
            return second;
        while(n>1)
        {
            n--;
            int temp=first+second;
            first=second;
            second=temp;
        }
        return second;
    }
};