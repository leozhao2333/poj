#include<cstdio>
#include<algorithm>
using namespace std;
int a,b,ans;
int main()
{
	while (scanf("%d%d",&a,&b)!=EOF)
	{
		ans=0;
		printf("%d %d ",a,b);
		if (a>b) swap(a,b);
		for (int i=a;i<=b;i++)
		{
			int temp=1,n=i;
			while (n-1)n%2==0?(n=n/2):(n=3*n+1),temp++;
			if (temp>ans)
			 ans=temp;
		}
		printf("%d\n",ans);
	}
}
