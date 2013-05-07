#ifdef _MSC_VER
//#define DEBUG
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
#define EPS 1e-6
using namespace std;


int bob[MAX][2],ralpy[MAX][2];
int map[MAX][MAX],visit[MAX],mat[MAX],next[MAX];
int N,K,ncases,ans[MAX];

int find(const int &u)
{
  int v;
  for(v=0; v<K; ++v)
    if( map[u][v] && !visit[v] )
    {
      visit[v]=1;
      if( mat[v]==-1 || find(mat[v]) )
      {
        mat[v]=u;
        next[u]=v;
        return 1;
      }
    }
    return 0;
}
int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	scanf("%d",&ncases);
//   ncases=1;

	while(ncases--)
	{
    int i,j;
    memset(map,0,sizeof(map));
    scanf("%d %d", &N,&K);
    for(i=0; i<N; ++i) scanf("%d %d", &bob[i][0],&bob[i][1]);
    for(i=0; i<K; ++i) scanf("%d %d", &ralpy[i][0],&ralpy[i][1]);
    for(i=0;i<N-1;++i)
      for(j=0;j<K;++j)
      {
        float len,da,db ;
        len = sqrt( (float)(bob[i][0]-bob[i+1][0])*(bob[i][0]-bob[i+1][0]) + 
          (bob[i][1]-bob[i+1][1])*(bob[i][1]-bob[i+1][1]) );
        da =  sqrt( (float)(bob[i][0]-ralpy[j][0])*(bob[i][0]-ralpy[j][0]) +
          (bob[i][1]-ralpy[j][1])*(bob[i][1]-ralpy[j][1]) );
        db =  sqrt( (float)(bob[i+1][0]-ralpy[j][0])*(bob[i+1][0]-ralpy[j][0]) +
          (bob[i+1][1]-ralpy[j][1])*(bob[i+1][1]-ralpy[j][1]) );
        if(da+db-2*len<EPS) map[i][j]=true;
      }
      memset(next,-1,sizeof(next));
      memset(mat,-1,sizeof(mat));
      int ans=0;
      for(i=0;i<N-1;++i)  // 求二分图的最大匹配
        if( next[i]==-1 )
        {
          memset(visit,0,sizeof(visit));
          ans += find(i);
        }
        printf("%d\n",ans+N);
        for(i=0; i<N; ++i)
        {
          if(i) printf(" ");
          printf("%d %d", bob[i][0],bob[i][1]);
          if( next[i]!=-1 ) printf(" %d %d",ralpy[next[i]][0],ralpy[next[i]][1]);
        }
        puts("");
        if(ncases)
          printf("\n");
//         return 0;
  }

  return 0;
}
