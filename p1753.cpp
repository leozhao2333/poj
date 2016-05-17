#include<cstdio>
#include<algorithm>
using namespace std;
char ch;
int tu[5][5];//白色是1,黑色是0 
int ans=0x7ffff,temp=0;
bool check()
{
	int sum=0;
	for (int i=1;i<=4;i++)
	 for (int j=1;j<=4;j++)
	  sum+=tu[i][j];
	return sum==0||sum==16;
}
void change(int x,int y)
{
	tu[x][y]=!tu[x][y];
	if (x>1)tu[x-1][y]=!tu[x-1][y];
	if (x<4)tu[x+1][y]=!tu[x+1][y];
	if (y>1)tu[x][y-1]=!tu[x][y-1];
	if (y<4)tu[x][y+1]=!tu[x][y+1];
}
void dfs(int x,int y)
{
	if (check()) ans=min(ans,temp);
	if (x==5)
	 x=1,y++;
	if (y==5)return;
	change(x,y);
	temp++;
	if (check()) ans=min(ans,temp);
	dfs(x+1,y);
	temp--;
	change(x,y);
	dfs(x+1,y);
}
int main()
{
	for (int i=1;i<=4;i++)
	{
	 for (int j=1;j<=4;j++)
	  scanf("%c",&ch),tu[i][j]=(ch=='b')?0:1;
	 getchar();
    }
	dfs(1,1);
	if (ans==0x7ffff)
	 printf("Impossible\n");
	else printf("%d\n",ans);
}
