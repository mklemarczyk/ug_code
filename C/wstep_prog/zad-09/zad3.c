#include <stdio.h>

void main(){
	int i;
	int j;
	int k;

	int ckol1;
	int cwie1;

	int ckol2;
	int cwie2;

	printf("Podaj rozmiar maciezy 1(format: NxM): \n");
	scanf("%ix%i", &cwie1, &ckol1);
	printf("Podaj rozmiar maciezy 2(format: NxM): \n");
	scanf("%ix%i", &cwie2, &ckol2);

	int tab1[cwie1][ckol1];
	int tab2[cwie2][ckol2];
	int wyn[cwie1][ckol2];
	
	if(ckol1 != cwie2){
		printf("Macierzy nie da sie pomnozyc!\n");
	}else{
		printf("Podaj dane1 (x y .., enter): \n");
		for(i=0; i<cwie1; i++){
			for(j=0; j<ckol1; j++){
				scanf("%i", &tab1[i][j]);
			}
		}

		printf("\nPodaj dane2 (x y .., enter): \n");
		for(i=0; i<cwie2; i++){
			for(j=0; j<ckol2; j++){
				scanf("%i", &tab2[i][j]);
			}
		}

		for(i=0; i<cwie1; i++){
			for(j=0; j<ckol2; j++){
				wyn[i][j] = 0;
				for(k=0; k<ckol1; k++){
					wyn[i][j] += tab1[i][k] * tab2[k][j];
				}
			}
		}

		printf("\nWydruk: \n");
		for(i=0; i<cwie1; i++){
			if(i>0)printf("\n");
			for(j=0; j<ckol2; j++){
				if(j>0)printf(" ");
				printf("%i", wyn[i][j]);
			}
		}
		printf("\n");
	}
}
