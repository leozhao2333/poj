#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string s,ss;
int i;
string backword[500],forwa[500];
int b,f;
int main()
{
	b=1;f=0;
	backword[1]="http://www.acm.org/"; 
	while (1==1)
	{
		cin>>s;
		if (s[0]=='Q')
		return 0;
		if (s[0]=='V')
		{
		  cin>>ss;
		  f=0;
		  b++;
		  backword[b]=ss.substr(0,ss.size());	
		  cout<<backword[b]<<endl;	
		}
		if (s[0]=='B')
		{
			if (b!=1)
			 {
			 	f++;
			 	forwa[f]=backword[b];
			 	b--;
			 	cout<<backword[b]<<endl;
				continue;
			 }
			if (b==1)
			{
				cout<<"Ignored"<<endl;
			} 
		}
		if (s[0]=='F')
		{
			if (f==0)
			 {
			 	cout<<"Ignored"<<endl;
			 	continue;
			 }
			b++;
			backword[b]=forwa[f];
			cout<<forwa[f]<<endl;
			f--; 
		}
	}	
}
/*VISIT http://acm.ashland.edu/
VISIT http://acm.baylor.edu/acmicpc/
BACK
BACK
BACK
FORWARD
VISIT http://www.ibm.com/
BACK
BACK
FORWARD
FORWARD
FORWARD
QUIT*/