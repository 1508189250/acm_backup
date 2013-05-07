/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-12-29 19:36
 # Filename: ZOJ1117 POJ1521 HDU1053 Entropy.cpp
 # Description : 
 ******************************************************************************/
// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#define MAX 128
using namespace std;

struct NODE
{
  int weight,index;
  NODE *lhs,*rhs;
}node[MAX*MAX];

int n_count;
int num[MAX];

bool inline cmp(const NODE &lhs,const NODE &rhs)
{
  return lhs.weight>rhs.weight;
}

void func(NODE *p_arry,const int &len)
{
  if(len<2)
    return;

  sort(p_arry,p_arry+len,cmp);
  swap(p_arry[len-2],p_arry[n_count]);

  p_arry[len-2].lhs=&p_arry[len-1];
  p_arry[len-2].rhs=&p_arry[n_count];
  p_arry[len-2].weight=p_arry[len-1].weight+p_arry[n_count].weight;
  ++n_count;
}

int sum_len(const NODE *p,const int &len)
{
  if(p->lhs==NULL)
    return p->weight*len;
  else
  {
    return sum_len(p->lhs,len+1) + sum_len(p->rhs,len+1);
  }
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
  char str[MAX*MAX];

  while(scanf("%s",str))
  {
    if(!strcmp(str,"END"))
      break;

    memset(num,0,sizeof(num));
    for(int i=0;i<strlen(str);++i)
      ++num[str[i]];
    sort(num,num+MAX,greater<int>());

    int len=0;
    for(;num[len];++len)
    {
      node[len].lhs=NULL;
      node[len].rhs=NULL;
      node[len].weight=num[len];
      node[len].index=len;
    }

    if(len>1)
    {
      n_count=len;
      for(int i=len;i>1;--i)
        func(node,i);

      int ans=sum_len(&node[0],0);

      printf("%d %d %.1lf\n",strlen(str)*8,ans,double(strlen(str)*8)/double(ans));
    }
    else
      printf("%d %d %.1lf\n",strlen(str)*8,num[0],double(strlen(str)*8)/double(num[0]));
  }

  return 0;
}
