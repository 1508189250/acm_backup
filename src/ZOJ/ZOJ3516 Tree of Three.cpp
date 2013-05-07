/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-07-11 19:56
 # Filename: ZOJ3516 Tree of Three.cpp
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
#include <vector>
using namespace std;

const int kMAX=10010;
int value[kMAX],array[kMAX];
vector<int> vec[kMAX];
int cnt;

void func(const int &x)
{
	array[cnt++]=value[x];
	for(size_t i=0;i<vec[x].size();++i)
		func(vec[x][i]);
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m,u,v;

  while(~scanf("%d",&n) && n)
  {
		scanf("%d",&value[0]);
		for(int i=0;i<kMAX;++i)
			vec[i].clear();

		for(int i=1;i<n;++i)
		{
			scanf("%d%d",&u,&value[i]);
			vec[u].push_back(i);
		}
		scanf("%d",&m);
		while(m--)
		{
			cnt=0;
			scanf("%d",&u);
			func(u);
			if(cnt<3)
				printf("-1\n");
			else
			{
				sort(array,array+cnt,greater<int>());
				for(int i=0;i<3;++i)
					printf("%d%c",array[i],i<2?' ':'\n');
			}
		}
  }

  return 0;
}

