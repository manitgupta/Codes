#include <stdlib.h>
#include <stdio.h>

int main ()
{
	int return_value;
	return_value = system ("ls -l /");
	printf("Hula Hoop\n");
	return return_value;
}