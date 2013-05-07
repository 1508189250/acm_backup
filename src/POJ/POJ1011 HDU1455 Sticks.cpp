/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-03-08 20:31
 # Filename: POJ1011 HDU1455 Sticks.cpp
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
#define MAX 70
using namespace std;

int array[MAX];
bool used[MAX];

bool dfs(const int &x, const int &n, const int &total,const int &remain, const int &left)
// x为上一条使用的小棍子, n为总的小棍子数, total为需要拼成的长棍子长度, 
// remain为离拼好一条的长棍子的长度, left为还需要拼好的长棍子数
{
	if(left<2)  //剪枝, 如果只剩下一条长棍子还没拼, 则可以知道余下的小棍子肯定可以拼成这条长棍子的
		return true;

  used[x]=true;

  bool ans=false;
	for(int i=0;i<n && !ans;++i)
		if(!used[i])
	{
		if(i>0 && !used[i-1] && array[i]==array[i-1])
    // 剪枝, 如果上一条小棍子和本条小棍子一样长, 且上一条小棍子用了也失败, 则可知这条小棍子也同样失败
			continue;

		if(remain<array[i]) //剪枝,小棍子比离拼好一条长棍子的长度大
			continue;

		else if(remain==array[i]) // 如果第i条棍子刚好可以拼好一条长棍子, 则left--, remain重置为total
			ans = dfs(i,n,total,total,left-1);

		else if(remain>array[i])  // 如果第i条加上去后还差一点, 继续拼
			ans = dfs(i,n,total,remain-array[i],left);

    if(remain ==total && !ans)  
    // 剪枝, 如果现在需要拼成的长棍子一点都还没有完成(remain==total),
    // 而且, 余下小棍子里最长的也不足以完成任务, 则余下的小棍子也不足以完成
    {
      used[x]=false;
      return false;
    }
	}

  used[x]=false;
	return ans;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int n;

	while(scanf("%d",&n) && n)
	{
		int max_len=INT_MIN,sum=0;
    memset(used,false,sizeof(used));
		for(int i=0;i<n;++i)
		{
			scanf("%d",&array[i]);
			sum+=array[i];
			max_len=max(max_len,array[i]);
		}

    sort(array,array+n,greater<int>());

		int ans=max_len;
		for(;ans<=sum/2;++ans)  //剪枝, 需要拼成的长棍子的长度范围应该是[max_len,sum/2]
			if(!(sum%ans))  // 剪枝, 只有总长度是长棍子长度的整数倍才有效
			{
				if(dfs(n,n,ans,ans,sum/ans))
				{
					printf("%d\n",ans);
					break;
				}
			}
		if(ans>sum/2)
			printf("%d\n",sum);
	}

  return 0;
}
