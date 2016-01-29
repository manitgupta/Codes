// Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
// In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated
// with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset
// of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the
// complete item, or don’t pick it (0-1 property).

//Value of the solution to i items either include ith item, in which case it is vi plus a subproblem solution 
// for (i - 1) items and the weight excluding wi, or does not include ith item, in which case it is a subproblem's 
// solution for (i - 1) items and the same weight. That is, if the thief picks item i, thief takes vi value, and thief can 
// choose from items w - wi, and get c[i - 1, w - wi] additional value. On other hand, if thief decides not to take item i, 
// thief can choose from item 1,2, . . . , i- 1 upto the weight limit w, and get c[i - 1, w] value. The better of these two 
// choices should be made.
//http://www.personal.kent.edu/~rmuhamma/Algorithms/MyAlgorithms/Dynamic/knapsackdyn.htm


//Implementation Using Vectors.

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define _DEBUG

#define Inf 2147483647
#define Max(a, b)  (a < b ? b : a)
#define Min(a, b)  (a > b ? b : a)
#define INT_MIN -99999999

//Naive Recursive implementation

int knapsack(int W, std::vector<int> wt, std::vector<int>& val, int n)
{
	if (n == 0 || W == 0) //No items or Weight available to filled in Knapsack is 0
		return 0;
	//If weight of the Nth item is more than weight of Knapsack, then theif as the option to
	//to select from 1,2,3......N-1 items for a total Weight of W
	if (wt.at(n-1) > W)
		return knapsack(W,wt,val,n-1); 	//Note the (n-1) here.
	else
		return max(knapsack(W,wt,val,n-1), val.at(n-1) + knapsack(W-wt.at(n-1),wt,val,n-1));	 
}




int main()
{
	std::vector<int> val {60,100,120};
	std::vector<int> wt {10,20,30};
	int W = 50;
	int n = val.size();
	cout<<knapsack(W,wt,val,n)<<endl;
	return 0;
}

//Compile Using g++ Vec_Knapsack.cpp -std=C++11