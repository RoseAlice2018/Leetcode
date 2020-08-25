#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define r 200004
long a[2*r];
int main()
{
	int n,m,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%ld",&a[i]);
	scanf("%d",&m);
	for(i=0;i<m;i++)
	scanf("%ld",&a[i+n]);
	sort(a,a+m+n);
	if((m+n)%2==0)
	{
		printf("%ld\n",a[(m+n)/2-1]);
	}
	else
	{
		printf("%ld\n",a[(m+n)/2]);
	}
	return 0;
}