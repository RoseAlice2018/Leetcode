#include<queue>
using namespace std;
class Solution {
public:
int check(int n)
{
    int res=0;
    while(n/10>0)
    {
        int temp=n%10;
        res+=temp;
        n=(n-temp)/10;
    }
    res+=n;
    return res;
}
struct point
{
    int x;
    int y;
    point (int t)
    {
        x=t;
        y=t;
    }
    point (){}
};
    int movingCount(int m, int n, int k) 
    {
        int count=0;
        point direction[2];
       direction[0].x=0;direction[0].y=1;
       direction[1].x=1;direction[1].y=0;
        point t;(t).x=0;(t).y=0;
        queue<point> temp;temp.push(t);count++;
        int vis[100][100]={0};
        vis[0][0]=1;
        while (!temp.empty())
        {
            point p=temp.front();
            temp.pop();
            for(int i=0;i<2;i++)
            {
                point kk;
                (kk).x=(p).x+direction[i].x;
                (kk).y=(p).y+direction[i].y;
                if((kk).x>=0&&(kk).x<=m-1&&(kk).y>=0&&(kk).y<=n-1&&vis[kk.x][kk.y]==0)
                {
                    if(check((kk).x)+check((kk).y)<=k)
                    {
                        count++;
                        temp.push(kk);
                        vis[kk.x][kk.y]=1;
                    }
                }
            }
        }
        
        
        return count;
    }
};