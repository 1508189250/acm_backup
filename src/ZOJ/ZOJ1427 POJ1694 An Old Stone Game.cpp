/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-03-21 19:27
 # Filename: ZOJ1427 POJ1694 An Old Stone Game.cpp
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
#define MAX 210
using namespace std;

int children[MAX][MAX];

int func(const int &r)
{
	int array[MAX];
	if(children[r][0]==0)
		return 1;
	int cnt=0;
	while(children[r][cnt])
	{
		array[cnt]=func(children[r][cnt]);
		++cnt;
	}
	sort(array,array+cnt,greater<int>());
	int ans=array[0],tmp=array[0]-1;
	for(int i=1;i<cnt;++i)
		if(tmp<array[i])
		{
			ans+=(array[i]-tmp);
			tmp=array[i]-1;
		}
		else
			--tmp;
	return ans;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int n,ncases,parent,tmp;
	scanf("%d",&ncases);

	while(ncases--)
	{
		scanf("%d",&n);
		memset(children,0,sizeof(children));
		for(int i=0;i<n;++i)
		{
			scanf("%d%d",&parent,&tmp);
			for(int j=0;j<tmp;++j)
				scanf("%d",&children[parent][j]);
		}

		int ans=func(1);
		printf("%d\n",ans);
	}

  return 0;
}
