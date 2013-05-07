// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <ctype.h>
#include <map>
using namespace std;

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int code[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9};
	int ncases,n,cou,len;
	char str[100];
	string num;
	map<string,int> mmap;


	scanf("%d",&ncases);

	while(ncases--)
	{
		mmap.clear();
		scanf("%d",&n);
		getchar();

		for(int i=0;i<n;++i)
		{
			gets(str);
			cou=0;
			num.clear();
			for(int i=0;str[i];++i)
			{
				if(cou==3)
				{
					++cou;
					num+='-';
				}
				if(isalpha(str[i]))
				{
					++cou;
					num+=code[str[i]-'A']+'0';
				}
				else if(isdigit(str[i]))
				{
					++cou;
					num+=str[i];
				}
			}
			mmap[num]++;
		}

		map<string,int>::iterator iter=mmap.begin();
		bool flag=true;
		for(;iter!=mmap.end();++iter)
		{
			if((*iter).second>1)
			{
				flag=false;
				printf("%s %d\n",iter->first.c_str(),iter->second);
			}
		}
		if(flag)
			printf("No duplicates.\n");
		if(ncases>0)
			printf("\n");
	}

	return 0;
}
