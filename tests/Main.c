#include <stdio.h>

#include <pm.h>

#define TOLERANCE 0.000001f

int main() 
{
	printf("\nPerforming 3-dimensional vector tests...\n");

	int passed = 0;

	/*============================ pmVec3Multiply ============================*/
	struct pmVector3 vec3 = {{1.0f, 2.0f, 3.0f}};
	float scalar = 2.0f;
	pmVec3Multiply(&vec3, scalar);
	if (vec3.components[0] == 2.0f && vec3.components[1] == 4.0f && vec3.components[2] == 6.0f)
	{
		printf("\tTest  1 passed.\n");
		passed++;
	}
	else
		printf("\tTest  1 failed\n");

	/*============================ pmVec3Divide ============================*/
	struct pmVector3 vec3_2 = {{2.0f, 4.0f, 6.0f}};
	float scalar_2 = 2.0f;
	pmVec3Divide(&vec3_2, scalar_2);
	if (vec3_2.components[0] == 1.0f && vec3_2.components[1] == 2.0f && vec3_2.components[2] == 3.0f)
	{
		printf("\tTest  2 passed.\n");
		passed++;
	}
	else
		printf("\tTest  2 failed\n");

	/*============================ pmVec3CrossProduct ============================*/
	struct pmVector3 vec3_3 = {{1.0f, 0.0f, 0.0f}};
	struct pmVector3 vec3_4 = {{0.0f, 1.0f, 0.0f}};
	struct pmVector3 result = pmVec3CrossProduct(&vec3_3, &vec3_4);
	if (result.components[0] == 0.0f && result.components[1] == 0.0f && result.components[2] == 1.0f)
	{
		printf("\tTest  3 passed.\n");
		passed++;
	}
	else
		printf("\tTest  3 failed\n");

	/*============================ pmVec3DotProduct ============================*/
	struct pmVector3 vec3_5 = {{1.0f, 2.0f, 3.0f}};
	struct pmVector3 vec3_6 = {{4.0f, 5.0f, 6.0f}};
	float dotProduct = pmVec3DotProduct(&vec3_5, &vec3_6);
	if (dotProduct == 32.0f)
	{
		printf("\tTest  4 passed.\n");
		passed++;
	}
	else
		printf("\tTest  4 failed\n");

	/*============================ pmVec3Length ============================*/

	struct pmVector3 vec3_7 = {{1.0f, 2.0f, 2.0f}};
	float length = pmVec3Length(&vec3_7);
	if (length == 3.0f)
	{
		printf("\tTest  5 passed.\n");
		passed++;
	}
	else
		printf("\tTest  5 failed\n");

	/*============================ pmVec3NormalizeInPlace ============================*/

	struct pmVector3 vec3_8 = {{1.0f, -2.0f, 2.0f}};
	pmVec3NormalizeInPlace(&vec3_8);
	if (pmVec3Length(&vec3_8) == 1.0f)
	{
		printf("\tTest  6 passed.\n");
		passed++;
	}
	else
		printf("\tTest  6 failed\n");

	/*============================ pmVec3NormalizeCopy ============================*/

	struct pmVector3 vec3_9 = {{1.0f, -2.0f, 2.0f}};
	struct pmVector3 normalized = pmVec3NormalizeCopy(vec3_9);
	if (pmVec3Length(&normalized) == 1.0f)
	{
		printf("\tTest  7 passed.\n");
		passed++;
	}
	else
		printf("\tTest  7 failed\n");

	/*============================ pmVec3Angle ============================*/

	struct pmVector3 vec3_10 = {{1.0f, 0.0f, 0.0f}};
	struct pmVector3 vec3_11 = {{0.0f, 1.0f, 0.0f}};
	float angle = pmVec3Angle(&vec3_10, &vec3_11, pmDegrees);
	if (angle == 90.0f)
	{
		printf("\tTest  8 passed.\n");
		passed++;
	}
	else
		printf("\tTest  8 failed\n");

	float angle_2 = pmVec3Angle(&vec3_10, &vec3_11, pmRadians);
	if (fabs(angle_2 - 1.570796f) < TOLERANCE)
	{
		printf("\tTest  9 passed.\n");
		passed++;
	}
	else
		printf("\tTest  9 failed\n");

	/*============================ pmVec3Projection ============================*/

	struct pmVector3 vec3_12 = {{2.0f, 3.0f, 4.0f}};
	struct pmVector3 vec3_13 = {{1.0f, 0.0f, 1.0f}};
	struct pmVector3 projection = pmVec3Projection(&vec3_12, &vec3_13);
	if (fabs(projection.components[0] - 3.0f) < TOLERANCE 
	&& fabs(projection.components[1] - 0.0f) < TOLERANCE 
	&& fabs(projection.components[2] - 3.0f) < TOLERANCE)
	{
		printf("\tTest 10 passed.\n");
		passed++;
	}
	else
		printf("\tTest 10 failed.\n");

	/*============================ pmVec3IsParallel ============================*/

	struct pmVector3 vec3_14 = {{1.0f, 0.0f, 0.0f}};
	struct pmVector3 vec3_15 = {{2.0f, 0.0f, 0.0f}};
	if (pmVec3IsParallel(&vec3_14, &vec3_15))
	{
		printf("\tTest 11 passed.\n");
		passed++;
	}
	else
		printf("\tTest 11 failed.\n");

	/*============================ pmVec3IsPerpendicular ============================*/

	struct pmVector3 vec3_16 = {{1.0f, 0.0f, 0.0f}};
	struct pmVector3 vec3_17 = {{0.0f, 1.0f, 0.0f}};
	if (pmVec3IsPerpendicular(&vec3_16, &vec3_17))
	{
		printf("\tTest 12 passed.\n");
		passed++;
	}
	else
		printf("\tTest 12 failed.\n");

	printf("%d out of 12 tests passed.\n", passed);

	printf("\nPerforming 4-dimensional vector tests...\n");

	printf("Testing ended.\n\n");
	return 0;
}