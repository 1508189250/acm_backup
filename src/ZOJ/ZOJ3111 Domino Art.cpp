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
#define MAX 70
using namespace std;

char board[MAX][MAX];
vector<int> edge[MAX*MAX];
int diff[4]={1,0,0,1};
int mat[MAX*MAX*2],used[MAX*MAX*2];
int n,m,ncase=1;

bool find(const int &x)
{
  for(int i=0;i<edge[x].size();++i)
  {
    int v=edge[x][i];
    if(!used[v])
    {
      used[v]=1;
      if(mat[v]==-1 || find(mat[v]))
      {
        mat[v]=x;
//         mat[x]=v;
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


  memset(board,'.',sizeof(board));

  while(~scanf("%d%d",&n,&m) && (n+m))
  {
    getchar();
    for(int i=1;i<=n;++i)
    {
      gets(board[i]+1);
      board[i][m+1]='.';
    }
    for(int i=0;i<=n*m;++i)
      edge[i].clear();

    int sharp=0;
    for(int i=1;i<=n;++i)
      for(int j=1;j<=m;++j)
        if(board[i][j]=='#')
        {
          ++sharp;
          for(int k=0;k<4;k+=2)
          {
            int a=i+diff[k];
            int b=j+diff[k+1];
            if(board[a][b]=='#')
            {
              edge[(i-1)*m+j-1].push_back((a-1)*m+b-1+m*n);
              edge[(a-1)*m+b-1].push_back((i-1)*m+j-1+m*n);
            }
          }
        }
          memset(mat,-1,sizeof(mat));
          int ans=0;
          for(int i=0;i<n*m;++i)
            if(mat[i]==-1)
            {
              memset(used,0,sizeof(used));
              if(find(i))
                ++ans;
            }
//             printf("%d\n",ans);
            printf("Case %d: ",ncase++);
            if(ans==sharp)
              printf("Possible\n");
            else
              printf("Impossible\n");
  }

  return 0;
}
