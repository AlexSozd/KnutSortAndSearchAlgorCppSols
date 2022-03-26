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
	int i,j,n,t,up,K;
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
	up=n-1;
	t=n;
	while(t>0)
	{
		t=0;
		for(j=0;j<up;j++)
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
	}
	for(i=0;i<n;i++)
	{
		cout<<tab[i].k<<"\t"<<tab[i].r<<"\n";
	}
	getch();
}
