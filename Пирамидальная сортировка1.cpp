#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <stack>
using namespace std;
struct Catridge
{
	int k;
	char r[10];
};
int main()
{
	int b,c[2],i,j,l,l1,m,min,max,n,ob=0,r,r1,K,x;
	char R[10];
	Catridge *tab;
	do
	{
		puts("Enter count of elements");
		cin>>n;
	}
	while(n<=0);
	tab=new Catridge[n];
	for(i=0;i<n;i++)
	{
		cout<<"Enter key of element #"<<i+1<<"\n";
		cin>>tab[i].k;
		cout<<"Enter value of element #"<<i+1<<"\n";
		cin>>tab[i].r;
	}
	l=n/2+1;
	r=n-1;
	while(r>0)
	{
		if(l>0)
		{
			l=l-1;
			strcpy(R,tab[l].r);
			K=tab[l].k;
		}
		else
		{
			strcpy(R,tab[r].r);
			K=tab[r].k;
			tab[r].k=tab[0].k;
			strcpy(tab[r].r,tab[0].r);
			r=r-1;
			if(r==0)
			{
				tab[0].k=K;
				strcpy(tab[0].r,R);
			}
		}
		j=l;
		do
		{
			i=j;
			if(j>0)
			{
				j=2*j;
			}
			else
			{
				j=1;
			}
			if(j<=r)
			{
				if(j<r)
				{
					if(tab[j].k<tab[j+1].k)
					{
						j=j+1;
					}
				}
				if(K<tab[j].k)
				{
					cout<<tab[i].k<<"\t"<<tab[j].k;
					tab[i].k=tab[j].k;
					strcpy(tab[i].r,tab[j].r);
					//H4
				}
			}
		}
		while((K<tab[j].k)&&(j<=r));
		tab[i].k=K;
		strcpy(tab[i].r,R);
		cout<<"\n"<<tab[i].k<<"\t"<<K<<"\n";
		for(b=0;b<n;b++)
		{
			cout<<tab[b].k<<"\t"<<tab[b].r<<"\n";
		}
		cout<<"\n"<<"l="<<l;
		cout<<"\n"<<"r="<<r<<"\n";
	}
	
	//cout<<"\n"<<"ob="<<ob<<"\n";
	for(i=0;i<n;i++)
	{
		cout<<tab[i].k<<"\t"<<tab[i].r<<"\n";
	}
	getch();
}
