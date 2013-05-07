/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-07-11 19:18
 # Filename: ZOJ3511 Cake Robbery.cpp
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

const int kMAX=100010;
vector<int> vec[kMAX];
int array[kMAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m;
	int x,y;

  while(~scanf("%d%d",&n,&m) && n)
  {
		vec[0].clear();
		for(int i=1;i<=n;++i)
			vec[0].push_back(i);

		int total=1;
		while(m--)
		{
			scanf("%d%d",&x,&y);
			if(x>y) swap(x,y);
			for(int i=0;i<total;++i)
			{
				int cnt=0,beg,end;
				for(size_t j=0;j<vec[i].size();++j)
				{
					if(x==vec[i][j])
					{
						beg=j;
						++cnt;
					}
					if(y==vec[i][j])
					{
						end=j;
						++cnt;
					}
				}
				if(cnt==2)
				{
					if(beg==end-1 || (end+1)%vec[i].size()==beg)
						break;//如果切痕重复，则没有必要算这一刀
          vec[total].clear();
					for(size_t k=beg;k<=end;++k)
						vec[total].push_back(vec[i][k]);
					total++;

					int idx=0;
					for(size_t k=0;k<=beg;++k)
						array[idx++]=vec[i][k];
					for(size_t k=end;k<vec[i].size();++k)
						array[idx++]=vec[i][k];
					vec[i].clear();
					vec[i].assign(array,array+idx);
          break;
				}
			}
		}
		size_t ans=0;
		for(int i=0;i<total;++i)
			ans=max(ans,vec[i].size());
		printf("%d\n",ans);
  }

  return 0;
}

