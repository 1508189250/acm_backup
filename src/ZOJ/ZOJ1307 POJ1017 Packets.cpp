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

int num[7];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  
	
	while(1)
	{
		int sum=0;
		for(int i=1;i<=6;++i)
		{
			scanf("%d",&num[i]);
			sum+=num[i];
		}
		if(sum==0)
			break;

		int ans=num[6]+num[5]+num[4]+num[3]>>2;

		if(num[1]<=num[5]*11)
			num[1]=0;
		else
			num[1]-=num[5]*11;

		if(num[2]<=num[4]*5)
			num[2]=0;
		else
			num[2]-=num[4]*5;

		num[3]=num[3]&3;

	}

  return 0;
}
