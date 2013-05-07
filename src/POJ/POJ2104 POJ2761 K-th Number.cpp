/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-02-06 21:45
 # Filename: POJ2104 POJ2761 K-th Number.cpp
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
#define MID(x,y) ((x+y)>>1)
#define MAX 100010
using namespace std;

class CParti_tree{

private:
  int beg_,end_;
  int to_left_[20][MAX];  //to_left_存的是d层在i之前(包括i)小于 array[mid] 的数的数目

public:
  int array[MAX];   //array存的是sort后的结果
  int seg[20][MAX];   //seg数组存的是d层划分后的数字 （类似快排Partation （d-1）次后的结果）
  
  void init()
  {
    memset(seg,0,sizeof(seg));
    memset(to_left_,0,sizeof(to_left_));
  }
  
  void tree_build(const int &l,const int &r,const int &level)
  {
    if(r-l==0)
      return;
    int mid=MID(l,r)/*node[t].getMid()*/;
    int lsame=mid-l+1;    //lsame表示和array[mid]相等且分到左边的
    for(int i=l;i<=r;++i)
      if(seg[level][i]<array[mid])
        --lsame;          //调整lsame
    int lpos=l, rpos=mid+1;
    for(int i=l;i<=r;++i)
    {
      int flag=0;
      if((seg[level][i]<array[mid])||(seg[level][i]==array[mid]&&lsame))    //左子树
      {
        flag=1;
        seg[level+1][lpos++]=seg[level][i];
        if(seg[level][i]==array[mid])
          --lsame;
      }
      else
      {
        seg[level+1][rpos++]=seg[level][i];
      }
      if(i==l)
        to_left_[level][i]=flag;
      else
        to_left_[level][i]=to_left_[level][i-1]+flag;
    }
    tree_build(l,mid,level+1);
    tree_build(mid+1,r,level+1);
  }

  void build(const int &beg,const int &end)
  {
    beg_=beg;end_=end;
	  sort(array+beg_,array+beg_+end_);
	  tree_build(beg_,end_,0);
  }

  int find_k_th(const int &L,const int &R,const int &l,const int &r,const int &level,const int &val)
  {
	  if(R-L==0)
		  return seg[level][l];
	  int s;    //s表示[ l , r ]有多少个分到左边
	  int ss;   //ss表示 [node[t].l , l-1 ]有多少个分到左边
    int mid=MID(L,R);
	  if(l==L)
		  ss=0;
	  else
		  ss= to_left_[level][l-1];
	  s=to_left_[level][r]-ss;
	  if(s>=val)    //有多于val个分到左边,显然去左儿子区间找第val个
		  return find_k_th(L,mid,L+ss,L+ss+s-1,level+1,val);   //重整边界
	  else
	  {
		  int bb=l-L-ss;    //bb表示 [node[t].l, l-1 ]有多少个分到右边
		  int b=r-l+1-s;    //b表示 [l, r]有多少个分到右边
		  return find_k_th(mid+1,R,mid+bb+1,mid+bb+b,level+1,val-s);
	  }
  }

  int query(const int &beg,const int &end,const int &k)
  {
	  return find_k_th(beg_,end_,beg,end,0,k);
  }
};

CParti_tree pt;
int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m;
  int beg,end,val;

  while(~scanf("%d%d",&n,&m))
  {
	  pt.init();
	  for(int i=1;i<=n;++i)
	  {
		  scanf("%d",&pt.array[i]);
		  pt.seg[0][i]=pt.array[i];
	  }
	  pt.build(1,n);
	  while(m--)
	  {
		  scanf("%d%d%d",&beg,&end,&val);
		  int ans=pt.query(beg,end,val);
		  printf("%d\n",ans);
	  }
  }

  return 0;
}
