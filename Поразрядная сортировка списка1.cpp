#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;
struct Catridge
{
	int *key;
	char value[10];
	Catridge *link;
};
int maxmas(Catridge *k, int n, int p)
{
	int i,j,max=k[0].key[0];
	for(i=0;i<n;i++)
	{
		for(j=0;j<p;j++)
		{
			if(max<k[i].key[j])
			{
				max=k[i].key[j];
			}
		}
	}
	cout<<"max= "<<max<<"\n";
	return max;
};
int minmas(Catridge *k, int n, int p)
{
	int i,j,min=k[0].key[0];
	for(i=0;i<n;i++)
	{
		for(j=0;j<p;j++)
		{
			if(min>k[i].key[j])
			{
				min=k[i].key[j];
			}
		}
	}
	cout<<"min= "<<min<<"\n";
	return min;
};
int main()
{
	int i,j,k,max,min,n,n1,p;
	Catridge *cur,*s,*P,**top,**botm;
	do
	{
		puts("Enter number of elements");
		cin>>n;
	}
	while(n<=0);
	do
	{
		puts("Enter number of keys");
		cin>>p;
	}
	while(p<=0);
	s=new Catridge[n];
	for(i=0;i<n;i++)
	{
		s[i].key=new int[p];
		for(j=0;j<p;j++)
		{
			cout<<"Enter key #"<<j+1<<"of element #"<<i+1<<"\n";
			cin>>s[i].key[j];
		}
		cout<<"Enter value of element #"<<i+1<<"\n";
		cin>>s[i].value;
	}
	max=maxmas(s,n,p);
	min=minmas(s,n,p);
	//add_coeff=min;
	n1=max-min+1;
	//top=new int[n1];
	//botm=new int[n1];
	top=new Catridge*[n1];
	botm=new Catridge*[n1];
	for(i=0;i<n-1;i++)
	{
		s[i].link=&s[i+1];
	}
	s[n-1].link=NULL;
	for(k=0;k<p;k++)
	{
		P=&s[0];
		j=0;
		for(i=0;i<n1;i++)
		{
			top[i]=botm[i];
			botm[i]=NULL;
		}
		do
		{
			i=P->key[p+1-k];
			top[i]->link=P;
			top[i]=P;
			if(k==0)
			{
				if((P==&s[j])&&(j>=0))
				{
					P=&s[j+1];
					j++;
				}
			}
			else
			{
				P=P->link;
			}
		}
		while(P!=NULL);
		if(P==NULL)
		{
			//algor_H();
			i=0;
			while(i<n1)
			{
				P=top[i];
				do
				{
					i++;
					if(i==n1)
					{
						P->link=NULL;
					}
				}
				while(botm[i]==NULL);
				//i++;
				P->link=botm[i];
			}
			P=botm[0];
		}
	}
	cur=P;
	while(cur!=NULL)
	{
		for(i=0;i<p;i++)
		{
			cout<<cur->key[i]<<"\t";
		}
		cout<<cur->value<<"\n";
		cur=cur->link;
	}
	/*for(i=0;i<n;i++)
	{
		cout<<s[i].key<<"\t"<<s[i].value<<"\n";
	}*/
	delete[] s;
	delete[] top;
	delete[] botm;
	getch();
}
