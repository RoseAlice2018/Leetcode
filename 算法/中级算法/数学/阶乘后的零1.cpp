class Solution {
public:
    int trailingZeroes(int n) {
       int zerocount=0;
       long current=5;
       while(n>=current)
       {
           zerocount+=(n/current);
           current*=5;
       }
       return zerocount;
    }
};