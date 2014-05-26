#include <stdio.h>
#include <math.h>

char znak(int cyfra){
	switch(cyfra){
		case 1:
			return 'I';
		case 5:
			return 'V';
		case 10:
			return 'X';
		case 50:
			return 'L';
		case 100:
			return 'C';
		case 500:
			return 'D';
		case 1000:
			return 'M';
		default:
			return '_';
	}
}

void arab_num(int liczba, int p){
	int level = pow(10, p);
	if(liczba % 4 == 0 || liczba % 9 == 0){
		printf("%c", znak(1 *level));
		liczba += 1;
	}
	int n = liczba / 5;
	if(n > 0){
		printf("%c", znak(5*n *level));
		liczba -= 5*n;
	}
	while(liczba > 0){
		printf("%c", znak(1 *level));
		liczba--;
	}
}

void arab_req(int liczba, int p){
	if(liczba > 0){
		arab_req(liczba / 10, p+1);
		arab_num(liczba % 10, p);
	}
}

void arab(int liczba, int p){
	arab_req(liczba,0);
}

void rzym(char* liczba){
	
}

int main(){
	
	arab(16, 0);
	printf("\n");// XV
	
	arab(53, 0);
	printf("\n");// LIII
	
	arab(132, 0);
	printf("\n");// CXXXII
	
	return 0;
}
