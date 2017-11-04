/*
Name: Kyunghoon Kim
Student number: 056 845 100
Email:khkim12@myseneca.ca
Workshop:Workshop5 - home
Section: IPC144SJJ
Date: 2/18/2017
*/

// Copy your source code from in_lab file to here V
// Expand the option list to include option 3 & 4 after V
// option 2. as following V
// "3. Update Employee Salary" V
// "4. Remove Employee" V

// Create two switch-cases for option 3 & 4 after case 2. 
// Implement "Update Salary" and "Remove Employee" 
// functionality as per instructions
// inside the relevant case statements


#include <stdio.h>

// Define Number of Employees "SIZE" to be 4
#define SIZE 4

// Declare Struct Employee 
struct Employee {
	int AnIdentificationNumber;
	int Age;
	double Salary;
	
};

/* main program */
int main(void)
{
	int temp=0;
	int i = 0;
	int option = 0;
	printf("---=== EMPLOYEE DATA ===---\n\n");

	// Declare a struct Employee array "emp" with SIZE elements
	// and initialize all elements to zero
	struct Employee emp[SIZE] = { { 0 } };


	do {
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	// Exit the program	
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;


		case 1: // Display Employee Data
				// @IN-LAB

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			for (i = 0; i < SIZE; i++) {
				if (emp[i].AnIdentificationNumber > 0) {
					printf("%6d%9d%11.2lf\n", emp[i].AnIdentificationNumber, emp[i].Age, emp[i].Salary);
				}
			}
			// Use "%6d%9d%11.2lf" formatting in a   
			// printf statement to display
			// employee id, age and salary of 
			// all  employees using a loop construct 

			// The loop construct will be run for SIZE times 
			// and will only display Employee data 
			// where the EmployeeID is > 0
			printf("\n");
			break;



		case 2:	// Adding Employee
				// @IN-LAB	

			printf("Adding Employee\n");
			printf("===============\n");
			for (i = 0; i < SIZE; i++) {
				if (emp[i].AnIdentificationNumber == 0) {
					break;
				}
			}

			if (i == SIZE) {
				printf("ERROR!!! Maximum Number of Employees Reached\n");
			}

			else {
				printf("Enter Employee ID: ");
				scanf("%d", &emp[i].AnIdentificationNumber);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[i].Age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[i].Salary);
			}

			printf("\n");
			// Check for limits on the array and add employee 
			// data accordingly. 
			break;

		case 3: //UpdateSalary;
			do {
				printf("Update Employee Salary\n");
				printf("======================\n");
				printf("Enter Employee ID: ");
				scanf("%d", &temp);
				for (i = 0; i < SIZE; i++) {
					if (temp==emp[i].AnIdentificationNumber){
						printf("The current salary is %.2lf\n", emp[i].Salary);
						printf("Enter Employee New Salary: ");
						scanf("%lf", &emp[i].Salary);
						printf("\n");
						break;
					}
				}
		} while (temp != emp[i].AnIdentificationNumber);

		break;

		case 4: // Remove Employee
			do {
				printf("Remove Employee\n");
				printf("===============\n");
				printf("Enter Employee ID: ");
				scanf("%d", &temp);

				for (i = 0; i < SIZE; i++) {
					if (temp == emp[i].AnIdentificationNumber) {
						printf("Employee %d will be removed\n", emp[i].AnIdentificationNumber);
						emp[i].AnIdentificationNumber = 0;
						printf("\n");
						break;
					}
				} 
			} while (i>SIZE);
			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}
	} while (option != 0);


	return 0;
}




// PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 5

ERROR: Incorrect Option: Try Again

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 111
Enter Employee Age: 34
Enter Employee Salary: 78980.88

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 112
Enter Employee Age: 41
Enter Employee Salary: 65000

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 113
Enter Employee Age: 53
Enter Employee Salary: 120345.78

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 114
Enter Employee Age: 25
Enter Employee Salary: 46780

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   112       41   65000.00
   113       53  120345.78
   114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 3

Update Employee Salary
======================
Enter Employee ID: 112
The current salary is 65000.00
Enter Employee New Salary: 99999.99

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   112       41   99999.99
   113       53  120345.78
   114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 4

Remove Employee
===============
Enter Employee ID: 112
Employee 112 will be removed

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   113       53  120345.78
   114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!
*/