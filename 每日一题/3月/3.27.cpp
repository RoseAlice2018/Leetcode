#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxdiv(int a,int b)
    {
        while (b>0)
        {
            int res=a%b;
            a=b;
            b=res;
        }
        return a;
        
    }
    bool hasGroupsSizeX(vector<int>& deck)
     {
         int res[20000]={0};
         int max=0;
         for(int i=0;i<deck.size();i++)
         {
             res[deck[i]]++;
             if(deck[i]>max)
                max=deck[i];
         }
          vector<int> test;
        for(int i=0;i<=max;i++)
        {
            if(res[i]>0)
                test.push_back(res[i]);
        }
        int X=test.size();
        for(int i=0;i<test.size()-1;i++)
        {
            if(maxdiv(test[i],test[i+1])<X)
                X=maxdiv(test[i],test[i+1]);
        }
        if(test.size()==1)
        {
            int k=test.front();
            if(k>1)
                return true;
            else
            {
                return false;
            }
            
        }
        if(X>=2)
            return true;
        else
        {
            return false;
        }
        
        
    }
};