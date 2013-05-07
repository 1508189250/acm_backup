/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-26 18:57
 # Filename: POJ2528 Mayor's posters.cpp
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
#include <set>
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define MAX 40010
using namespace std;

struct NODE
{
	int l,r, val;
}node[MAX*4],order[MAX];

set<int> set_result;

void init()
{
	memset(node,'\0',sizeof(node));
	memset(order,'\0',sizeof(order));
	set_result.clear();
}

void build(const int &t , const int &l,const int &r)
{
  if(l>=r) return;
	node[t].l=l;
	node[t].r=r;
	node[t].val=-1;
  if(l==r-1)
    return;
	int mid=(l+r)>>1;
	build(L(t),l,mid);
	build(R(t),mid,r);
}

void update(const int &t,const int &l,const int &r,const int &val)
{
	if(node[t].l>=l && node[t].r<=r)
  {
		node[t].val=val;
		return;
  }
	if(node[t].val>=0 )
	{
		node[R(t)].val = node[L(t)].val = node[t].val;
		node[t].val=-1;
	}
	int mid=(node[t].l+node[t].r)>>1;
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

void query(const int &t,const int &l,const int &r)
{
	if(node[t].val>=0)
	{
		set_result.insert(node[t].val);
		return;
	}
  if(l==r-1)
    return;
	int mid = (node[t].l+node[t].r)>>1;
	if(l>=mid)
		query(R(t),l,r);
	else if(r<=mid)
		query(L(t),l,r);
	else 
	{
		query(L(t),l,mid);
		query(R(t),mid,r);
	}
}

void func(int *len,const int &cnt,const int &n)
{
	build(1,0,cnt);
	for(int i=0;i<n;++i)
	{
		int x = lower_bound(len,len+cnt,order[i].l) - len;
		int y = lower_bound(len,len+cnt,order[i].r) - len;
		update(1,x,y+1,order[i].val);
	}
	query(1,0,cnt);
  printf("%d\n",set_result.size());  
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncases;
  int len[MAX];
  scanf("%d",&ncases);

  while(ncases--)
  {
	  scanf("%d",&n);
	  int cnt=0;
	  init();
	  for(int i=0;i<n;++i)
	  {
		  scanf("%d %d",&order[i].l,&order[i].r);
		  len[cnt++]=order[i].l;
      len[cnt++]=order[i].r;
      len[cnt++]=order[i].l-1;
      len[cnt++]=order[i].r+1;
		  order[i].val=i;
	  }
	  sort(len,len+cnt);
	  cnt = unique(len,len+cnt)-len;
	  func(len,cnt,n);
  }

  return 0;
}
