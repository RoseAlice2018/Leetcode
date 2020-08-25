#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool checkbox(vector<vector<char>>& board,int i,int j)
    {
        unordered_set<int> t;
        //i 行 j 列
        for(int beginx=i;beginx<i+3;beginx++)
        {
            for(int beginy=j;beginy<j+3;beginy++)
            {
                int temp=board[beginx][beginy]-'0';
                if(board[beginx][beginy]=='.')
                    continue;
                if(t.count(temp))
                    return false;
                t.insert(temp);
            }
        }
        return true;
    }
    bool checkline(vector<vector<char>>& board,int ix,int jx)
    {
        unordered_set<int> t;
        unordered_set<int> t1;
        for(int i=0;i<9;i++)
        {
            int temp=board[ix][i]-'0';
            if(board[ix][i]=='.')
                    continue;
            if(t.count(temp))
                return false;
            t.insert(temp);
        }
        for(int i=0;i<9;i++)
        {
            int temp=board[i][jx]-'0';
            if(board[i][jx]=='.')
                    continue;
            if(t1.count(temp))
                return false;
            t1.insert(temp);
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board)
     {
        //1. 行列
        for(int i=0;i<9;i++)
        {
            if(!checkline(board,i,i))
                return false;
        }
        //2.box
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
               if(!checkbox(board,i,j))
                    return false;
            }
        }
        return true;
    }
};