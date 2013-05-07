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

	int ncases,n,tmp;
	scanf("%d",&ncases);
	while(ncases--)
	{
		int t_max=INT_MIN,t_min=INT_MAX;
		scanf("%d",&n);

		while(n--)
		{
			scanf("%d",&tmp);
			t_max=max(t_max,tmp);
			t_min=min(t_min,tmp);
		}

		printf("%d\n",(t_max-t_min)*2);

	}

  return 0;
}
