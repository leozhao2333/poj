#include<cstdio>
using namespace std;
int n,i,j,sum,m,x;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
	  scanf("%d",&m);
	  sum=0-m;
	  for (j=1;j<=m;j++)
	   {
	   	scanf("%d",&x);
	   	sum=sum+x;
	   }
	  printf("%d\n",sum+1); 
	}
}
