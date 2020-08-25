#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
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
         int num[15000];
         int maxsize=0;
         string temp(num1.rbegin(),num1.rend());
         int i=0;
         while(i<size1)
         {  
             int a=temp[i]-'0';
             //mutiply
             for(int j=0;j<size2;j++)
             {
               int b=num2[j]-'0';
               int t=a*b+num[i+j];
                if(t<10)
                {
                    num[i+j]+=t;
                    maxsize=i+j;
                }
                else
                {
                    num[i+j]+=t%10;
                    //carry
                    num[i+j+1]+=(t-t%10)/10;
                     maxsize=i+j+1;
                   
                } 
             }
             i++;
         }
         for( i=0;i<=maxsize;i++)
        {
            res+=num[i]+'0';
        }
        return res;
    }
};