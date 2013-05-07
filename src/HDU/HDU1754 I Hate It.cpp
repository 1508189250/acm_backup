/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-17 20:35
 # Filename: HDU1754 I Hate It.cpp
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
#define MAX 200010
using namespace std;

struct NODE_T
{
	int l,r,score;
}node[MAX*4];

void init()
{
	memset(node,'\0',sizeof(node));
}

void build(const int &t,const int &l,const int &r)
{
	node[t].l = l;
	node[t].r = r;
	node[t].score = -1;
	if(l==r-1)
		return;
	int mid=(l+r)>>1;
	build(L(t),l,mid);
	build(R(t),mid,r);
}
void update(const int &t,const int &l,const int &r,const int score)
{
	if(node[t].l==l && node[t].r==r)
	{
		node[t].score = score;
		return;
	}
	int mid = (node[t].l+node[t].r)>>1;
	if( l>=mid)
		update(R(t),l,r,score);
	else if(mid>=r)
		update(L(t),l,r,score);
  node[t].score = max(node[L(t)].score,node[R(t)].score);
}

int query(const int &t,const int &l,const int &r)
{
	if(node[t].l>=l && node[t].r<=r)
		return node[t].score;
	int mid=(node[t].l+node[t].r)>>1;
	if(l>=mid)
		return query(R(t),l,r);
	else if(r<=mid)
		return query(L(t),l,r);
	else
	{
		int a = query(L(t),l,mid);
		int b = query(R(t),mid,r);
		return max(a,b);
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
  char ch;

  while(~scanf("%d%d",&n,&m))
  {
	  init();
	  build(1,0,n+1);
	  for(int i=1;i<=n;++i)
	  {
		  scanf("%d",&x);
		  update(1,i,i+1,x);
	  }
	  while(m--)
    {
      getchar();
		  scanf("%c %d %d",&ch,&x,&y);
		  if(ch=='Q')
			  printf("%d\n",query(1,x,y+1));
		  else
			  update(1,x,x+1,y);
	  }
  }

  return 0;
}
