#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int min(int a,int b)
{
    if(a<b)
        return a;
    else 
        return b;
}
int main()
{
    unordered_map<char,string> week={{'A', "MON"}, {'B', "TUE"}, {'C', "WED"}, {'D', "THU"},
                                        {'E', "FRI"}, {'F', "SAT"}, {'G', "SUN"}};
    string s1,s2;
    cin>>s1>>s2;
     string s3,s4;
    cin>>s3>>s4;
    int tag=0;//tag used to tell the first or second same letter
    for(int i=0;i<min(s1.size(),s2.size());i++)
    {
        if(s1[i]==s2[i]&&s1[i]>='A'&&s1[i]<='G'&&tag==0)
        {
            tag++;
            cout<<week[s1[i]]<<" ";
        }
        if(s1[i]==s2[i]&&tag==1&&((s1[i]>='0'&&s1[i]<='9')||(s1[i]>='A'&&s1[i]<='N')))
        {
            tag++;
            if(s1[i]>='0'&&s1[i]<='9')
                cout<<'0'<<s1[i]<<":";
            else 
                cout<<s1[i]-'A'+11<<":";
        }
        if(tag>1)
            break;
    }
   
    for(int i=0;i<min(s3.size(),s4.size());i++)
    {
        if(s3[i]==s4[i]&&i<=9&&((s1[i]>='a'&&s1[i]<='z')||(s1[i]>='A'&&s1[i]<='Z')))
        {
            cout<<"0"<<i;
            break;
        }
            
        else if(s3[i]==s4[i]&&((s1[i]>='a'&&s1[i]<='z')||(s1[i]>='A'&&s1[i]<='Z')))
        {
            cout<<i;
            break;
        }
            
    }

    return 0;
}