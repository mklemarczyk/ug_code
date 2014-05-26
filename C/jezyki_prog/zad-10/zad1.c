#include <stdio.h>

int main(){
	int i, x, y;
	printf("Podaj x: ");
	scanf("%i", &x);

	printf("Podaj y: ");
	scanf("%i", &y);

	int sA = x*y;
	int tabA[sA];
	int tabB[sA];

	// Initiation tabA
	for(i = 0; i < sA; i++){
		tabA[i] = i;
	}

	// Tranpose tabA -> tabB
	for(i = 0; i < sA; i++){
		int r = i / x;
		int c = i - r * x;
		tabB[c * x + r] = tabA[i];
	}

	// Print tabB
	for(i = 0; i < sA; i++){
		printf("%4i ", tabB[i]);
		if(i%y == y-1) printf("\n");
	}

	return 0;
}
