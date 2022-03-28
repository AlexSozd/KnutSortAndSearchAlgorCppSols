#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;
struct Catridge
{
	int k;
	char r[10];
};
int main()
{
	int buf,d,f,i,j,k,l,n,ob,s;
	//char R[10];
	Catridge *tab;
	do
	{
		puts("Enter count of elements");
		cin>>n;
	}
	while(n<=0);
	tab=new Catridge[2*n];
	for(i=0;i<n;i++)
	{
		cout<<"Enter key of element #"<<i+1<<"\n";
		cin>>tab[i].k;
		cout<<"Enter value of element #"<<i+1<<"\n";
		cin>>tab[i].r;
	}
	//ob=0;
	s=0;
	i=0;
	j=n-1;
	k=n;
	l=2*n-1;
	d=1;
	f=1;
	do
	{
		//ob=0;
		f=1;
		while(i!=j)
		{
			if(tab[i].k>tab[j].k)
			{
				tab[k].k=tab[j].k;
				strcpy(tab[k].r,tab[j].r);
				//ob++;
				k=k+d;
				j=j-1;
				if(tab[j+1].k>tab[j].k)
				{
					do
					{
						tab[k].k=tab[i].k;
						strcpy(tab[k].r,tab[i].r);
						//ob++;
						k=k+d;
						i=i+1;
					}
					while(tab[i-1].k<=tab[i].k);
					f=0;
					d=-d;
					buf=k;
					k=l;
					l=buf;
				}
			}
			else
			{
				tab[k].k=tab[i].k;
				strcpy(tab[k].r,tab[i].r);
				//ob++;
				k=k+d;
				i=i+1;
				if(tab[i-1].k>tab[i].k)
				{
					do
					{
						tab[k].k=tab[j].k;
						strcpy(tab[k].r,tab[j].r);
						//ob++;
						k=k+d;
						j=j-1;
					}
					while(tab[j+1].k<=tab[j].k);
					f=0;
					d=-d;
					buf=k;
					k=l;
					l=buf;
				}
			}
		}
		tab[k].k=tab[i].k;
		strcpy(tab[k].r,tab[i].r);
		if(f==0)
		{
			s=1-s;
			if(s==0)
			{
				i=0;
				j=n-1;
				k=n;
				l=2*n-1;
			}
			else
			{
				i=n;
				j=2*n-1;
				k=0;
				l=n-1;
			}
			d=1;
			//f=1;
		}
		ob++;
		cout<<"Circle #"<<ob<<"\n";
	}
	while(f==0);
	for(i=0;i<n;i++)
	{
		//cout<<tab[i].k<<"\t"<<tab[i].r<<"\n";
		if(s=0)
		{
			cout<<tab[i+n].k<<"\t"<<tab[i+n].r<<"\n";
		}
		else
		{
			cout<<tab[i].k<<"\t"<<tab[i].r<<"\n";
		}
	}
	getch();
}
