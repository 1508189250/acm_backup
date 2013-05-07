#ifdef _MSC_VER
#define DEBUG
#endif

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
//#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#include <vector>
using namespace std;

#define  MAX 50005              //��Ŀ�п��ܵ�������       
int STACK[MAX],top;          //Tarjan �㷨�е�ջ 
bool InStack[MAX];             //����Ƿ���ջ�� 
int DFN[MAX];                  //��������������ʴ��� 
int Low[MAX];                  //��׷�ݵ�����ջ�е��������
int ComponentNumber;       //����ͼǿ��ͨ�������� 
int Index;                 //������ 
vector <int> Edge[MAX];        //�ڽӱ��ʾ 
int InComponent[MAX];			//��¼ÿ�����ڵڼ���ǿ��ͨ������
void Tarjan(int i) 
{ 
  int j; 
  DFN[i]=Low[i]=Index++; 
  InStack[i]=true; 
  STACK[++top]=i; 
  for (size_t e=0;e<Edge[i].size();e++) 
  { 
    j=Edge[i][e]; 
    if (DFN[j]==-1) 
    { 
      Tarjan(j); 
      Low[i]=min(Low[i],Low[j]); 
    } 
    else if (InStack[j]) //���ָ��Ľڵ�j����ջ�У�����j����i��ջ����j�е�i��ͨ·��ͬʱ����iָ��j����i��j���ɻ�·
      Low[i]=min(Low[i],DFN[j]); 	//���ָ��Ľڵ�����ջ�У���ָ��Ľڵ���δ����ǿ��ͨ����
    //���ǰ�������ж��������Ǵ���Ļ�����i��j����ͬһ����ͨ������
  } 
  if (DFN[i]==Low[i]) //��ͨ�����������ջ�ĵ�
  { 
    ComponentNumber++; 
    do 
    { 
      j=STACK[top--]; 
      InStack[j]=false; 
//       Component[ComponentNumber].push_back(j);
      InComponent[j]=ComponentNumber;	//��ÿһ����ͨ�����ϵĽڵ�Ⱦɫ
    } 
    while (j!=i); 
  } 
}

void solve(int N)     //N�Ǵ�ͼ�е�ĸ�����ע����0-indexed�� 
{ 
  memset(STACK,-1,sizeof(STACK)); 
  memset(InStack,0,sizeof(InStack)); 
  memset(DFN,-1,sizeof(DFN)); 
  memset(Low,-1,sizeof(Low)); 
  top=0;Index=0;ComponentNumber=0;

  for(int i=1;i<=N;i++) 
    if(DFN[i]==-1) 
      Tarjan(i);    
}

vector<int> v_component_edge[MAX];
int used[MAX];
int mat[MAX];
bool find(const int &x)
{
  size_t i;
  for(i=0;i<v_component_edge[x].size();++i)
  {
    int v=v_component_edge[x][i];
    if(!used[v])
    {
      used[v]=1;
      if(mat[v]==-1 || find(mat[v]))
      {
        mat[v]=x;
        return true;
      }
    }
  }
  return false;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int ncases,n,m,u,v;
  scanf("%d",&ncases);

  while(ncases--)
  {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
      Edge[i].clear();
      v_component_edge[i].clear();
    }
    while(m--)
    {
      scanf("%d%d",&u,&v);
      Edge[u].push_back(v);
    }

    solve(n);

    for(int i=1;i<=n;++i)
      for(size_t j=0;j<Edge[i].size();++j)
        if(InComponent[i]!=InComponent[Edge[i][j]])
          v_component_edge[InComponent[i]].push_back(InComponent[Edge[i][j]]);

    int ans=0;
    memset(mat,-1,sizeof(mat));
    for (int i=1;i<=ComponentNumber;++i)
    {
      memset(used,0,sizeof(used));
      if(find(i)) ++ans;
    }

    printf("%d\n",ComponentNumber-ans);

  }

  return 0;
}
