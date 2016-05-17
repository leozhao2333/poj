#include <cstdio>
#include <algorithm>

using namespace std;

long long tree[1000000],plus[1000000],g[300000];
long long i,m,n,x,y,z;
char c;

void buildtree(long long l,long long r,long long node)
{
	if (l==r)
	    tree[node]=g[l];
	else
	{
		long long mid=(l+r)/2;
		buildtree(l,mid,node*2);
		buildtree(mid+1,r,node*2+1);
		tree[node]=tree[node*2]+tree[node*2+1];
	}
	return;
}

void inserttree(long long l,long long r,long long x,long long y,long long z,long long node)
{
	if ((l==x) && (r==y))
	    plus[node]=plus[node]+z;
	else
	{
		tree[node]=tree[node]+(y-x+1)*z;
		long long mid=(l+r)/2;
		if (y<=mid)
		    inserttree(l,mid,x,y,z,node*2);
		else
		    if (x>mid)
		        inserttree(mid+1,r,x,y,z,node*2+1);
		    else
		    {
		    	inserttree(l,mid,x,mid,z,node*2);
		    	inserttree(mid+1,r,mid+1,y,z,node*2+1);
			}
	}
	return;
}

long long asktree(long long l,long long r,long long x,long long y,long long node)
{
	if (plus[node]!=0)
	{
		if (l!=r)
		{
			plus[node*2]=plus[node*2]+plus[node];
			plus[node*2+1]=plus[node*2+1]+plus[node];
		}
		tree[node]=tree[node]+plus[node]*(r-l+1);
		plus[node]=0;
	}
	if ((l==x) && (r==y))
	    return tree[node];
	long long mid=(l+r)/2;
	if (y<=mid)
	    return asktree(l,mid,x,y,node*2);
	if (x>mid)
	    return asktree(mid+1,r,x,y,node*2+1);
	return asktree(l,mid,x,mid,node*2)+asktree(mid+1,r,mid+1,y,node*2+1);
}

int main()
{
	scanf("%lld%lld",&n,&m);
	for (i=1;i<=n;i++)
	    scanf("%lld",&g[i]);
	buildtree(1,n,1);
	for (i=1;i<=m;i++)
	{
		getchar();c=getchar();
		if (c=='C')
		{
			scanf("%lld %lld %lld",&x,&y,&z);
			if (x>y)
			    swap(x,y);
			inserttree(1,n,x,y,z,1);
		}
		if (c=='Q')
		{
			scanf("%lld %lld",&x,&y);
			if (x>y)
			    swap(x,y);
			printf("%lld\n",asktree(1,n,x,y,1));
		}
	}
	return 0;
}
