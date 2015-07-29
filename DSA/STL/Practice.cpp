// @BEGIN_OF_SOURCE_CODE 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <cstdlib>
 
#define Inf 2147483647
#define Pi acos(-1.0)
#define N 1000000
#define LL long long
 
inline LL Power(int b, int p) { LL ret = 1; for ( int i = 1; i <= p; i++ ) ret *= b; return ret; }
const int dr [] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dc [] = {0, 1, 1, 1, 0, -1, -1, -1};
 
#define all(c) c.begin(), c.end()	//for selecting all items in a container
#define F(i, a) for( int i = (0); i < (a); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Set(a, s) memset(a, s, sizeof (a))
#define Max(a, b)  (a < b ? b : a)	//max fnction
#define Min(a, b)  (a > b ? b : a)	//min function
#define present(container, element) (container.find(element) != container.end()) 		//check if element in container for map/set
#define cpresent(container, element) (find(all(container),element) != container.end()) 	//check if element in container for vector
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)  
using namespace std;
int main() 
{
    std::vector<int> v;
    for (int i = 0; i < 5; ++i)
    {
     	v.push_back(rand() % 1000);
    }
 
    tr(v, it) 
    { 
        printf("%d ",*it); 
    } 
    printf("\n");
    
    ///----EXAMPLE 1----- Return Types of functions.
    //Use *max_element for getting the value.
    int maxval = *max_element(all(v));
    printf("%d\n",maxval);
    
    //--------EXAMPLE 2------------
    //Subtract the begin iterator of a container to get index.
    int index = max_element(v.begin(), v.end()) - v.begin();
    printf("%d\n",index);
    
    //--------EXAMPLE 3 ------ SORTING USING SET CONTAINER.
    std::set<int> s(all(v));
    std::vector<int> v2(all(s));
    tr(v2,it)
    {
    	printf("%d ",*it);
    }
    printf("\n");

    //---------EXAMPLE 4---------PRINT ALL POSSIBLE PERMUTATIONS
    // For printing/traversing all possible combinations, inital vector must be sorted.
    int count = 0;
    do
    {
        count++;
    	tr(v2,it)
    	{
    		printf("%d ",*it);
    	}
        printf("\n");
    }while(next_permutation(all(v2)));
    printf("Total No. of Permutations: %d\n",count); 

    //-----EXAMPLE 5-----Sorting function
    sort(v.rbegin(), v.rend());     //rbegin() points to the last element, one less than end() iterator.
    printf("Sorted Array\n");       //The array is reverse sorted in place.
    tr(v,it)  
    {
        printf("%d ",*it);
    }
    return 0;
}