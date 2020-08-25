class Solution {
public:
    int level(char c)
    {
        if(c=='I')
            return 1;
        else if(c=='V')
            return 2;
        else if(c=='X')
            return 3;
        else if(c=='L')
            return 4;
        else if(c=='C')
            return 5;
        else if(c=='D')
            return 6;
        else if(c=='M')
            return 7;
        return 0;
    }
    int value(char c)
    {
         if(c=='I')
            return 1;
        else if(c=='V')
            return 5;
        else if(c=='X')
            return 10;
        else if(c=='L')
            return 50;
        else if(c=='C')
            return 100;
        else if(c=='D')
            return 500;
        else if(c=='M')
            return 1000;
        return 0;
    }
    int romanToInt(string s) 
    {
        int res=0;
        int i=0;
        for( i=0;i<s.size()-1;i++)
        {
            if(level(s[i])>=level(s[i+1]))
            {
                res+=value(s[i]);
            }
            else
            {
                res+=(value(s[i+1])-value(s[i]));
                i=i+1;
            }  
        }
        if(i<s.size())
        {
            res+=value(s[i]);
        }
        return res;
    }
};