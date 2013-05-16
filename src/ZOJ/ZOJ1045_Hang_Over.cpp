/*
 * =====================================================================================
 *
 *       Filename:  ZOJ1045_Hang_Over.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/5/14 7:22:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Neo Fung (http://blog.neofung.org), iam AT neofung DOT org
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <math.h>

using namespace std;

int main(void)
{
    //ifstream cin("data.txt");
    double c;
    double length[1000];
    int i,n;
    length[0]=0.0;
    for(i=1;length[i-1]<=5.20;++i)
    {
        //c = 1.0/(i+1);
        length[i]=length[i-1]+1.0/(i+1);
    }

    n=i;

    while(cin>>c &&  c > 0.000001)
    {
        for(i=0;i<n;++i)
        {
            if(c<length[i])
            {
                cout<<i<<" card(s)"<<endl;
                break;
            }
        }

    }


    return 0;
}
