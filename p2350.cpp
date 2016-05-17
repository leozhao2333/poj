#include<cstdio>
using namespace std;
int a[1010],n,m;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		int sum=0;
		float xba;
		scanf("%d",&m);
		for (int i=1;i<=m;i++)scanf("%d",&a[i]),sum+=a[i];
		xba=sum*1.0/m;
		int tj=0;
		for (int i=1;i<=m;i++)
		 if (a[i]>xba)
		  tj++;
		xba=(float)tj*1.0/m;
		xba*=(float)100;
		printf("%.3lf",(float)xba);
		printf("%\n");  
	}
}
