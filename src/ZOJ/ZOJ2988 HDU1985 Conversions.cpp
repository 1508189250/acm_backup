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
#define MAX 100010
using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int ncases;
	double n;
	char str[5];
	scanf("%d",&ncases);
	
	for(int i=1;i<=ncases;++i)
	{
		printf("%d ",i);
		scanf("%lf %s",&n,str);
		if(strcmp(str,"kg")==0)
		{
			printf("%.4lf lb\n",n*2.2046);
		}
		if(strcmp(str,"lb")==0)
		{
			printf("%.4lf kg\n",n*0.4536);
		}
		if(strcmp(str,"l")==0)
		{
			printf("%.4lf g\n",n*0.2642);
		}
		if(strcmp(str,"g")==0)
		{
			printf("%.4lf l\n",n*3.7854);
		}
// 		printf("\n");
	}

  return 0;
}
