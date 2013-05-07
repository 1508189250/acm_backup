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
#include <queue>
#define MAX 100010
using namespace std;


priority_queue<int,vector<int>,greater<int>  > q;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int s,w,c,k,m;

  while(~scanf("%d%d%d%d%d",&s,&w,&c,&k,&m) )
  {
		while(!q.empty())
			q.pop();
		int time=m+s;
		q.push(time);
		for(int i=1;i<k;++i)
		{
			time+=m;
			q.push(time);
		}

		int last_dig=0,remain=9999/c+1;
		while(remain--)
		{
			time=q.top();
			q.pop();
			if(time>last_dig)
			{
				last_dig=time+w;
				time+=(w+s+s);
			}
			else
      {
        last_dig+=w;
				time=last_dig+s+s;
      }
			q.push(time);
		}
		printf("%d\n",last_dig+s);
  }

  return 0;
}
