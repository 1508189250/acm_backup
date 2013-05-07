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
	int ncases,n;
	int num1[100],num2[100];
	scanf("%d",&ncases);
	while(ncases--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",&num1[i]);
		for(int i=0;i<n;++i)
			scanf("%d",&num2[i]);

		int sflag=true,qflag=true;
		for(int i=0;i<n;++i)
		{
			if(num1[i]!=num2[i])
				qflag=false;
			if(num1[i]!=num2[n-i-1])
				sflag=false;
		}
		if(sflag && qflag)
			printf("both\n");
		else if(sflag)
			printf("stack\n");
		else if(qflag)
			printf("queue\n");
		else 
			printf("neither\n");
	}

  return 0;
}
