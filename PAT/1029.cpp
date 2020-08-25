#include<iostream>
using namespace std;
int main()
{
    int M;
    scanf("%d",&M);
   long int num1[20001];
    for(int i=0;i<M;i++)
        scanf("%d",&num1[i]);
    int N;
    scanf("%d",&N);
    long int num2[20001];
    for(int i=0;i<N;i++)
        scanf("%d",&num2[i]);
    int temp[40002];
    int left=0,right=0;
    for(int k=0;k<M+N;k++)
    {
        if(left==M)
        {
            temp[k]=num2[right];
            right++;
        }
        else if(right==N)
        {
            temp[k]=num1[left];
            left++;
        }
        else if(num1[left]<=num2[right])
        {
            temp[k]=num1[left];
            left++;
        }
        else if(num1[left]>num2[right])
        {
            temp[k]=num2[right];
            right++;
        }
    }
    int mid=(M+N)/2;
    if((M+N)%2==0)
        mid--;
    cout<<temp[mid];   
    return 0;
}
/*8 -666958 -383142 -122738 -82272 244017 425599 612258 794413
5 -833155 -653864 -612882 267374 512280
*/