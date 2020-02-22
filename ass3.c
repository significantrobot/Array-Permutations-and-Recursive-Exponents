/************************************************
*YANIV LEVY
*T.Z.316464817
*Group 01 (Computer Science)
*ass03

*************************************************/



//#define MAX 5
#include <stdio.h>
#include <math.h>

/***********
*Function Name: compareArr2
*Input: int Appearances1, int arr2[], int size2, int arr1number
*Output: int 0,1
*Function Operation:
	The functions recieves arr1number and Appearances1 from isPermutation,
	and uses a loop and Appearances2 to count
	how many times arr1number appears in arr2.

	If Appearances1 = Appearances2, return is 1,
	and isPermutation continues to compare numbers.

	If Appearances1 != Appearances2, return is 0,
	and isPermutation also returns 0, which means
	arr1 and arr2 are not permutations.
*************/

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

int counter = 0;

/*****
*Function Name: recEffiPow
*Input: double x, int y
*Output: double
*Function Operation:
	This function also uses a recursive call,
	but one that is more efficient than recPow.
	When y is even, the call is split into x^(y/2) * x^(y/2),
	where each exponent is calculated by a recursive call.

	When y is odd, the call is split into x * x^((y-1)/2) * x^((y-1)/2)
	*******/

double recEffiPow(double x, int y) {
	//efficiency counter
	counter++;

	//exception handing -- what to do for 0^y, 0^-y, 1^y, x^0, x^1, x^-1
	//these conditions are also used by the recursive call when y = 1 and y=0
	if (x == 0 && y>0) {
		return 0;
	}

	else if (x == 0 && y < 0) {
		return 1 / x;

	}

	else if (x == 1) {
		return 1;
	}

	else if (y == 0) {
		return 1;
	}

	else if (y == 1) {
		return x;
	}

	else if (y == -1) {
		return 1 / x;
	}

	//Not exceptions:
	else if (x != 0 && x != 1 && y > 1) {
		//When y is an even number
		if (y % 2 == 0) {
			return (recEffiPow(x, y / 2) * recEffiPow(x, y / 2));
		}

		//When y is an odd number
		if (y % 2 == 1) {
			return (x * (recEffiPow(x, ((y - 1) / 2))) * (recEffiPow(x, ((y - 1) / 2))));
		}
	}

	//When y is a negative number, it is made positive,
	//the recursive call is made, and return is 1/(return),
	//like in recPow
	else if (x != 0 && x != 1 && y < 1) {
		y = -y;
		return 1 / (recEffiPow(x, y));
	}


}


/*****
*Function Name: recPower
*Input: double x, int y
*Output: double
*Function Operation:
	This function uses a simple recursive call to calculate an exponent.
	If y is positive, it performs the call and returns x^y.
	If y is negative, it makes y positive, performs the recursive call
	(which then runs as if y was positive to begin with),
	and returns 1/ (x^+y).
*******/

double recPow(double x, int y) {
	//efficiency counter
	counter++;

	//exception handing -- what to do for 0^y, 0^-y, 1^y, x^0, x^1, x^-1
	//these conditions are also used by the recursive call when y = 1 and y=0
	if (x == 0 && y > 0) {
		return 0;
	}

	else if (x == 0 && y < 0) {
		return 1 / x;
	}

	else if (x == 1) {
		return 1;
	}

	else if (y == 0) {
		return 1;
	}

	else if (y == 1) {
		return x;
	}

	else if (y == -1) {
		return 1 / x;
	}

	//recursive call for positive y.
	else if (x != 0 && x != 1 && y > 1) {
		return x * recPow(x, y - 1);
	}

	//recursive call for negative y. Y is made positive,
	//the call is made, and return is ( 1 / <function for positive y> )
	else if (x != 0 && x != 1 && y < -1) {
		y = -y;
		return 1 / (recPow(x, y));
	}

}

/*****
*Function Name: iterPow
*Input: double x, int my
*Output: double
*Function Operation:
	This function for uses "for" loops to multiply x by itself a y number times.
	If y is positive, it simply returns the product.
	If y is negative, it runs a similar loop, and returns 1/product.

*******/

double iterPow(double x, int y) {
	//original base number is preserved so that we can cycle x through the loop
	double OriginalBase = x;
	int Iteration;

	//exception handing -- what to do for 0^y, 0^-y, 1^y, x^0, x^1, x^-1
	if (x == 0 && y>0) {
		return 0;
	}

	else if (x == 0 && y < 0) {
		return 1/ x;

	}

	else if (x == 1) {
		return 1;
	}

	else if (y == 0) {
		return 1;
	}

	else if (y == 1) {
		return x;
	}

	else if (y == -1) {
		return 1 / x;
	}

	//if y is a positive number, initialize Iteration = 1,
	//and run the exponent loop until Iteration = y. return x
	else if (x != 0 && x != 1 && y > 1) {
		for (Iteration = 1; Iteration < y; Iteration++) {
			x = x * OriginalBase;
			counter++;
		}
		return x;
	}

	//if y is a negative number, initialize Iteration = y,
	//and run the exponent loop until Iteration = -1. Return 1/x
	else if (x != 0 && x!= 1 && y < -1) {
		for (Iteration = y; Iteration < -1; Iteration++) {
			x = x * OriginalBase;
			counter++;
		}
		return 1 / x;
	}
}

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

