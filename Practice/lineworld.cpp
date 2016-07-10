#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;
//http://www.codeforces.com/problemset/problem/500/A
struct node{
	int val;
	struct node *next;
};

typedef struct node NODE;
typedef struct node* link;

void insertlist(link* adjlist, int a, int b)				//insert b in a's adj list, edge from a TO b
{
	link temp = (link)malloc(sizeof(NODE));
	temp->val = b;
	temp->next = adjlist[a];
	adjlist[a] = temp;
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

int isReachable(link* adjlist,int visited[], int s, int t, int path[], int &index)
{
	visited[s] = 1;	//mark it visited.
	path[index++] = s;
	if (s == t)
		return 1;
	link temp = adjlist[s];
	while(temp != NULL)
	{
		if(!visited[temp->val])
		{
			if(isReachable(adjlist,visited, temp->val, t, path, index))
				return 1;
			temp = temp->next;
		}
	}
	index--;
	return 0;
}

int main()
{
	int n,t,b;
	cin>>n>>t;
	//freopen("input.txt","r",stdin);
	link *adjlist = (link*)malloc(sizeof(link)*n);
	for (int i = 0; i < n; ++i)
	{
		adjlist[i] = NULL;
	}
	for (int i = 0; i < n-1; ++i)
	{
		cin>>b;
		insertlist(adjlist,i,b+i);
	}
	//printlist(adjlist, n);
	int index = 0;
	int visited[n];
	int path[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = 0;
	}
	if(isReachable(adjlist,visited,0,t-1, path, index))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	// for (int i = 0; i < index; ++i)
	// {
	// 	cout<<path[i]<<"->";
	// }
	return 0;
}