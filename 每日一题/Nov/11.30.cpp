#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string reorganizeString(string S) 
    {
        if(S.size()<=2)
            return S;
        char cur=S[0];
        char next=S[1];
        int num_next=1;
        string res;
        res.push_back(cur);
        //res.push_back(next);
        while(1)
        {
            if(next!=cur)
            {
                
                cur=next;
                res.push_back(cur);
                if(num_next+1<S.size())
                {
                    next=S[++num_next];
                }
                else
                {
                    return res;
                }
            }
            else
            {
                for(int i=num_next;i<S.size();i++)
                {
                    if(S[i]!=cur)
                    {
                        swap(S[i],S[num_next]);
                    }
                }
                next=S[num_next];
                if(next==cur)
                {
                    res.clear();
                    return res;
                }
            }
           
        } return res;
    }
};