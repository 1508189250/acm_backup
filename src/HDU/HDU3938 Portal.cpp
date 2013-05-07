/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-02-07 17:37
 # Filename: HDU3938 Portal.cpp
 # Description : 
 ******************************************************************************/
#ifdef _MSC_VER
#define DEBUG
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
#define MAX 50000
using namespace std;

struct EDGE
{
	int u,v,len;
	bool inline operator < (const EDGE &rhs) const
	{
		return len<rhs.len;
	}
}edge[MAX];

struct QUERY
{
	int q,ind; 
	bool inline operator < (const QUERY &rhs) const
	{
		return q<rhs.q;
	}
}query[MAX];

int pre[MAX], num[MAX], ans[MAX];
int inline find(const int &x)
{
	return x==pre[x]?x:find(pre[x]);
}

void init(const int &n)
{
	for(int i=1;i<=n;++i)
	{
		num[i]=1;
		pre[i]=i;
	}
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m,q;
  while(~scanf("%d%d%d",&n,&m,&q))
  {
	  init(n);
	  for(int i=0;i<m;++i)
		  scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].len);
	  sort(edge,edge+m);
	  for(int i=0;i<q;++i)
	  {
		  scanf("%d",&query[i].q);
		  query[i].ind=i;
	  }
	  sort(query,query+q);

	  int cnt=0;
    int ind=0;
    for(int i=0;i<q;++i)
    {
      while(edge[ind].len<=query[i].q && ind<m)
      {
        int a=find(edge[ind].u);
        int b=find(edge[ind].v);
        if(a>b) swap(a,b);
        if(a!=b) 
        {
          cnt+=num[a]*num[b];        
          num[a]+=num[b];
        }
        pre[a]=pre[b]=pre[edge[ind].u]=pre[edge[ind].v]=a;
        ++ind;
      }
      ans[query[i].ind]=cnt;
    }
	  for(int i=0;i<q;++i)
		  printf("%d\n",ans[i]);
  }

  return 0;
}
