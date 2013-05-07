/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-16 11:54
 # Filename: ZOJ3041 City Selection.cpp
 # Description : 
 ******************************************************************************/
#ifdef _MSC_VER
#define DEBUG
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
#define MAX 200010
using namespace std;

struct POINT
{
	int x,y;
}citys[MAX],factory[MAX],result[MAX];

bool inline cmp(const POINT &lhs,const POINT &rhs)
{
	if(lhs.x==rhs.x)
		return lhs.y>rhs.y;
	else
		return lhs.x<rhs.x;
}
bool inline cmp1(const POINT &lhs,const POINT &rhs)
{
	if(lhs.x==rhs.x)
		return lhs.y<rhs.y;
	else
		return lhs.x<rhs.x;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m;
  while(~scanf("%d%d",&n,&m))
  {
	  for(int i=0;i<n;++i)
		  scanf("%d%d",&citys[i].x,&citys[i].y);
	  for(int i=0;i<m;++i)
		  scanf("%d%d",&factory[i].x,&factory[i].y);
	  sort(citys, citys+n,cmp);
	  sort(factory,factory+m,cmp);
	  
	  int ans=0;
	  bool pre=true;
	  int pre_ind=0;
	  for(int i=0;i<n ;++i)
	  {
		  bool flag=true;
		  for(int j=0;j<m && flag;++j)
			  if(citys[i].x>=factory[j].x && citys[i].y<=factory[j].y)
				  flag=false;
		  if(flag)
			  result[ans++]=citys[i];
	  }
	  sort(result,result+ans,cmp1);
	  printf("%d\n",ans);
	  for(int i=0;i<ans;++i)
		  printf("%d %d\n",result[i].x,result[i].y);
  }
	return 0;
}
