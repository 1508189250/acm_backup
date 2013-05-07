/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-25 18:57
 # Filename: POJ1177 HDU1828 Picture.cpp
 # Description : 线段树求矩形并
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
#define MAX 5010
using namespace std;

//length当前节点子树覆盖的长度
//num，当前节点子树中被分为多少段不连续的小段，用于计算平行于X轴的线段长度
//cover，标记当前节点是否被覆盖
//lb，rb，标记当前节点的左端点和右端点是否被覆盖，找num的数量需要用到。
struct T_NODE
{
	int l,r,length,cover,num;	
	bool lb,rb;
}node[MAX<<2];

struct LINE
{
	int x,y1,y2,flag;
}line[MAX<<1];

int y_coord[MAX<<1];

void add_line(const int &x1,const int &x2,const int &y1,const int &y2,int &cnt)
{
	line[cnt].x=x1;	line[cnt].y1=y1; line[cnt].y2=y2; line[cnt].flag=1;
	y_coord[cnt++]=y1;
	line[cnt].x=x2;	line[cnt].y1=y1; line[cnt].y2=y2; line[cnt].flag=-1;
	y_coord[cnt++]=y2;
}

bool inline cmp(const LINE &lhs,const LINE &rhs)
{
	return lhs.x<rhs.x;
}

void init()
{
	memset(node,0,sizeof(node));
}

void build(const int &t,const int &l,const int &r)
{
	node[t].l=l;
	node[t].r=r;
	node[t].num = 0;
	if(l==r-1) 
		return;
	int mid=(l+r)>>1;
	build(L(t),l,mid);
	build(R(t),mid,r);
}

void update_len(const int &t)
{
	if(node[t].cover>0)
	{
		node[t].num = node[t].lb =node[t].rb =1;
		node[t].length = y_coord[node[t].r]-y_coord[node[t].l];
	}
	else if(node[t].l==node[t].r-1)
		node[t].length=node[t].num=node[t].lb=node[t].rb=0;
	else
	{
		node[t].length = node[R(t)].length+node[L(t)].length;
		node[t].rb=node[R(t)].rb;
		node[t].lb=node[L(t)].lb;
		//如果两段的端点重合，则-1
		node[t].num=node[L(t)].num+node[R(t)].num - node[L(t)].rb*node[R(t)].lb;
	}

}

void update_tree(const int &t,const LINE &lne)
{
	if(y_coord[node[t].l]>=lne.y1 && y_coord[node[t].r]<=lne.y2)
	{
		node[t].cover+=lne.flag;
		update_len(t);
		return;
	}
	if(node[t].l==node[t].r-1)
		return;
	int mid = (node[t].l+node[t].r)>>1;
	if(lne.y1<=y_coord[mid])
		update_tree(L(t),lne);
	if(lne.y2>y_coord[mid])
		update_tree(R(t),lne);
	update_len(t);
}

__int64 solve(const int &n,const int &cnt)
{
	init();
	build(1,0,cnt-1);
	__int64 sum=0ll;
  int last =0 ,lines=0;
	for(int i=0;i<n;++i)
	{
		update_tree(1,line[i]);
		if(i>0)
			sum+=2ll * lines *(line[i].x - line[i-1].x);  //求平行于X轴的边的长度
		sum += abs(node[1].length - last);  //求平行于Y轴的边的长度
		last = node[1].length;
		lines = node[1].num;
	}
	return sum;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n;
  int x1,y1,x2,y2;

  while(~scanf("%d",&n) && n)
  {
	  int cnt=0;
	  for(int i=0;i<n;++i)
	  {
		  scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		  add_line(x1,x2,y1,y2,cnt);
	  }
	  sort(line,line+cnt,cmp);
	  sort(y_coord,y_coord+cnt);
	  int temp=unique(y_coord,y_coord+cnt)-y_coord;
	  printf("%I64d\n",solve(cnt,temp));
  }

  return 0;
}
