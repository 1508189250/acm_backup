// POJ3628 Bookshelf 2.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <limits.h>
#include <memory>

using namespace std;

int main(void)
{
	int n,c;
	int w[25];

	while(scanf("%d %d",&n,&c)!=EOF)
	{
		int sum=0;
		int *bag;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&w[i]);
			sum+=w[i];
		}
		bag = new int[sum+1];
		memset(bag,0,sizeof(bag));
// 		for(int i=1;i<=c;++i)
// 			bag[i]=0;

		for(int i=1;i<=n;++i)
			for(int k=sum;k>=w[i];--k)
				if (bag[k]<bag[k-w[i]]+w[i])
				{
					bag[k]=bag[k-w[i]]+w[i];
				}

				int min=sum;

				for(int i=c;i<=sum;++i)
					if(min>bag[i]-c && bag[i]>=c)
					{
						min=bag[i]-c;
						break;
					}

					cout<<min<<endl;
					delete []bag;
	}


	return 0;
}
