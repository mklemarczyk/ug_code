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

double Cumulative(int n, int k, double p){
	int i;
	double sum = 0;
	for(i = 0; i <= k; i++){
		sum += prawda(n,i,p);
	}
	return sum;
}

double Hoeffding(int n, int k, double p){
	double f;
	f = n * p;
	f = f - k;
	f = pow(f, 2);
	f = f / n;
	f = f * -2.0;
	f = exp(f);
	f = f * 1.0/2.0;
	return f;
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
	double dwu1 = Cumulative(x,y,z);
	double dwu2 = Hoeffding(x,y,z);
	
	printf("Wynik: %f <= %f  E= %f\n", dwu, dwu2, dwu1);
}
