/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-09-14 19:30
 * Filename : POJ2309 BST.cpp
 * Description : 
 * *****************************************************************************/
// POJ2309 BST.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
// #define DEBUG

#include <stdio.h>

using namespace std;

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int ncases;
	unsigned int n,pow2[31];
	pow2[0]=1;

	for(int i=1;i<=30;++i)
		pow2[i]=pow2[i-1]<<1;

	scanf("%d",&ncases);

	while(ncases--)
	{
		scanf("%u",&n);
		if(n%2)
		{
			printf("%d %d\n",n,n);
			continue;
		}
		int index=30;
		for(;index>=0;--index)
			if(n%pow2[index]==0)
				break;
		unsigned int sum=pow2[index]-1;;
		printf("%d %d\n",n-sum,n+sum);
	}

	return 0;
}
