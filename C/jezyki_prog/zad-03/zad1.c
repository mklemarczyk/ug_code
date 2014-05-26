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
	return 0;
}
