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
#define MAX 300
using namespace std;

int mat[MAX][MAX];

int func(const int &n,const int &m)
{
	int ans=0;
	int num[5];

	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
		{
			memset(num,0,sizeof(num));
			for(int k=0;k<m;++k)
					if(mat[i][k]==mat[j][k])
						++num[mat[i][k]];

			for(int i=0;i<5;++i)
				ans+=((num[i]*(num[i]-1))>>1);
		}
	return ans;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int ncases,n,m,tmp;
	char ch;
	scanf("%d",&ncases);
	while(ncases--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i)
		{
			getchar();
			for(int j=0;j<m;++j)
			{
				ch=getchar();
				switch(ch)
				{
					case 'B':
						tmp=0;
						break;
					case 'J':
						tmp=1;
						break;
					case 'H':
						tmp=2;
						break;
					case 'Y':
						tmp=3;
						break;
					case 'N':
						tmp=4;
						break;
				}
				mat[i][j]=tmp;
			}
		}

		int ans=func(n,m);;
		printf("%d\n",ans);
	}

  return 0;
}
