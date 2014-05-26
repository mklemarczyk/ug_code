#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_DL_IM 30
#define MAX_DL_NA 30

typedef  struct {
	char imie[MAX_DL_IM];
	char nazwisko[MAX_DL_NA];
	int pensja;
} osoba;

osoba* tabl;

int czytanie(char * filename) {
    FILE *f = fopen(filename, "r");    // otwiera plik do odczytu (musi istniec)
    if (f == NULL) {
        perror("Nie udalo sie otworzyc pliku.");
        return 1;
    }
	char imie[MAX_DL_IM];
	char nazwisko[MAX_DL_NA];
	int pensja;
	int ile = 0;
	char* tmpString = (char*)malloc(sizeof(char) * MAX_DL_IM);
	while(fscanf(f, "%s", tmpString) != EOF) ile++;
	ile = ile / 3;
	rewind(f);
	tabl = (osoba*)malloc(sizeof(osoba) * ile);
	int i;
	for(i = 0; i < ile; i++) {
		fscanf(f, "%s", &tabl[i].imie);
		fscanf(f, "%s", &tabl[i].nazwisko);
		fscanf(f, "%i", &tabl[i].pensja);
	}
	fclose(f);
	return ile;
}

void swapos(osoba* x, int n1, int n2){
	osoba tmp = x[n1];
	x[n1] = x[n2];
	x[n2] = tmp;
}

double bubble_sort(int start, int ile) {
	clock_t pocz = clock();
	int i, j;
	int max = start + ile;
	for(i = 0; i < max; i++){
		for(j = 0; j < max; j++){
			if(osobaCompare(tabl[i], tabl[j]) < 0){
				swapos(tabl, i, j);
			}
		}
	}
	clock_t koniec = clock();
	return (double)(koniec-pocz) / CLOCKS_PER_SEC;
}

int osobaCompare(osoba osoba1, osoba osoba2){
	if(strcmp(osoba1.nazwisko, osoba2.nazwisko) == 0) {
		return strcmp(osoba1.imie, osoba2.imie);
	}else {
		return strcmp(osoba1.nazwisko, osoba2.nazwisko);
	}
}

void TopDownMergeSort(osoba* A, osoba* B, int n) {
	TopDownSplitMerge(A, 0, n, B);
}

void CopyArray(osoba* B, int iBegin, int iEnd, osoba* A) {
	int k;
	for(k = iBegin; k < iEnd; k++) {
		A[k] = B[k];
	}
}

// iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set)
TopDownSplitMerge(osoba* A, int iBegin, int iEnd, osoba* B) {
	if(iEnd - iBegin < 2)                       // if run size == 1
		return;                                //   consider it sorted
    // recursively split runs into two halves until run size == 1,
    // then merge them and return back up the call chain
    
	int iMiddle = (iEnd + iBegin) / 2;          // iMiddle = mid point
	
	TopDownSplitMerge(A, iBegin,  iMiddle, B);  // split / merge left  half
	TopDownSplitMerge(A, iMiddle,    iEnd, B);  // split / merge right half
	
	TopDownMerge(A, iBegin, iMiddle, iEnd, B);  // merge the two half runs
	
	CopyArray(B, iBegin, iEnd, A);              // copy the merged runs back to A
}
 
//  left half is A[iBegin :iMiddle-1]
// right half is A[iMiddle:iEnd-1   ]
TopDownMerge(osoba* A, int iBegin, int iMiddle, int iEnd, osoba* B) {
	int i0 = iBegin;
	int i1 = iMiddle;
	int j;

	// While there are elements in the left or right runs
	for (j = iBegin; j < iEnd; j++) {
		// If left run head exists and is <= existing right run head.
		if (i0 < iMiddle && (i1 >= iEnd || osobaCompare(A[i0], A[i1]) < 0)) {
			B[j] = A[i0];
			i0 = i0 + 1;
		} else {
			B[j] = A[i1];
			i1 = i1 + 1;
		}
	}
}

double merge_sort(int start, int ile) {
	clock_t pocz = clock();

	osoba* temp = (osoba*)malloc(sizeof(osoba) * ile);
	TopDownMergeSort(tabl, temp, ile);

	clock_t koniec = clock();
	return (double)(koniec-pocz) / CLOCKS_PER_SEC;
}

void pisanie(int ile) {
	int i;
	for(i = 0; i < ile; i++) {
		printf("%s %s %i\n", tabl[i].nazwisko, tabl[i].imie, tabl[i].pensja);
	}
}

int main (int arg_num, char* arg[]) {
	if (arg_num == 3) {
		int ile = czytanie(arg[1]);
		if (ile > 0) {
			double time;
			//time = bubble_sort(0, ile);
			time = merge_sort(0, ile);
			pisanie(ile/*arg[2]*/);
			printf("\n[Info] Czas wykonania sortowania: %lf sek.\n\n", time);
		}
	} else
		printf("\n Poprawne wywolanie: './zad2 dane wynik'\n\n");
	return 0;
}
