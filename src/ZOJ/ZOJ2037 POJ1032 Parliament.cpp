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
#define MAX 1010
using namespace std;

int num[MAX];

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
		int cnt=0,tmp=n;
		for(int i=2;;++i)
		{
			if(i>tmp)
				break;
			num[cnt++]=i;
			tmp-=i;
		}

		int t=cnt-1;
		while(tmp--)
    {
      if(t<0)
        t+=cnt;
			++num[(t)%cnt];
      t--;
    }

		for(int i=0;i<cnt;++i)
			printf("%d%c",num[i],i==(cnt-1)?'\n':' ');
    if(ncases)
      printf("\n");
	}

  return 0;
}
