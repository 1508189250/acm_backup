// ZOJ3019 Puzzle.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#define MAX 10010

using namespace std;

int main(void)
{
// 	ifstream cin("data.txt");
	int n,m;
	int array1[MAX],array2[MAX];

	while(cin>>n>>m)
	{
		int i,j;

		for(i=0;i<n;++i)
			cin>>array1[i];
		for(j=0;j<m;++j)
			cin>>array2[j];
		sort(array1,array1+n);
		sort(array2,array2+m);

		int index=-1;
		int sum=0;
		for(i=0;i<n;++i)
			for(j=index+1;j<m;++j)
			{
				if(array1[i]==array2[j])
				{
					++sum;
					index=j;
					break;
				}
			}
		cout<<sum<<endl;
	}

	return 0;
}

