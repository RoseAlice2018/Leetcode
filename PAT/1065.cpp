#include<iostream>
using namespace std;
int main()
{
    int k;
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        printf("Case #%d: ",i);
       long long A,B,C;
        cin>>A>>B>>C;
        long long sum=A+B;
        if(A>0&&B>0&&sum<0)
            printf("true\n");
        else if(A<0&&B<0&&sum>=0)
            printf("false\n");
        else if(sum>C)
            printf("true\n");
        else if(sum<=C)
            printf("false\n");

    }
    return 0;
}