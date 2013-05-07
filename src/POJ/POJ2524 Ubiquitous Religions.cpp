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
#define MAX 50010
using namespace std;

int pre[MAX];

int inline find(const int &x)
{
	return x==pre[x]?x:find(pre[x]);
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int n,k,x,y;
	int ncases=1;

	while(scanf("%d %d",&n,&k) && (n||k))
	{
		for(int i=1;i<=n;++i)
			pre[i]=i;

		for(int i=0;i<k;++i)
		{
			scanf("%d%d",&x,&y);
			int a=find(x),b=find(y);
			pre[x]=pre[y]=pre[a]=pre[b]=min(a,b);
		}

		int ans=0;
		for(int i=1;i<=n;++i)
			if(i==pre[i])
				++ans;
		printf("Case %d: %d\n",ncases++,ans);

	}

  return 0;
}
