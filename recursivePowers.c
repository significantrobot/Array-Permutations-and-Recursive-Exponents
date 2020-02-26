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
