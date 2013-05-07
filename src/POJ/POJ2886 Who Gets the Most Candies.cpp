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
#include <vector>
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define MAX 500010
using namespace std;

struct NODE
{
	int l,r,val;
}node[MAX<<3];

struct CHILD{
  char name[20];
  int val;
}children[MAX];

int anti_pri[MAX];

void ap(void)
{
	memset(anti_pri,0,sizeof(anti_pri));
	for(int i=1;i<MAX;++i)
		for(int j=1;i*j<MAX;++j)
			++anti_pri[i*j];
}

void init()
{
	memset(node,'\0',sizeof(node));
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

int query(const int &t,const int &l,const int &r)
{
  if(node[t].l>=l && node[t].r<=r) return node[t].val;
  int mid = (node[t].l+node[t].r)>>1;
  int ans = 0;  
  if( l <= mid )  
    ans += query(L(t),l,r);  
  if( r > mid )  
    ans += query(R(t),l,r);  
  return ans;  
}

void update(const int &t,int val,int *pos)
{
	--node[t].val;
	if(node[t].l==node[t].r-1)
  {
    *pos=node[t].l;
    return;
	}
  if(node[L(t)].val>val)
    update(L(t),val,pos);
  else
    update(R(t),val-node[L(t)].val,pos);
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,k;
  ap();
  while(~scanf("%d%d",&n,&k))
  {
	  init();
	  build(1,0,n);
	  for(int i=0;i<n;++i)
		  scanf("%s %d",children[i].name,&children[i].val);
    int ind=0,ans=0,kick=k-1,pos,mark=0,hole=n;
    do 
    {
      update(1,kick,&pos);
      ++mark;
      --hole;
      if(anti_pri[mark]>ans)
      {
        ans=anti_pri[mark];
        ind=pos;
      }
      if(!hole)
        break;

      int left=0;
      if(pos>0)
        left=query(1,0,pos);
      if(children[pos].val>0)
        kick=(left+children[pos].val%hole-1+hole)%hole;
      else
        kick=(left+children[pos].val%hole+hole)%hole;
    } while (hole);

      printf("%s %d\n",children[ind].name,ans);
  }
  return 0;
}