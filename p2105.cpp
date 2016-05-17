#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
string ch;
int n;
int f(int k)
{
	int sum=1;
	for (int i=1;i<=k;i++)
	 sum*=2;
	return sum; 
}
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		int sum1=0,sum2=0,sum3=0,sum4=0,s[33];
        cin>>ch;
        for (int i=0;i<=31;i++)
         s[i+1]=ch[i]-'0';
	    for (int i=1;i<=8;i++)
	     sum1+=(s[i]*f(8-i));
	    for (int i=9;i<=16;i++)
	     sum2+=(s[i]*f(16-i));
	    for (int i=17;i<=24;i++)
	     sum3+=(s[i]*f(24-i));
	    for (int i=25;i<=32;i++)
	     sum4+=(s[i]*f(32-i));
	    printf("%d.%d.%d.%d\n",sum1,sum2,sum3,sum4); 
    }
}
