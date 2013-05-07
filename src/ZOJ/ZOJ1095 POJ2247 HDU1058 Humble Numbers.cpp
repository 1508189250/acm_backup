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
#include <vector>
#define MAX 1000000010
#define MAX_SIZE 5845
using namespace std;
long long ans[MAX_SIZE];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  memset(ans,0,sizeof(ans));
  ans[0]=1;
  int i=0,j=0,k=0,l=0,cnt=1;

  while(cnt<MAX_SIZE)
  {
    ans[cnt] = min(2*ans[i],min(3*ans[j],min(5*ans[k],7*ans[l])));
    if(ans[cnt]==2*ans[i])
      ++i;
    if(ans[cnt]==3*ans[j])
      ++j;
    if(ans[cnt]==5*ans[k])
      ++k;
    if(ans[cnt]==7*ans[l])
      ++l;
    ++cnt;
  }

  int n;
  while(scanf("%d",&n)&&n)
  {
	  char str[3];
	  if(n%10==1 &&n%100!=11)
      strcpy(str,"st");
	  else if(n%10==2&&n%100!=12)
      strcpy(str,"nd");
	  else if(n%10==3&&n%100!=13)
      strcpy(str,"rd");
	  else
      strcpy(str,"th");
	  printf("The %d%s humble number is %d.\n",n,str,ans[n-1]);
  }
  return 0;
}
