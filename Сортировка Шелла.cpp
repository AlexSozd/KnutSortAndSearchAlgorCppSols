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
int get_ht(int n)
{
	int count=n/2,t;
	/*if(count%2!=0)
	{
		if((count/2)%2!=0)
		{
			t=count/2;
		}
		else
		{
			t=count/2+1;
		}
		//t=count/2+1;
	}
	else
	{
		if((count/2)%2!=0)
		{
			t=count/2;
		}
		else
		{
			t=count/2+1;
		}
		t=count/2;
	}*/
	if(count%2!=0)
	{
		t=count;
	}
	else
	{
		t=count+1;
	}
	cout<<"t= "<<t<<"\n";
	return t;
}
int main()
{
	int i,j,h,n,ht,t,K;
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
	/*for(t=3;t>=0;t--)
	{
		h=ht;
		for(j=h;j<n;j++)
		{
			i=j-h;
			K=tab[j].k;
			strcpy(R, tab[j].r);
			while((K<tab[i].k)&&(i>=0))
			{
				tab[i+h].k=tab[i].k;
				strcpy(tab[i+h].r,tab[i].r);
				i=i-h;
			}
			//if(K>=tab[i].k)
			tab[i+h].k=K;
			strcpy(tab[i+h].r, R);
		}
		ht=ht-2;
	}*/
	ht=get_ht(n);
	while(ht>0)
	{
		h=ht;
		for(j=h;j<n;j++)
		{
			i=j-h;
			K=tab[j].k;
			strcpy(R, tab[j].r);
			while((K<tab[i].k)&&(i>=0))
			{
				tab[i+h].k=tab[i].k;
				strcpy(tab[i+h].r,tab[i].r);
				i=i-h;
			}
			tab[i+h].k=K;
			strcpy(tab[i+h].r, R);
		}
		ht=ht-2;
	}
	for(i=0;i<n;i++)
	{
		cout<<tab[i].k<<"\t"<<tab[i].r<<"\n";
	}
	getch();
}
