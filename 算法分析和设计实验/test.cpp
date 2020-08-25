#include<stdio.h>
#include<math.h>
bool isprime(int N)
{
    if(N==1)
        return false;
    for(int i=2;i<=sqrt(N);i++)
    {
        if(N%i==0)
            return false;
    }
    return true;
}
int Prime[1000];
int count=0;
bool issumprime(int i)
{
    
}
int main()
{
    int x;
    scanf("%d",&x);
    for(int i=1;i<10000;i++)
    {
        if(isprime(i))
            Prime[count++]=i;
    }
    for(int i=x;;i++)
    {
        if(isprime(i)&&issumprime(i))
        {
            printf("%d",i);
            break;
        }
    }
    return 0;
}