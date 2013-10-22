#include <stdio.h>
#include <math.h>

char progowa(int a, int b){
	int iloczyn = a*b;
	if(iloczyn > 100)
		return 'a';
	else if(iloczyn < 100)
		return 'b';
	else
		return 'c';
}

void trojmian(double a, double b, double c){
	double delta = b*b - 4*a*c;
	if(delta > 0){
		printf("Dwa pierwiastki:\n");
		printf("Pierwszy: %f\n", (-b + sqrt(delta)) / (2 * a) );
		printf("Drugi: %f\n", (-b - sqrt(delta)) / (2 * a) );
	}else if(delta == 0){
		printf("Jeden pierwiastek: %f\n", -b / (2 * a));
	}else{
		printf("Brak pierwiastkow w liczbach rzeczywistych.\n");
	}
}

void main(){
	//int a;
	//int b;
	
	//printf("Podaj pierwsza: ");
	//scanf("%i", &a);
	
	//printf("Podaj druga: ");
	//scanf("%i", &b);

	//printf("Litera to: %c\n", progowa(a,b));
	
	//printf("\n");
	
	double a5;
	double b5;
	double c5;
	
	printf("Podaj pierwsza: ");
	scanf("%lf", &a5);
	
	printf("Podaj druga: ");
	scanf("%lf", &b5);
	
	printf("Podaj trzecią: ");
	scanf("%lf", &c5);
	
	trojmian(a5,b5,c5);
}
