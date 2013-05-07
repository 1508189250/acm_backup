/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-09-09 17:58
 * Filename : ZOJ1025 POJ1065 HDU1051 Wooden Sticks.cpp
 * Description : ���������õ���̰���㷨�������ȶԳ���len�����������ת��Ϊ��
				weight��û�н�������������еĸ����������κ�һ�����������У���
				Ȼ��ͷԪ�غ�βԪ�أ������������βԪ�ء�������num����������Ƿ�
				βԪ�أ��ǵĻ���0�����ǵĻ���1�����ڵ�i��Ԫ�أ���ǰ�ҵ�һ������
				ĳ�������е�βԪ�أ�ͬʱ�ȵ�i��Ԫ��С��Ԫ����������ֵ��������
				��Ϊindex�������ǿ��԰�num[index]��Ϊ1��ʾ�䲻��βԪ���ˡ����
				ͳ�ƻ��ж��ٸ�βԪ�ؾͿ���֪���ж��ٸ������������ˡ��ܵ�ʱ�临��
				��ΪO(N^2)��
 * *****************************************************************************/
// ZOJ1025 POJ1065 HDU1051 Wooden Sticks.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <stdio.h>
#include <string.h>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;

struct node
{
	int len,weight;
}sticks[5010];

int num[5010];

bool cmp(const node &lhs,const node &rhs)
{
 	if(lhs.len !=rhs.len)
 		return lhs.len<rhs.len;
 	else
 		return lhs.weight<rhs.weight;
}

int main(void)
{
	int ncases,n;

	scanf("%d",&ncases);
	while(ncases--)
	{
		memset(num,0,sizeof(num));
		scanf("%d",&n);
		int sum=n;

		for(int i=0;i<n;++i)
			scanf("%d %d",&sticks[i].len,&sticks[i].weight);

		sort(sticks,sticks+n,cmp);

		for(int i=1;i<n;++i)
		{
			int minlen=-1;
			int index=-1;
			for(int j=i-1;j>=0;--j)
			{
				if(sticks[i].weight>=sticks[j].weight && !num[j] && minlen<sticks[j].weight)
				{
					index=j;
					minlen=sticks[j].weight;
				}
			}
			if(minlen>-1)
			{
				num[index]=1;
				--sum;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
