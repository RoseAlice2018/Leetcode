#include<iostream>
#include<vector>
using namespace std;
int main()
{
    string n[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    string num;
   // cin>>num;
    int sum=0;
    for(int i=0;i<num.size();i++)
    {
        sum+=num[i]-'0';
    }
    vector<int> res;
    if(sum==0)
    res.push_back(0);
    while(sum>0)
    {
        int temp=sum%10;
        res.push_back(temp);
        sum=(sum-temp)/10;
    }
    for(int i=res.size()-1;i>0;i--)
    {
        printf("%s ",n[res[i]].c_str());
    }
    printf("%s",n[res[0]].c_str());
    return 0;
}