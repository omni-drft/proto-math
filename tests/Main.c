#include <stdio.h>

#include <pm.h>
#include <vec.h>

int main() 
{
	printf("C Test\n");
	pmTest();
	
	
	float testComponents[3] = { 2, 4, 5 };
	struct pmVector3 test;

	pmVec3Multiply(&test, 2.4f);

	printf("[ %.2f, %.2f, %.2f ]\n", test.components[0], test.components[1], test.components[2]);




}