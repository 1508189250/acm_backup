/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-12-08 21:01
 # Filename: POJ2187 Beauty Contest.cpp
 # Description : 
 ******************************************************************************/
#include "stdafx.h"
#define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#define MAX 50010
#define EPS 1e-6
using namespace std;

struct POINT
{
	double x,y;
}tree[MAX],stk[MAX];

int len;

double inline crossProduct(const POINT &a,const POINT &b,const POINT &c)	
//����ac��ab�ķ���
{
	return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);  
}

/************************************************************************/
/*double�Ĵ�С�ж�                                                      */
/************************************************************************/
bool inline _less(const double &lhs,const double &rhs)			{	return lhs < rhs - EPS;  }
bool inline _less_or_equal(const double &lhs,const double &rhs)	{	return lhs < rhs + EPS;  }
bool inline _equal(const double &lhs,const double &rhs)			{	return fabs(lhs-rhs)< EPS;  }
bool inline _greater(const double &lhs,const double &rhs)		{	return lhs>rhs+EPS;}
bool inline _greater_or_equal(const double &lhs,const double &rhs){	return lhs>rhs-EPS;}

/************************************************************************/
/* ��������ľ���                                                       */
/************************************************************************/
double inline Distance(const POINT &lhs,const POINT &rhs)
{
  return sqrt((lhs.x-rhs.x)*(lhs.x-rhs.x)+(lhs.y-rhs.y)*(lhs.y-rhs.y));
}
double Dis(POINT a,POINT b) {
  return ( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}

bool cmp(POINT a,POINT b){
  double len = crossProduct(tree[0],a,b);
  if( _equal(len,0.0) )
    return _less(Distance(tree[0],a),Distance(tree[0],b));
  return _less(len,0.0);
}

// int stk[MAX];
int top;
double Rotating_calipers(POINT *stk,int n){
  stk[n] = stk[0];
  int q = 1;
  double ans = 0.0;
  for(int i=0; i<n; i++){
//     while( _less(fabs(crossProduct(stk[i],stk[i+1],stk[q])),fabs(crossProduct(stk[i],stk[i+1],stk[q+1]))) )
    while(_less(crossProduct(stk[i+1],stk[i],stk[q]),crossProduct(stk[i+1],stk[i],stk[q+1])))
      q = (q+1)%n;
    ans = max(ans,Dis(stk[i],stk[q]));
  }
  return ans;
}

double Graham(int n){    
  int tmp = 0;      
  for(int i=1; i<n; i++)    	
    if( _less(tree[i].x,tree[tmp].x) || _equal(tree[i].x,tree[tmp].x) && _less(tree[i].y,tree[tmp].y) )    		
      tmp = i;    
  swap(tree[0],tree[tmp]);    
  sort(tree+1,tree+n,cmp);    
  stk[0] = tree[0]; 
  stk[1] = tree[1];    
  top = 1;
  for(int i=2; i<n; i++){
    while( _less_or_equal( crossProduct(stk[top],stk[top-1],tree[i]), 0.0 ) && top >= 1 )
      top--;
    stk[++top] = tree[i];
  }
  return Rotating_calipers(stk,top+1);
}
int main(){
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
  int n;
  while( ~scanf("%d",&n) && n ){
    for(int i=0; i<n; i++)
      scanf("%lf %lf",&tree[i].x,&tree[i].y);
    int ans = (int)Graham(n);
    printf("%d\n",ans);
  }
  return 0;
}
