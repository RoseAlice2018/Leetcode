class Solution {
public:
    int num[100];
    int count=0;
    int climbStairs(int n)
    {
        //递归多层时会出现超时
        // if(n==1)
        //      return 1;
        // if(n==2)
        //     return 2;
        // if(n>=3)
        //     return climbStairs(n-1)+climbStairs(n-2);
        for(int i=0;i<46;i++)
        {
            if(i==1)
            {
                num[count++]=1;
            }
            if(i==2)
            {
                num[count++]=2;
            }
            if(i>=3)
            {
                num[count]=num[count-1]+num[count-2];
                count++;
            }
        }
        return num[n];
        
    }
};