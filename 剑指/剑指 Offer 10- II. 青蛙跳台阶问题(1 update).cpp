class Solution {
public:
    int numWays(int n) {
        if(n==0)
            return 1;
        if(n==1)
            return 1;
        else if(n==2)
            return 2;
        else 
            return (numWays(n-1)+numWays(n-2))%((int)1e9+7);
    }
};