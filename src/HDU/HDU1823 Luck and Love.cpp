/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-02-04 21:05
 # Filename: HDU1823 Luck and Love.cpp
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
#define MAX 110
#define INF 1e-6
using namespace std;

struct CNODE
{
  int l,r,max;
  int getlen(){return r-l;};
  int getmid(){return (l+r)>>1;};
  void set(const int &lhs,const int &rhs){l=lhs;r=rhs;}
};
struct NODE
{
  int l,r;
  CNODE child[(10*MAX)<<2];
  int getlen(){return r-l;};
  int getmid(){return (l+r)>>1;};
  void set(const int &lhs,const int &rhs){l=lhs;r=rhs;}
}node[MAX<<2];

void init()
{
  memset(node,'\0',sizeof(node));
}

void sub_build(const int &f,const int &t , const int &l,const int &r)
{
  node[f].child[t].set(l,r);
  node[f].child[t].max=-10;
  if(l==r-1)
  {
    if(node[f].getlen()==1)
      node[f].child[t].max=-10;
    else
      node[f].child[t].max=max(node[L(f)].child[t].max,node[R(f)].child[t].max);
    return;
  }
  int mid=(l+r)>>1;
  sub_build(f,L(t),l,mid);
  sub_build(f,R(t),mid,r);      
  node[f].child[t].max=max(node[f].child[L(t)].max,node[f].child[R(t)].max);
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
  if(p[t].l>=l && p[t].r<=r)
  {
    p[t].max=max(val,p[t].max);
    return;
  }
  if(p[t].getlen()==1)
  {
    p[t].max=val;
    return;
  }
  int mid=p[t].getmid();
  if(l<mid)
    sub_update(p,L(t),l,r,val);
  if(r>mid)
    sub_update(p,R(t),l,r,val);
  p[t].max =max(p[L(t)].max,p[R(t)].max);
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
    return p[t].max;
  int mid=p[t].getmid();
  int ans=-10;
  if(l<mid)
    ans = max(ans,sub_query(p,L(t),l,r));
  if(r>mid)
    ans = max(ans,sub_query(p,R(t),l,r));
  return ans;
}
int query(const int &t,const int &l1,const int &r1,const int &l2,const int &r2)
{
  if(node[t].l>=l1 && node[t].r<=r1)
    return sub_query(node[t].child,1,l2,r2);
  if(node[t].l==node[t].r-1) return -10;
  int mid=node[t].getmid();
  int ans=-10;
  if(l1<mid) ans = max(ans,query(L(t),l1,r1,l2,r2));
  if(r1>mid)  ans = max(ans,query(R(t),l1,r1,l2,r2));
  return ans;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n;
  int n_h,l1,r1,l2,r2,val;
  char ch;
  double lf_a,lf_l,lf_a2;

  while(scanf("%d",&n)&&n);
  {
    init();
    build(1,0,101,0,1001);
    while(n--)
    {
      scanf("%c",&ch);
      if(ch=='I')
      {
        scanf("%d%lf%lf",&n_h,&lf_a,&lf_l);
        l1=n_h-100;
        r1=static_cast<int>((lf_a+INF)*10.0);
        val=static_cast<int>((lf_l+INF)*10.0);
        update(1,l1,l1+1,r1,r1+1,val);
      }
      else if(ch=='Q')
      {
        scanf("%d%d%lf%lf",&l1,&r1,&lf_a,&lf_a2);
        if(l1>r1) swap(l1,r1);
        if(lf_a>lf_a2) swap(lf_a,lf_a2);
        l1-=100;
        r1-=99;
        l2=static_cast<int>((lf_a+INF)*10.0);
        r2=static_cast<int>((lf_a2+INF)*10.0+1.0);
        int ans=query(1,l1,r1,l2,r2);
        if(ans==-10)
          printf("-1\n");
        else
          printf("%.1lf\n",ans/10.0);
      }
      getchar();
    }
  }

  return 0;
}
