#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) 
    {
        string temp(a.rbegin(),a.rend());
        string temp1(b.rbegin(),b.rend());
        vector<int> res(max(a.size(),b.size())+10,0);
        int count=0;
        int i;
        for( i=0;i<min(a.size(),b.size());i++)
        {
            int t1=temp[i]-'0';
            int t2=temp1[i]-'0';
            int t=t1+t2+res[i];
            if(t>=2)
            {
                res[i+1]=1;
                res[i]=t-2;
                count=i+1;
            }
            else
            {
                res[i]=t;
                count=i;
            }
        }
        while(i<a.size())
        {
            res[i]=temp[i];
            count=i;
            i++;
        }
          while(i<b.size())
        {
            res[i]=temp1[i];
            count=i;
            i++;
        }
        string ts="";
        for(int i=0;i<=count;i++)
        {
            ts+=res[i]+'0';
        }
        string tt(ts.rbegin(),ts.rend());
        return tt;
    }
};