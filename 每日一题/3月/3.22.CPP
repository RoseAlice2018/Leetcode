#include<vector>
using namespace std;
class Solution {
public:
    int minIncrementForUnique(vector<int>& A)
     {
        int move=0;
        int barrel[50000]={0};
        for(int i=0;i<A.size();i++)
        {
            if(barrel[A[i]]==0)
                barrel[A[i]]=1;
            else
            {
                // move 
                for(int j=A[i];j<50000;j++)
                {
                    move++;
                    if(barrel[j]==0&&j!=A[i])
                    {
                        barrel[j]=1;
                      
                        break;
                    }  
                }
            }
            
        }
        return move;
    }
};