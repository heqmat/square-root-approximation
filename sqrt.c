#include <stdio.h>

#define NUMBER 823.0 //define the number you want to take square root of it.

double the_number;
double i_a;
double i_b;

double squared(double base) {
	double temp = 1.0;
	for (int i = 0; i < 2; i++) {
		temp = temp * base;
	}
	return temp;
}

double other_squares(double num) {
	int intnum = (int) num;
	double bottom_limit;
	// 100^2 is 10,000 which means any number you want to take square root of it must be smaller than 10,000 or you need to change it to 1000 for numbers smaller than 1 000 000 and so on. 
	for (int i = 1; i < 100; i++) {
		if ((double) intnum < squared((double) i)) {
			bottom_limit = i-1;
			break;
		}

	}
	return bottom_limit;
}

int main() {
	i_a = other_squares(NUMBER);
	i_b = i_a + 1;

	for (int i = 0; i < 100; i++) {
		double midnumber = (i_b + i_a)/2.0;

		double sqrt_of_mid = squared(midnumber);

		if (NUMBER < squared(midnumber)) {
			i_b = midnumber;
		}

		else if (NUMBER > squared(midnumber)) {
			i_a = midnumber;
		}

	}

	printf("Approximated value of sqrt of %lf is %.10f", NUMBER, i_a); //With these values, output was printed as 28.6879765756 which is literally same as real value(you will see the value in more detail if you use something like %.12f in the printf function.)  
}






