#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;
struct Catridge
{
	int key;
	char value[10];
};
int maxmas(Catridge *k, int n)
{
	int max=k[0].key;
	for(int i=1;i<n;i++)
	{
		if(max<k[i].key)
		{
			max=k[i].key;
		}
	}
	cout<<"max= "<<max<<"\n";
	return max;
};
int minmas(Catridge *k, int n)
{
	int min=k[0].key;
	for(int i=1;i<n;i++)
	{
		if(min>k[i].key)
		{
			min=k[i].key;
		}
	}
	cout<<"min= "<<min<<"\n";
	return min;
};
int main()
{
	int i,j,add_coeff,max,min,n,n1,*count;
	Catridge *k,*s;
	do
	{
		puts("Enter number of elements");
		cin>>n;
	}
	while(n<=0);
	k=new Catridge[n];
	s=new Catridge[n];
	for(i=0;i<n;i++)
	{
		cout<<"Enter key of element #"<<i+1<<"\n";
		cin>>k[i].key;
		cout<<"Enter value of element #"<<i+1<<"\n";
		cin>>k[i].value;
	}
	max=maxmas(k,n);
	min=minmas(k,n);
	add_coeff=min;
	n1=max-min+1;
	count=new int[n1];
	for(i=0;i<n1;i++)
	{
		count[i]=0;
	}
	for(j=0;j<n;j++)
	{
		count[k[j].key-add_coeff]++;
		//cout<<k[j].key-add_coeff<<"\t"<<count[k[j].key-add_coeff]<<"\n";
	}
	for(i=1;i<n1;i++)
	{
		count[i]=count[i]+count[i-1];
		//cout<<i<<"\t"<<count[i]<<"\n";
	}
	for(j=n-1;j>=0;j--)
	{
		i=count[k[j].key-add_coeff]-1;
		s[i].key=k[j].key;
		strcpy(s[i].value,k[j].value);
		//cout<<k[j]<<"\n";
		//cout<<i<<"\t"<<s[i].key<<"\t"<<s[i].value<<"\n";
		//count[k[j].key-add_coeff]=i-1;
		count[k[j].key-add_coeff]=i;
	}
	for(i=0;i<n;i++)
	{
		cout<<s[i].key<<"\t"<<s[i].value<<"\n";
	}
	delete[] k;
	delete[] count;
	delete[] s;
	getch();
}
