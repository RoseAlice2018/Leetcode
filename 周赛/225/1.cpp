#include<iostream>
using namespace std;
class Solution {
public:
    string maximumTime(string time) {
        for(int i=0;i<time.size();i++)
        {
            if(time[i]==':')
                ;
            else
            {
                if(time[i]=='?')
                {
                    if(i==0)
                    {
                        if(time[1]!='?'&&time[1]-'0'>3)
                            time[0]='1';
                        else 
                            time[0]='2';
                    }
                    else if(i==1)
                    {
                        if(time[0]=='2')
                            time[1]='3';
                        else 
                            time[1]='9';
                    }
                    else if(i==3)
                        time[i]='5';
                    else if(i==4)
                        time[i]='9';
                }
            }
        }
        return time;
    }
};