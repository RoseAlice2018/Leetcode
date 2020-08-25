#include<stdio.h>
int main()
{
    char S;
    int count=0;
    while ((S=getchar())!='$')
    {
        if(S<='9'&&S>='0')
            count++;
    }
    printf("%d",count);
    return 0;
}