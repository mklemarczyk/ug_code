#include <stdio.h>
#include <math.h>

int dwumian(int n, int k){
	if(n < k) return 0;
	else if(k == 1) return n;
	else if(k == 0) return 1;
	return dwumian(n-1,k-1) + dwumian(n-1,k);
}

double prawda(int n, int k, double p){
	return dwumian(n,k) * pow(p, k) * pow(1-p, n-k);
}

void main(){
	int x,y;
	double z;
	
	printf("Podaj p: ");
	scanf("%lf", &z);
	
	printf("Podaj n: ");
	scanf("%d", &x);
	
	printf("Podaj k: ");
	scanf("%d", &y);
	
	double dwu = prawda(x,y,z);
	
	printf("Wynik: %f\n", dwu);
}
