#include<iostream>
#include<vector>
using namespace std;
vector<char> res;
void check(int color)
{
    char c;
    if(color<13)
    {
        res.push_back('0');
        if(color<10)
         {
             c=color+'0';
             res.push_back(c);
         }
         else
         {
             if(color==10)
                res.push_back('A');
            else if(color==11)
                res.push_back('B');
            else if(color==12)
                res.push_back('C');
         }         
    }
    else
    {
        int t=color%13;
        color=(color-t)/13;
        if(color<=13)
        {
        if(color<10)
         {
             c=color+'0';
             res.push_back(c);
         }
         else
         {
             if(color==10)
                res.push_back('A');
            else if(color==11)
                res.push_back('B');
            else if(color==12)
                res.push_back('C');
        }
        color=t;
        if(color<=13)
    {
        if(color<10)
         {
             c=color+'0';
             res.push_back(c);
         }
         else
         {
             if(color==10)
                res.push_back('A');
            else if(color==11)
                res.push_back('B');
            else if(color==12)
                res.push_back('C');
         }         
    }        
    }

    }
    
}
int main()
{
    int red,green,blue;
    cin>>red>>green>>blue;
    res.push_back('#');
    check(red);
    check(green);
    check(blue);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i];
    }
    return 0;
}