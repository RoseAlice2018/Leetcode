#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int direction[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
    void visit(vector<vector<char>>& grid,int visited[][100],int i,int j)
    {
            int ri,rj;
         for(int m=0;m<4;m++)
         {
             ri=i+direction[m][0];
             rj=j+direction[m][1];
             if(ri>=0&&ri<grid.size()&&rj>=0&&rj<grid[0].size()&&visited[ri][rj]==0&&grid[ri][rj]=='1')
             {
                 visited[ri][rj]=1;
                 visit(grid,visited,ri,rj);
             }

         }
         return;
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        if(grid.size()==0)
            return ;
        int res=0;// result
        int m=grid.size();
        int n=grid[0].size(); 
        int visited[100][100]={0};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j]==0&&grid[i][j]=='1')
                {
                    visited[i][j]=1;
                    visit(grid,visited,i,j);
                    res++;
                }
            }
        }
        return res;

    }
};