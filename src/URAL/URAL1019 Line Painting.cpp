/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-20 21:28
 # Filename: URAL1019 Line Painting.cpp
 # Description : 
 ******************************************************************************/
#ifdef _MSC_VER
// #define DEBUG
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
#define MAX 100010
using namespace std;

struct NODE
{
	int l,r, val;
}node[MAX*4],order[MAX];

int color[MAX];

void init()
{
	memset(node,'\0',sizeof(node));
  memset(order,'\0',sizeof(order));
	memset(color,0,sizeof(color));
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
	if(node[t].l==l && node[t].r==r)
  {
		node[t].val=val;
		return;
  }
	if(node[t].val>=0 && node[t].val !=val)
	{
		node[R(t)].val = node[t].val;
		node[L(t)].val = node[t].val;
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
		for(int i=node[t].l;i<node[t].r;++i)
			color[i] = node[t].val;
		return;
	}
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
		update(1,x,y,order[i].val);
	}
	query(1,0,cnt);
	color[cnt]=0;
	len[cnt]=1000000000;
  int s = 0,e = 0,te,ts;  
  color[cnt] = !color[cnt-1];  
  len[cnt] = 1000000000;  
  for(int i=0; i<cnt;++i)  
  {  
    ts = len[i];  
    while( color[i] == 0 )  
      i++;  
    te = len[i];  
    if( te - ts > e - s )  
    {  
      e = te;  
      s = ts;  
    }  
  }  
  printf("%d %d\n",s,e);  
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n;
  int x,y;
  char ch;
  int len[MAX];

  while(~scanf("%d",&n))
  {
	  int cnt=0;
	  init();
	  order[0].l=0;
	  order[0].r=1000000000;
	  order[0].val=0;;
	  len[cnt++]=0;
	  len[cnt++]=order[0].r;
	  for(int i=1;i<=n;++i)
	  {
		  scanf("%d %d %c",&order[i].l,&order[i].r,&ch);
		  len[cnt++]=order[i].l;
		  len[cnt++]=order[i].r;
		  if(ch=='b')
			  order[i].val=1;
	  }
	  sort(len,len+cnt);
	  cnt = unique(len,len+cnt)-len;
	  func(len,cnt,n+1);
  }

  return 0;
}
