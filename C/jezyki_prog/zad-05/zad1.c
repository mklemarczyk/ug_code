#include<stdio.h>
#include<string.h>

void dzielenie(int n, int k, int *q, int *r){
	(*q) = n / k;
	(*r) = n - (k * (*q));
}

int main () {
	int n = 16;
	int k = 3;

	int q;
	int r;

	dzielenie(n, k, &q, &r);

	printf("%i, %i\n", q, r);

	return 0;
}
