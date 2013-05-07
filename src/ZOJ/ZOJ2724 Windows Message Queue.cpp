// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>

#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <assert.h>
#include <ctype.h>

#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;

struct MSG
{
	char msg[20];
	int para,priority;
};

bool operator<(const MSG &lhs,const MSG &rhs)
{
	return rhs.priority<lhs.priority;
}

priority_queue<MSG> mque;

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	char com[5],msg[20];
	int para,priority;
	MSG tmp;

	while(scanf("%s",com) !=EOF)
	{
		if(com[0]=='P')
		{
			scanf("%s %d %d",msg,&para,&priority);
			tmp.para=para;
			tmp.priority=priority;
			strcpy(tmp.msg,msg);
			mque.push(tmp);
		}
		else
		{
			if(mque.empty())
				printf("EMPTY QUEUE!\n");
			else
			{
				tmp=mque.top();
				mque.pop();
				printf("%s %d\n",tmp.msg,tmp.para);
			}
		}
		getchar();
	}

	return 0;
}
