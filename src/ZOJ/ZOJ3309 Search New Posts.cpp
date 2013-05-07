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
#include <queue>
#include <map>
#define MAX 100010
using namespace std;

struct NODE
{
	string str;
	int w;
	bool operator<(const NODE &tmp) const
	{
		return w<tmp.w;
	}
}node;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncase=1;
	string str;
  //   scanf("%d",&ncase);

  while(~scanf("%d",&n) && n)
  {
		map<string,int> sn_map;
		priority_queue<NODE> q;
		for(int i=0;i<n;++i)
		{
			cin>>str;
			if(str=="new")
			{
				cin>>node.str;
				node.w=i;
				q.push(node);
				sn_map[node.str]=1;
			}
			else if(str=="reply")
			{
				cin>>node.str;
				node.w=i;
				q.push(node);
				sn_map[node.str]=1;
			}
			else if(str=="tag")
			{
				cin>>str;
				sn_map[str]=0;
			}
			else
			{
				int cnt=0;
				map<string,int> t_map(sn_map);
				priority_queue<NODE> t_q(q);
				while(cnt<100 && !t_q.empty())
				{
					node=t_q.top();
					t_q.pop();
					if(!t_map[node.str])
						continue;
					else{
						cout<<node.str<<endl;
						t_map[node.str]=0;
            ++cnt;
					}
				}
				cout<<"###"<<endl;
			}
    }
			cout<<endl;
  }

  return 0;
}
