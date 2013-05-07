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
#define MAX 400010
using namespace std;

int sum[2050],cookie[MAX],minimum[2050],maximum[2050];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m;
  //   scanf("%d",&ncase);

  while(~scanf("%d%d",&n,&m) )
  {
    int win_len=INT_MAX;
    for(int i=0;i<n;++i)
      scanf("%d",&cookie[i]);
    for(int i=1;i<=m;++i)
      scanf("%d%d",&minimum[i],&maximum[i]);

    int left=0,right=0;
    memset(sum,0,sizeof(sum));
    //     sum[cookie[0]]=1;
    while(left<n && right<=n)
    {
      bool less=false,more=false;
      for(int i=1;i<=m;++i)
      {
        if(sum[i]<minimum[i])
        {
          less=true;
          break;
        }
        if(sum[i]>maximum[i])
        {
          more=true;
          break;
        }
      }
      if(less)
      {
        ++sum[cookie[right]];
        ++right;
      }
      else if(more)
      {
        --sum[cookie[left]];
        ++left;
      }
      else
      {
        win_len=min(right-left,win_len);
        --sum[cookie[left]];
        ++left;
      }
    }
    printf("%d\n",win_len==INT_MAX?-1:win_len);
  }

  return 0;
}
