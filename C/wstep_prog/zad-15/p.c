#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	FILE *in_plik;
	FILE *out_plik;

	int c;
	
	if(argc < 3){	
		printf("Zbyt malo parametrow !!!\n");
		exit(1);
	}
	
	if(argc != 3){	
		printf("Blad podaj nazwe pliku !!!\n");
		exit(1);
	}
	
	in_plik = fopen(argv[1],"r");
	printf("Odczytuje zawartosc pliku: %s\n\n",argv[1]);
	if(in_plik == NULL){
		printf("Blad otwarcia pliku wejsciowego ...\n");
		exit(1);
	}
	
	out_plik = fopen(argv[2],"a");
	if(out_plik == NULL){
		printf("Blad otwarcia pliku wyjsciowego ...\n");
		exit(1);
	}
	
	printf("Zapisuje do pliku: %s\n\n",argv[2]);
	while((c=fgetc(in_plik)) != EOF)
	{
		if(c != 'a' && c!= 'A')
			fputc((int)c,out_plik);
		printf("%c",c);
	}
	
	printf("\n");
	
	fclose(in_plik);
	fclose(out_plik);
	
	return (0);
}
