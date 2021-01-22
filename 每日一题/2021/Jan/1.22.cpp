#include<vector>
using namespace std;
class Solution {
public:
    void add(vector<int>& A,int K,int index)
    {
        if(index<0)
        {
            vector<int> B ;
            B.push_back(0);
            add(B,K,0);
            for(int i=0;i<A.size();i++)
                B.push_back(A[i]);
            A=B;
            return;            
        }
        int temp=A[index]+K;
        if(temp>=10)
        {
            A[index]=temp%10;
            int more=(temp-temp%10)/10;
            add(A,more,index-1);
        }
        else
        {
            A[index]=temp;
        }
        return ;
    }
    vector<int> addToArrayForm(vector<int>& A, int K) {
        add(A,K,A.size()-1);
        return A;
    }
};