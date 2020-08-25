#include<iostream>
#include<string.h>
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
    int N;
    scanf("%d",&N);
    string num1,num2;
    //scanf("%s %s",num1,num2);
     cin>>num1>>num2;
    int tag=0;
    int num1dot=0;
    int num2dot=0;
    for(int i=0;i<min(num2.size(),(N,num1.size()));i++)
    {
        if(num1[i]!=num2[i])
        {
            tag=1;
            break;
        }
    }
    for(int i=0;i<num1.size();i++)
        if(num1[i]=='.')
            num1dot=i;
    for(int i=0;i<num2.size();i++)
         if(num2[i]=='.')
            num2dot=i;
    if(num1dot==0)
        num1dot=num1.size();
     if(num2dot==0)
        num2dot=num2.size();
    if(num1dot!=num2dot)
        tag=1;
    // if not euqal tag==1
    if(tag)
    {
        printf("NO ");
        printf("0.");
        for(int i=0;i<N;i++)
            printf("%c",num1[i]);
        printf("*10^%d ",num1.size()); 
        printf("0.");
        for(int i=0;i<N;i++)
            printf("%c",num2[i]);
        printf("*10^%d",num2.size()); 
    }   
    else 
    {
        printf("YES ");
        printf("0.");
        for(int i=0;i<N;i++)
            printf("%c",num1[i]);
        printf("*10^%d",num1.size());        
    }
    return 0;
}