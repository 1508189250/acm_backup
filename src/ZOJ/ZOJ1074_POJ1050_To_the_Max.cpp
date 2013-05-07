/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-07-08 14:16
 * Filename : ZOJ1074_POJ1050_To_the_Max.cpp
 * Description : To The Max 
 * *****************************************************************************/
// ZOJ1074_POJ1050_To_the_Max.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void SumRow(int matrix[100][100],int up ,int down,int *sum,int n)
{
	for(int i=0;i<n;++i)
	{
		sum[i]=0;
		for(int j=down;j<=up;++j)
			sum[i]+=matrix[i][j];
	}
	

}

int main(void)
{
	const int N=100;
	int matrix[N][N]={0};
	int sum[N]={0};
	//ifstream cin("data.txt");
	int n;
	int i,j,k;
	int nAll,nStart,maxsum;
	cin>>n;
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			cin>>matrix[i][j];

	maxsum=-1000;
	for(i=0;i<n;++i)
		for(j=i;j<n;++j)
		{
			SumRow(matrix,j,i,&sum[0],n);
			nAll=nStart=sum[n-1];
			for (k=n-2;k>-1;--k)
			{
				if (nStart<0)
				{
					nStart=0;
				}
				nStart+=sum[k];
				if (nAll<nStart)
				{
					nAll=nStart;
				}
			}

			if (maxsum<nAll)
			{
				maxsum=nAll;
			}

		}

		cout<<maxsum<<endl;

	return 0;
}

