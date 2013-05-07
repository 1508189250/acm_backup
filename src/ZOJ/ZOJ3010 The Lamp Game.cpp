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
#include <vector>
#include <stack>
#define MAX 1<<12
using namespace std;

double cost[11],remain[MAX];
vector<int> vec[11];
stack<int> stk;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int n,m,t,temp;

	while(~scanf("%d%d",&n,&m) &&(n||m))
	{
    while(!stk.empty())
     stk.pop();
    int up=1<<n;
		for(int i=0;i<up;++i)
			remain[i]=0.0;
		remain[up-1]=m;

		stk.push(up-1);

		for(int i=0;i<n;++i)
		{
			vec[i].clear();
			scanf("%d",&t);
			while(t--)
			{
				scanf("%d",&temp);
				vec[i].push_back(temp-1);
			}
			scanf("%lf",&cost[i]);
			cost[i]=1-cost[i]/100.0;
		}

		while(!stk.empty())
		{
			int x=stk.top();
			stk.pop();

			for(int i=0;i<n;++i)
				if(x>>i | 1)
				{
					int state=x^(1<<i);
					double left=remain[x]*cost[i];
					for(size_t j=0;j<vec[i].size();++j)
					{
						state = state^(1<<vec[i][j]);
// 						left*=cost[vec[i][j]];
          }
          if(remain[state]<left)
          {
					  remain[state]=left;
					  stk.push(state);
          }
				}
    }
    if(remain[0]<1e-6)
      printf("-1\n");
    else
      printf("%.2lf\n",remain[0]);
		
	}

  return 0;
}
