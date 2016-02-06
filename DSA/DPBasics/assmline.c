#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

#define NUM_STATION 4

using namespace std;

#define _DEBUG

#define Inf 2147483647
#define Max(a, b)  (a < b ? b : a)
#define Min(a, b)  (a > b ? b : a)
#define INT_MIN -99999999

//Geeks for Geeks + Cormen

//This function prints the route through which the car should go to get optimum production time.
void print_opt_route()

//This function finds the optimum car assembly time.
int opt_car_assembly_time(int a[][NUM_STATION],int t[][NUM_STATION], int e[], int x[])
{
	//We need two tables to store the fastest way to LEAVE the jth station on the Line i. ie. to pass through it.
	int T1[NUM_STATION],T2[NUM_STATION];
	//T1[0], and T2[0] denote the first station on each assembly line. Time to reach them is simply sum of entry time and ai,j
	T1[0] = e[0] + a[0][0];
	T2[0] = e[1] + a[1][0];

	//Now we need to calculate the value of each Ti[j] in a bottom-up fashion using recurrence.
	for (int i = 1; i < NUM_STATION; ++i)
	{
		T1[i] = Min(T1[i-1] + a[0][i] , T2[i-1] + t[1][i] + a[0][i]);
		T2[i] = Min(T2[i-1] + a[1][i] , T1[i-1] + t[0][i] + a[1][i]);		
	}

	return Min(T1[NUM_STATION-1] + x[0],T2[NUM_STATION-1]+x[1]);
}


int main()
{
	int a[][NUM_STATION] = {{4, 5, 3, 2},
                {2, 10, 1, 4}};
    // ti,j is time taken to move to station j from line i. No cost is incurred for movement in same line.
    int t[][NUM_STATION] = {{0, 7, 4, 5},
                {0, 9, 2, 8}};
    //Entry time for both the lines.
    int e[] = {10, 12};
    //Exit Time for both the lines. 
    int x[] = {18, 7};
    cout<<opt_car_assembly_time(a,t,e,x)<<endl;
	return 0;
}