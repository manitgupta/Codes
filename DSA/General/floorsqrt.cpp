#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

//FIND THE FLOOR OF THE SQAURE ROOT OF A NUMBER.
//http://www.geeksforgeeks.org/square-root-of-an-integer/

using namespace std;

#define _DEBUG

#define Inf 2147483647
#define Max(a, b)  (a < b ? b : a)
#define Min(a, b)  (a > b ? b : a)
#define INT_MIN -99999999

int floorsqrt(int x)
{
	int s = x/2;	//floor of square root cannot be more than half of the number.
	int start = 0,end=s,ans;
	while(start <=end)
	{
		int mid = (start+end)/2;
		if(mid*mid == x)	//x is a perfect square
			return mid;
		else if (mid*mid < x)	//we need to narrow down the start boundary since floor(sqrt(x)) is in later half
		{
			start = mid+1;
			ans = mid;	//to move the ans closer to sqrt(x)
		}
		else	//when mid*mid > x;
			end = mid-1; 
	}
	return ans;
}

/*For x = 45
FIRST ITERATION			0------11-----22
s = 22
start = 0 end = 22 		
mid = 11
121 > 45
end = 11-1 = 10 and start = 0
SECOND ITERATION		0----5-----10
mid = 5
25 < 45
start = 6,ans = 5 and end = 10 (remains same)
THIRD ITERATION		6---8---10
mid = 8
64 > 45
end = 8-1 = 7 start = 6(remains same) and ans = 5(remains same)
FOURTH ITERATION	6---7
mid = (7+6)/2 = 13/2 = 6
36 < 45
start = 7, ans = 6 and end = 7 (remains same)
FIFTH ITERATION	7--7 	(For perfect squares, narrowed down in final step)
mid = (7+7)/2  = 7
49 > 45
end = 7-1 = 6, start = 7 and ans=6(remains same)
EXIT with ans = 6
*/ 
int main()
{
	for (int i = 0; i < 50; ++i)
	{
		cout<<"FloorSqrt("<<i<<")= "<<floorsqrt(i)<<endl;
	}
	return 0;
}