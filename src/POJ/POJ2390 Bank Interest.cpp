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

	int r,n;
	double m;

	while(~scanf("%d%lf%d",&r,&m,&n))
	{
		double rate=1.0+r*0.01;
		while(n--)
			m*=rate;
		printf("%d\n",static_cast<int>(m));
	}

  return 0;
}
