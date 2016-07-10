#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//https://www.hackerrank.com/challenges/red-john-is-back
int SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n+1];
    int ans=0;
    for (int i = 0; i <= n; ++i)
    {
        prime[i] = true;
    }
 
    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p=2; p<=n; p++)
       if (prime[p])
          ans++;
    return ans;
}

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
        ans = SieveOfEratosthenes(count[N]);
        cout<<ans<<endl;   
    }
    return 0;
}