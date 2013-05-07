/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-30 21:17
 # Filename: ZOJ3279 Ants.cpp
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
#define MAX 100010
using namespace std;

struct NODE
{
	int l,r;
	int sum;
}node[MAX*4];
int num[MAX];

void init()
{
	memset(node,'\0',sizeof(node));
}

void build(const int &t , const int &l,const int &r)
{
	node[t].l=l;
	node[t].r=r;
  if(l==r-1)
  {
	  node[t].sum=num[l];
    return;
  }
	int mid=(l+r)>>1;
	build(L(t),l,mid);
	build(R(t),mid,r);
	node[t].sum=node[L(t)].sum+node[R(t)].sum;
}

void update(const int &t,const int &l,const int &r,const int &val)
{
	if(node[t].l >=l && node[t].r<=r)
  {
		node[t].sum=val;
		return;
  }

  if(node[t].l==node[t].r-1)
    return;

	int mid=(node[t].l+node[t].r)>>1;
	if(l<=mid)
		update(L(t),l,r,val);
	if(r>mid)
		update(R(t),l,r,val);
	node[t].sum=node[L(t)].sum+node[R(t)].sum;
}

int query(const int &t,const int &ind)
{
	if(node[t].l == node[t].r-1)
		return node[t].r;
	int mid = (node[t].l+node[t].r)>>1;
	if(ind<=node[L(t)].sum)
		return query(L(t),ind);
	else
		return query(R(t),ind-node[L(t)].sum);
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,q,a;
  char ch;
  int now;

  while(~scanf("%d",&n))
  {
	  init();
	  for(int i=0;i<n;++i)
		  scanf("%lld",&num[i]);
	  build(1,0,n);
	  scanf("%d",&q);
	  while(q--)
	  {
		  getchar();
		  scanf("%c",&ch);
		  if(ch=='q')
		  {
			  scanf("%d",&now);
			  printf("%d\n",query(1,now));
		  }
		  else
		  {
			  scanf("%d%d",&a,&now);
			  update(1,a-1,a,now);
		  }
	  }
  }

  return 0;
}
