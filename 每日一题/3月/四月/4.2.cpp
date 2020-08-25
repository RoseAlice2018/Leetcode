#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        int neighbors[3]={0,1,-1};
        int row=board.size();
        int col=board[0].size();
        vector<vector<int>> copyboard(row,vector<int>(col,0));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                copyboard[i][j]=board[i][j];
            }
        }
        for(int rows=0;rows<row;rows++)
        {
            for(int cols=0;cols<col;cols++)
            {
                int liveneighbors=0;
                for(int i=0;i<3;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        if(!(neighbors[i]==0&&neighbors[j]==0))
                        {
                            int r=rows+neighbors[i];
                            int c=cols+neighbors[j];
                            if((r>=0&&r<row)&&(c>=0&&c<col)&&((copyboard[r][c]==1)))
                                liveneighbors+=1;
                        }
                    }
                }
                //1.3
                if((liveneighbors>3||liveneighbors<2)&&copyboard[rows][cols]==1)
                {
                    board[rows][cols]=0;
                }
                //4
                if(liveneighbors==3&&copyboard[rows][cols]==0)
                    board[rows][cols]=1;
            }
        }
    }

};