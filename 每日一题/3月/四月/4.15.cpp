#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    struct point
    {
        int x=0,y=0;
    };
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        int direction[4][2]={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<point> s;
        vector<vector<int>> seen(m, vector<int>(n));
        vector<vector<int>> dist(m, vector<int>(n));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    point temp;
                    temp.x=i;temp.y=j;
                    s.push(temp);
                    seen[i][j]=1;
                }
            }
        }
        while (!s.empty())
        {
            point t=s.front();
            s.pop();
            for(int i=0;i<4;i++)
            {
                int ni=t.x+direction[i][0];
                int nj=t.y+direction[i][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !seen[ni][nj]) 
                {
                    seen[ni][nj]=1;
                    dist[ni][nj]=dist[t.x][t.y]+1;
                    point te;te.x=ni;te.y=nj;
                    s.push(te);
                }
            }
        }
        return dist;
        
    }
};
// for(int i=0;i<matrix.size();i++)
//         {
//             for(int j=0;j<matrix[0].size();j++)
//             {
//                 if(matrix[i][j]!=0)
//                 {
//                     int lesdistance=INT_MAX;
//                 for(int m=0;m<s.size();m++)
//                 {
//                     int dis=abs(s[m].x-i)+abs(s[m].y-j);
//                     if(dis==0)
//                     {
//                         lesdistance=dis;
//                         break;
//                     }
//                     if(dis<lesdistance)
//                         lesdistance=dis;
//                 }
//                 matrix[i][j]=lesdistance;
//                 }
                
//             }
//         }
//         return matrix;