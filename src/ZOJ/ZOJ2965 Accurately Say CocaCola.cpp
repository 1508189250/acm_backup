#ifdef _MSC_VER
#define DEBUG
#endif

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
//#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#define MAX 800
using namespace std;

int num[MAX],min_num[150];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	memset(num,0,sizeof(num));
	for(int i=0;i<150;++i)
		min_num[i]=MAX;
	for(int i=1;i<MAX;++i)
	{
		bool flag=false;
		if(i%7==0)
			flag=true;
		else if(i%10==7)
			flag=true;
		else if((i/10)%10==7)
			flag=true;
		else if((i/100)==7)
			flag=true;
		if(flag)
		{
			num[i]=num[i-1]+1;
			min_num[num[i]]=min(min_num[num[i]],i-num[i]+1);
		}
	}

	int ncases,n;
	scanf("%d",&ncases);
	while(ncases--)
	{
		scanf("%d",&n);
		printf("%d\n",min_num[n]);
	}

  return 0;
}
