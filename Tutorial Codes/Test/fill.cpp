#include <iostream>
#include <iomanip>

int main()
{
   for (int i = 0; i < 10; ++i)
   {
   		std::cout << std::setw(3) << std::setfill('0') << i << std::endl;
   	/* code */
   }
}