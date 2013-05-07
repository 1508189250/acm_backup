// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>

#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <limits>
#include <assert.h>
#include <ctype.h>

#include <vector>
#include <stack>
#include <queue>
#include <deque>
#define MAX 12

using namespace std;
int map[MAX][MAX],n,visit[MAX],done;
char str[50];

void init()
{
	memset(map,0,sizeof(map));
	for(int i=0;i<=n;++i)
		map[i][i]=1;
	memset(visit,0,sizeof(visit));
	done=0;
}

void input()
{
	for(int i=1;i<=n;++i)
	{
		gets(str);
		int len=strlen(str);
		for(int j=0;j<len;++j)
			if(isdigit(str[j]))
				map[i][str[j]-'0']=map[str[j]-'0'][i]=1;
	}
}

bool dfs(int x)
{
	if(visit[x])
			return false;
	visit[x]=1;
	++done;
	if(done==n+1 && map[x][0]) return true;
	bool ans=false;
	for(int i=1;i<=n;++i)
		if(map[x][i])
			ans=ans || dfs(i);
	visit[x]=0;
	--done;
	return ans;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int ncases=1;
	while(scanf("%d",&n)&&n)
	{
		getchar();
		init();
		input();
		bool ans=dfs(0);
		if(ans)
			printf("Case %d: Granny can make the circuit.\n",ncases++);
		else
			printf("Case %d: Granny can not make the circuit.\n",ncases++);
	}

	return 0;
}
