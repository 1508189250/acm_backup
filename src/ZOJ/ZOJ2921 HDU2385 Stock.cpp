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

int recives[MAX],price[MAX],sell[MAX],sum[MAX];

struct SHARE
{
  int price,sell;
  bool operator<(const SHARE &tmp) const
  {
    return price<tmp.price;
  }
};

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncase=1;
   scanf("%d",&ncase);

	 while(ncase--)
	 {
		 scanf("%d",&n);
		 int ans=0;
		 for(int i=0;i<n;++i)
			 scanf("%d%d%d",&recives[i],&price[i],&sell[i]);
		 priority_queue<SHARE> q;
		 SHARE share;
		 for(int i=n-1;i>=0;--i)
		 {
       share.sell=sell[i];
       share.price=price[i];
       q.push(share);
			 while(recives[i] && !q.empty())
			 {
				share=q.top();
				q.pop();
				if(share.sell>recives[i])
				{
					ans+=recives[i]*share.price;
					share.sell-=recives[i];
					recives[i]=0;
					q.push(share);
				}
				else 
				{
					ans+=share.sell*share.price;
					recives[i]-=share.sell;
				}
			 }
		 }
		 printf("%d\n",ans);
	 }

  return 0;
}
