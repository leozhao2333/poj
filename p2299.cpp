#include<cstdio>
#include<iostream>
using namespace std;
int n,a[600000],t[600000];
long long cnt;
void Merge(int l,int mid,int r)
{
	int i=l,j=mid+1,k=0;
	while(i<=mid&&j<=r)
	{
		if (a[i]>a[j])
		{
			t[k++]=a[j++];
			cnt+=mid-i+1;
		}
		else
		{
			t[k++]=a[i++];
		}
	}
	while(i<=mid)t[k++]=a[i++];
	while(j<=r)t[k++]=a[j++];
	for (i=0;i<k;i++)a[l+i]=t[i];
}
void mergesort(int l,int r)
{
	int mid=(l+r)/2;
	if (l<r)
	{
	mergesort(l,mid);
	mergesort(mid+1,r);
	Merge(l,mid,r);
    }
}
int main()
{
	while(scanf("%d",&n))
	{
		if (n==0)return 0;
		cnt=0;
		for (int i=1;i<=n;i++)
		 scanf("%d",&a[i]);
		mergesort(1,n);
		cout<<cnt<<endl;
	}
}
