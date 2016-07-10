#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void findPermutations(string A, vector<char> current, int visited[], vector< vector<char> >& res)
{
	if(current.size() == A.length())
	{
		for (int i = 0; i < current.size(); ++i)
		{
			cout<<current[i];
		}
		cout<<endl;
		res.push_back(current);
		return;
	}
	for(int i = 0; i < A.length(); i++)
	{
		if(!visited[i])
		{
			current.push_back(A[i]);
			visited[i] = 1;
			findPermutations(A,current,visited, res);
			current.pop_back();
			visited[i] = 0;		
		}
	}
}

int main()
{
	string A = "ABCDE";
	vector< vector<char> > res;
	vector<char> current;
	int visited[100];
	for (int i = 0; i < A.length(); ++i)
	{
		visited[i] = 0;
	}
	findPermutations(A, current,visited,res);
	return 0;
}