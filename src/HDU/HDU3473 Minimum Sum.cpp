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
#define GETMID(x,y) ((x+y)>>1)
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define MAX 100010
using namespace std;

// class CParti_tree{
// 
// private:
// 
// public:
  int array[MAX];   //array存的是sort后的结果
  int to_left_[22][MAX];  //to_left_存的是d层在i之前(包括i)小于 array[mid] 的数的数目
  int seg[22][MAX];   //seg数组存的是d层划分后的数字 （类似快排Partation （d-1）次后的结果）
  long long sum_[22][MAX]; //sum存储的是d层划分后在i之前(包括i)放到左边的数的和
  long long l_array_sum_[MAX];  //保存array在sort前的前i个数的和
  int n_to_left_num_;   //保存对于每一次检索, [l,r]中有多少个数放到mid的左边
  long long l_to_left_sum_;   //保存对于每一次检索,[l,r]放到左边的树的和

  void init()
  {
    memset(seg,0,sizeof(seg));
    memset(to_left_,0,sizeof(to_left_));
    memset(sum_,0ll,sizeof(sum_));
    memset(l_array_sum_,0ll,sizeof(l_array_sum_));
  }

  void tree_build(const int &l,const int &r,const int &L,const int &R,const int &level)
  {
    if(r-l==0)
      return;
    int mid=GETMID(L,R)/*node[t].getMid()*/;
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
        sum_[level][i]=sum_[level][i-1]+seg[level][i];
      }
      else
      {
        seg[level+1][rpos++]=seg[level][i];
        sum_[level][i]=sum_[level][i-1];
      }
      to_left_[level][i]=to_left_[level][i-1]+flag;
    }
    tree_build(l,mid,L,mid,level+1);
    tree_build(mid+1,r,mid,R,level+1);
  }

  void build(const int &beg,const int &end)
  {
    for(int i=beg;i<=end;++i)
      l_array_sum_[i]=l_array_sum_[i-1]+array[i];
    sort(array+beg,array+beg+end);
    tree_build(beg,end,beg,end,0);
  }

  int find_k_th(const int &l,const int &r,const int &L,const int &R,const int &level,const int &val)
  {
    if(r-l==0)
      return seg[level][l];
    int s;    //s表示[ l , r ]有多少个分到左边
    int ss;   //ss表示 [node[t].l , l-1 ]有多少个分到左边
    if(l==L)
      ss=0;
    else
      ss= to_left_[level][l-1];
    s=to_left_[level][r]-ss;
    if(s>=val)    //有多于val个分到左边,显然去左儿子区间找第val个
      return find_k_th(L+ss,L+ss+s-1,L,GETMID(L,R),level+1,val);   //重整边界
    else
    {
      int mid=GETMID(L,R);
      int bb=l-L-ss;    //bb表示 [node[t].l, l-1 ]有多少个分到右边
      int b=r-l+1-s;    //b表示 [l, r]有多少个分到右边
      l_to_left_sum_ += (sum_[level][r] - sum_[level][l-1]);
      n_to_left_num_+=s;
      return find_k_th(mid+bb+1,mid+bb+b,mid,R,level+1,val-s);
    }
  }

  int query(const int &beg,const int &end,const int &k,const int L,const int R)
  {
    l_to_left_sum_=0ll;
    n_to_left_num_=0;
    return find_k_th(beg,end,L,R,0,k);
  }
// };

// CParti_tree pt;
int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m,ncases;
  int beg,end,ind;
  scanf("%d",&ncases);

  for(int nc=1;nc<=ncases;++nc)
  {
    printf("Case #%d:\n",nc);
    scanf("%d",&n);
    /*pt.*/init();
    for(int i=1;i<=n;++i)
    {
      scanf("%d",&/*pt.*/array[i]);
      /*pt.*/seg[0][i]=/*pt.*/array[i];
    }
    /*pt.*/build(1,n);
    scanf("%d",&m);
    while(m--)
    {
      scanf("%d%d",&beg,&end);
      ++beg;
      ++end;
      ind=GETMID(beg,end);
      int ave=/*pt.*/query(beg,end,ind,1,n);
      int lnum=/*pt.*/n_to_left_num_;
      int rnum=(end-beg+1-lnum);
      long long l_to_right_sum=/*pt.*/l_array_sum_[end]-/*pt.*/l_array_sum_[beg-1] - /*pt.*/l_to_left_sum_;
      long long ans = l_to_right_sum-ave*(rnum-lnum)-/*pt.*/l_to_left_sum_;

      printf("%lld\n",ans);
    }
    printf("\n");
  }

  return 0;
}
