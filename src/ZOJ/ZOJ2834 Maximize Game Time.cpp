/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-04-28 20:12
 # Filename: ZOJ2834 Maximize Game Time.cpp
 # Description : 
 ******************************************************************************/
#ifdef _MSC_VER
#define DEBUG
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#define MAX 1010
using namespace std;

struct NODE
{
  //�ø���-�ֵܽڵ��ʾ�����
  int father,child,brother;
  //max_child_extinction, ��ʾ����˽ڵ�û�б�ɱ�������ӽڵ��������ɱ����������������������Ŀ����ֻ֪��һ�����ӵ�ȫ�ұ�ɱ�����������Ӳ���ɱ�������������ӵĺ����ܹ�ɱ��
  //dp, ��������ģ��˽ڵ㱻ɱ���������
  //extinction, �Դ˽ڵ�Ϊ����������ȫ�������ʱ��
  //kill, ɱ������ڵ���Ҫ����ʱ��
  int max_child_extinction,dp,extinction,kill;
  void init()
  {
    father=child=brother=-1;
    dp=extinction=max_child_extinction=0;
  }
}node[MAX];

int input[MAX][2];

//ɱ��idxΪ����������ȫ������Ҫ��ʱ��
int TotalFamilyExtinction(const int &idx)
{
  if(node[idx].extinction)
    return node[idx].extinction;
  node[idx].extinction=node[idx].kill;
  int child=node[idx].child;
  while(child>-1)
  {
    node[idx].extinction+=TotalFamilyExtinction(child);
    child=node[child].brother;
  }
  return node[idx].extinction;
}

//idx��ɱ��������£���idxΪ����������ܹ�����ʱ��
int MaxChildExtinction(const int &idx)
{
	if(node[idx].max_child_extinction)
		return node[idx].max_child_extinction;
  int child=node[idx].child;
  //����ÿһ���������childȫ�ұ�ɱ������child����ɱ����������child��child�ܹ�ɱ��
  while(child>-1)
  {
    int tmp=TotalFamilyExtinction(child);
    int sec_child=node[idx].child;
    while(sec_child>-1)
    {
      if(sec_child!=child)
        tmp+=MaxChildExtinction(sec_child);
      sec_child=node[sec_child].brother;
    }
    node[idx].max_child_extinction=max(tmp, node[idx].max_child_extinction);
    child=node[child].brother;
  }
  return node[idx].max_child_extinction;
}


int dfs(const int &idx)
{
  if(node[idx].dp)
    return node[idx].dp;
  node[idx].dp = node[idx].kill;
  int child=node[idx].child,sum=0;
  while(child>-1)
  {
    sum+=MaxChildExtinction(child);
    child=node[child].brother;
  }
  child=node[idx].child;
  int ans=0;
  while(child>-1)
  {
    ans=max(ans,TotalFamilyExtinction(child));
    int sec_child=node[idx].child;
    while(sec_child>-1)
    {
      if(child!=sec_child)
        //dpΪ�����˽ڵ�idx��ɱ�����Ҫʱ��
        //��Ϊ����ľ��裬����idx��dp��Ȼ����һ������childȫ�ұ�ɱ������һ������sec_child��dp���Լ���ĺ��Ӳ���ɱ�������Ǳ�ĺ��ӵĺ����ܹ�����ɱ�����ʱ��
        ans=max(ans,sum-MaxChildExtinction(child)-MaxChildExtinction(sec_child)+TotalFamilyExtinction(child)+dfs(sec_child));
      sec_child=node[sec_child].brother;
    }
    child=node[child].brother;
  }
  node[idx].dp+=ans;
  return node[idx].dp;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,father;
  //   scanf("%d",&ncase);

  while(~scanf("%d",&n) && n)
  {
    for(int i=0;i<n;++i)
    {  
      node[i].init();
      scanf("%d",&node[i].kill);
    }
    for(int i=0;i<n;++i)
    {
      scanf("%d",&father);
      node[i].father=father;
      if(father==-1)
        continue;
      node[i].brother=node[father].child;
      node[father].child=i;
    }
    int ans=0;
    //ע����ܴ���ɭ�ֵ��������������n-1Ϊ����������������������ȫ��ɱ��
    for(int i=0;i<n-1;++i)
      if(node[i].father==-1)
        ans+=TotalFamilyExtinction(i);
    ans+=dfs(n-1);
    printf("%d\n",ans);
  }

  return 0;
}
