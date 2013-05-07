/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-02-01 20:18
 # Filename: HDU3911 Black And White.cpp
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
  //lb_sum, lw_sum 以左端点为起点最长的黑/白长度
  //rb_sum, rw_sum 以右端点为起点最长的黑/白长度
  //b_sum, w_sum [l,r)中最长的黑/白长度
  //len [l,r)的长度
  //xor 是否进行取反, 在g++编译器中换名字
	int l,r,lb_sum,lw_sum,rb_sum,rw_sum,b_sum,w_sum,len;
  bool xor;
}node[MAX*4];

int num[MAX];

void init()
{
	memset(node,'\0',sizeof(node));
	memset(num,0,sizeof(num));
}

void update_node(const int &t)
{
	node[t].lw_sum=node[L(t)].lw_sum+(node[L(t)].len==node[L(t)].lw_sum ?
    node[R(t)].lw_sum:0);
	node[t].rw_sum=node[R(t)].rw_sum+(node[R(t)].len==node[R(t)].rw_sum ?
    node[L(t)].rw_sum:0);
	node[t].w_sum=max(node[L(t)].w_sum,node[R(t)].w_sum);
	if(node[L(t)].rw_sum && node[R(t)].lw_sum)
		node[t].w_sum=max(node[t].w_sum,node[L(t)].rw_sum+node[R(t)].lw_sum);

  node[t].lb_sum=node[L(t)].lb_sum+(node[L(t)].len==node[L(t)].lb_sum ?
    node[R(t)].lb_sum:0);
  node[t].rb_sum=node[R(t)].rb_sum+(node[R(t)].len==node[R(t)].rb_sum ?
    node[L(t)].rb_sum:0);
  node[t].b_sum=max(node[L(t)].b_sum,node[R(t)].b_sum);
  if(node[L(t)].rb_sum && node[R(t)].lb_sum)
    node[t].b_sum=max(node[t].b_sum,node[L(t)].rb_sum+node[R(t)].lb_sum);
}

void build(const int &t , const int &l,const int &r)
{
	node[t].l=l;
	node[t].r=r;
	node[t].len=r-l;
  node[t].xor=false;
  if(l==r-1)
  {
	  if(num[l])
		  node[t].lb_sum=node[t].rb_sum=node[t].b_sum=1;
	  else
		  node[t].lw_sum=node[t].rw_sum=node[t].w_sum=1;
    return;
  }
	int mid=(l+r)>>1;
	build(L(t),l,mid);
	build(R(t),mid,r);
	update_node(t);
}

void change_node(const int &t)
{
  swap(node[t].lw_sum , node[t].lb_sum);
  swap(node[t].rw_sum , node[t].rb_sum);
  swap(node[t].w_sum , node[t].b_sum);
}

void godown(const int &t)
{
  if( node[t].l==node[t].r-1)
  {
    //整体操作的粗粒度为2,即[l,r)的最短长度为2
    return;
  }
  if(node[t].xor)
  {
    node[L(t)].xor = !node[L(t)].xor;
    node[R(t)].xor = !node[R(t)].xor;
    node[t].xor = !node[t].xor;
    change_node(L(t));
    change_node(R(t));
  }
}
void update(const int &t, const int &l,const int &r)
{
  godown(t);
  if(node[t].l>=l && node[t].r<=r)
  {
    node[t].xor = !node[t].xor;
    change_node(t);
    return;
  }
	if(node[t].l == node[t].r-1)
    return;
  
  int mid=(node[t].l+node[t].r)>>1;
  if(l<=mid)
    update(L(t),l,r);
  if(r>mid)
    update(R(t),l,r);
  update_node(t);
}

int query(const int &t,const int &l,const int &r)
{
  godown(t);

	if(node[t].l>=l && node[t].r<=r)
		return node[t].b_sum;

	if(node[t].l==node[t].r-1)
		return 0;

	int mid = (node[t].l+node[t].r)>>1;
  int ans=0;
  if(l>=mid)
	  ans =  query(R(t),l,r);
  else if(r<mid)
	  ans = query(L(t),l,r);
  else
  {
	  ans=max(query(L(t),l,mid),query(R(t),mid,r));
	  if(node[L(t)].rb_sum && node[R(t)].lb_sum)
      {  
        int sum=0;
        //注意边界及覆盖情况
        sum+=min(node[L(t)].rb_sum,mid-l);
        sum+=min(node[R(t)].lb_sum,r-mid);
        ans = max(sum,ans);  
      }  
  }
  update_node(t);
  return ans;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m;
  int q,x,y;

  while(~scanf("%d",&n) &&n)
  {
	  init();
	  for(int i=0;i<n;++i)
		  scanf("%d",&num[i]);
	  build(1,0,n);

	  scanf("%d",&m);
	  while(m--)
	  {
		  scanf("%d%d%d",&q,&x,&y);
		  if(q==0)
		  {
			  int ans=query(1,x-1,y);
			  printf("%d\n",ans);
		  }
		  else
			  update(1,x-1,y);
	  }
  }

  return 0;
}
