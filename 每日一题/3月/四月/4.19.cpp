#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2)
     {
         string S1;string S2;
         for(int i=0;i<n1;i++)
            S1.append(s1);
        for(int i=0;i<n2;i++)
            S2.append(s2);
        int M=0;
        int lefts2=0;
        int sizeS2=S2.size();
        for(int i=0;i<S1.size();i++)
        {
           
            if(S1[i]==S2[lefts2])
            {
                lefts2++;
            }
             if(lefts2==sizeS2)
            {
                lefts2=0;
                M++;
            }    
                    
        }
        return M;
    }
};