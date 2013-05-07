/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-12-23 18:12
 # Filename: ZOJ2376 POJ1852 Ants.cpp
 # Description : 
 ******************************************************************************/
// #include "stdafx.h"
// #define DEBUG

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
	int ncases,n;
	int len,maxpos,minpos;
	int pos;
	scanf("%d",&ncases);

	while(ncases--)
	{
		maxpos=INT_MIN;
		minpos = INT_MIN;
		scanf("%d%d",&len,&n);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&pos);
			maxpos = max(maxpos,max(pos,len-pos));
			minpos = max(minpos,min(pos,len-pos));
		}
		printf("%d %d\n",minpos,maxpos);
	}


  return 0;
}
