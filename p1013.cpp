#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int n;
char a[5][1000],b[5][1000],c[5][1000];
int heavy[15];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s%s%s",&a[1],&b[1],&c[1]);
		scanf("%s%s%s",&a[2],&b[2],&c[2]);
		scanf("%s%s%s",&a[3],&b[3],&c[3]);
		memset(heavy,0,sizeof(heavy));
		int ans1=0,ans2=0,flag=false;
		for (int i=1;i<=12;i++)//暴力枚举假币 
		{
		 if (flag)
		  break;
		 for (int j=1;j<=2;j++)//j=1代表假币较轻，j=2代表假币较重 
		  {
		  	if (flag)
		  	 break;
		  	heavy[i]=(j==1)?-1:1;
		  	bool temp=true;
		  	for (int k=1;k<=3;k++)
		  	 {
		  	 	if (!temp)
		  	 	break;
		  	 	int temp1=0,temp2=0;
		  	 	for (int l=0;l<=strlen(a[k])-1;l++)
		  	 	 temp1+=heavy[a[k][l]-'A'+1];
		  	 	for (int l=0;l<=strlen(b[k])-1;l++)
				  temp2+=heavy[b[k][l]-'A'+1];
				switch(c[k][0])
				{
					case 'u':if (temp1<=temp2)temp=false;break;
					case 'd':if (temp1>=temp2)temp=false;break;
					case 'e':if (temp1!=temp2)temp=false;break;
				} 
			 }
			if (temp)ans1=i,ans2=j,flag=true;
		  }
		 heavy[i]=0; 
	    }
	    printf("%c is the counterfeit coin and it is ",ans1+'A'-1);
	    if (ans2==1)
	    printf("light.\n");
	    else printf("heavy.\n");
	}
}
