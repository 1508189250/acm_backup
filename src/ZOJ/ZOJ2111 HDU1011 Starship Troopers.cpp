/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-02-03 18:04
 # Filename: ZOJ2111 HDU1011 Starship Troopers.cpp
 # Description : ����DP. dp[x][y]��ʾ������x�����y�˿��Ի�ö�������brain.
 �м����¾����ĵ�û��bug, ����Ҫ������
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
#define MAX 110
using namespace std;

vector<int> vec[MAX];
int bugs[MAX],brains[MAX];
bool visited[MAX];
int dp[MAX][MAX];

void init(const int &n)
{
	memset(visited,false,sizeof(visited));
	memset(dp,0,sizeof(dp));
	for(int i=0;i<=n;++i)
	{
		vec[i].clear();
	}
}

void add(const int &x,const int &y)
{
	vec[x].push_back(y);
	vec[y].push_back(x);
}

void dfs(const int &u, int m)
{
	visited[u]=true;
  int t=(bugs[u]+19)/20; 
  for(int i=t;i<=m;++i)
    dp[u][i]=brains[u];

	for(size_t i=0;i<vec[u].size();++i)
	{
		int v=vec[u][i];
		if(!visited[v])
		{
			dfs(v,m);

      // ���絽��ڵ� u ���� j ��(j>=t),
      // ��������̽ڵ� v ����k��, ������u����j-k��
      // �������һ�ڵ���dp[u][j]=max{dp[u][j-k]+dp[v][k]}; 
      for(int j=m;j>t;--j)
				for(int k=1;j-k>=t;++k)
						dp[u][j] = max(dp[u][j],dp[u][j-k]+dp[v][k]);
		}
	}
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m,x,y;

  while(~scanf("%d%d",&n,&m)&& !(n==-1&&m==-1))
  {
	  init(n);
	  for(int i=1;i<=n;++i)
		  scanf("%d%d",&bugs[i],&brains[i]);
	  for(int i=1;i<n;++i)
	  {
		  scanf("%d%d",&x,&y);
		  add(x,y);
	  }
    if(m==0)
    {
      printf("0\n");
      continue;
    }
	  dfs(1,m);
	  printf("%d\n",dp[1][m]);
  }

  return 0;
}
