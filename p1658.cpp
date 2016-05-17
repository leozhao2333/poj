#include<cstdio>
using namespace std;
int t,a[10];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		for (int i=1;i<=4;i++)
		 scanf("%d",&a[i]),printf("%d ",a[i]);
		if ((a[2]-a[1])==(a[3]-a[2]))
		printf("%d\n",a[4]+(a[2]-a[1]));
		else printf("%d\n",a[4]*(a[2]/a[1]));
	}
}
