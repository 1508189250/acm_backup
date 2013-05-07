/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-07-19 19:35
 # Filename: URAL1126 Magnetic Storms.cpp
 # Description : 
 ******************************************************************************/
#ifdef _MSC_VER
//#define DEBUG
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
#include <queue>
using namespace std;

const int kMAX=10010;
struct NODE
{
	int id,val;
};

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncase=1;
	NODE node;
	deque<NODE> q;

  while(~scanf("%d",&n) && n)
  {
		q.clear();
		int cnt=0;
		while(scanf("%d",&node.val) && node.val>-1)
		{
			node.id=cnt++;

			while(!q.empty() && q.front().id < cnt-n)
				q.pop_front();
			while(!q.empty() && q.back().val < node.val)
				q.pop_back();

			q.push_back(node);
			if(cnt>=n)
				printf("%d\n",q.front().val);
		}
  }

  return 0;
}

