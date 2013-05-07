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
#define MAX 30
using namespace std;

long long up[MAX][MAX],down[MAX][MAX];
int plank[MAX];

void output(const int &n,long long m)
{
  bool isUp;
	int ind;
	for(int i=1;i<=n;++i)
		plank[i]=i;
  for(int len=n;len>=1;--len)
  {
    if(len==n)
    {
      for(int i=1;i<=len;++i)
			{
        if(m-down[len][i]<=0){
					ind=i;isUp=false; break;
				}
				else
					m-=down[len][i];
				if(m-up[len][i]<=0)
				{
					ind=i;isUp=true;
					break;
				}
				else
					m-=up[len][i];
			}
    }
		else
		{
			if(isUp)
			{
				for(int i=ind;i<=len;++i)
				{
					if(m-down[len][i]<=0)
					{
						ind=i;isUp=false;
						break;
					}
					else
						m-=down[len][i];
				}
			}
			else
			{
				for(int i=1;i<ind;++i)
				{
					if(m-up[len][i]<=0)
					{
						ind=i;isUp=true;
						break;
					}
					else
						m-=up[len][i];
				}
			}
		}

    printf("%d%c",plank[ind],len==1?'\n':' ');
		for(int i=ind;i<len;++i)
			plank[i]=plank[i+1];
  }
// 	printf("\n");
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  up[1][1]=down[1][1]=1ll;

  for(int len=2;len<=20;++len)
    for(int i=1;i<=len;++i)
    {
      for(int j=1;j<i;++j)
        down[len][i]+=up[len-1][j];
      for(int j=i;j<len;++j)
        //因为第i长用来做第一条了，所以余下的只有len-1条，
        //而原来第i+1长的在这里就变成第i长的了
        up[len][i]+=down[len-1][j];
    }

  int n,ncase=1;
  long long m;
  scanf("%d",&ncase);

  while(ncase--)
  {
		scanf("%d%lld",&n,&m);

    output(n,m);
  }

  return 0;
}
