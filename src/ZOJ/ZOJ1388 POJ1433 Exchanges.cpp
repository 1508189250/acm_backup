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
#define MAX 100010
using namespace std;

int pre[15000];

int inline find(const int &x)
{
	return x==pre[x]?x:find(pre[x]);
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int d,m,n,a,b;
  int state[15000];//0表示可靠的，1表示连通的，2表示孤立的；寄存器的状态
  scanf("%d",&d);
  for(int i=1;i<=d;i++)
  {
    scanf("%d %d",&n,&m);
    for(int j=1;j<=n;j++)
			pre[j]=j;

		int sum=0;
    for(int j=1;j<=m;j++)
    {
      scanf("%d %d",&a,&b);
			int x=find(a),y=find(b);
			if(x==1 && y!=1)
				++sum;
			else if(x!=1 && y==1)
				sum+=2;
			else if(x!=1 && y!=1)
				sum+=3;
      pre[a]=pre[b]=pre[x]=pre[y]=1;
    }
    printf("%d\n",sum);
    //if(i<d)printf("\n");
  }
  return 0;
}
