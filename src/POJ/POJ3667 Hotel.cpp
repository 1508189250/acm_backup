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
#define MAX 50010
using namespace std;

struct NODE
{
  int l,r,lval,rval,sum;
}node[MAX*4];

void init()
{
  memset(node,'\0',sizeof(node));
}

void build(const int &t , const int &l,const int &r)
{
  node[t].l=l;
  node[t].r=r;
  node[t].lval=node[t].rval=node[t].sum=r-l;
  if(l==r-1)
    return;
  int mid=(l+r)>>1;
  build(L(t),l,mid);
  build(R(t),mid,r);
}

void inline setNode(const int &t,const int &state)
{
  int len=node[t].r-node[t].l;
  node[t].lval=node[t].rval=node[t].sum=len*state;
}

int inline getLen(const int &t)
{
  return node[t].r-node[t].l;
}

void update(const int &t,const int &l,const int &r,const int &state)
{
  const int len=getLen(t);
  if(node[t].l>=l && node[t].r<=r)  //整段设置
  {
    setNode(t,state);
    return;
  }

  if(node[t].sum==len || node[t].sum==0)  //Lazy更新
  {
    int st=0;
    if(node[t].sum)
      st=1;
    setNode(L(t),st);
    setNode(R(t),st);
  }

  int mid=(node[t].l+node[t].r)>>1;
  if(l>=mid)
    update(R(t),l,r,state);
  else if(r<=mid)
    update(L(t),l,r,state);
  else
  {
    update(L(t),l,mid,state);
    update(R(t),mid,r,state);
  }

  node[t].lval=node[L(t)].lval;
  if(node[L(t)].lval==getLen(L(t)))
    node[t].lval+=node[R(t)].lval;
  node[t].rval=node[R(t)].rval;
  if(node[R(t)].rval==getLen(R(t)))
    node[t].rval+=node[L(t)].rval;
  node[t].sum=node[L(t)].rval+node[R(t)].lval;
  node[t].sum=max(node[t].sum,node[L(t)].sum);
  node[t].sum=max(node[t].sum,node[R(t)].sum);
}

int query(const int &t,const int &need)
{
  if(node[t].sum<need)
    return -1;
  if(node[t].l==node[t].r-1)
    return node[t].l;
  if(node[t].lval>=need)
    return node[t].l;
  if(node[L(t)].sum>=need)
    return query(L(t),need);
  else if(node[L(t)].rval+node[R(t)].lval>=need)
    return node[L(t)].r-node[L(t)].rval;
  else 
    return query(R(t),need);
}

int main(void)
{
#ifdef DEBUG  
    freopen("../stdin.txt","r",stdin);
    freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m;
  int s,x,d;

  while(~scanf("%d%d",&n,&m))
  {
    init();
    build(1,0,n);
    while(m--)
    {
      scanf("%d",&s);
      if(s==1)
      {
        scanf("%d",&d);
        int ans=query(1,d);
        printf("%d\n",ans+1);
        if(ans>=0)
          update(1,ans,ans+d,0);
      }
      else
      {
        scanf("%d%d",&x,&d);
        update(1,x-1,x+d-1,1);
      }
    }
  }

  return 0;
}
