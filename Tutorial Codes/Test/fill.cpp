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

int floorsqrt(int n)
{
	int s = x/2;
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
			end = mid-1 
	}
	return ans;
}

int main()
{
	floorsqrt(11);
	return 0;
}