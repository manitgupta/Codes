#include <iostream>
#include <vector>
#include <algorithm>    

using namespace std;

void findCombinations(vector<int> &A, int target, int index, vector<int>& current, vector<vector<int> > &result)
{
    if (target == 0)
    {
        result.push_back(current);
    }
    for(int i = index; i < A.size(); i++)
    {
        if (A[i] < target)
            return;
        
        current.push_back(A[i]);
        findCombinations(A,target - A[i], i, current, result);
        current.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int> > result;
    vector<int> current;
    findCombinations(A,B,0,current, result);
    
    return result;
}

int main()
{
    vector<int> A;
    A.push_back(2);
    A.push_back(2);
    A.push_back(3);
    A.push_back(6);
    A.push_back(7);
    int B = 7;

    sort( A.begin(), A.end() );
    A.erase( unique( A.begin(), A.end() ), A.end() );
    
    for (int i = 0; i < A.size(); ++i)
    {
        cout<<A[i]<<" ";
    }
    //cout<<res<<endl;
    return 0;
}