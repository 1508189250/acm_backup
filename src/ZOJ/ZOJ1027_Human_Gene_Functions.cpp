/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-07-12 16:46
 * Filename : ZOJ1027_Human_Gene_Functions.cpp
 * Description : ZOJ1027 POJ1080	Human Gene Functions
 * *****************************************************************************/
// ZOJ1027_Human_Gene_Functions.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
//#include <fstream>

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

int max(int a,int b,int c)
{
	int temp;
	temp = a>b ? a : b;
	temp = temp>c ? temp : c;
	return temp;

}

int main(void)
{
	//ifstream cin("data.txt");
	int ncase;
	int alen,blen;
	int i,j,k;
	int l,m,n;

	int alaph[128]={0};
	char astr[101],bstr[101];
	int match[5][5]={5,-1,-2,-1,-3,-1,5,-3,-2,-4,-2,-3,5,-2,-2,-1,-2,-2,5,-1,-3,-4,-2,-1,0};
	int matrix[101][101]={0};


	alaph['A']=0;
	alaph['C']=1;
	alaph['G']=2;
	alaph['T']=3;

	cin>>ncase;
	while(ncase)
	{
		cin>>alen;
		for(i=1;i<=alen;++i)
		{
			cin>>astr[i];
		}
		cin>>blen;
		for(i=1;i<=blen;++i)
			cin>>bstr[i];

		for(i=1;i<=alen;++i)
		{
			matrix[i][0] = matrix[i-1][0] + match[alaph[astr[i]]][4];
		}
		for(j=1;j<=blen;++j)
		{
			matrix[0][j] = matrix[0][j-1] + match[4][alaph[bstr[j]]];
//			matrix[0][j] = matrix[0][j-1] + match[alaph[astr[j]]][4];
		}

		for(i=1;i<=alen;++i)
			for(j=1;j<=blen;++j)
			{
				/************************************************************************/
				/*  1：i-1已经与j-1匹配 此时i，j的匹配结果为 matrix[i-1][j-1]+(i与j的匹配值)	*/
				/*	2：i与j-1匹配  此时 j只能与“-”匹配  结果为 matrix[i][j-1]+(j与'-'的匹配值)*/
				/*  3：i-1与j匹配  此时恰好与2相反                                              */
				/************************************************************************/
				l = match[alaph[astr[i]]][alaph[bstr[j]]] + matrix[i-1][j-1];
				m = match[4][alaph[bstr[j]]] + matrix[i][j-1];
				n = match[alaph[astr[i]]][4] + matrix[i-1][j];
				matrix[i][j] = max(l,m,n);
			}

		cout << matrix[alen][blen]<<endl;

		--ncase;
	}


	return 0;
}

