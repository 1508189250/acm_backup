// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <map>
#define MAX 1000
using namespace std;

map<string,int> responding;
int matrix[MAX][MAX],used[MAX],mat[MAX];
int n,m,nn;

bool inline find(const int &x)
{
	for(int i=m;i<m+nn;++i)
		if(!used[i] && matrix[x][i])
		{
			used[i]=1;
			if(mat[i]==-1 || find(mat[i]))
			{
				mat[i]=x;
				return true;
			}
		}
	return false;
}

int hungary()
{
	int ans=0;
	memset(mat,-1,sizeof(mat));
	for(int i=0;i<m;++i)
	{
		memset(used,0,sizeof(used));
		if(find(i))
			++ans;
	}
	return ans;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int ncases=1,k;
	string str,style;
	scanf("%d",&ncases);
	while(ncases--)
	{
		responding.clear();
		memset(matrix,0,sizeof(matrix));
		scanf("%d",&n);
		nn=n;
		for(int i=0;i<n;++i)
		{
// 			getchar();
			cin>>str;
			responding.insert(make_pair (str,i));
		}
		scanf("%d",&m);
		for(int i=0;i<m;++i)
		{
// 			getchar();
			cin>>style>>str;
			if(responding.find(str)==responding.end())
			{
				responding.insert(make_pair(str,n++));
			}
			matrix[i][responding.find(str)->second+m]=1;
		}
		scanf("%d",&k);
		while(k--)
		{
// 			getchar();
			cin>>style>>str;
			if(responding.find(str)==responding.end())
			{
				responding.insert(make_pair(str,n++));
			}			
			if(responding.find(style)==responding.end())
			{
				responding.insert(make_pair(style,n++));
			}
			matrix[responding.find(style)->second+m][responding.find(str)->second+m]=1;
		}
		for(int i=0;i<m+n;++i)
			for(int j=0;j<m+n;++j)
				for(int k=0;k<m+n;++k)
					if(matrix[j][i]&&matrix[i][k])
						matrix[j][k]=1;
		int ans=hungary();
		printf("%d\n",m-ans);
		if(ncases)
			printf("\n");
	}

	return 0;
}
