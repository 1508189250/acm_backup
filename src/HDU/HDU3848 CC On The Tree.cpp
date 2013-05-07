/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-02-03 17:16
 # Filename: HDU3848 CC On The Tree.cpp
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
#include <vector>
#define MAX 10010
#define INF INT_MAX
using namespace std;

struct NODE
{
	int to,len;
}nd_temp;

vector<NODE> vec[MAX];
int dp_f[MAX],dp_s[MAX];

void init(const int &n)
{
	for(int i=0;i<n;++i)
	{
		vec[i].clear();
		dp_f[i]=dp_s[i]=INF;
	}
}

void dfs(const int &now,const int &pre)
{
	if(vec[now].size()==1)
	{
		dp_f[now]=0;
		return;
	}
	for(size_t i=0;i<vec[now].size();++i)
	{
		int v=vec[now][i].to;
		int len=vec[now][i].len;
		if(v==pre)
			continue;
		dfs(v,now);
		if(dp_f[now]-dp_f[v]>len)
		{
			dp_s[now]=dp_f[now];
			dp_f[now]=dp_f[v]+len;
		}
		else if(dp_s[now]-dp_f[v]>len)
			dp_s[now]=dp_f[v]+len;
	}
}

void add(const int &from,const int &to,const int &len)
{
	nd_temp.to=to;
	nd_temp.len=len;
	vec[from].push_back(nd_temp);
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  
  int n;
  int x,y,len;

  while(~scanf("%d",&n)&&n)
  {
	  init(n);
	  for(int i=1;i<n;++i)
	  {
		  scanf("%d%d%d",&x,&y,&len);
      --x; --y;
		  add(x,y,len);
		  add(y,x,len);
	  }
    if(n==2)
    {
      printf("%d\n",len);
      continue;
    }
    for(x=0;x<n;++x)
      if(vec[x].size()>1)
        break;
	  dfs(x,-1);
	  int ans=INF;
	  for(int i=0;i<n;++i)
      if(dp_f[i] !=0 && dp_s[i]!=0 && dp_f[i]!=INF && dp_s[i]!=INF)
  		  ans=min(ans,dp_f[i]+dp_s[i]);
	  printf("%d\n",ans);
  }

  return 0;
}
