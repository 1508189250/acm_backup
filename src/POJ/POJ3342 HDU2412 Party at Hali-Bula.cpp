/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-04-26 20:27
 # Filename: POJ3342 HDU2412 Party at Hali-Bula.cpp
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
#include <map>
#define MAX 100010
using namespace std;

struct NODE
{
  int child,father,brother,present,not_present;
  bool present_unique,not_present_unique;
  void init()
  {
    child=father=brother=not_present=0;
    present=present_unique=not_present_unique=1;
  }
  int max()
  {
    return present>not_present?present:not_present; 
  }
}node[MAX];

void dfs(const int &idx)
{
	int child=node[idx].child;
	while(child)
	{
		dfs(child);
		node[idx].present+=node[child].not_present;
		node[idx].not_present+=node[child].max();
    if(!node[child].not_present_unique)
      node[idx].present_unique=false; //本节点出现，则本节点的最优值是否唯一只和子节点不出现的最优值是否唯一有关
    if(node[child].present==node[child].not_present)
      node[idx].not_present_unique=false;//本节点不出现，则本节点的最优值是否唯一只和子节点出现与否时的值是否相等有关
		child=node[child].brother;
	}
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n;
	map<string,int>::iterator iter;
	string son,father;

  while(~scanf("%d",&n) && n)
  {
		map<string,int> sn_map;
		cin>>father;
		sn_map[father]=1;
		node[1].init();
		int cnt=2;
		for(int i=1;i<n;++i)
		{
			cin>>son>>father;
			iter=sn_map.find(son);
			if(iter==sn_map.end())
      {
        node[cnt].init();
				sn_map[son]=cnt++;
      }
			iter=sn_map.find(father);
			if(iter==sn_map.end())
      {
        node[cnt].init();
				sn_map[father]=cnt++;
      }
			int n_child=sn_map[son],n_father=sn_map[father];
			node[n_child].father=n_father;
			node[n_child].brother=node[n_father].child;
			node[n_father].child=n_child;
		}
    dfs(1);
    int ans,flag;
    if(node[1].present==node[1].not_present)
      ans=node[1].present,flag=0;
    else if(node[1].present>node[1].not_present)
      ans=node[1].present,flag=node[1].present_unique;
    else
      ans=node[1].not_present,flag=node[1].not_present_unique;
    printf("%d %s\n",ans,flag?"Yes":"No");
  }

  return 0;
}
