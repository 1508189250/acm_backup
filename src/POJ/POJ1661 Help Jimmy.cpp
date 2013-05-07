// POJ1661 Help Jimmy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory.h>
#include <limits>


using namespace std;

#define LIMITS 20000000
#define VEC_ELEM pair<int , pair<int,int> >

bool more_fuc(const VEC_ELEM &lhs, const VEC_ELEM &rhs)
{
	return (lhs.first > rhs.first)?true:false;
}

int main(void)
{
	int ncases;
	int N,X,Y,max;
	int xl,xr,h;
	vector<VEC_ELEM> myvec;
	scanf("%d",&ncases);
	pair<__int64,__int64> DP[40010];

	while(ncases--)
	{
		myvec.clear();

		scanf("%d %d %d %d",&N,&X,&Y,&max);
		X +=20000;
		__int64 result(LIMITS);

		for(int i=0;i<40010;++i)
		{
			DP[i].first=LIMITS;
			DP[i].second=Y ;
		}

		DP[X].first = 0;
		DP[X].second = Y;

		for(int i=0;i<N;++i)
		{
			scanf("%d %d %d",&xl,&xr,&h);
			if(h<=Y)
				myvec.push_back( VEC_ELEM(h, pair<int,int>(xl+20000,xr+20000)));
		}

		sort(myvec.begin(),myvec.end(),more_fuc);

		for(vector<VEC_ELEM >::iterator iter=myvec.begin();iter !=myvec.end();++iter)
		{

			h=(*iter).first;
			xl=(*iter).second.first;
			xr=(*iter).second.second;

			if (DP[xl].first<LIMITS)
			{
				if (DP[xl].second-h>max)
				{
					DP[xl].first=LIMITS;
					DP[xl].second=Y;
				} 
				else
				{
					DP[xl].first=DP[xl].first+DP[xl].second-h;
					DP[xl].second=h;
				}
			}
			if (DP[xr].first<LIMITS)
			{
				if (DP[xr].second-h>max)
				{
					DP[xr].first=LIMITS;
					DP[xr].second=Y;
				} 
				else
				{
					DP[xr].first=DP[xr].first+DP[xr].second-h;
					DP[xr].second=h;
				}
			}

			for(int j=xl+1;j<xr;++j)
			{
				if(DP[j].first<LIMITS && DP[j].second-h<=max && DP[j].second!=h)
				{
					int temp1,temp2;

					int distence(j-xl);
					if(distence+DP[j].second-h+DP[j].first<DP[xl].first)
					{
						DP[xl].first=distence+DP[j].second-h+DP[j].first;
						DP[xl].second=h;
					}
					temp1=DP[xl].first-distence;

					distence=(xr-j);
					if(distence+DP[j].second-h+DP[j].first<DP[xr].first )
					{
						DP[xr].first=distence+DP[j].second-h+DP[j].first;
						DP[xr].second=h;
					}
					temp2=DP[xr].first-distence;

					DP[j].first=LIMITS;

				}
			}
		}
		// 		cout<<DP[20162].first+DP[20162].second<<endl;
		for (int i=0;i<40010;++i)
		{
			if (DP[i].first+DP[i].second < result && DP[i].second<=max &&DP[i].first<LIMITS)
			{
				result = DP[i].first+DP[i].second;
			}
		}
		printf("%d\n",result);

	}


	return 0;
}

