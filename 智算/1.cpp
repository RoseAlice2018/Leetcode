#include<iostream>
using namespace std;
    int temprature=100000;
    int volumn=-100000;
    int n,L,A,B;   
void opt(int option,int x)
{
    if(option==1)
    {
        temprature=x;
    }
    else if(option==2)
    {
        volumn=x;
    }
    else if(option==3)
    {
        if(temprature>=A&&temprature<=B&&volumn>L)
        {
            cout<<temprature<<endl;
        }
        else
        {
            cout<<"GG"<<endl;
        }
        
    }
}
int main()
{
     
    cin>>n>>L>>A>>B;
    int option,x;
    for(int i=0;i<n;i++)
    {
        cin>>option;
        if(option!=3)
        {
            cin>>x;
            opt(option,x);
        }
        else
        {
            opt(option,x);
        }
    }
    return 0;
}