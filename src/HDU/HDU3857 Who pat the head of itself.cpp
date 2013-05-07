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
#include <queue>
using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,num;
  queue<int> que;

  while(~scanf("%d",&n))
  {
	  for(int i=1;i<=n;++i)
	  {
		  scanf("%d",&num);
		  if(num==i)
        que.push(num);
	  }
    if(que.empty())
      printf("No Mistake\n");
    else
      while(!que.empty())
      {
        printf("%d",que.front());
        que.pop();
        if(que.empty())
          printf("\n");
        else
          printf(" ");
      }
  }

  return 0;
}
