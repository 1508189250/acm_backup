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
#include <stack>
using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int ncases,n,m,a,b;

	scanf("%d",&ncases);
	while(ncases--)
	{
		stack<int> stk[4];

		scanf("%d%d",&n,&m);
		for(int i=n;i>=1;--i)
			stk[1].push(i);

		int flag=0,step;
		for(int i=1;i<=m;++i)
		{
			scanf("%d%d",&a,&b);
			if(flag)
				continue;

			if(!stk[a].empty() && (stk[b].empty()|| stk[b].top()>stk[a].top()))
			{
				stk[b].push(stk[a].top());
				stk[a].pop();
			}
			else
			{
				flag=-1;
				step=i;
			}

			if(stk[3].size()==n)
			{
				flag=1;
				step=i;
			}
		}
    printf("%d\n",flag>0?step:(flag==0?0:-step));
	}

  return 0;
}
