#include<iostream>
using namespace std;
int main()
{
    int N;
    scanf("%d",&N);
    int num[100];
    for(int i=0;i<N;i++)
        scanf("%d",&num[i]);
    int left=0,right=0,maxvalue=0;
    int thissum=0;int temp=num[0];
    int count=0;
    for(int i=0;i<N;i++)
    {
        if(num[i]>=0)
            count++;
        if(num[i]+thissum<0)
        {
            temp=num[i+1];
            thissum=0;
        }
        else if(thissum+num[i]>=0)
        {
            thissum+=num[i];
        }
        if(thissum>maxvalue)
        {
            maxvalue=thissum;
            right=num[i];
            left=temp;
        }      
        
    }
    if(maxvalue==0)
    {
        if(count==0)
        {
             printf("0 %d %d",num[0],num[N-1]);
        }
        else
        {
            printf("0 0 0");
        }
        
       
    }
        
    else
    {
        printf("%d %d %d",maxvalue,left,right);
    }
    
    return 0;
}