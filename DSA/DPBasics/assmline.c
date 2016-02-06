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
#define NUM_STATION 4

//Stores the final line from which the car exits.
int exit_line;
//Geeks for Geeks + Cormen

//This function prints the route through which the car should go to get optimum production time.
void car_assembly_route(int a[][NUM_STATION],int t[][NUM_STATION], int e[], int x[],int T1[],int T2[],int l[][NUM_STATION])
{
	int opt_time;	//OPT time of assembly. No need to create this variable we if are returning it.
	//T1[0], and T2[0] denote the first station on each assembly line. Time to reach them is simply sum of entry time and ai,j
	T1[0] = e[0] + a[0][0];
	T2[0] = e[1] + a[1][0];

	for (int i = 1; i < NUM_STATION; ++i)
	{
		if (T1[i-1] + a[0][i] < T2[i-1] + t[1][i] + a[0][i])
		{
			//Means we reached T1[i](ith station on Line 1) from the (i-1)th station on Line 1 itself
			T1[i] = T1[i-1] + a[0][i];
			l[0][i] = 0;
		}
		else
		{
			//Means we reached T1[i] from (i-1)th station on Line 2
			T1[i] = T2[i-1] + t[1][i] + a[0][i];
			l[0][i] = 1;	
		}
		if (T2[i-1] + a[1][i] < T1[i-1] + t[0][i] + a[1][i])
		{
			T2[i] = T2[i-1] + a[1][i];
			l[1][i] = 1;
		}
		else
		{
			T2[i] = T1[i-1] + t[0][i] + a[1][i];
			l[1][i] = 0;
		}
	}
	if(T1[NUM_STATION-1] + x[0] < T2[NUM_STATION-1]+x[1])
	{
		opt_time = T1[NUM_STATION-1] + x[0];
		exit_line = 0;
	}
	else
	{
		opt_time = T2[NUM_STATION-1] + x[1];
		exit_line = 1;
	}
	cout<<"The Optimum Time to for assembly line is:"<<opt_time<<endl;
}

//Prints the Path covered by the car through the assembly lines
void print_opt_route(int l[][NUM_STATION])
{
	cout<<"Path of the car is:"<<endl;
	int i = exit_line;
	cout<<"line "<<i+1<<" station "<<NUM_STATION-1<<endl;
	for (int j = NUM_STATION-1; j > 0; j--)
	{
		//Stores the station number from which car arrived onto the station j on line i.
		i = l[i][j];
		cout<<"line "<<i+1<<" station "<<j-1<<endl;
	}
}

//Prints path in increasing order of station number.
void print_opt_route_recur(int l[][NUM_STATION], int i, int j)
{
	//Base Case when we have reached last station.
	if (j == 0)
		return;
	print_opt_route_recur(l,l[i][j],j-1);
	cout<<"line "<<i+1<<" station "<<j-1<<endl;
}

//This function finds the optimum car assembly time.
int opt_car_assembly_time(int a[][NUM_STATION],int t[][NUM_STATION], int e[], int x[])
{
	//We need two tables/arrays to store the fastest way to LEAVE the jth station on the Line i. ie. to pass through it.
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
	//Add exit times and compare the final time.
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
    //We need two tables/arrays to store the fastest way to LEAVE the jth station on the Line i. ie. to pass through it.
    int T1[NUM_STATION],T2[NUM_STATION];
	//We need to tables/arrays to store the which station was used in the optimal path.
	//li,j stores the line number i which was used to reach the station j.
	int l[2][NUM_STATION];
	car_assembly_route(a,t,e,x,T1,T2,l);
	//print_opt_route(l);
    print_opt_route_recur(l,exit_line,NUM_STATION);
    //cout<<opt_car_assembly_time(a,t,e,x)<<endl;
	return 0;
}