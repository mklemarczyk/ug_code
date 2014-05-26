#include <stdio.h>

int main(){
	int x1, y1, x2, y2;
	
	printf("Podaj pozycje 1 hetmana(x,y): ");
	scanf("%i,%i", &x1, &y1);

	printf("Podaj pozycje 2 hetmana(x,y): ");
	scanf("%i,%i", &x2, &y2);

	int x3, y3;
	x3 = x1 - x2;
	y3 = y1 - y2;

	if(x3 == 0 || y3 == 0 || x3*x3 == y3*y3){
		printf("Hetmany się szachują\n");
	}else{
		printf("Hetmany się nie szachują\n");
	}

	return 0;
}
