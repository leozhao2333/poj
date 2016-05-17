#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#define inf 0x7fffffff
using namespace std;
const int maxn=200+10;
int n,m,from,to;
struct node
{
	int v,flow;
	int next;
}edge[maxn*4];
int head[maxn],edgenum;
void add(int u,int v,int flow)
{
	edge[edgenum].v=v;edge[edgenum].flow=flow;
	edge[edgenum].next=head[u];head[u]=edgenum++;
	edge[edgenum].v=u;edge[edgenum].flow=0;
	edge[edgenum].next=head[v];head[v]=edgenum++;
}
int d[maxn];
int bfs()
{
	memset(d,0,sizeof(d));
	d[from]=1;
	queue<int>Q;
	Q.push(from);
	while(!Q.empty())
	{
		int u=Q.front();Q.pop();
		for (int i=head[u];i!=-1;i=edge[i].next)
		{
			int v=edge[i].v;
			if (!d[v]&&edge[i].flow)
			{
				d[v]=d[u]+1;
				Q.push(v);
				if (v==to)return 1;
			}
		}
	}
    return 0;
}
int dfs(int u,int flow)
{
	if (u==to||flow==0)return flow;
	int cap=flow;
	for (int i=head[u];i!=-1;i=edge[i].next)
	{
		int v=edge[i].v;
		if (d[v]==d[u]+1&&edge[i].flow)
		{
			int x=dfs(v,min(cap,edge[i].flow));
			edge[i].flow-=x;
			edge[i^1].flow+=x;
			cap-=x;
			if (cap==0)return flow;
		}
	}
	return flow-cap;
}
int dinic()
{
	int ans=0;
	while(bfs())ans+=dfs(from,inf);
	return ans;
}
int main()
{
	while(scanf("%d%d",&m,&n)!=EOF)
	{
	memset(head,-1,sizeof(head));
	edgenum=0;
	int a,b,c;
	for (int i=0;i<m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
	}
	from=1;
	to=n;
	printf("%d\n",dinic());
    }
}
