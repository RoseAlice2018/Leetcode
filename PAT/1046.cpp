#include<iostream>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int sumdis=0;
    int distance[N];
    for(int i=0;i<N;i++)
    {
        cin>>distance[i];
        sumdis+=distance[i];
    } 
    int M;
    cin>>M;
    for(int k=0;k<M;k++)
    {
        int a,b;
        cin>>a>>b;
        int minx=min(a,b);
        int maxx=max(a,b);
        int mindist1=0;
        for(int i=minx-1;i<maxx-1;i++)
            mindist1+=distance[i];
        int mindist2=sumdis-mindist1;
        int min=0;
        if(mindist1>mindist2)
            min=mindist2;
        else
        {
            min=mindist1;
        }
        cout<<min<<endl;

    }
    return 0;
}