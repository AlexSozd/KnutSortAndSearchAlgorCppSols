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
	int value;
};
int main()
{
	int i,j,n;
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
		cout<<"Enter element #"<<i+1<<"\n";
		cin>>k[i].value;
		k[i].key=0;
	}
	for(i=n-1;i>=1;i--)
	{
		for(j=i-1;j>=0;j--)
		{
			if(k[i].value<k[j].value)
			{
				k[j].key++;
			}
			else
			{
				k[i].key++;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		j=k[i].key;
		s[j].key=k[i].key;
		s[j].value=k[i].value;
	}
	for(i=0;i<n;i++)
	{
		cout<<"s["<<s[i].key<<"]= "<<s[i].value<<"\n";
	}
	delete[] k;
	delete[] s;
	getch();
}
