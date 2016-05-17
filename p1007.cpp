#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
struct data{char c[60];int tj;}ku[110];
bool cmp(data a,data b){return (a.tj<b.tj)?true:false;}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%s",ku[i].c);
		ku[i].tj=0;
		for (int j=0;j<n;j++)
		 for (int k=j+1;k<n;k++)
		  if (ku[i].c[j]>ku[i].c[k])
		   ku[i].tj++;
	}
    sort(ku+1,ku+m+1,cmp);
	for (int i=1;i<=m;i++)
	 printf("%s\n",ku[i].c);	
}
