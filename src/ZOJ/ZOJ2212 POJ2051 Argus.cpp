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

struct NODE
{
	int num,old_priod,priod;
};

bool operator<(const NODE &lhs,const NODE &rhs)
{
	if (rhs.priod !=lhs.priod)
		return rhs.priod<lhs.priod;
	else
		return rhs.num<lhs.num;
}
priority_queue<NODE> mq;

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	char str[10];
	int k,order=0;
	NODE temp;
	while(scanf("%s",str))
	{
		if(str[0]=='#')
			break;
		scanf("%d%d",&temp.num,&temp.priod);
		temp.old_priod=temp.priod;
		mq.push(temp);
		getchar();
	}
	scanf("%d",&k);
	while(k--)
	{
		temp=mq.top();
		mq.pop();
		printf("%d\n",temp.num);
		temp.priod+=temp.old_priod;
		mq.push(temp);
	}

	return 0;
}
