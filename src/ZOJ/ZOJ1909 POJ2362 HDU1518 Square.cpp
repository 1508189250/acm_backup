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

bool dfs(const int &rest,const int &sum,const int &cur)	//rest����ǰ�ߵ�ʣ�೤��, sum����ʣ��ľ�����ܳ���, cur��¼��ǰ��ľ��
{
	if(sum==ave)	//������������Ѿ��ҵ��������ˣ��������߲�������
		return true;

	for(int i=cur;i<n;++i)
	{
		if (num[i]==num[i-1] && !visit[i-1])	//��������ߺ���һ���ߵĳ���һ��������һ����û�����ϣ��������߼���
			continue;

		if(!visit[i] && num[i]<=rest)
		{
			visit[i]=true;
			if(rest==num[i])		
			{
				//���1���ҵ�һ���ߺ󣬽�����һ����
				if(dfs(ave,sum-rest,0))	
					return true;
			}
			else if( dfs( rest-num[i], sum-num[i],i))
				return true;
			visit[i]=false;

			//�����Ӧ�ӱ��1�����״̬����ͷ(0)��ʼ��һ���û���ù��ıߣ���������߾������漸�������޷��õ����������״̬����ȡ
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
			maxlen = max(num[i],maxlen);	//������ľ�����ľ��
		}
		ave = sum/4;
		if(sum%4 || maxlen>ave)	//����ܵĳ��Ȳ��ܱ�4�����������ľ�����ڱ߳��ȣ�����
			goto end;

		memset(visit,false,sizeof(visit));
		sort(num,num+n,greater<int>());	//����ľ�����ճ�������
		ans=dfs(ave,sum,0);
end:
		if(ans)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
