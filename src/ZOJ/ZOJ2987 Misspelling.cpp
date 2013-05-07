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
	char str[100];
	scanf("%d",&ncases);

	for(int nc=1;nc<=ncases;++nc)
	{
		printf("%d ",nc);
		scanf("%d %s",&n,str);
		--n;
		for(int i=0;i<strlen(str);++i)
			if(i!=n)
				printf("%c",str[i]);
		printf("\n");
	}

  return 0;
}
