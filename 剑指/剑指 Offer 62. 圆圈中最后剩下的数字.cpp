#include<iostream>
#include<vector>
using namespace  std;
class Solution {
public:
    int lastRemaining(int n, int m) {
        vector<int> temp;
        for(int i=0;i<n;i++)
            temp.push_back(i);
        vector<int>::iterator it=temp.begin();
        while(temp.size()>1)
        {
            int k;
            if(m<=temp.size())
                k=m;
            else{
                k=m%temp.size();
            }
            it=temp.begin()+k-1;
            temp.erase(it);
        }
        return temp[0];
    }
};