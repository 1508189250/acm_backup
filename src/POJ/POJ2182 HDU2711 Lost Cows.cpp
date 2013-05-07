/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-30 20:20
 # Filename: POJ2182 HDU2711 Lost Cows.cpp
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
#include <stack>
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define MAX 8010
using namespace std;

struct NODE
{
	int l,r,val;
}node[MAX*4];

stack<int> stk;

void init()
{
	memset(node,'\0',sizeof(node));
	while(!stk.empty())
		stk.pop();
}

void build(const int &t , const int &l,const int &r)
{
	node[t].l=l;
	node[t].r=r;
	node[t].val=r-l;
  if(l==r-1)
    return;
	int mid=(l+r)>>1;
	build(L(t),l,mid);
	build(R(t),mid,r);
}

void update(const int &t,const int &val)
{
  --node[t].val;
	if(node[t].l == node[t].r-1)
  {
	  stk.push(node[t].l);
		return;
  }
	if(node[L(t)].val>val)
		update(L(t),val);
	else
		update(R(t),val-node[L(t)].val);
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int num[MAX],n;

  while(~scanf("%d",&n))
  {
	  num[0]=0;
	  for(int i=1;i<n;++i)
		  scanf("%d",&num[i]);
	  init();
	  build(1,0,n);
	  for(int i=n-1;i>=0;--i)
		  update(1,num[i]);
	  while(!stk.empty())
	  {
		  printf("%d\n",stk.top()+1);
		  stk.pop();
	  }
  }

  return 0;
}
