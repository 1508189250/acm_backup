#include "stdafx.h"
#define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#define MAX 35
using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int now[MAX],pre[MAX];
	int n,node,conn,len;

	while(~scanf("%d",&n))
	{
		memset(pre,0,sizeof(pre));
		while(n--)
    {
      for(int i=1;i<MAX;++i)
        now[i]=INT_MAX;
			scanf("%d",&node);
			for(int i=1;i<=node;++i)
			{
        int temp=INT_MAX;
				while(scanf("%d",&conn)&&conn)
				{
					scanf("%d",&len);
					temp=min(temp,pre[conn]+len);
				}
        now[i]=temp;
			}
			memcpy(pre,now,sizeof(now));
      if(n)
      {
        getchar();
        getchar();
      }
		}
		int max_len=INT_MAX;
		for(int i=1;i<=node;++i)
			if(max_len>pre[i])
				max_len=pre[i];
		printf("%d\n",max_len);
	}


  return 0;
}
