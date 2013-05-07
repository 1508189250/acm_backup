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
#define MAX 110
using namespace std;

int map[MAX][MAX];		//�ڽӾ���
int used[MAX];				//��ÿ��������·�������ڼ�¼��ǰ�ڵ��Ƿ�������·����
int mat[MAX];				//�����ڵ��Ӧ��ƥ����
int m,n;

bool find(const int &x)		//��x��ʼ�Ƿ�������·
{
  int i;
  for(i=1;i<=n;++i)
  {
    if(!map[x][i] && !used[i])		//��x��i�б�������i���ڵ�ǰ������·��
    {
      used[i]=1;
      if(!mat[i] || find(mat[i]))	//��iû��ƥ������i��ƥ���ʼ������·
      {
        mat[i]=x;
        return true;
      }
    }
  }
  return false;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  //   scanf("%d",&ncase);
	int u,v;

  while(~scanf("%d",&n) && n)
  {
		memset(map,0,sizeof(map));
		memset(mat,0,sizeof(mat));
		for(u=1;u<=n;++u)
			while(scanf("%d",&v) && v)
				map[u][v]=1;
    for(int i=1;i<=n;++i)
      for(int j=i+1;j<=n;++j)
        if(!(map[u][v]&&map[v][u]))
          map[u][v]=map[v][u]=0;

		int ans=0;
		for(int i=1;i<=n;++i)
		{
			memset(used,0,sizeof(used));
			if(find(i))
				++ans;
		}
		printf("%d\n",ans);
  }

  return 0;
}
