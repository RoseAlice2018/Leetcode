#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int node[n+10];
    for(int i=0;i<n-1;i++)
    {
        int temp;
        scanf("%d",&temp);
        node[i+2]=temp;
    }
    
    return 0;
}