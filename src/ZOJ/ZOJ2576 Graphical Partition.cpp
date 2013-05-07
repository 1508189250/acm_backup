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
#include <set>
#define MAX 12
using namespace std;

struct NODE
{
  int num[MAX];
  int n;
	void func()
	{
		sort(num,num+n);
	}

  void output()
  {
    for(int j=0;j<n;++j)
      printf("%c%d",j==0?'{':',',num[j]);
    printf("}\n");
  }

  bool inline operator<(const NODE &tmp) const
  {
    if(n!=tmp.n)
      return n>tmp.n;
    else
      for(int i=0;i<n;++i)
        if(num[i]<tmp.num[i])
          return true;
        else if(num[i]>tmp.num[i])
          return false;
    return false;
  }

}ans[MAX],node;

set<NODE> m_set;

void func(const int &n,const int &m,const int &degree,)
{
	if(n==0)
	{
		m_set.insert(
	}
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n;

  while(scanf("%d",&n)&&n)
  {
		m_set.clear();
		node.n=2;
		node.num[0]=node.num[1]=n;

		printf("%d\n",func(2*n,n/*,node*/));

    for(set<NODE>::iterator i=m_set.begin();i!=m_set.end();++i)
      printf("%d ",i->n);
		printf("\n");
  }

  return 0;
}
