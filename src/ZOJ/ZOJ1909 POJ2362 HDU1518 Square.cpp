/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-10-19 21:29
 # Filename: ZOJ1909 POJ2362 HDU1518 Square.cpp
 # Description : 
 ******************************************************************************/
// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <memory.h>
#include <list>
#include <algorithm>
using namespace std;
int num[25],n;
bool visit[25];
int ave;

bool dfs(const int &rest,const int &sum,const int &cur)	//rest代表当前边的剩余长度, sum代表剩余木棍的总长度, cur记录当前的木棍
{
	if(sum==ave)	//到了这里代表已经找到三条边了，第四条边不用找了
		return true;

	for(int i=cur;i<n;++i)
	{
		if (num[i]==num[i-1] && !visit[i-1])	//如果这条边和上一条边的长度一样，且上一条边没有用上，那这条边减掉
			continue;

		if(!visit[i] && num[i]<=rest)
		{
			visit[i]=true;
			if(rest==num[i])		
			{
				//标记1，找到一条边后，进入下一条边
				if(dfs(ave,sum-rest,0))	
					return true;
			}
			else if( dfs( rest-num[i], sum-num[i],i))
				return true;
			visit[i]=false;

			//这个对应从标记1进入的状态，从头(0)开始找一条最长没有用过的边，如果这条边经过上面几步还是无法用到，则代表当初状态不可取
			if(rest==ave) return false;		
		}
	}
	return false;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int ncases;
	scanf("%d",&ncases);
	while(ncases--)
	{
		int sum=0;
		int maxlen=0;
		bool ans=false;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&num[i]);
			sum+=num[i];
			maxlen = max(num[i],maxlen);	//求所有木棍中最长木棍
		}
		ave = sum/4;
		if(sum%4 || maxlen>ave)	//如果总的长度不能被4整除，或者最长木棍大于边长度，减掉
			goto end;

		memset(visit,false,sizeof(visit));
		sort(num,num+n,greater<int>());	//所有木棍按照长度排序
		ans=dfs(ave,sum,0);
end:
		if(ans)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
