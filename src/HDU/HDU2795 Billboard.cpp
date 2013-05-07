/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-18 20:11
 # Filename: HDU1689 Just a Hook.cpp
 # Description : 
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
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define MAX 200010
using namespace std;

struct NODE
{
	int l,r,sum;
}node[MAX*4];

void init()
{
	memset(node,'\0',sizeof(node));
}

void build(const int &t , const int &l,const int &r,const int &sum)
{
	node[t].l=l;
	node[t].r=r;
	node[t].sum=sum;
  if(l==r-1)
    return;
	int mid=(l+r)>>1;
	build(L(t),l,mid,sum);
	build(R(t),mid,r,sum);
}

int update(const int &t,const int &val)
{
	if(node[t].sum<val)
		return -1;

	if(node[t].l ==node[t].r-1 && node[t].sum>=val)
  {
	  node[t].sum-=val;
		return node[t].r;
  }
	int mid=(node[t].l+node[t].r)>>1;
	int ans=-1;
	if(node[L(t)].sum>=val)
		ans = update(L(t),val);
	else
		ans = update(R(t),val);
	node[t].sum=max(node[L(t)].sum,node[R(t)].sum);
	return ans;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int h,w,n;

  while(~scanf("%d%d%d",&h,&w,&n))
  {
	  init();
	  build(1,0,min(h,n),w);
	  while(n--)
	  {
		  scanf("%d",&w);
		  int ans=update(1,w);
		  printf("%d\n",ans);
	  }
  }

  return 0;
}
