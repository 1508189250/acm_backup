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

double array[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int ncases,n;
	scanf("%d",&ncases);

	while(ncases--)
	{
		scanf("%d",&n);
		double sum=0.0;
		for(int i=0;i<n;++i)
		{
			scanf("%lf",&array[i]);
			sum+=array[i];
		}
		sum/=n;
		int ans=0;
		for(int i=0;i<n;++i)
			if(array[i]>sum)
				++ans;
		printf("%.3lf%%\n",static_cast<double>(ans*100)/n);
	}

  return 0;
}
