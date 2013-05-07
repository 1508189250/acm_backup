/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-09-07 15:27
 * Filename : ZOJ2777 POJ2090 Visible Lattice Points.cpp
 * Description : 
 * *****************************************************************************/
// ZOJ2777 POJ2090 Visible Lattice Points.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"

#include <stdio.h>
#include <iostream>

#define MAX 1010

using namespace std;

int gcd(int x,int y)
{
	if(x<y) swap(x,y);
	if(y==0) return x;
	else
		return gcd(y,x%y);
}

int main(void)
{
	int num[MAX];
	int ncases,n;

	num[1]=3;

	for(int i=2;i<MAX;++i)
	{
		int sum=0;
		for(int j=1;j<i;++j)
			if(gcd(i,j)==1)
				sum+=2;
		num[i]=num[i-1]+sum;
	}

	scanf("%d",&ncases);
	for(int i=1;i<=ncases;++i)
	{
		scanf("%d",&n);
		printf("%d %d %d\n",i,n,num[n]);
	}
	return 0;
}

