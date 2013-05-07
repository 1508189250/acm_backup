/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-07-22 16:10
 * Filename : ZOJ1940 POJ2251 Dungeon Master.cpp
 * Description : 
 * *****************************************************************************/
// ZOJ1940 POJ2251 Dungeon Master.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <map>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory.h>

using namespace std;

struct point
{
	int x,y,z;
};

bool operator==(const point& lhs,const point& rhs){
	return
		((lhs.x==rhs.x)&&(lhs.y==rhs.y)&&(lhs.z==rhs.z));
}

bool operator!=(const point& lhs,const point& rhs){
	return
		!((lhs.x==rhs.x)&&(lhs.y==rhs.y)&&(lhs.z==rhs.z));
}

int main(void)
{
// 	ifstream cin("data.txt");

	int L,R,C;
	int matrix[30][30][30];
	point START,END,now,temp;
	char ch;
	int pathway;
	queue<point> bfs;
	queue<int> path;

	while(cin>>L>>R>>C && (L||R||C))
	{
		for(int i=0;i<L;i++)
			for(int j=0;j<R;j++)
				for(int k=0;k<C;++k)
				{
					cin>>ch;
					matrix[i][j][k]=ch;
					if(ch == 'S')
					{
						START.x=i;
						START.y=j;
						START.z=k;
					}
					if(ch == 'E')
					{
						END.x=i;
						END.y=j;
						END.z=k;
					}
				}

		while(!bfs.empty()) bfs.pop();
		while(!path.empty()) path.pop();

		bfs.push(START);
		path.push(0);
		matrix[START.x][START.y][START.z]='#';

// 		now=START;

		while(!bfs.empty() && bfs.front()!=END )
		{
			now=bfs.front();
			pathway=path.front();
			++pathway;
			bfs.pop();
			path.pop();

			if(now.x+1<L)
			{
				temp=now;
				temp.x++;
				if(matrix[temp.x][temp.y][temp.z] != '#')
				{
					bfs.push(temp);
					path.push(pathway);
					matrix[temp.x][temp.y][temp.z] = '#';
				}
			}

			if(now.x-1>=0)
			{
				temp=now;
				temp.x--;				
				if(matrix[temp.x][temp.y][temp.z] != '#')
				{
					bfs.push(temp);
					path.push(pathway);
					matrix[temp.x][temp.y][temp.z] = '#';
				}
			}

			if(now.y+1<R)
			{
				temp=now;
				temp.y++;
				if(matrix[temp.x][temp.y][temp.z] != '#')
				{
					bfs.push(temp);
					path.push(pathway);
					matrix[temp.x][temp.y][temp.z] = '#';
				}
			}

			if(now.y-1>=0)
			{
				temp=now;
				temp.y--;
				if(matrix[temp.x][temp.y][temp.z] != '#')
				{
					bfs.push(temp);
					path.push(pathway);
					matrix[temp.x][temp.y][temp.z] = '#';
				}
			}

			if(now.z+1<C)
			{
				temp=now;
				temp.z++;
				if(matrix[temp.x][temp.y][temp.z] != '#')
				{
					bfs.push(temp);
					path.push(pathway);
					matrix[temp.x][temp.y][temp.z] = '#';
				}
			}

			if(now.z-1>=0)
			{
				temp=now;
				temp.z--;				
				if(matrix[temp.x][temp.y][temp.z] != '#')
				{
					bfs.push(temp);
					path.push(pathway);
					matrix[temp.x][temp.y][temp.z] = '#';
				}
			}


		}

		if (!bfs.empty())
		{
			cout<<"Escaped in "<<path.front()<<" minute(s)."<<endl;
		} 
		else
		{
			cout<<"Trapped!"<<endl;
		}

	} 

	return 0;
}
