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
	int i,j,down,n,t,up,K;
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
	down=0;
	up=n-1;
	t=n-1;
	while(down<up)
	{
		for(j=down;j<up;j++)
		{
			if(tab[j].k>tab[j+1].k)
			{
				t=j;
				K=tab[j].k;
				strcpy(R, tab[j].r);
				tab[j].k=tab[j+1].k;
				strcpy(tab[j].r, tab[j+1].r);
				tab[j+1].k=K;
				strcpy(tab[j+1].r, R);
			}
		}
		up=t;
		cout<<"t= "<<t<<"\n";
		for(i=up;i>down;i--)
		{
			if(tab[i].k<tab[i-1].k)
			{
				t=i;
				K=tab[i].k;
				strcpy(R, tab[i].r);
				tab[i].k=tab[i-1].k;
				strcpy(tab[i].r, tab[i-1].r);
				tab[i-1].k=K;
				strcpy(tab[i-1].r, R);
			}
		}
		down=t;
		cout<<"t= "<<t<<"\n";
	}
	for(i=0;i<n;i++)
	{
		cout<<tab[i].k<<"\t"<<tab[i].r<<"\n";
	}
	getch();
}
