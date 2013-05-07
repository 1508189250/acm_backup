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
	int l,r,val;
  char ch;
	bool operator<(const NODE &tmp) const
	{
	return val<tmp.val;
	}

}node[MAX<<2],order[MAX<<1];

int len[MAX<<2];

void init()
{
	memset(node,'\0',sizeof(node));
  memset(order,'\0',sizeof(order));
}

void build(const int &t , const int &l,const int &r)
{
  if(l>=r) return;
	node[t].l=l;
	node[t].r=r;
	node[t].val=1;
  if(l==r-1)
    return;
	int mid=(l+r)>>1;
	build(L(t),l,mid);
	build(R(t),mid,r);
}

void update(const int &t,const int &l,const int &r,const int &val)
{
  if(val==node[t].val)
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

int color[MAX];

void query(/*int *len,*/const int &t,const int &l,const int &r)
{
	if(node[t].val>0)
	{
// 		int ans= (node[t].val)*(len[node[t].r]-len[node[t].l]);
//     return ans;
    color[node[t].val]=1;
    return;
	}
//   if(l==r-1) 
//     return /*0*/;
	int mid = (node[t].l+node[t].r)>>1;
	if(l>=mid)
		/*return*/ query(/*len,*/R(t),l,r);
	else if(r<=mid)
		/*return*/ query(/*len,*/L(t),l,r);
	else 
	{
		/*return*/ query(/*len,*/L(t),l,mid);
    query(/*len,*/R(t),mid,r);
	}
}

void func(int *len,const int &cnt,const int &n,const int &t)
{
	build(1,0,cnt);
	for(int i=0;i<n;++i)
  {
    int x = lower_bound(len,len+cnt,order[i].l) - len;
    int y = lower_bound(len,len+cnt,order[i].r) - len;
    if(order[i].ch=='C')
    {
		  update(1,x,y+1,order[i].val);
    }
    else
    {	
      for(int i=1;i<=t;++i)
        color[i]=0;
      /*int ans=*/query(/*len,*/1,x,y+1);
      int ans=0;
      for(int i=1;i<=t;++i)
        ans+=color[i];
      printf("%d\n",ans);
    }
	}
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int l,t, n;

  while(~scanf("%d%d%d",&l,&t,&n))
  {
	  int cnt=0;
	  init();
	  for(int i=0;i<n;++i)
	  {
      getchar();
		  scanf("%c %d %d",&order[i].ch,&order[i].l,&order[i].r);
      if(order[i].l>order[i].r)
        swap(order[i].l,order[i].r);

		  len[cnt++]=order[i].l;
		  len[cnt++]=order[i].r;
      if(order[i].ch=='C')
        scanf("%d",&order[i].val);

	  }
	  sort(len,len+cnt);
	  cnt = unique(len,len+cnt)-len;
	  func(len,cnt,n,t);
  }

  return 0;
}

