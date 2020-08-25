#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;
int main()
{
    unordered_set<char> dic;
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    for(int i=0;i<s2.size();i++)
    {
        char A=s2[i];
        if(dic.count(A))
            ;
        else
        {
            dic.insert(A);
        }
    }
    for(int i=0;i<s1.size();i++)
    {
        char A=s1[i];
        if(dic.count(A))
            ;
        else
        {
            cout<<A;
        }
        
    }
    return 0;
}