#include<iostream>
using namespace std;

int count(int m,int n)//m apples
{

   if(m==0||n==1) return 1;
   if(n>m) return count(m,m);
   return count(m-n,n)+count(m,n-1);
}


int main()
{
 int cnt=0;
 int apples=0,dishes=0;
 while(cin>>cnt)
 {
    while(cnt--)
	{
	  cin>>apples>>dishes;
	  int ans=count(apples,dishes);
	  cout<<ans<<endl;
	}
 
 }
  return 0;
}
