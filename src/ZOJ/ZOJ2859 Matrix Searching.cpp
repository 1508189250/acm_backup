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
#define MAX 310
using namespace std;

struct CNODE
{
	int l,r,min;
  int getlen(){return r-l;};
  int getmid(){return (l+r)>>1;};
  void set(const int &lhs,const int &rhs){l=lhs;r=rhs;}
};
struct NODE
{
  int l,r;
  CNODE child[MAX<<2];
  int getlen(){return r-l;};
  int getmid(){return (l+r)>>1;};
  void set(const int &lhs,const int &rhs){l=lhs;r=rhs;}
}node[MAX<<2];

int num[MAX][MAX];

void init()
{
	memset(node,'\0',sizeof(node));
}

void sub_build(const int &f,const int &t , const int &l,const int &r)
{
  node[f].child[t].set(l,r);
	node[f].child[t].min=INT_MAX;
  if(l==r-1)
  {
    if(node[f].getlen()==1)
      node[f].child[t].min=INT_MAX;//num[node[f].l][l];
    else
      node[f].child[t].min=min(node[L(f)].child[t].min,node[R(f)].child[t].min);
    return;
  }
	int mid=(l+r)>>1;
	sub_build(f,L(t),l,mid);
  sub_build(f,R(t),mid,r);      
  node[f].child[t].min=min(node[f].child[L(t)].min,node[f].child[R(t)].min);
}
void build(const int &t,const int &l1,const int &r1,const int &l2,const int &r2)
{
  node[t].set(l1,r1);
  if(l1==r1-1)
  {
    sub_build(t,1,l2,r2);
    return;
  }
  int mid=(l1+r1)>>1;
  build(L(t),l1,mid,l2,r2);
  build(R(t),mid,r1,l2,r2);
  sub_build(t,1,l2,r2);
}

void sub_update(CNODE *p,const int &t,const int &l,const int &r,const int &val)
{
  p[t].min=min(val,p[t].min);
  if(p[t].l>=l && p[t].r<=r)
      return;
  if(p[t].getlen()==1)
    return;
  int mid=p[t].getmid();
  if(l<mid)
    sub_update(p,L(t),l,r,val);
  if(r>mid)
    sub_update(p,R(t),l,r,val);
}

void update(const int &t,const int &l1,const int &r1,
            const int &l2,const int &r2, const int &val)
{
  sub_update(node[t].child,1,l2,r2,val);
  if(node[t].l>=l1 && node[t].r<=r1)
    return;
  if(node[t].getlen()==1)
    return;
  int mid=node[t].getmid();
  if(l1<mid)
    update(L(t),l1,r1,l2,r2,val);
  if(r1>mid)
    update(R(t),l1,r1,l2,r2,val);
}

int sub_query(CNODE *p,const int &t,const int &l,const int &r)
{
  if(p[t].l>=l && p[t].r<=r)
    return p[t].min;
  if(p[t].l==p[t].r-1) 
    return INT_MAX;
  int mid=p[t].getmid();
  int ans=INT_MAX;
	if(l<=mid)
    ans = min(ans,sub_query(p,L(t),l,r));
  if(r>mid)
    ans = min(ans,sub_query(p,R(t),l,r));
  return ans;
}
int query(const int &t,const int &l1,const int &r1,const int &l2,const int &r2)
{
  if(node[t].l>=l1 && node[t].r<=r1)
    return sub_query(node[t].child,1,l2,r2);
  if(node[t].l==node[t].r-1) return INT_MAX;
  int mid=node[t].getmid();
  int ans=INT_MAX;
  if(l1<=mid) ans = min(ans,query(L(t),l1,r1,l2,r2));
  if(r1>mid)  ans = min(ans,query(R(t),l1,r1,l2,r2));
  return ans;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int ncases,n,m;
  int l1,r1,l2,r2,val;
  memset(num,INT_MAX,sizeof(num));

  scanf("%d",&ncases);
  while(ncases--)
  {
    scanf("%d",&n);
    init();
    build(1,0,n+1,0,n+1);
    for(int i=0;i<n;++i)
      for(int j=0;j<n;++j)
      {
        scanf("%d",&val);
        update(1,i,i+1,j,j+1,val);
      }
    scanf("%d",&m);
    while(m--)
    {
      scanf("%d%d%d%d",&l1,&l2,&r1,&r2);
      int ans=query(1,l1-1,r1,l2-1,r2);
      printf("%d\n",ans);
    }
  }

  return 0;
}