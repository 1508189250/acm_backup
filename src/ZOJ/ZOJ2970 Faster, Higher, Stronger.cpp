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
	char str[20];
	int ncases;
	scanf("%d",&ncases);
	while(ncases--)
	{
		getchar();
		gets(str);
		int n;
		scanf("%d",&n);
		if(str[0]=='F')
		{
			int minvalue=INT_MAX;
			int temp;
			for(int i=0;i<n;++i)
			{
				scanf("%d",&temp);
				minvalue=min(temp,minvalue);
			}
			printf("%d\n",minvalue);
		}
		else
		{
			int minvalue=INT_MIN;
			int temp;
			for(int i=0;i<n;++i)
			{
				scanf("%d",&temp);
				minvalue=max(temp,minvalue);
			}
			printf("%d\n",minvalue);
		}
	}

  return 0;
}
