/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-04-08 20:51
 # Filename: ZOJ1486 Color the Tree.cpp
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
#include <vector>
#define MAX 60
#define MAX_DIGIT 200
using namespace std;

vector<int> vec_array[MAX];
// int visit[MAX],ans;
int n,m;

int multiply(int* a,int ca,int* b,int cb,int* c)  
{  
  int i,j,* s;  
  s=(int*)malloc(sizeof(int)*(ca+cb));  
  for (i=0;i<ca+cb;i++)  
    s[i]=0;  
  for (i=0;i<ca;i++)  
    for (j=0;j<cb;j++)  
      s[i+j+1]+=(a[i])*(b[j]);//i+j+1的目的就是为了防止最高位进位而产生错误  
  for (i=ca+cb-1;i>=0;i--)  
    if (s[i]>=10)  
    {  
      s[i-1]+=s[i]/10;  
      s[i]%=10;  
    }  
    i=0;  
    while (s[i]==0)  
      i++;//去除前导0  
    for (j=0;i<ca+cb;i++,j++)  
      c[j]=s[i];  
    free(s);  
    return j;
}  

bool in_degree[MAX],visit[MAX];

void dfs(const int &x)
{
	visit[x]=true;
	for(int i=0;i<vec_array[x].size();++i)
		if(!visit[vec_array[x][i]])
		{
			in_degree[vec_array[x][i]]=true;
			dfs(vec_array[x][i]);
		}
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int u,v;

  while(~scanf("%d%d",&n,&m) && n+m)
  {
		for(int i=1;i<=n;++i)
			vec_array[i].clear();
		for(int i=1;i<n;++i)
		{
			scanf("%d%d",&u,&v);
			vec_array[u].push_back(v);
			vec_array[v].push_back(u);
		}

		memset(visit,false,sizeof(visit));
		memset(in_degree,false,sizeof(in_degree));
		for(int i=1;i<=n;++i)
			if(!visit[i])
				dfs(i);

		int a[MAX_DIGIT],b[MAX_DIGIT],c[MAX_DIGIT];
		int ca=0,cb=0,cc=0;
		int tmp=m;

		if(in_degree[1])
			--tmp;
		if(tmp>9)
		{
			a[0]=tmp/10;
			a[1]=tmp%10;
			ca=2;
		}
		else
		{
			a[0]=tmp;
			ca=1;
		}
		
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));

		for(int i=2;i<=n;++i)
		{
			tmp=m;
			if(in_degree[i])
				--tmp;
			if(tmp>9)
			{
				b[0]=tmp/10;
				b[1]=tmp%10;
				cb=2;
			}
			else
			{
				b[0]=tmp;
				cb=1;
			}
			cc=multiply(a,ca,b,cb,c);
			memcpy(a,c,sizeof(a));
			ca=cc;
		}
    if(ca==0)
      printf("0");
    else
  		for(int i=0;i<ca;++i)
	  		printf("%d",a[i]);
		printf("\n");
  }

  return 0;
}
