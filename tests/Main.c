#include <stdio.h>

#include <pm.h>


int main() 
{
	
	printf("%Lf\n", pmSine(PM_PI / 4));
	printf("%Lf\n", pmCosine(PM_PI / 4));

	return 0;

}