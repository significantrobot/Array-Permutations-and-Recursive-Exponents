#include <stdio.h>
#include <math.h>

/*****
*Function Name: isPermutation
*Input: int arr1[], int size1, int arr2[], int size2
*Output: int 0,1
*Function Operation:
	This function accepts two arrays. It examines the first
	array using a double "for" loop and counts how many times
	each number appears. Once a number has been counted,
	it invokes compareArr2(), which compares how many times
	the same number appears in Arr2 (see notes for compareArr2).

	The return from compareArr2, which is how many times
	the number appears in the second array, is compared
	using int "comparison" to how many times the number appears in arr1.

	If every number in Arr1 appears the same number
	of times in Arr2, Arr2 is a permutation of Arr1, and 1 is returned.

	If any number in Arr1 does not appear
	the same number of times in Arr2,
	Arr2 is not a permutation of Arr1, and 0 is returned.

*******/

int isPermutation(int arr1[], int size1, int arr2[], int size2) {
	int Appearances1 = 0;
	int comparison = 1;

	//exception - if arrays are different size, they are not permutation
	if (size1 != size2) {
		return 0;
	}

	//comparing arr1 to itself and counting with Appearances1
	//how many times each number appears in arr1
	for (int index = 0; index < size1; index++){
		for (int j = 0; j < size1; j++) {
			if (arr1[index] == arr1[j]) {
				Appearances1++;
			}
		}
		
		//call to compareArr2, comparing its return
		comparison = compareArr2(Appearances1, arr2, size2, arr1[index]);
		//if at any point the numbers are not the same, 0 is returned
		if (comparison == 0) {
			return 0;
		}
		Appearances1 = 0;
	}
	//if the numbers are the same all the way through both arrays:
	return 1;

}

/*****
*Function Name: printArr2D
*Input: int[][], int rows, int columns
*Output: prints the array int[][], padded with zeroes,
to match length of largeset number in the array
*Function Operation:
	This function uses a double "for" loop to progressively compare
	the size of the values in both rows of the array to each other.
	The value of the highest number is stored in "Longest",
	and (log10(Longest) + 1) gives us the number of digits in Longest.
	DigitsinLongest is the variable used for the print0 modifier
	in printf for the array values.

*******/

void printArr2D(int arr[][MAX], int rows, int columns) {
	int Longest = 0, DigitsinLongest;
	
	//double for loop progressively compares
	for (int i_size = 0; i_size < rows; i_size++) {
		for (int j_size = 0; j_size < columns; j_size++) {
			//Storing the largest value in "Longest"
			if (arr[i_size][j_size] > Longest) {
				Longest = arr[i_size][j_size];
			}
		}
	}
	//Number of digits in the largest number
	DigitsinLongest = 1 + log10(Longest);

	//printing the array with modifier DigitsinLongest
	for (int i_location = 0; i_location < rows; i_location++) {
		for (int j_location = 0; j_location < columns; j_location++) {
			printf("%0*d ", DigitsinLongest,arr[i_location][j_location]);
		}
		printf("\n");
	}

}

