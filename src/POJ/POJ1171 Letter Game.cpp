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
#define MAX 128
using namespace std;

struct NODE
{
	int len,score;
  char str[MAX];
	bool operator<(const NODE &tmp) const
	{
		if(len==tmp.len)
			return score>tmp.score;
		else
			return len>tmp.len;
	}
}node[40010];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  
	int value[26] = {2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
	char collect[MAX],str[MAX];
	int sum[MAX],t_array[MAX];

	gets(collect);
	memset(sum,0,sizeof(sum));
// 	memcpy(score,0,sizeof(score))
	for(int i=0;collect[i];++i)
		++sum[collect[i]];

	int cnt=0;
	while(gets(str) && str[0]!='.')
	{
		memcpy(t_array,sum,sizeof(t_array));
		node[cnt].len=strlen(str);
		int tmp=0,flag=1;
		for(int i=0;str[i] && flag;++i)
		{
			if(!t_array[str[i]])
				flag=0;
			--t_array[str[i]];
			tmp+=value[str[i]-'a'];
		}
    if(!flag)
      continue;
    strcpy(node[cnt].str,str);
		node[cnt++].score=tmp;
	}
	sort(node,node+cnt);

	int line_3,line_4=0;
	for(;line_4<cnt;++line_4)
		if(node[line_4].len<=4)
			break;
	for(line_3=line_4;line_3<cnt;++line_3)
		if(node[line_3].len<=3)
			break;

	int ans=0;
	for(int i=0;i<cnt;++i) 
		ans=max(ans,node[i].score);
	for(int i=line_4;i<cnt;++i)
		for(int j=line_3;j<cnt /*&& i!=j*/;++j)
    {		
      memcpy(t_array,sum,sizeof(t_array));
      int flag=1;
      for(int k=0;node[i].str[k] && flag;++k)
      {
        if(!t_array[str[k]])
          flag=0;
        --t_array[str[k]];
      }
      for(int k=0;node[j].str[k] && flag;++k)
      {
        if(!t_array[str[k]])
          flag=0;
        --t_array[str[k]];
      }
      if(flag)
			  ans=max(ans,node[i].score+node[j].score);
    }

	printf("%d\n",ans);

  return 0;
}
