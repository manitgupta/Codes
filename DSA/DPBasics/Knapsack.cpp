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
// choices should be made. Also, if the weight of item i cannot be accomodated into the Knapsack, the we have no option but to
//leave it, in this case it the theig can choose from 1,2....i-1 items upto a weight limit of w.
//http://www.personal.kent.edu/~rmuhamma/Algorithms/MyAlgorithms/Dynamic/knapsackdyn.htm


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

// P(k,w) = P(k-1,w) if wk > W
// 		  = max(P(k-1,w),P(k-1,w-wk) + vk) otherise

int knapsack(int W, int wt[], int val[], int n)
{
	if (n == 0 || W == 0) //No items or Weight available to filled in Knapsack is 0
		return 0;
	//If weight of the Nth item is more than weight of Knapsack, then theif as the option to
	//to select from 1,2,3......N-1 items for a total Weight of W
	if (wt[n-1] > W)
		return knapsack(W,wt,val,n-1); 	//Note the (n-1) here.
	else
		return max(knapsack(W,wt,val,n-1),val[n-1] + knapsack(W-wt[n-1],wt,val,n-1));	 
}

int knapsack_dp(int W, int wt[], int val[], int n)
{
	//cout<<n<<" "<<W<<endl;
	int Pf[n+1][W+1];	//2-D Structure to contruct the DP table
	for (int k = 0; k <= n; ++k)
	{
		Pf[k][0] = 0;		//Trivial Case
	}
	for (int w = 0; w <= W; ++w)
	{
		Pf[0][w] = 0;		//Trivial Case
	}
	for (int k = 1; k <= n; ++k)
	{
		for (int w = 1; w <= W; ++w)
		{
			Pf[k][w] = (wt[k-1] > w) ? Pf[k-1][w] : Max(Pf[k-1][w],Pf[k-1][w-wt[k-1]]+val[k-1]);
		}
	}
	cout<<"DP Table:"<<endl;
	for (int i = 0; i <=n; ++i)
	{
		for (int j = 0; j <=W; ++j)
		{
			cout<<Pf[i][j]<<"\t";
		}
		cout<<endl;
	}
	return Pf[n][W];
}	


int main()
{
	int val[] = {5,10,15};
	int wt[] = {1,3,4};
	int W = 6;
	int n = sizeof(val)/sizeof(val[0]);
	cout<<"Best Price of Items: "<<knapsack_dp(W,wt,val,n)<<endl;
	return 0;
}