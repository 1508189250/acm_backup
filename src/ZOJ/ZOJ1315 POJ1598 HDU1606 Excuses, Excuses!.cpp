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
#define MAX 100
using namespace std;

string excuse[MAX],str[MAX];
int ans[MAX];

bool stringCompareIgnoreCase(std::string lhs,std::string rhs)
{
  return _stricmp(lhs.c_str(),rhs.c_str());
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int n,k;
	int ncases=1;

	while(cin>>n>>k)
	{
		memset(ans,0,sizeof(ans));
		for(int i=0;i<n;++i)
			cin>>excuse[i];
		for(int i=0;i<k;++i)
		{
			getline(str[i],cin);
			
		}
	}

  return 0;
}
