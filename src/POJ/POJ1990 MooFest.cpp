/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-07-06 19:35
 # Filename: POJ1990 MooFest.cpp
 # Description : 
 ******************************************************************************/
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
#define lowbit(x) (x&(-x))
using namespace std;

const int kMAX=20010;

// 树状数组中，count_sum统计的是对于第i头牛的坐标x，在它左边的牛的数目；
// pos_sum统计的是对于第i头牛的坐标x，在它左边的牛的坐标的和
int count_sum[kMAX],pos_sum[kMAX];

__int64 getsum(int x,const int *c)
{
  __int64 sum=0;
  for(int i=x;i>0;i-=lowbit(i))
      sum+=c[i];
  return sum;
}

void updata(int x,const int var,int *c)
{
  for(int i=x;i<kMAX;i+=lowbit(i))
      c[i]+=var;
}

struct NODE{
  int pos,var;
  inline bool operator<(const NODE &tmp) const
  {
    return var<tmp.var;
  }
}node[kMAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n;

  while(~scanf("%d",&n) && n)
  {
    for(int i=0;i<n;++i)
      scanf("%d%d",&node[i].var,&node[i].pos);

    sort(node,node+n);  //先对var从小到大排序，这样使得每次插入的牛都是所有牛中声音最大的
		memset(count_sum,0,sizeof(count_sum));
		memset(pos_sum,0,sizeof(pos_sum));

		__int64 ans=0;
		__int64 total=node[0].pos;
		updata(node[0].pos,1,count_sum);
		updata(node[0].pos,node[0].pos,pos_sum);

		for(int i=1;i<n;++i)
		{
			__int64 left_count=getsum(node[i].pos,count_sum);//在i号牛左边的牛的数目
			__int64 left_sum = getsum(node[i].pos,pos_sum);//在i号牛左边的所有牛的坐标和
			__int64 left_total = node[i].pos * left_count - left_sum;//在i号牛左边的所有牛离i号牛的距离和
			__int64 right_total = total - left_sum - (i-left_count)*node[i].pos;//在i号牛右边的所有牛离i号牛的距离和
			ans+=(left_total+right_total)*node[i].var;

			updata(node[i].pos,1,count_sum);
			updata(node[i].pos,node[i].pos,pos_sum);
			total+=node[i].pos;
		}

		printf("%I64d\n",ans);
  }

  return 0;
}

