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
//capacity记录的是每条边最大可以承受的流量，flow记录每条边已经承受的流量，visit记录的是到每个节点的流量，pre记录节点的前驱
int n,f,d;

int EK(const int &source,const int &target)
{
	queue<int> mQueue;
	int ans=0;
	memset(flow,0,sizeof(flow));
	memset(pre,0,sizeof(pre));
	memset(visit,0,sizeof(visit));
	while(true)	//每一步都用BFS求一条源点到终点的最短路
	{
		mQueue.push(source);
		memset(visit,0,sizeof(visit));	//对于每一次BFS，都要把visi清空
		memset(pre,0,sizeof(pre));
		visit[source]=INT_MAX;	//我们假设进入源节点的流量是无限大
		while(!mQueue.empty())
		{
			int u=mQueue.front();
			mQueue.pop();
			for(int v=source;v<=target;++v)
				if(!visit[v] && capacity[u][v]>flow[u][v])	//最短路的要求是每条边已经承受的流量小于每条边可以承受的最大流量
				{
					mQueue.push(v);
					visit[v]=min(visit[u],capacity[u][v]-flow[u][v]);	//v的前驱节点已经承受的流量和u到v间还可以承受流量的最小值
					pre[v]=u;
				}
		}
		if(visit[target]==0)	//如果目标点已经没有流量了，也就是从源点到目标点的所有路径都已经到了最大承受能力了，跳出循环
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
