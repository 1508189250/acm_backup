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
using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  
	int now,pre,dis;
	int ncase=1;

	while(scanf("%d%d",&dis,&now))
	{
		if(dis>=5280)
			break;
		if(ncase++>1)
			printf("\n");
		pre=0;

		while(1)
		{
			if(now==dis)
			{
				printf("Moving from %d to %d: found it!\n",pre,now);
				break;
			}
			else if(abs(now-dis)==abs(pre-dis))
				printf("Moving from %d to %d: same.\n",pre,now);
			else if(abs(now-dis)<abs(pre-dis))
				printf("Moving from %d to %d: warmer.\n",pre,now);
			else
				printf("Moving from %d to %d: colder.\n",pre,now);
			pre=now;
			scanf("%d",&now);
		}
	}

  return 0;
}
