// ZOJ1796 Euchre Results.cpp : Defines the entry point for the console application.
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

int main(void)
{
// 	ifstream cin("data.txt");
	int Bwin,Blost,Cwin,Clost,Zwin,Zlost;

	while(cin>>Bwin>>Blost>>Cwin>>Clost>>Zwin>>Zlost
			&& (Bwin||Blost||Cwin||Clost||Zwin||Zlost))
	{
		cout<<"Anna's won-loss record is "
			<<Blost+Clost-Zwin
			<<'-'
			<<Bwin+Cwin-Zlost
			<<'.'
			<<endl;
	}


	return 0;
}
