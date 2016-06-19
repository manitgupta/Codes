#include <iostream>
#include <vector>

using namespace std;

void generateSubsets(vector< vector<int> > &result, vector<int> &currentSet, int A[], int n)
{
	for(int i = 0; i < n; i++)
	{
		result.push_back(currentSet);
		currentSet.clear();
		currentSet.push_back(A[i]);
		generateSubsets(result, currentSet, A+1, n-1);
	}
}


// vector< vector<int> > subsets(int A[], int n)
void subsets(int A[], int n)
{
	vector< vector<int> > result;
	vector<int> currentSet;
	// int n = A.size();
	generateSubsets(result, currentSet, A, n);

	// return result;
	for (int i=0; i< result.size(); i++ )
    {
        for (int j=0; j<result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << "\n";
    }
}

int main()
{

	return 0;

}