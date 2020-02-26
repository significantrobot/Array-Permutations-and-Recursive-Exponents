
//#define MAX 5
#include <stdio.h>
#include <math.h>



int compareArr2(int Appearances1, int arr2[], int size2, int arr1number) {
	int Appearances2 = 0;

	//counting appearances of arr1number in arr2
	for (int j = 0; j < size2; j++) {
		if (arr1number == arr2[j]) {
			Appearances2++;
		}
	}

	//Not a permutation
	if (Appearances2 != Appearances1) {
		return 0;
	}

	else {
		return 1;
	}


}


