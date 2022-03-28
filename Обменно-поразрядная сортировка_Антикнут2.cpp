#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <stack>
using namespace std;
struct Catridge
{
	int k;
	char r[10];
};

void sort_bit(Catridge *a, int left, int right, int b)
{
	int i,j,l,K,num_bit,r,x;
	char R[10];
	l=left;
	r=right;
	num_bit=b;
	if(num_bit==0)
	{
		j=0;
		for(i=l;i<=r;i++)
		{
			x=(1<<(32-b-1))&a[i].k;
			//cout<<"x="<<x;
			x=x>>(32-b-1);
			cout<<"x="<<x;
			if(x==-1)
			{
				K=a[i].k;
				strcpy(R,a[i].r);
				a[i].k=a[l+j].k;
				strcpy(a[i].r, a[l+j].r);
				a[l+j].k=K;
				strcpy(a[l+j].r,R);
				j++;
			}
		}
		cout<<"yes";
	}
	else
	{
		j=0;
		for(i=l;i<=r;i++)
		{
			x=(1<<(32-b-1))&a[i].k;
			if(x==0)
			{
				K=a[i].k;
				strcpy(R,a[i].r);
				a[i].k=a[l+j].k;
				strcpy(a[i].r, a[l+j].r);
				a[l+j].k=K;
				strcpy(a[l+j].r,R);
				j++;
			}
		}
	}
	cout<<"l="<<l;
	cout<<"r="<<r;
	cout<<"b="<<num_bit;
	if(num_bit<=31)
	{
		if((l>=0)&&(j>0))
		{
			sort_bit(a,l,l+j-1,num_bit+1);
		}
		if((r>=0)&&(r>=(l+j)))
		{
			sort_bit(a,l+j,r,num_bit+1);
		}
	}
	
}

int main()
{
	int i,n;
	//char R[10];
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
	//min=minmas(tab,n);
	//max=maxmas(tab,n);
	//l=0;
	//r=n-1;
	
	sort_bit(tab,0,n-1,0);
	
	for(i=0;i<n;i++)
	{
		cout<<tab[i].k<<"\t"<<tab[i].r<<"\n";
	}
	getch();
}
