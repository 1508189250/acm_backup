/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-06-12 21:38
 # Filename: ZOJ2507 Let's play a game.cpp
 # Description : 
 ******************************************************************************/
#ifdef _MSC_VER
#define DEBUG
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
using namespace std;

const int kMAX=10010;
const double kEPS=10E-6;

int main(void)
{
#ifdef DEBUG  
	freopen("../stdin.txt","r",stdin);
	freopen("../stdout.txt","w",stdout); 
#endif  

	int n,ncase=1,tmp;
//	scanf("%d",&ncase);

	while(~scanf("%d",&n) && n)
	{
		int sg=0,flag=0;
		while(n--)
		{
			scanf("%d",&tmp);
			sg^=tmp;
			if(tmp>1)
				flag=1;
		}
		if((sg&&flag) || (!sg&&!flag))
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}
