#include<iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int num[n];
    int count[10000]={0};
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
        count[num[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        if(count[num[i]]==1)
        {
            cout<<num[i];
            return 0;
        }
    }
    printf("None");    

    return 0;
}