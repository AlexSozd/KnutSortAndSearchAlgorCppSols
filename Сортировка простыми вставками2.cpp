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
	int i,j,n,K;
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
	for(j=1;j<n;j++)
	{
		i=j-1;
		K=tab[j].k;
		strcpy(R,tab[j].r);
		while((K<tab[i].k)&&(i>=0))
		{
			tab[i+1].k=tab[i].k;
			strcpy(tab[i+1].r,tab[i].r);
			i=i-1;
		}
		tab[i+1].k=K;
		strcpy(tab[i+1].r,R);
	}
	for(i=0;i<n;i++)
	{
		cout<<tab[i].k<<"\t"<<tab[i].r<<"\n";
	}
	getch();
}
