#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct data{int tj;int *kk;}a[100010];
int ku[100010][10],ii,n;
bool cmp(data a,data b){return (a.tj<b.tj)?true:false;}
int js(char ch)
 {
     if(ch=='A' || ch=='B' || ch=='C')
         return 2;
     if(ch=='D' || ch=='E' || ch=='F')
         return 3;
     if(ch=='G' || ch=='H' || ch=='I')
         return 4;
     if(ch=='J' || ch=='K' || ch=='L')
         return 5;
     if(ch=='M' || ch=='N' || ch=='O')
         return 6;
     if(ch=='P' || ch=='R' || ch=='S')
         return 7;
     if(ch=='T' || ch=='U' || ch=='V')
         return 8;
     if(ch=='W' || ch=='X' || ch=='Y')
         return 9;
 }
int main()
{
	scanf("%d",&n);
	ii=0;
	for (int i=1;i<=n;i++)
	{
		char c[100];
		bool flag=true;
		int k=0;
		scanf("%s",c);
		ii++;
		for (int j=0;c[j]!='\0';j++)
		 if (c[j]>='0'&&c[j]<='9')
		  k++,ku[ii][k]=c[j]-48;
		 else if (c[j]>='A'&&c[j]<='Z')
		       {k++,ku[ii][k]=js(c[j]);} 
		for (int j=1;j<ii;j++)
		{
		  if (flag==false)
		   break;	
		  for (k=1;k<=7;k++)
		   if (ku[j][k]!=)
		   //if (ku[j][k]==ku[ii][k])
		    //{a[j].tj++;a[j].kk=ku[j];ii--;flag=false;break;}
		   //else break; 
		}
	}
   sort(a+1,a+ii+1,cmp);
   for (int i=1;i<=ii;i++)
    {
    	for (int j=1;j<=7;j++)
    	 printf("%d ",ku[i][j]);
        printf("%d\n",a[i].tj); 
    }	
}
