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
#include <queue>
#define MAX 30010
using namespace std;

int add[MAX],get[MAX];
priority_queue<int> max_root_q;
priority_queue<int, vector<int>, greater<int> > min_root_q;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m;
  int ncases;
  scanf("%d",&ncases);

  while(ncases--)
  {	

    while(!max_root_q.empty())
      max_root_q.pop();
    while(!min_root_q.empty())
      min_root_q.pop();

    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;++i)
      scanf("%d",&add[i]);
    for(int i=1;i<=n;++i)
      scanf("%d",&get[i]);

    int cnt=1,ind=1;
    for(int i=1;i<=n;++i)
    {
      while(cnt!=get[i]+1)
      {
        if(!max_root_q.empty() && max_root_q.top()>add[cnt])
          max_root_q.push(add[cnt++]);
        else
          min_root_q.push(add[cnt++]);
      }

      int tmp=ind-max_root_q.size();
      if(tmp<0)
        while(tmp!=0)
        {
          min_root_q.push(max_root_q.top());
          max_root_q.pop();
          ++tmp;
        }
      else
        while(tmp!=0)
        {
          max_root_q.push(min_root_q.top());
          min_root_q.pop();
          --tmp;
        }
        printf("%d\n",max_root_q.top());
        ++ind;
    }
    if(ncases)
      printf("\n");
  }

  return 0;
}
