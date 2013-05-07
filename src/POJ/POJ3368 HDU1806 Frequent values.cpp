/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-31 22:41
 # Filename: POJ3368 HDU1806 Frequent values.cpp
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
  //分别为左端点, 右端点, l对应的输入的数值, r-1对应的输入的数值, 
  //左端点向右对应的连续的长度, 右端点向左对应的连续的长度, 
  //[l, r)区间对应的最长的连续长度, 总体的长度
	int l,r,lval,rval,lsum,rsum,sum,len;
}node[MAX*4];

int num[MAX];

void init()
{
	memset(node,'\0',sizeof(node));
	memset(num,0,sizeof(num));
}

void update_node(const int &t)
{
	
	node[t].lsum=node[L(t)].lsum+(node[L(t)].len==node[L(t)].lsum && node[L(t)].rval==node[R(t)].lval?
    node[R(t)].lsum:0);
	node[t].rsum=node[R(t)].rsum+(node[R(t)].len==node[R(t)].rsum && node[R(t)].lval==node[L(t)].rval?
    node[L(t)].rsum:0);
	node[t].sum=max(node[L(t)].sum,node[R(t)].sum);
	if(node[L(t)].rval==node[R(t)].lval)
		node[t].sum=max(node[t].sum,node[L(t)].rsum+node[R(t)].lsum);
	node[t].lval=node[L(t)].lval;
	node[t].rval=node[R(t)].rval;
}

void build(const int &t , const int &l,const int &r)
{
	node[t].l=l;
	node[t].r=r;
  node[t].len=r-l;
  if(l==r-1)
  {
    node[t].lval=node[t].rval=num[node[t].l];
    node[t].sum=node[t].lsum=node[t].rsum=1;
    return;
  }
	int mid=(l+r)>>1;
	build(L(t),l,mid);
	build(R(t),mid,r);
	update_node(t);
}

int query(const int &t,const int &l,const int &r)
{
	if(node[t].l>=l && node[t].r<=r)
		return node[t].sum;
	if(node[t].l==node[t].r-1)
		return 1;
	int mid = (node[t].l+node[t].r)>>1;
  if(l>=mid)
	  return query(R(t),l,r);
  else if(r<mid)
	  return query(L(t),l,r);
  else
  {
	  int ans=max(query(L(t),l,mid),query(R(t),mid,r));
	  if(node[L(t)].rval==node[R(t)].lval)
      {  
        int sum=0;
        //注意边界及覆盖情况
        sum+=min(node[L(t)].rsum,mid-l);
        sum+=min(node[R(t)].lsum,r-mid);
        ans = max(sum,ans);  
      }  
	  return ans;
  }
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m;
  int x,y;

  while(scanf("%d",&n) &&n)
  {
	  scanf("%d",&m);
	  init();
	  for(int i=0;i<n;++i)
		  scanf("%d",&num[i]);
	  build(1,0,n);
	  while(m--)
	  {
		  scanf("%d%d",&x,&y);
		  int ans=query(1,x-1,y);
		  printf("%d\n",ans);
	  }
  }

  return 0;
}
