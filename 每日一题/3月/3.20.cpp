#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) 
    {
        int num[10002]={0};
        for(int i=0;i<arr.size();i++)
            num[arr[i]]+=1;
        vector<int> res;
        for(int i=0;i<10002;i++)
        {
            if(k==0)
                break;
            if(num[i]>0)
            {
                for(int j=0;j<num[i];j++)
                {
                    res.push_back(i);
                    k--;
                    if(k==0)
                        break;
                }
            }
        }
        return res;
    }
};