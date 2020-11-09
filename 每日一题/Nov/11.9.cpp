#include<vector>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
    {
        vector<vector<double>> map;
        for(int i=0;i<points.size();i++)
        {
            vector<double> temp;
            double distance=sqrt(pow(points[i][0]-0,2)+pow(points[i][1]-0,2));
            temp.push_back(distance);
            temp.push_back(i);
            map.push_back(temp);
        }
        sort(map.begin(),map.end(),cmp);
        vector<vector<int>> res;
        for(int i=0;i<K;i++)
        {
            res.push_back(points[map[i][1]]);
        }
        return res;
    }
   static bool cmp(vector<double> a,vector<double> b)
    {
        if(a[0]<b[0])
            return true;
        else 
            return false;
    }
};