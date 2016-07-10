#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,N;
    //base case
    int ans;
    cin>>t;
    for (int p = 0; p < t; ++p)
    {
        cin>>N;
        int count[N+1];
        count[1] = 1;    
        count[2] = 1;
        count[3] = 1;
        count[4] = 2;

        for(int i = 5; i <= N; i++)
        {
            count[i] = count[i-1] + count[i-4];
        }
        cout<<count[N]<<endl;   
    }
    return 0;
}