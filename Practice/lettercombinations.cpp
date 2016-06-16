#include <iostream>
#include <vector>
#include <string>
using namespace std;

void findCombinations(string A, string &temp, vector<string> &result, vector<string> &numChars) 
{
	//cout<<A.length()<<endl;
	if (A.length() == 0)
	{
		result.push_back(temp);
		return;
	}
	int digit = A[0] - '0';
	//cout<<digit<<endl;
	string letters = numChars[digit];
	//cout<<letters<<endl;
	for(int i=0; i < letters.length(); i++)
	{
	temp.push_back(letters[i]);
	//cout<<temp<<endl;
	findCombinations(A.substr(1), temp, result, numChars);
	temp.pop_back();
	}
}


vector<string> letterCombinations(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details 
    vector<string> numChars = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> result;
    string temp;
    //cout<<"Start"<<endl;
    findCombinations(A, temp, result, numChars);

    return result;
}

int main()
{
	string A = "234";
	vector<string> result;
	result = letterCombinations(A);
	cout<<"Result Array size =  "<<result.size()<<endl;
	for (std::vector<string>::const_iterator i = result.begin(); i != result.end(); ++i)
    	std::cout << *i << ' ';
	return 0;
}

