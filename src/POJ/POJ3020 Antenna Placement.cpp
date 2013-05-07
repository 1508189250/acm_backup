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
#define MAX 50
using namespace std;

char pic[MAX][MAX];
int diff[]={-1,0,1,0,0,-1,0,1};
bool interest[MAX*MAX],map[MAX*MAX][MAX*MAX],used[MAX*MAX];
int mat[MAX*MAX];

bool find(const int &x,const int &n)
{
	for(int i=0;i<n;++i)
	{
		if(map[x][i] && !used[i] && interest[i])
		{
			used[i]=true;
			if(mat[i]==-1 || find(mat[i],n))
			{
				mat[i]=x;
				return true;
			}
		}
	}
	return false;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  
	int h,w,ncases;
	scanf("%d",&ncases);

	while(ncases--)
	{
		scanf("%d%d",&h,&w);
		memset(pic,'o',sizeof(pic));
		memset(map,0,sizeof(map));
		memset(mat,-1,sizeof(mat));
		memset(interest,false,sizeof(interest));

		getchar();
		for(int i=1;i<=h;++i)
			gets(pic[i]+1);

		int cnt=0;
		for(int i=1;i<=h;++i)
			for(int j=1;j<=w;++j)
				if(pic[i][j]=='*')
				{
					++cnt;
					interest[(i-1)*w+j-1]=true;
					for(int k=0;k<8;k+=2)
					{
						int a=i+diff[k];
						int b=j+diff[k+1];
						if(pic[a][b]=='*')
							map[(i-1)*w+j-1][(a-1)*w+b-1] = map[(a-1)*w+b-1][(i-1)*w+j-1]=1;
					}
				}
		int n=h*w;
		int ans=0;
		for(int i=0;i<n;++i)
		{
			memset(used,false,sizeof(used));
			if(interest[i])
				if(find(i,n))
					++ans;
		}

		printf("%d\n",cnt-ans+ans/2);
	}

  return 0;
}
