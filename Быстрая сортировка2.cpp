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
int get_t(int n)
{
	int i=0,count=n,t;
	while(count>1)
	{
		count=count/2;
		i++;
	}
	t=i;
	cout<<"t= "<<t<<"\n";
	return t;
};
int maxmas(Catridge *k, int n)
{
	int max=k[0].k;
	for(int i=1;i<n;i++)
	{
		if(max<k[i].k)
		{
			max=k[i].k;
		}
	}
	cout<<"max= "<<max<<"\n";
	return max;
};
int minmas(Catridge *k, int n)
{
	int min=k[0].k;
	for(int i=1;i<n;i++)
	{
		if(min>k[i].k)
		{
			min=k[i].k;
		}
	}
	cout<<"min= "<<min<<"\n";
	return min;
};
int main()
{
	int c,i,j,k,l,l1,m,n,n1,ob=0,r,r1,K,K0,KN;
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
	K0=minmas(tab,n)-1;
	KN=maxmas(tab,n)+1;
	n1=get_t(n);
	stack <int> st;
	//st.size=n1;
	if(n>19)
	{
		m=9;
	}
	else
	{
		m=n/2-1;
	}
	l=0;
	r=n-1;
	if(m<n)
	{
		do //И стек занят
		{
			//l=0;
			//r=n-1;
			i=l;
			j=r+1;
			k=tab[l].k;
			do
			{
				i=i+1;
				while((k>tab[i].k)&&(i<=j))
				{
					i++;
				}
				j=j-1;
				while((k<tab[j].k)&&(j>=(i-1)))
				{
					j--;
				}
				if(i<j)
				{
					K=tab[i].k;
					strcpy(R,tab[i].r);
					tab[i].k=tab[j].k;
					strcpy(tab[i].r, tab[j].r);
					tab[j].k=K;
					strcpy(tab[j].r,R);
					ob++;
				}
			}
			while(i<j);
			K=tab[l].k;
			strcpy(R,tab[l].r);
			tab[l].k=tab[j].k;
			strcpy(tab[l].r, tab[j].r);
			tab[j].k=K;
			strcpy(tab[j].r,R);
			ob++;
			//Q7
			if(((r-j)>=(j-l))&&((j-l)>m))
			{
				//Stack
				l1=j+1;
				r1=r;
				for(c=j+1;c<=r;c++)
				{
					st.push(tab[c].k);
				}
				r=j-1;
			}
			else if(((r-j)<(j-l))&&((r-j)>m))
			{
				//Stack
				l1=l;
				r1=j+1;
				for(c=l;c<=j+1;c++)
				{
					st.push(tab[c].k);
				}
				l=j+1;
			}
			else if(((r-j)>m)&&(m>=(j-l)))
			{
				l=j+1;
			}
			else if(((j-l)>m)&&(m>=(r-j)))
			{
				r=j-1;
			}
			else
			{
				//Out of stack
				if(st.empty()==false)
				{
					st.pop();
					l=l1;
					r=r1;
					ob++;
				}
			}
		}
		while(st.empty()==false);
	}
	cout<<"\n"<<"ob="<<ob<<"\n";
	for(i=0;i<n;i++)
	{
		cout<<tab[i].k<<"\t"<<tab[i].r<<"\n";
	}
	if(m>1)
	{
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
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<tab[i].k<<"\t"<<tab[i].r<<"\n";
	}
	getch();
}
