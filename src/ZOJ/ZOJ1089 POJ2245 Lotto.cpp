// ZOJ1089 POJ2245 Lotto.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
// 	ifstream cin("data.txt");
	int num[14];
	int n;
	int flag=1;

	while(cin>>n&&n)
	{
		if(flag)
			flag=0;
		else
			cout<<endl;

		for(int i=0;i<n;++i)
			cin>>num[i];

		for(int i=0;i+5<n;++i)
			for(int j=i+1;j+4<n;++j)
				for(int k=j+1;k+3<n;++k)
					for(int l=k+1;l+2<n;++l)
						for(int m=l+1;m+1<n;++m)
							for(int o=m+1;o<n;++o)
								printf("%d %d %d %d %d %d\n",num[i],num[j],num[k],num[l],num[m],num[o]);
	}

	return 0;
}
