#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
    {
        for(int i=0;i<arr.size();i++)
        {
            for(int j=i;j<arr.size();j++)
            {
                if(arr[i]==2*arr[j]||arr[j]==2*arr[i])
                {
                    return true;
                }
            }
        }
        return false;
    }
};