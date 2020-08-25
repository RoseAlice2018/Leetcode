class Solution {
public:
    bool canMeasureWater(int x, int y, int z) 
    {
        // 找到x，y的最大公约数
        int d=x%y;
        while (d)
        {
            x=y;
            y=d;
            d=x%y;
        }
        if(z%y==0)
            return true;
        else
        {
             return false;
        }        
    }
};