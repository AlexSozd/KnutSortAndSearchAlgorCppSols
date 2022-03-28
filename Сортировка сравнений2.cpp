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
int main()
{
	int i,j,n,*count;
	Catridge *k,*s;
	do
	{
		puts("Enter number of elements");
		cin>>n;
	}
	while(n<=0);
	k=new Catridge[n];
	count=new int[n];
	s=new Catridge[n];
	for(i=0;i<n;i++)
	{
		cout<<"Enter key of element #"<<i+1<<"\n";
		cin>>k[i].key;
		cout<<"Enter value of element #"<<i+1<<"\n";
		cin>>k[i].value;
		count[i]=0;
	}
	for(i=n-1;i>=1;i--)
	{
		for(j=i-1;j>=0;j--)
		{
			if(k[i].key<k[j].key)
			{
				count[j]++;
			}
			else
			{
				count[i]++;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		j=count[i];
		s[j].key=k[i].key;
		strcpy(s[j].value,k[i].value);
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
