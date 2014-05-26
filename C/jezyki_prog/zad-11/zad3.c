#include <stdio.h>

double f(double x, double y){
	return x+2*y;
}

double calka(double a, double b, double c, double d, double n){
	double range1 = (b - a) / n;
	double range2 = (d - c) / n;
	double result = 0;
	int i,j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			result += f(a+i*range1, c+j*range2) * range1 * range2;
		}
	}
	return result;
}


int main(){
	
	double cal = calka(0,1,0,1,900);
	printf("%lf\n", cal);
	
	return 0;
}

