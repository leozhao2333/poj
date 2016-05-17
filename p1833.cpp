#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int n,k,m,i,j,a[1100];
int main()
{
	scanf("%d",&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&n,&k);
		for (j=1;j<=n;j++)
		scanf("%d",&a[j]);
		for (j=1;j<=k;j++)
		 next_permutation(a+1,a+n+1);
		for (j=1;j<=n;j++) 
		 printf("%d ",a[j]);
		printf("\n"); 
	}
}
