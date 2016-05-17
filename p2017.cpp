#include<cstdio>
using namespace std;
int n;
int main()
{
	while(scanf("%d",&n))
	{
		if (n==-1)
		 return 0;
		int ans=0,last=0,s,t;
		for (int i=1;i<=n;i++)
		 scanf("%d%d",&s,&t),ans+=s*(t-last),last=t;
		printf("%d miles\n",ans); 
	}
}
