#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int M,N;
    cin>>M>>N;
    int Pix[M*N];
    for(int i=0;i<M*N;i++)
        scanf("%d",&Pix[i]);
    sort(Pix,Pix+M*N);
    int middle=M*N/2;
    cout<<Pix[middle];
    return 0;
}