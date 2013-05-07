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
#include <assert.h>
#include <ctype.h>
#define MAX 150000
using namespace std;

int func(int x)
{
	int ans=0;
	while(x)
	{
		++ans;
		x/=10;
	}
	return ans;
}

unsigned int array[MAX];

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
		int num=1,cnt=0,tmp;

		tmp=1;
		while(n>cnt+tmp)
		{
			int t=num;
			for(int i=tmp;i>0;--i)
			{
				array[cnt+i]=t%10;
				t/=10;
			}
			n-=(cnt+tmp);
      assert(n>=0);
			cnt+=tmp;
			tmp=func(++num);
		}

    int t=num;
		for(int i=tmp;i>0;--i)
		{
			array[cnt+i]=t%10;
			t/=10;
		}

		printf("%d\n",array[n]);
	}

  return 0;
}
