#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	vector<int> v;
	for (int i = 0; i < 25; ++i)
	{
		v.push_back(rand()%10);
	}
	
	for (int i = 0; i < 25; ++i)
	{
		printf("%d ",v[i]);
	}

	int maximum = *max_element(v.begin(),v.end());
	printf("Max = %d\n",maximum);
	std::vector<int> count(maximum);

	for (int i = 0; i < 25; ++i)
	{
		count[v[i]]++;
		printf("Count[%d] =  %d \n",v[i],count[v[i]]);
	}

	int most_occured = max_element(count.begin(),count.end()) - count.begin();
	printf("%d is the most repeated element\n",most_occured);

	return 0;
}