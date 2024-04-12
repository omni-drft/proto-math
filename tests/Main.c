#include <stdio.h>

#include <pm.h>


int main() 
{
	
	struct pmVector3 v1;
	v1.components[0] = 1;
	v1.components[1] = 2;
	v1.components[2] = 3;

	struct pmVector3 v2;
	v2.components[0] = 4;
	v2.components[1] = 5;
	v2.components[2] = 6;


	printf("%f", pmVec3Angle(&v1, &v2, pmRadians));

	return 0;

}