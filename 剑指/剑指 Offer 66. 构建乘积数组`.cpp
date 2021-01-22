#include<vector>
using namespace std;
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        //ps 有点像脑筋急转弯
        int length=a.size();
        vector<int> Triangle_d(length,1);
        vector<int> Triangle_u(length,1);

        //caculate the lower triangle
        for(int i=1;i<length;i++)
        {
            Triangle_d[i]=Triangle_d[i-1]*a[i-1];
        }
        //caculate the upper triangle
        for(int i=length-2;i>=0;i--)
        {
            Triangle_u[i]=a[i+1]*Triangle_u[i+1];
        }
        for(int i=0;i<length;i++)
            a[i]=Triangle_u[i]*Triangle_d[i];
        return a;
    }
};