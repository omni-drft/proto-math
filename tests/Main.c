#include <stdio.h>

#include <pm.h>


int main() 
{
	
	struct pmVector3 v1;
	v1.components[0] = 1;
	v1.components[1] = 1;
	v1.components[2] = 1;

	struct pmVector3 v2;
	v2.components[0] = 1;
	v2.components[1] = 2;
	v2.components[2] = 1;


	printf("%f", pmVec3Angle(&v1, &v2, pmDegrees));


	return 0;

}