#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool validMountainArray(vector<int>& A) 
    {
        int mount=0;
        if(A.size()<=2)
            return false;
        for(int i=1;i<A.size()-1;i++)
        {
            if(A[i]>A[i-1]&&A[i]>A[i+1])
            {
                mount=i;
                break;
            }
        }
        if(mount==0)
            return false;
        int temp=0;
        while(temp<mount)
        {
            if(A[temp]<A[temp+1])
            {
                temp++;
            }
            else
            {
                return false;
            }
        }
        temp=mount;
        while(temp<A.size()-1)
        {
            if(A[temp]>A[temp+1])
                temp++;
            else 
                return false;
        }
        return true;
    }
};