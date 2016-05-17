#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define clc long long
using namespace std;
clc tree[1000000],plus[1000000],g[1000000];
clc n,m,x,y,z;
char c[5];
void build(clc l,clc r,clc root)
{
	if (l==r)
	 tree[root]=g[l];
	else
	{
		clc mid=(l+r)/2;
		build(l,mid,root*2);
		build(mid+1,r,root*2+1);
		tree[root]=tree[root*2]+tree[root*2+1];
	}
}
void update(clc l,clc r,clc x,clc y,clc z,clc root)
{
	if ((l==x)&&(r==y))
	plus[root]+=z;
	else
	{
		tree[root]=tree[root]+(y-x+1)*z;
		clc mid=(l+r)/2;
		if (y<=mid) 
		   update(l,mid,x,y,z,root*2);
		else 
		    if (x>mid)
		     update(mid+1,r,x,y,z,root*2+1);
		    else
			{
			    update(l,mid,x,mid,z,root*2);
		        update(mid+1,r,mid+1,y,z,root*2+1);
		    }
	}
	return;
}
clc ask(clc l,clc r,clc x,clc y,clc root)
{
	if (plus[root]!=0)
	{
		if (l!=r)
		{
			plus[root*2]=plus[root*2]+plus[root];
			plus[root*2+1]=plus[root*2+1]+plus[root];
		}
		tree[root]=tree[root]+plus[root]*(r-l+1);
		plus[root]=0;
	}
	if ((l==x)&&(r==y)) return tree[root];
	long long mid=(l+r)/2;
	if (y<=mid)return ask(l,mid,x,y,root*2);
	if (x>mid)return ask(mid+1,r,x,y,root*2+1);
	return ask(l,mid,x,mid,root*2)+ask(mid+1,r,mid+1,y,root*2+1);
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++)
	 scanf("%lld",&g[i]);
	build(1,n,1);
	for (int i=1;i<=m;i++)
	{
		scanf("%s",c);
		if (c[0]=='C')
		{
			scanf("%lld%lld%lld",&x,&y,&z);
			if (x>y) swap(x,y);
			update(1,n,x,y,z,1);
		}
		if (c[0]=='Q')
		{
			scanf("%lld %lld",&x,&y);
			if (x>y) swap(x,y);
			printf("%lld\n",ask(1,n,x,y,1));
		}
	}
}
