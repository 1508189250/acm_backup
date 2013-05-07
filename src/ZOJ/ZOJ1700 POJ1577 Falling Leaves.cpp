// ZOJ1700 POJ1577 Falling Leaves.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"


#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <memory.h>
#include <vector>

using namespace std;

struct node 
{
    char data;
    struct node *left,*right;
}*Head;

void insert(char elem,struct node * & p)
{
    if( p== NULL )
    {
        p= (struct node*)malloc(sizeof(struct node));
        p->data = elem;
        p->left = p->right = NULL;
        return ;
    }
    if( elem > p->data )
        insert(elem,p->right);
    else 
        insert(elem,p->left);
}


void preorder(struct node *&p)
{
	if(p==NULL) return;
	else
	{
		printf("%c",p->data);
		preorder(p->left);
		preorder(p->right);
	}
}

int main(void)
{
//     ifstream cin("data.txt");
    string str;
		vector<string> myvec;

    while(cin>>str)
    {
        if(str!="*"&&str!="$")
            myvec.push_back(str);
        else
        {
					for(vector<string>::reverse_iterator iter=myvec.rbegin();iter!=myvec.rend();++iter)
					{
						for(string::iterator iter2=iter->begin();iter2!=iter->end();++iter2)
							insert(*iter2,Head);
					}

					preorder( Head);
					printf("\n");
                    Head=NULL;
					myvec.clear();
        }
    }

    return 0;
}
