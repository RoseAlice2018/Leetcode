#include<iostream>
using namespace std;
void print(char temp[54])
{
    for(int i=0;i<53;i++)
    {
        int t=temp[i]-'0';
        if(t>0&&t<=13)
        {
            printf("S%d ",t);
        }
        if(t>13&&t<=26)
        {
            printf("H%d ",t-13);
        }
        if(t>26&&t<=39)
        {
            printf("C%d ",t-26);
        }
        if(t>39&&t<=52)
        {
            printf("D%d ",t-39);
        }
        if(t>52)
        {
            printf("J%d ",t-52);
        }
    }
    int t=temp[53]-'0';
     if(t>=0&&t<=13)
        {
            printf("S%d",t);
        }
        if(t>13&&t<=26)
        {
            printf("H%d",t-13);
        }
        if(t>26&&t<=39)
        {
            printf("C%d",t-26);
        }
        if(t>39&&t<=52)
        {
            printf("D%d",t-39);
        }
        if(t>52)
        {
            printf("J%d",t-52);
        }

}
int main()
{
    int repeatime;
    scanf("%d",&repeatime);
    char initialstatue[54];
    int keynum[54];
    for(int i=0;i<54;i++)
    {
        initialstatue[i]=i+'1';
        int temp;
        scanf("%d",&temp);
        keynum[i]=temp;
    }
    char temp[54];
    for(int i=0;i<54;i++)
        temp[ i]='-';
    int c1=0; // c1 means temp;
    int c2=0; // c2 means initial
    for(int i=0;i<repeatime;i++)
    {
        if(temp[0]=='-')
        {
            c1=1;
            c2=0;
        }
        if(initialstatue[0]=='-')
        {
            c1=0;
            c2=1;
        }
        for(int j=0;j<54;j++)
        {
            if(c1)//temp 为结果
            {
              temp[keynum[j]-1]=initialstatue[j];  
            }
            if(c2)
            {
                initialstatue[keynum[j]-1]=temp[j];
            }            
        }
        if(c1)
        {
            for(int m=0;m<54;m++)
                initialstatue[m]='-';
        }
        if(c2)
        {
            for(int m=0;m<54;m++)
                temp[m]='-';
        }
    }
    if(temp[0]=='-'&&initialstatue[0]!='-')
    {
        print(initialstatue);
    }
    else if(initialstatue[0]=='-'&&temp[0]!='-')
    {
        print(temp);
    }            
    return 0;
}