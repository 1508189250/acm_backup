/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-04-28 20:12
 # Filename: ZOJ2834 Maximize Game Time.cpp
 # Description : 
 ******************************************************************************/
#ifdef _MSC_VER
#define DEBUG
#define _CRT_SECURE_NO_DEPRECATE
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
#define MAX 1010
using namespace std;

struct NODE
{
  //用父子-兄弟节点表示这棵树
  int father,child,brother;
  //max_child_extinction, 表示假如此节点没有被杀死，儿子节点可以任意杀死的情况下最长寿命。按照题目，可知只有一个孩子的全家被杀，而其他孩子不被杀，但是其他孩子的孩子能够杀死
  //dp, 符合题意的，此节点被杀死的最长寿命
  //extinction, 以此节点为根的子树的全家死光的时间
  //kill, 杀死这个节点需要多少时间
  int max_child_extinction,dp,extinction,kill;
  void init()
  {
    father=child=brother=-1;
    dp=extinction=max_child_extinction=0;
  }
}node[MAX];

int input[MAX][2];

//杀死idx为根的子树的全家所需要的时间
int TotalFamilyExtinction(const int &idx)
{
  if(node[idx].extinction)
    return node[idx].extinction;
  node[idx].extinction=node[idx].kill;
  int child=node[idx].child;
  while(child>-1)
  {
    node[idx].extinction+=TotalFamilyExtinction(child);
    child=node[child].brother;
  }
  return node[idx].extinction;
}

//idx不杀死的情况下，以idx为根的子树最长能够存活的时间
int MaxChildExtinction(const int &idx)
{
	if(node[idx].max_child_extinction)
		return node[idx].max_child_extinction;
  int child=node[idx].child;
  //遍历每一种情况，即child全家被杀，其他child不被杀，但是其他child的child能够杀死
  while(child>-1)
  {
    int tmp=TotalFamilyExtinction(child);
    int sec_child=node[idx].child;
    while(sec_child>-1)
    {
      if(sec_child!=child)
        tmp+=MaxChildExtinction(sec_child);
      sec_child=node[sec_child].brother;
    }
    node[idx].max_child_extinction=max(tmp, node[idx].max_child_extinction);
    child=node[child].brother;
  }
  return node[idx].max_child_extinction;
}


int dfs(const int &idx)
{
  if(node[idx].dp)
    return node[idx].dp;
  node[idx].dp = node[idx].kill;
  int child=node[idx].child,sum=0;
  while(child>-1)
  {
    sum+=MaxChildExtinction(child);
    child=node[child].brother;
  }
  child=node[idx].child;
  int ans=0;
  while(child>-1)
  {
    ans=max(ans,TotalFamilyExtinction(child));
    int sec_child=node[idx].child;
    while(sec_child>-1)
    {
      if(child!=sec_child)
        //dp为触动此节点idx被杀的最长需要时间
        //此为本题的精髓，对于idx，dp必然是它一个孩子child全家被杀，另外一个孩子sec_child的dp，以及别的孩子不被杀死，但是别的孩子的孩子能够任意杀死的最长时间
        ans=max(ans,sum-MaxChildExtinction(child)-MaxChildExtinction(sec_child)+TotalFamilyExtinction(child)+dfs(sec_child));
      sec_child=node[sec_child].brother;
    }
    child=node[child].brother;
  }
  node[idx].dp+=ans;
  return node[idx].dp;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,father;
  //   scanf("%d",&ncase);

  while(~scanf("%d",&n) && n)
  {
    for(int i=0;i<n;++i)
    {  
      node[i].init();
      scanf("%d",&node[i].kill);
    }
    for(int i=0;i<n;++i)
    {
      scanf("%d",&father);
      node[i].father=father;
      if(father==-1)
        continue;
      node[i].brother=node[father].child;
      node[father].child=i;
    }
    int ans=0;
    //注意可能存在森林的情况，除非是以n-1为根的树，否则别的树都可以全家杀死
    for(int i=0;i<n-1;++i)
      if(node[i].father==-1)
        ans+=TotalFamilyExtinction(i);
    ans+=dfs(n-1);
    printf("%d\n",ans);
  }

  return 0;
}
