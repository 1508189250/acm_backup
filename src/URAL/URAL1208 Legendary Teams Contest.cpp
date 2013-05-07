#include "stdafx.h"
#define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#include <map>
#define MAX 25
using namespace std;

char name[MAX*3][MAX];
int in_team[MAX];
int matrix[MAX][3];
int /*mat[MAX*3],*/used[MAX*3];
int n_student,max_sum;
int n_k;

int find(const char *str)
{
  for (int i=0;i<n_student;++i)
    if(strcmp(str,name[i])==0)
      return i;
  return -1;
}
bool check(const int &x)
{
	for(int i=0;i<3;++i)
		if(used[matrix[x][i]])
			return false;
	return true;
}
void setUsed(const int &x,const int &mark)
{
	for(int i=0;i<3;++i)
		used[matrix[x][i]]=mark;
}
void dfs(const int &now,int sum)
{
	max_sum=max(max_sum,sum);
  for(int i=now+1;i<n_k;++i)
		if(check(i))
		{
			setUsed(i,1);
			dfs(i,sum+1);
			setUsed(i,0);
		}
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

  map<string,int> student;
  char str[21];

  scanf("%d",&n_k);
  n_student=0;
  max_sum = 0;
  memset(name,'\0',sizeof(name));
  memset(matrix,0,sizeof(matrix));			
  memset(used,0,sizeof(used));
//   memset(mat,0,sizeof(mat));
  memset(in_team,0,sizeof(in_team));

  for(int i=0;i<n_k;++i)
  {
    for(int j=0;j<3;++j)
    {
      scanf("%s",str);
      int ind = find(str);
      if(ind==-1)
      {
        ind=n_student++;
        strcpy(name[ind],str);
      }
      matrix[i][j]=ind;
    }
  }

  dfs(-1,0);
  printf("%d\n",max_sum);

  return 0;
}
