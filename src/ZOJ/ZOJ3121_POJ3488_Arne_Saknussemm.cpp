/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-07-12 16:43
 * Filename : ZOJ3121_POJ3488_Arne_Saknussemm.cpp
 * Description : ZOJ3121 POJ3488 Arne Saknussemm
 * *****************************************************************************/
// ZOJ3121_POJ3488_Arne_Saknussemm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

int main(void)
{
	//ifstream cin("data.txt");
	char fragments[1001][1001];
	int n,length;
	int i,j,flag =1;
	string str;
	while(cin>>n)
	{
		for(i=0;i<n;++i)
		{
			str.clear();
			cin>>str;
			for(j=0;j<str.length();++j)
				fragments[i][j] = str.at(j);
		}
		length = str.length();
		str.clear();
		for(j = length-1; j>=0;--j)
			for(i = n-1;i>=0;--i)
			{
				if(fragments[i][j] == '_')
					str += ' ';
				else if(fragments[i][j] == '\\')
					str +='\n';
				else
					str += fragments[i][j];
			}

		for (length = str.length()-1;length>=0;--length)
		{
			if (str.at(length) != ' ')
			{
				break;
			}
		}

		for(i = 0 ;i<=length;++i)
		{
			printf("%c",str.at(i));
		}
		cout<<endl<<endl;
	}


	return 0;
}


