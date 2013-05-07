// #include "stdafx.h"
// #define DEBUG


#include <string.h>
#include <string>
#include <memory.h>
#include <queue>
#include <limits.h>
#define MAX 440
using namespace std;

int capacity[MAX][MAX],flow[MAX][MAX];
int pre[MAX],visit[MAX];
//capacity��¼����ÿ���������Գ��ܵ�������flow��¼ÿ�����Ѿ����ܵ�������visit��¼���ǵ�ÿ���ڵ��������pre��¼�ڵ��ǰ��
int n,f,d;

int EK(const int &source,const int &target)
{
	queue<int> mQueue;
	int ans=0;
	memset(flow,0,sizeof(flow));
	memset(pre,0,sizeof(pre));
	memset(visit,0,sizeof(visit));
	while(true)	//ÿһ������BFS��һ��Դ�㵽�յ�����·
	{
		mQueue.push(source);
		memset(visit,0,sizeof(visit));	//����ÿһ��BFS����Ҫ��visi���
		memset(pre,0,sizeof(pre));
		visit[source]=INT_MAX;	//���Ǽ������Դ�ڵ�����������޴�
		while(!mQueue.empty())
		{
			int u=mQueue.front();
			mQueue.pop();
			for(int v=source;v<=target;++v)
				if(!visit[v] && capacity[u][v]>flow[u][v])	//���·��Ҫ����ÿ�����Ѿ����ܵ�����С��ÿ���߿��Գ��ܵ��������
				{
					mQueue.push(v);
					visit[v]=min(visit[u],capacity[u][v]-flow[u][v]);	//v��ǰ���ڵ��Ѿ����ܵ�������u��v�仹���Գ�����������Сֵ
					pre[v]=u;
				}
		}
		if(visit[target]==0)	//���Ŀ����Ѿ�û�������ˣ�Ҳ���Ǵ�Դ�㵽Ŀ��������·�����Ѿ����������������ˣ�����ѭ��
			break;
		for(int u=target;u!=source;u=pre[u])
		{
			flow[pre[u]][u]+=visit[target];
			flow[u][pre[u]]-=visit[target];
		}
		ans+=visit[target];
	}
	return ans;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int fnum,dnum,temp;

	while(scanf("%d%d%d",&n,&f,&d)!=EOF)
	{
		memset(capacity,0,sizeof(capacity));
		for(int i=1;i<=n;++i)
		{
			capacity[i][n+i]=1;
			scanf("%d%d",&fnum,&dnum);
			while(fnum--)
			{
				scanf("%d",&temp);
				capacity[2*n+temp][i]=1;
			}
			while(dnum--)
			{
				scanf("%d",&temp);
				capacity[n+i][2*n+f+temp]=1;
			}
		}
		for(int i=2*n+1;i<=2*n+f;++i)
			capacity[0][i]=1;
		for(int i=2*n+f+1;i<=2*n+f+d;++i)
			capacity[i][2*n+f+d+1]=1;
		int ans=EK(0,2*n+f+d+1);
		printf("%d\n",ans);
	}

	return 0;
}
