#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool subexist(vector<vector<char>> board,string word,int num,int n,vector<vector<int>> state,int x,int y)
    {
        if(num==n)
        {
            return true;
        }
        else
        {
            int dp1[4]={0,0,1,-1};
            int dp2[4]={1,-1,0,0};
            for(int i=0;i<4;i++)
            {
                
                    int tx=x+dp1[i];
                    int ty=y+dp2[i];
                    if(tx<0||tx>=board.size()||ty<0||ty>=board[0].size()||state[tx][ty]==1)
                    {
                        ;
                    }
                    else
                    {
                        if(word[num]==board[tx][ty])
                        {
                            state[tx][ty]=1;
                            if(subexist(board,word,num+1,n,state,tx,ty))
                            {
                                return true;
                            }
                            state[tx][ty]=0;
                        }
                        else
                        {
                            ;
                        }   
                    }
                    
                
            }
        }
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> state(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    state[i][j]=1;
                    if(subexist(board,word,1,word.size(),state,i,j))
                    {
                        return true;
                    }
                    state[i][j]=0;
                }
            }
        }
        return false;
    }
};