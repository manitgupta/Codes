#include <iostream>

using namespace std;

  int fi(int n) 
     { 
       int result = n; 
       for(int i=2;i*i <= n;i++) 
       { 
         if (n % i == 0) result -= result / i; 
         while (n % i == 0) n /= i; 
       } 
       if (n > 1) result -= result / n; 
       return result; 
     } 
int main ()
{
   	int t;
   	cin>>t;
   	int num[100000];
   	for(int i=0;i<t;i++)
   	{
   		cin>>num[i];
	}
	for(int i=0;i<t;i++)
	{
		cout<<fi(num[i])<<endl;
	}
    return 0;
}