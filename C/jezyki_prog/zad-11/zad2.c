#include <stdio.h>

double f(double x){
	return x;
}

double calka(double a, double b, double n){
	double range = (b - a) / n;
	double result = 0;
	int i;
	for(i = 0; i < n; i++){
		double fun = f(a+i*range)*range;
		result += fun;
	}
	return result;
}


int main(){
	
	double cal = calka(0,1,90000);
	printf("%lf\n", cal);
	
	return 0;
}

