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
#define MAX 210
using namespace std;

struct NODE
{
	int d,p;
// 	bool inline operator<(const NODE &tmp) const
// 	{
// 		if(d==tmp.d)
// 			return p>tmp.p;
// 		else
// 			return d>tmp.d;
//   }
}node[MAX];

int ans[MAX],visit[MAX],nd,np;

void dfs(int *array,const int &ind,const int &n,const int &m,int x,int y)
{
	if(ind==m)
	{
		if(abs(x-y)<abs(nd-np))
		{
			memcpy(ans,array,sizeof(ans));
			nd=x;
			np=y;
		}
    else if((abs(x-y)==abs(nd-np))&&((x+y)>(nd+np)))
    {
      memcpy(ans,array,sizeof(ans));
      nd=x;
      np=y;
    }
		return;
	}

	for(int i=0;i<n;++i)
		if(!visit[i])
		{
			visit[i]=1;
			array[ind]=i;
			dfs(array,ind+1,n,m,x+node[i].d,y+node[i].p);
			visit[i]=0;
		}
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int n,m,ncases=1;
	int array[MAX];
	while(~scanf("%d%d",&n,&m) && (n||m))
	{
		for(int i=0;i<n;++i)
			scanf("%d%d",&node[i].d,&node[i].p);
		memset(ans,0,sizeof(ans));
		memset(visit,0,sizeof(visit));
		memset(array,0,sizeof(array));
		nd=INT_MAX;
		np=0;
		dfs(array,0,n,m,0,0);
		sort(ans,ans+m);
    printf("Jury #%d\nBest jury has value %d for prosecution and value %d for defence:\n",ncases++,nd,np);
		for(int i=0;i<m;++i)
			printf(" %d",ans[i]+1);
    printf("\n\n");
	}
  return 0;
}
