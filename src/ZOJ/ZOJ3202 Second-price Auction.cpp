#include "stdafx.h"
#define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>

using namespace std;

int main(void)
{
#ifdef DEBUG  
	freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
	freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int amount[110];
	int first_ind,second_ind;
	int ncases,n;
	scanf("%d",&ncases);

	while(ncases--)
	{
		scanf("%d",&n);
		scanf("%d%d",&amount[0],&amount[1]);
		first_ind=0,second_ind=1;
		if(amount[0]<amount[1])
			swap(first_ind,second_ind);

		for(int i=2;i<n;++i)
		{
			scanf("%d",&amount[i]);
			if(amount[i]>=amount[first_ind])
			{
				second_ind=first_ind;
				first_ind=i;
			}
			else if(amount[i]>amount[second_ind])
				second_ind=i;
		}
		printf("%d %d\n",first_ind+1,amount[second_ind]);
	}

	return 0;
}
