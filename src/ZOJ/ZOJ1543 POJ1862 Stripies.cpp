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
#include <queue>
#define MAX 110
using namespace std;

// double num[MAX];


int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int n;
  double x,y;

	while(~scanf("%d",&n))
	{
    priority_queue<double> m_q;
    double temp;
		for(int i=0;i<n;++i)
    {
			scanf("%lf",&temp);
      m_q.push(temp);
    }
		
//     if(n<2)
//     {
//       printf("0.000\n");
//       continue;
//     }
    while(m_q.size()>1)
    {
      x=m_q.top();
      m_q.pop();
      temp = 2*sqrt(x*m_q.top());
      m_q.pop();
      m_q.push(temp);
    }

		printf("%.3lf\n",m_q.top());
	}

  return 0;
}
