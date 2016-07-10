#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

//http://www.codeforces.com/problemset/problem/115/A

//Below code is modified to work with Graphs as well.
//See original submission on Codeforces website.
//Finding length of largest connected component in Directed Graphs.

struct node
{
	int val;
	struct node *next;
};

typedef struct node NODE;
typedef struct node* link;

void insertlist(link* adjlist, int a, int b)
{
	link temp = (link)malloc(sizeof(NODE));
	temp->val = b;
	temp->next = adjlist[a];	//add to head
	adjlist[a] = temp;
}

void minGroups(link* adjlist, int v, vector<int>& visited, int &numEmp)
{
	visited[v] = 1; //mark it visited.
	link temp = adjlist[v];
	while(temp != NULL)
	{
		if(!visited[temp->val])
		{
			// cout<<"temp->val = "<<temp->val<<endl;
			numEmp++;
			// cout<<"numEmp = "<<numEmp<<endl;
			minGroups(adjlist, temp->val, visited, numEmp);
		}
		temp = temp->next;
	}
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

int main()
{
	freopen("input.txt", "r", stdin);
	int n, temp, numEmp, largestEmp;
	vector<int> visited(2002);
	cin>>n;
	link* adjlist = (link*)malloc(sizeof(link)*(n+1));	//nodes numbered 1 to n
	for (int i = 0; i <= n; ++i)
	{
		adjlist[i] = NULL;
		visited[i] = 0;			//mark every vertex unvisited.
	}
	//take input and create graph.
	for (int i = 1; i <= n; ++i)
	{
		cin>>temp;
		if(temp != -1)
		{
			insertlist(adjlist, i, temp);	//add temp to i's adjlist.
		}
	}
	printlist(adjlist, n+1);
	largestEmp = 1;
	for (int i = 1; i <= n; ++i)
	{
		if(!visited[i])
		{
			numEmp = 1; 	//least size is 1.
			minGroups(adjlist, i, visited, numEmp);
			fill(visited.begin(), visited.end(),0);
			//cout<<"Num = "<<numEmp<<" i  = "<<i<<endl;
			if( numEmp > largestEmp)
				largestEmp = numEmp;
		}	
	}
	cout<<largestEmp<<endl;
}