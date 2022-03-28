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
int get_t(int n)
{
	int i=0,k=0,count=n,t;
	while(count>1)
	{
		if(count%2!=0)
		{
			k=1;
		}
		count=count/2;
		i++;
	}
	t=i+k;
	cout<<"t= "<<t<<"\n";
	return t;
};
int main()
{
	int d,i,j=0,n,p,q,r,t,x,K;
	char R[10];
	Catridge *tab;
	do
	{
		puts("Enter count of elements");
		cin>>n;
	}
	while(n<=1);
	tab=new Catridge[n];
	t=get_t(n);
	for(i=0;i<n;i++)
	{
		cout<<"Enter key of element #"<<i+1<<"\n";
		cin>>tab[i].k;
		cout<<"Enter value of element #"<<i+1<<"\n";
		cin>>tab[i].r;
	}
	p=pow(2,t-1);
	//p=2^(t-1);
	//q=p/2;
	//r=0;
	//d=p;
	while(p>0)
	{
		q=pow(2,t-1);
		//cout<<"\n"<<"q= "<<q<<"\n";
		r=0;
		//cout<<"r= "<<r<<"\n";
		d=p;
		//cout<<"d= "<<d<<"\n";
		do
		{
			//cout<<"n-d= "<<n-d<<"\n";
			for(i=0;i<n-d;i++)
			{
				//cout<<"yes"<<"\n";
				x=i&p;
				//cout<<"x= "<<x<<"\n";
				if(x==r)
				{
					//cout<<"yes"<<"\n";
					if(tab[i].k>tab[i+d].k)
					{
						K=tab[i].k;
						strcpy(R, tab[i].r);
						tab[i].k=tab[i+d].k;
						strcpy(tab[i].r, tab[i+d].r);
						tab[i+d].k=K;
						strcpy(tab[i+d].r, R);
						j++;
						//cout<<"j= "<<j<<"\n";
				   }
				}
	      }
			d=q-p;
			q=q/2;
			r=p;
			//cout<<"\n"<<"q= "<<q<<"\n";
			//cout<<"r= "<<r<<"\n";
			//cout<<"d= "<<d<<"\n";
		}
		while(q>=p);
		p=p/2;
		//cout<<"\n"<<"p= "<<p<<"\n";
	}
	for(i=0;i<n;i++)
	{
		cout<<tab[i].k<<"\t"<<tab[i].r<<"\n";
	}
	delete[] tab;
	getch();
}
