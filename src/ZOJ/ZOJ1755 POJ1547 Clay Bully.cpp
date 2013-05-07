// ZOJ1755 POJ1547 Clay Bully.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



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

using namespace std;

struct student
{
	int x,y,z;
	int size;
	string name;
};

int main(void)
{
// 	ifstream cin("data.txt");

	int num;
	int maxsize,minsize;
	string maxname,minname;
	student tempStu;

	while(cin>>num && num>0)
	{
		maxsize=0;
		minsize=500;
		for(int i=0;i<num;++i)
		{
			cin>>tempStu.x>>tempStu.y>>tempStu.z>>tempStu.name;
			tempStu.size=tempStu.x * tempStu.y*tempStu.z;
			if(tempStu.size >maxsize)
			{
				maxsize=tempStu.size;
				maxname=tempStu.name;
			}
			if(tempStu.size<minsize)
			{
				minsize=tempStu.size;
				minname=tempStu.name;
			}
		}
		cout<<maxname<<" took clay from "<<minname<<'.'<<endl;
	}


	return 0;
}
