#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

#include <vector>
using std::vector;

int main()
{
   vector< int > integers1(7); // 7-element vector< int >
   vector< int > integers2( 10 ); // 10-element vector< int >

   size_t i;
   
   cout << integers1.size() << endl;

   return 0;
}