#include <stdio.h>

int main(){
	int i, j, x, y, z;
	printf("Podaj x: ");
	scanf("%i", &x);

	printf("Podaj y: ");
	scanf("%i", &y);

	printf("Podaj z: ");
	scanf("%i", &z);

	int sA = x*y;
	int sB = y*z;
	int sC = x*z;
	int tabA[sA];
	int tabB[sA];
	int tabC[sC];

	// Initiation tabA
	for(i = 0; i < sA; i++){
		tabA[i] = i;
	}
	for(i = 0; i < sB; i++){
		tabB[i] = i;
	}

	// Multiply tabA * tabB -> tabC
	for(i = 0; i < sC; i++){
		int r = i / x;
		int c = i - r * x;
		int w = 0;
		for(j = 0; j < y; j++){
			w += tabA[j * x + c] * tabB[r * y + j];
		}
		tabC[r * x + c] = w;
	}

	// Print tabB
	for(i = 0; i < sC; i++){
		printf("%4i ", tabC[i]);
		if(i%z == z-1) printf("\n");
	}

	return 0;
}
