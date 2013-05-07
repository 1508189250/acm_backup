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

struct NODE
{
	int beg,end,id;
	bool operator<(const NODE &tmp) const 
	{
		if(end==tmp.end)
			return beg<tmp.beg;
		else
			return end<tmp.end;
	}
}node[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncase=1;
  //   scanf("%d",&ncase);

  while(~scanf("%d",&n) && n)
  {

		for(int i=0;i<n;++i)
    {
			scanf("%d%d",&node[i].beg,&node[i].end);
      node[i].id=i+1;
    }

		sort(node,node+n);
    printf("%d",node[0].id);
		int end=node[0].end;
		for(int i=0;i<n;++i)
			if(end<=node[i].beg)
			{
				printf(" %d",node[i].id);
				end=node[i].end;
			}
		printf("\n");
  }

  return 0;
}
