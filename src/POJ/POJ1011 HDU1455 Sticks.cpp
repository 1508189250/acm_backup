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
// xΪ��һ��ʹ�õ�С����, nΪ�ܵ�С������, totalΪ��Ҫƴ�ɵĳ����ӳ���, 
// remainΪ��ƴ��һ���ĳ����ӵĳ���, leftΪ����Ҫƴ�õĳ�������
{
	if(left<2)  //��֦, ���ֻʣ��һ�������ӻ�ûƴ, �����֪�����µ�С���ӿ϶�����ƴ�����������ӵ�
		return true;

  used[x]=true;

  bool ans=false;
	for(int i=0;i<n && !ans;++i)
		if(!used[i])
	{
		if(i>0 && !used[i-1] && array[i]==array[i-1])
    // ��֦, �����һ��С���Ӻͱ���С����һ����, ����һ��С��������Ҳʧ��, ���֪����С����Ҳͬ��ʧ��
			continue;

		if(remain<array[i]) //��֦,С���ӱ���ƴ��һ�������ӵĳ��ȴ�
			continue;

		else if(remain==array[i]) // �����i�����Ӹպÿ���ƴ��һ��������, ��left--, remain����Ϊtotal
			ans = dfs(i,n,total,total,left-1);

		else if(remain>array[i])  // �����i������ȥ�󻹲�һ��, ����ƴ
			ans = dfs(i,n,total,remain-array[i],left);

    if(remain ==total && !ans)  
    // ��֦, ���������Ҫƴ�ɵĳ�����һ�㶼��û�����(remain==total),
    // ����, ����С���������Ҳ�������������, �����µ�С����Ҳ���������
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
		for(;ans<=sum/2;++ans)  //��֦, ��Ҫƴ�ɵĳ����ӵĳ��ȷ�ΧӦ����[max_len,sum/2]
			if(!(sum%ans))  // ��֦, ֻ���ܳ����ǳ����ӳ��ȵ�����������Ч
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
