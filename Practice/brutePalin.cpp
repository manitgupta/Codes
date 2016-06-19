#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool checkPalin(string A)
{
	int len = A.length();
	for(int i = 0; i < len/2; i++)
	{
		if (A[i] != A[len - i- 1])
			return false;
	}
	return true;
}

void partitionUtil(vector< vector<string> > &result, vector<string> &currentPart, int start, int n, string A)
{
	if (start >= n)
	{
		result.push_back(currentPart);
		return;
	}
	//all possible ending points, start is the starting point
	for(int i = start; i < n; i++)
	{
		//if A[start...i] is a palindrome
		//commenting the if makes it generate all substrings.
		if (checkPalin(A.substr(start, i - start + 1)))
		{
			//if palin, add to current Set
			currentPart.push_back(A.substr(start, i - start + 1));
			//recur for the remaining part of the string
			partitionUtil(result, currentPart, i+1, n, A);

			// Remove substring str[start..i] from current 
            // recursively empties the currPart vector when
            // currentPart is pused in result and we are traveling
            //put the levels of recursion. 
            currentPart.pop_back();
		}
	}
}

//vector<vector<string> > Solution::partition(string A) {

void partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector< vector<string> > result;
    vector<string> currentPart;
    int n = A.length();
    partitionUtil(result, currentPart, 0, n, A);
    
    for (int i=0; i< result.size(); i++ )
    {
        for (int j=0; j<result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << "\n";
    }
    //return result;
}

int main()
{
	string A = "aab";
	partition(A);
	return 0;
}