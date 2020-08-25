#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    string add(string a,string b)
    {
        string res="";
        int size1=a.size();
        int size2=b.size();
        int maxsize=max(size1,size2);
        int num[maxsize+10];
        string temp(a.rbegin(),b.rend());
        string temp1(b.rbegin(),b.rend());
        int i=0;
        int max=0;
        while(i<min(size1,size2));
        {
            int t1=temp[i]-'0';
            int t2=temp1[i]-'0';
            int t=t1+t2+num[i];
            if(t>=10)
            {
                num[i]=t-10;
                num[i+1]=1;
                max=i+1;
            }
            else
            {
                num[i]=t;
                max=i;
            } 
            i++;
        }
        if(size1==size2)
            ;
        else if(size1<size2)
        {
            while(i<size2)
            {
                num[i]=temp1[i]-'0';
            }
            max=size2;
        }
        else
        {
            while(i<size1)
            {
                num[i]=temp[i]-'0';
            }
            max=size1;
        }
        for(int i=0;i<max;i++)
        {
            res+=num[i]+'0';
        }
        string r(res.rbegin(),res.rend());
        return r;
    }
    string multiply(string num1, string num2)
     {
         int size1=num1.size();
         int size2=num2.size();
         string res;
         if((size1==1&&num1[0]=='0')||(size2==0&&num2[0]=='0'))
         {
             res+='0';
             return res;
         }
         int a=num1[0]-'0';
         res=num2;
         while(a--)
         {
             res=add(res,num2);
         }
        return res;
    }
};