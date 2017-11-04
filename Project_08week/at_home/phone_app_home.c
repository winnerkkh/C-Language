
/*
Name: KYUNGHOON KIM
Student number: 056845100
Email: khkim12@myseneca.ca
Workshop: Workshop7_home
Section:IPC144SJJ
Date: March 14th, 2017
*/

#include <stdio.h>


//Define the maximum ber of phone number to be 3
#define SIZE 3

// Home part Array of areaCode
int filteringAreaCode[SIZE] = { 416, 647, 905 }; 


//Prototype a C function named decompose that returns nothing and has four parameter
void decompose(const long long int pNumber, int *areaCode, int *prefix, int *lineNumber);

// Prototype a C function named isValid that returns an int and has one parameter. 
//The parameter is an unmodifiable long long.
int isValid(const long long int pNumber);

//implement the definition of your decompose function
void decompose(const long long pNumber, int *areaCode, int *prefix, int *lineNumber) {
	*areaCode = pNumber / 10000000;
	*prefix = pNumber / 10000 % 1000;
	*lineNumber = pNumber % 10000;
}

// Prototype a C function named isValid that returns an int and has one parameter.
//The parameter is an unmodifiable long long.

int isValid(const long long pNumber) {
	int areaCode = 0;
	int prefix = 0;
	int i=0;
	int result =0;

	areaCode = pNumber / 10000000;
	prefix = pNumber / 10000 % 1000;

	if (prefix >= 100 && prefix <= 999) {
		for (i = 0; i < SIZE; i++)
			if (areaCode == filteringAreaCode[i]) {
				result = 1;
			}
	}
	return result;
}


/* main program */
int main(void) {

	long long phoneNumber[SIZE] = { 0, 0, 0 };
	int option;
	int areaCode = 0;
	int prefix = 0;
	int lineNumber = 0;
	int i = 0;
	int phoneCounter = 0;
	int temp = 0;
	long long tempInput = 0;

	printf("---=== Phone Numbers ===---\n\n");
	do {
		// Display the Option List
		printf("1. Display Phone List\n");
		printf("2. Add a Number\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	// Exit the program
			break;

		case 1: // Display the Phone List
				// @IN-LAB
			printf("Phone Numbers\n");
			printf("==============\n");
			// Display each number in decomposed form
			for (i = 0; i < SIZE; i++) {

				decompose(phoneNumber[i], &areaCode, &prefix, &lineNumber);

				if (areaCode > 0) {
					printf("(%3d)-%3d-%4d\n", areaCode, prefix, lineNumber);
				}
			}
			printf("\n");
			break;

		case 2:	// Add a Phone Number
				// @IN-LAB
			printf("Add a Number\n");
			printf("============\n");
		/*
			// Check if the phoneNumber array is full.
			if (phoneCounter >= SIZE) {
				printf("ERROR!!! Phone Number List is Full\n\n");
			}

			else {
				scanf("%lld", &phoneNumber[phoneCounter]);
				phoneCounter++; 
				printf("\n");
			}*/
		

			if (phoneCounter < SIZE) {
				scanf("%lld", &tempInput);
				temp = isValid(tempInput);
				if (temp == 1) {
					phoneNumber[phoneCounter] = tempInput;
					phoneCounter++;
					printf("\n");
				}

				else {
					printf("ERROR!!! Phone Number is not Valid\n\n");
				}
			}
			
			else if (phoneCounter >= SIZE) {
				printf("ERROR!!! Phone Number List is Full\n\n");
			}
			break;
			
		default:
			printf("ERROR!!!: Incorrect Option: Try Again\n");
			printf("\n");

		break;
		}

	} while (option != 0);

	printf("Exiting Phone Number App. Good Bye!!!\n\n");
	return 0;

}

// Program Input/Output
/*

---=== Phone Numbers ===---

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 1

Phone Numbers
==============

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 2

Add a Number
============
4164915050

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 2

Add a Number
============
9052301212

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 2

Add a Number
============
6475551212

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 1

Phone Numbers
==============
(416)-491-5050
(905)-230-1212
(647)-555-1212

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 2

Add a Number
============
ERROR!!! Phone Number List is Full

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 0

Exiting Phone Number App. Good Bye!!!

*/