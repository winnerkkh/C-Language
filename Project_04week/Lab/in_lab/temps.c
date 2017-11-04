/*
Name: Kyunghoon Kim
Student number: 056 845 100
Email: khkim12@myseneca.ca
Workshop: Workshop3
Section: IPC144SJJ
Date: 2/1/2017
*/

#include <stdio.h>
#define NUMS 3

int main(void)
{
	int i = 0;
	int High = 0;
	int Low = 0;
	int Totalhigh = 0;
	int Totallow = 0;
	double average;

	printf("---=== IPC Temperature Calculator ===---\n");

	for (i = 0; i < NUMS; i++) {
		printf("Enter the high value for day %d: ", i + 1);
		scanf("%d", &High);
		printf("\n");
		printf("Enter the low value for day %d: ", i + 1);
		scanf_s("%d", &Low);
		printf("\n");

		while (High > 40 || Low < -40 || Low >= High) {
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");
			printf("Enter the high value for day %d: ", i + 1);
			scanf_s("%d", &High);
			printf("\n");
			printf("Enter the low value for day %d: ", i + 1);
			scanf_s("%d", &Low);
			printf("\n");
		}

		Totalhigh = Totalhigh + High;
		Totallow = Totallow + Low;
		
	}


	average = (double)(Totalhigh + Totallow) / (NUMS * 2);
	printf("The average (mean) temperature was: %.2lf\n", average);

	return 0;
}




