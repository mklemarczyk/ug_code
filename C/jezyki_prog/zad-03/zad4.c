

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
	float x = 1.0f;
	while (1.0f + x > 1.0f)
		x = x / 2.0f;
	printf("%e\n", x);

	double y = 1.0;
	while (1.0 + y > 1.0)
		y = y / 2.0;
	printf("%le\n", y);

	long double z = 1.0;
	while (1.0 + z > 1.0)
		z = z / 2.0;
	printf("%Le\n", z);

	return 0;
}



