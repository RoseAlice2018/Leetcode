 #include<iostream>
 #include<string.h>
 #include<math.h>
 using namespace std;
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int sum=0;
        int pointer_begin=0,pointer_end=0;
        int res=0;
        while(pointer_begin<s.size()&&pointer_end<=s.size())
        {
            if(sum>=maxCost)
            {
                //over
                sum-=fabs(s[pointer_begin]-t[pointer_begin]);
                pointer_begin++;
            }
            else if(pointer_end<s.size())
            {
                sum+=fabs(s[pointer_end]-t[pointer_end]);//new value of subsequence
                pointer_end++;
                if(sum<=maxCost)
                {
                      int temp=pointer_end-pointer_begin;
                        if(temp>res)
                        res=temp;
                }
            }
            else 
                break;
        }
        return res;
    }
};