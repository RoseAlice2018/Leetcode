#include<vector>
using namespace std;
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()<=2)
            return true;
        double x1=coordinates[0][0],y1=coordinates[0][1];
        double x2=coordinates[1][0],y2=coordinates[1][1];
        double k=(x2-x1)!=0?(y2-y1)/(x2-x1):0;
        double b=y1-k*x1;
        for(int i=2;i<coordinates.size();i++)
        {
            if(x2-x1==0)
            {
                if(coordinates[i][0]==x1)
                    continue;
                else 
                    return false;
            }
            if(k==0)
            {
                if(coordinates[i][1]==coordinates[0][1])
                    continue;
                else
                {
                    return false;
                }     
            }
            if(k*coordinates[i][0]+b!=coordinates[i][1])
                return false;
        }
        return true;
    }
};