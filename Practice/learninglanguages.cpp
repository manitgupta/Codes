#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

//http://www.codeforces.com/problemset/problem/277/A
struct node {
	int val;
	struct node *next;
};

typedef struct node NODE;
typedef struct node* link;

void insertedge(link* adjlist, int a, int b)
{
	link temp = (link)malloc(sizeof(NODE));
	temp->val = b;
	temp->next = adjlist[a];
	adjlist[a] = temp;
}

void insertedgeundirected(link* adjlist, int a, int b)
{
	link temp = (link)malloc(sizeof(NODE));
	temp->val = b;
	temp->next = adjlist[a];
	adjlist[a] = temp;

	link temp2 = (link)malloc(sizeof(NODE));
	temp2->val = a;
	temp2->next = adjlist[b];
	adjlist[b] = temp2;
}

void printlist(link *adjlist, int n)
{
	for (int i = 0; i < n; ++i)
	{
		link temp = adjlist[i];
		cout<<i<<": ";
		while(temp != NULL)
		{
			cout<<temp->val<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
}

void DFS(link* graphlist, int i, int visited[])
{
	visited[i] = 1;
	link temp = graphlist[i];
	while(temp != NULL)
	{
		if(!visited[temp->val])
		{
			DFS(graphlist, temp->val, visited);
		}
		temp = temp->next;
	}
}

int main()
{	
	// freopen("input.txt","r",stdin);
	int n,m,k,lang,juggad=0;
	cin>>n>>m;
	link* adjlist = (link*)malloc(sizeof(link)*(n+1));
	for (int i = 0; i <= n; ++i)
	{
		adjlist[i] = NULL;
	}
	for (int i = 1; i <= n; ++i)
	{
		cin>>k;
		if(k == 0)
			juggad++;
		for (int j = 0; j < k; ++j)
		{
			cin>>lang;
			insertedge(adjlist,i,lang);
		}
	}
	// cout<<"juggad = "<<juggad<<"n = "<<n<<endl;
	if(juggad == n)
	{
		cout<<n<<endl;
		return 0;
	}
	// printlist(adjlist,n+1);
	link* graphlist = (link*)malloc(sizeof(link)*(n+1));
	for (int i = 0; i <= n; ++i)
	{
		graphlist[i] = NULL;
	}

	for (int i = 1; i <= n; ++i)
	{
		link temp1 = adjlist[i];
		while(temp1 != NULL)
		{
			for (int j = i+1; j <= n; ++j)
			{
				link temp2 = adjlist[j];
				while(temp2!= NULL)
				{
					if(temp1->val == temp2->val)
					{
						insertedgeundirected(graphlist, i, j);
						break;
					}
					temp2 = temp2->next;
				}
			}
			temp1 = temp1->next;
		}
	}
	// printlist(graphlist,n+1);
	int visited[n+1];
	int components = 0;
	for (int i = 1; i <= n; ++i)
	{
		visited[i] = 0;
	}
	for (int i = 1; i <= n; ++i)
	{
		if(!visited[i])
		{
			DFS(graphlist,i,visited);
			components++;
		}
	}

	cout<<components-1<<endl;
	return 0;
}