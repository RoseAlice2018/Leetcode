#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder)
        {
            return recur(postorder,0,postorder.size()-1);
    }
    bool recur(vector<int> postorer,int i,int j)
    {
        if(i>=j)
            return true;
        int p=i;
        while(postorer[p]<postorer[j])
            p++;
        int m=p;
        while(postorer[p]>postorer[j])
            p++;
        return p==j&&recur(postorer,i,m-1)&&recur(postorer,m,j-1);
    }
};