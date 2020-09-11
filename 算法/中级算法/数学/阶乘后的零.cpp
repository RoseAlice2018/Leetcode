class Solution {
public:
    int trailingZeroes(int n) {
        int zerocount=0;
        for(int i=5;i<=n;i+=5)
        {
            int current=i;
            while(current%5==0)
            {
                zerocount++;
                current/=5;
            }
        }
        return zerocount;
    }
};