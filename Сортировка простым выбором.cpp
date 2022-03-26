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
	int i,j,max,max_i,n,K;
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
	for(j=n-1;j>0;j--)
	{
		max=tab[j].k;
		max_i=j;
		for(i=j;i>=0;i--)
		{
			if(max<tab[i].k)
			{
				max=tab[i].k;
				max_i=i;
			}
		}
		K=tab[j].k;
		strcpy(R,tab[j].r);
		tab[j].k=tab[max_i].k;
		strcpy(tab[j].r, tab[max_i].r);
		tab[max_i].k=K;
		strcpy(tab[max_i].r,R);
	}
	for(i=0;i<n;i++)
	{
		cout<<tab[i].k<<"\t"<<tab[i].r<<"\n";
	}
	getch();
}
