#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;
int main()
{
	int i,j,n,*k,*count,*s;
	do
	{
		puts("Enter number of elements");
		cin>>n;
	}
	while(n<=0);
	k=new int[n];
	count=new int[n];
	s=new int[n];
	for(i=0;i<n;i++)
	{
		cout<<"Enter element #"<<i+1<<"\n";
		cin>>k[i];
		count[i]=0;
	}
	for(i=n-1;i>=1;i--)
	{
		for(j=i-1;j>=0;j--)
		{
			if(k[i]<k[j])
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
		s[j]=k[i];
	}
	for(i=0;i<n;i++)
	{
		cout<<"s["<<i<<"]= "<<s[i]<<"\n";
	}
	delete[] k;
	delete[] count;
	delete[] s;
	getch();
}
