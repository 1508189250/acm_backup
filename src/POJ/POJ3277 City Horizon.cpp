/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-26 20:43
 # Filename: POJ3277 City Horizon.cpp
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
#define MAX 80010
using namespace std;

struct NODE
{
	__int64 l,r, val;
}node[MAX<<2],order[MAX<<1];

__int64 len[MAX<<2];

void init()
{
	memset(node,'\0',sizeof(node));
    memset(order,'\0',sizeof(order));
}

void build(const __int64 &t , const __int64 &l,const __int64 &r)
{
  if(l>=r) return;
	node[t].l=l;
	node[t].r=r;
	node[t].val=0;
  if(l==r-1)
    return;
	__int64 mid=(l+r)>>1;
	build(L(t),l,mid);
	build(R(t),mid,r);
}

void update(const __int64 &t,const __int64 &l,const __int64 &r,const __int64 &val)
{
  if(val<node[t].val)
    return;
	if(l<=node[t].l && node[t].r<=r)
  {
		node[t].val=val;
		return;
  }
  if(node[t].l==node[t].r-1)
    return;
	if(node[t].val>0)
	{
		node[R(t)].val = node[L(t)].val = node[t].val;
		node[t].val=0;
	}
	__int64 mid=(node[t].l+node[t].r)>>1;
	if(l>=mid)
		update(R(t),l,r,val);
	else if(r<=mid)
		update(L(t),l,r,val);
	else
	{
		update(L(t),l,mid,val);
		update(R(t),mid,r,val);
	}
}

__int64 query(__int64 *len,const __int64 &t,const __int64 &l,const __int64 &r)
{
	if(node[t].val>0)
	{
		__int64 ans= (node[t].val)*(len[node[t].r]-len[node[t].l]);
    return ans;
	}
  if(l==r-1) return 0ll;
	__int64 mid = (node[t].l+node[t].r)>>1;
	if(l>=mid)
		return query(len,R(t),l,r);
	else if(r<=mid)
		return query(len,L(t),l,r);
	else 
	{
		return query(len,L(t),l,mid)+query(len,R(t),mid,r);
	}
}

bool inline cmp(const NODE &lhs,const NODE &rhs)
{return lhs.val<rhs.val;};

void func(__int64 *len,const __int64 &cnt,const __int64 &n)
{
	build(1,0,cnt-1);
	for(int i=0;i<n;++i)
	{
		int x = lower_bound(len,len+cnt,order[i].l) - len;
		int y = lower_bound(len,len+cnt,order[i].r) - len;
		update(1,x,y,order[i].val);
	}
	__int64 ans=query(len,1,0,cnt-1);
	printf("%I64d\n",ans);
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  __int64 n;

  while(~scanf("%lld",&n))
  {
	  __int64 cnt=0;
	  init();
	  for(int i=0;i<n;++i)
	  {
		  scanf("%lld %lld %lld",&order[i].l,&order[i].r,&order[i].val);
		  len[cnt++]=order[i].l;
		  len[cnt++]=order[i].r;
	  }
    sort(order,order+n,cmp);
	  sort(len,len+cnt);
	  cnt = unique(len,len+cnt)-len;
	  func(len,cnt,n);
  }

  return 0;
}
