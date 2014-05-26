#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
	printf("%15s | %22s | %23s | %15s | %15s | %15s\n", "", "wartość dolna", "wartość górna", "ziarno", "precyzja", "format");
	printf("%15s | %20i | %20i | %15s | %15s | %15s\n", "short", SHRT_MIN, SHRT_MAX, "", "", "%i");
	printf("%15s | %20i | %20i | %15s | %15s | %15s\n", "int", INT_MIN, INT_MAX, "", "", "%i");
	printf("%15s | %20li | %20li | %15s | %15s | %15s\n", "long", LONG_MIN, LONG_MAX, "", "", "%li");
	printf("%15s | %20lli | %20lli | %15s | %15s | %15s\n", "long long", LLONG_MIN, LLONG_MAX, "", "", "%lli");
	printf("%15s | %20e | %20e | %15e | %15i | %15s\n", "float", FLT_MIN, FLT_MAX, FLT_EPSILON, FLT_DIG, "%f lub %e");
	printf("%15s | %20le | %20le | %15le | %15i | %15s\n", "double", DBL_MIN, DBL_MAX, DBL_EPSILON, DBL_DIG, "%lf lub %le");
	printf("%15s | %20Le | %20Le | %15Le | %15i | %15s\n", "long double", LDBL_MIN, LDBL_MAX, LDBL_EPSILON, LDBL_DIG, "%Lf lub %Le");
	
	printf("\n\n\n");
	
	printf("2.1 (INT)\n");
	printf("INT_MAX + 1 = %i = INT_MIN\n", INT_MAX +1);
	printf("INT_MIN - 1 = %i = INT_MAX\n", INT_MIN -1);
	
	printf("\n2.2 (FLOAT dodawanie)\n");
	float x1 = FLT_EPSILON / 2.0f;
	float x2 = FLT_EPSILON * 2.0f;
	float w1 = 1.0f + (x1 + x2);
	float w2 = (1.0f + x1) + x2;
	printf("1.0 + (x1 + x2)  = %e\n", w1);
	printf("(1.0 + x1) + x2 = %e\n", w2);

	printf("\n2.3 (FLOAT mnozenie)\n");
	float x3 = 1.0f / FLT_MAX;
	float x4 = FLT_MAX;
	float w3 = x3 * (x4 * x4);
	float w4 = (x3 * x4) * x4);
	printf("1.0 * (x1 * x2)  = %e\n", w3);
	printf("(1.0 * x1) * x2 = %e\n", w4);

	printf("\n2.4 (FLOAT duze)\n");
	int i;
	float x;
	float y;
	for(i = 1; i <= 1000000000; i++){
		x = x + (1.0 / i);
	}
	for(i = 1000000000; i > 0; i--){
		y = y + (1.0 / i);
	}
	printf("Charmo 1 -> 10^9 = %e\n", x);
	printf("Charmo 10^9 -> 1 = %e\n", y);


	return 0;
}
