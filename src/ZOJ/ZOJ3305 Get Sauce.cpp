/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-05-13 19:52
 # Filename: ZOJ3305 Get Sauce.cpp
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
#define MAX 50010
using namespace std;

int num[MAX];

int func(const int &cnt)
{
	int ans=0,tmp;
	for(int i=0;i<cnt;++i)
	{
		scanf("%d",&tmp);
		ans=ans|(1<<(tmp-1));
	}
	return ans;
}

bool b_visit[MAX];
int dfs(const int &idx,const int &cnt,const int &sum)
{
	int ans=sum;
	for(int i=idx;i<cnt;++i)
		{
			bool b_flag=true;
			for(int j=0;j<idx;++j)
				if(b_visit[j] && num[j]&num[i])
				{
					b_flag=false;
					break;
				}
			if(b_flag)
			{
				b_visit[i]=true;
				ans=max(ans,dfs(i+1,cnt,sum+1));
				b_visit[i]=false;
			}
		}
	return ans;
}

int main(void)
{
#ifdef DEBUG  
	freopen("../stdin.txt","r",stdin);
	freopen("../stdout.txt","w",stdout); 
#endif  

	int n,m;
	int tmp;
	//   scanf("%d",&ncase);

	while(~scanf("%d%d",&n,&m))
	{
		int cnt=0;
		while(m--)
		{
			scanf("%d",&tmp);
			tmp=func(tmp);
			bool b_flag=true;
			for(int i=0;i<cnt;++i)
				if(num[i])
				{
					int var=tmp&num[i];
					if(var==num[i])
					{
						b_flag=false;
						break;
					}
					else if(var==tmp)
						num[i]=0;
				}
			if(b_flag)
				num[cnt++]=tmp;
		}
		sort(num,num+cnt,greater<int>());
		cnt=unique(num,num+cnt)-num;
		if(num[cnt-1]==0)
			--cnt;
		memset(b_visit,false ,sizeof(b_visit));
		int ans=dfs(0,cnt,0);
		printf("%d\n",ans);
	}

	return 0;
}
