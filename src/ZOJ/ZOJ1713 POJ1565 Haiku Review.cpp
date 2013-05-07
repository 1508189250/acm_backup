#ifdef _MSC_VER
#define DEBUG
#endif

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
//#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>

using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	string str,sub_str[4];
	string syllables="aeiouy";

	while(getline(cin,str))
	{
		if(str=="e/o/i")
			break;
    str.append("/");
		int n=str.find('/');
		sub_str[1]=str.substr(0,n+1);
		int pre=n+1;
		n=str.find('/',pre);
		sub_str[2]=str.substr(pre,n-pre+1);
		sub_str[3]=str.substr(n+1,str.length()-n-1);
		int flag=0;

		for(int i=1;i<4;++i)
		{
			int cnt=0;
			for(int j=0;j<syllables.length();++j)
			{
				pre=n=0;
				n=sub_str[i].find(syllables.at(j),pre);
				while(n!=string::npos)
				{
					if(syllables.find(sub_str[i].at(n+1))==string::npos)
						++cnt;
					pre=n+1;
					n=sub_str[i].find(syllables.at(j),pre);
				}
			}
			if(!flag &&i==2&& cnt!=7)
				flag=i;
			else if(!flag && i!=2&&cnt!=5)
				flag=i;
		}
		if(flag)
			printf("%d\n",flag);
		else
			printf("Y\n");
	}

  return 0;
}
