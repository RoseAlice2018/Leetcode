#include<iostream>
using namespace std;
class Solution {
public:
    int getSum(int a, int b) {
        while(b)
        {
            int c=(unsigned int)(a&b)<<1;
            a=a^b;
            b=c;
        }
        return a;
    }
};