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
#define MAX 100010
using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

//   int n,ncase=1;
	string str;
	bool used[MAX],flag=true;
	int num[MAX],cnt=0,ans[MAX];
	queue<int> q;
  memset(used,false,sizeof(used));

	while(getline(cin,str,')'))
	{
		if(str[str.size()-1]=='(')
		{
			while(!q.empty())
				q.pop();
			if(used[1])
				q.push(1);
			else
				flag=false;
			int n=0;
			if(flag)
				while(!q.empty())
				{
					int x=q.front();
					q.pop();
					ans[n++]=num[x];
					if(used[x*2])
						q.push(x*2);
					if(used[x*2+1])
						q.push(x*2+1);
				}
			if(n!=cnt)
				flag=false;
			if(flag)
				for(int i=0;i<n;++i)
					printf("%d%c",ans[i],i==(n-1)?'\n':' ');
			else
				printf("not complete\n");

			flag=true;
			memset(used,false,sizeof(used));
			cnt=0;
		}
		else
		{
			int tmp=0;
			int i;
			for(i=1;i<str.size();++i)
				if(str[i]==',')
					break;
				else if(isdigit(str[i]))
				{
					tmp*=10;
					tmp+=(str[i]-'0');
				}

			++i;
			int index=1;
			for(;i<str.size();++i)
				if(str[i]=='L')
					index*=2;
				else if(str[i]=='R')
					index=(index*2+1);
			if(used[index])
				flag=false;
      used[index]=true;
			num[index]=tmp;
			++cnt;
		}
	}

  return 0;
}
