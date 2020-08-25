#include<iostream>
#include<string>
using namespace std;
int  modify(string& sentce)
{
    int size=sentce.size();
    for(int i=0;i<sentce.size();i++)
    {
        if(i+3>=size)
            break;
        if(sentce[i]==sentce[i+1]&&sentce[i+1]==sentce[i+2])
        {
            //rule1;
            for(int j=i;j<sentce.size()-1;j++)
            {
                sentce[j]=sentce[j+1];
            }
            size--;
            i--;
            continue;
        }
        if(sentce[i]==sentce[i+1]&&sentce[i+2]==sentce[i+3])
        {
            //rule2;
            for(int j=i+2;j<sentce.size()-1;j++)
                sentce[j]=sentce[j+1];
            size--;
            i=i+1;
            continue;
        }
    }
    int i=size-3;
    if(sentce[i]==sentce[i+1]&&sentce[i+1]==sentce[i+2])
        {
            //rule1;
            for(int j=i;j<sentce.size()-1;j++)
            {
                sentce[j]=sentce[j+1];
            }
            size--;
            i--;
        }
    return size;
}
int main()
{
    int N;
    scanf("%d",&N);
    string s[100];
    for(int i=0;i<N;i++)
        cin>>s[i];
    for(int i=0;i<N;i++)
    {
        int size=modify(s[i]);
        for(int j=0;j<size;j++)
            printf("%c",s[i][j]);
        printf("\n");
    }
    return 0;
}