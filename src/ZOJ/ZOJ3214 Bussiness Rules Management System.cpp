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
#include <queue>
#define MAX 100010
using namespace std;

struct NODE
{
  string rule;
  int priority,time;
  bool operator<(const NODE &tmp) const
  {
    if(priority==tmp.priority)
      return time<tmp.time;
    else
      return priority<tmp.priority;
  }
}node;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncase=1,pri;
  string sz_str;
  char op;
  scanf("%d",&ncase);

  while(cin>>n )
  {
    map<string,int> rule,is_del;
    priority_queue<NODE> que;

    for (int i=0;i<n;++i)
    {
      cin>>sz_str>>pri;
      rule[sz_str]=pri;
      is_del[sz_str]=0;
    }
    int m;
    cin>>m;
    for(int i=0;i<m;++i)
    {
      cin>>op;
      if(op=='a')
      {
        cin>>sz_str;
        node.rule=sz_str;
        node.time=i;
        node.priority=rule[sz_str];
        que.push(node);
        is_del[sz_str]=0;
      }
      else if(op=='d')
      {
        cin>>sz_str;
        is_del[sz_str]=1;
      }
      else
      {
        //         bool flag=true;
        while(1)
        {
          if (que.empty())
          {
            cout<<"<empty>"<<endl;
            break;
          }
          node=que.top();
          que.pop();
          if(is_del[node.rule])
            continue;
          else
          {
            cout<<node.rule<<endl;
            is_del[node.rule]=1;
            break;
          }
        }
      }
    }
  }

  return 0;
}