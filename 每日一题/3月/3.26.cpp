#include<vector>
using namespace std;
class Solution {
public:
    struct  node
    {
        int x;
        int y;
    };
    
    int numRookCaptures(vector<vector<char>>& board) 
    {
        // find the R
        node R;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='R')
                {
                    //find the R
                    // if(board[i][j+1]=='B'&&board[i-1][j]=='B'&&board[i+1][j]=='B'&&board[i][j-1]=='B')
                    //     return 0;
                    R.x=i;
                    R.y=j;
                    break;                    
                }
            }
        }
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        int count=0;
        for(int i=0;i<4;i++)
        {
            for (int step = 0;; ++step) 
            {
                int tx = R.x + step * dx[i];
                int ty = R.y+ step * dy[i];
                if (tx < 0 || tx >= 8 || ty < 0 || ty >= 8 || board[tx][ty] == 'B') break;
                if (board[tx][ty] == 'p') 
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};