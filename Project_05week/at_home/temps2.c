
#include <stdio.h>

#define MAXDAYS 10

int main(void)

{
	int day;
	int highTemperature[MAXDAYS];
	int lowTemperature[MAXDAYS];
	int sum = 0;
	int close = 0;
	int i = 0;
	double average = 0;
	

	printf("---=== IPC Temperature Analyzer V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &day);
	printf("\n");

	
	while (3 > day || 10 < day) {
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &day);
		printf("\n");
	}

	for (i = 0; i < day; i++) {
		printf("Day %d - High: ", i + 1);
		scanf("%d", &highTemperature[i]);
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &lowTemperature[i]);
	}
	printf("\n");
	printf("Day  Hi  Low\n");
	for (i = 0; i < day; i++) {
		printf("%d    %d    %d\n", i + 1, highTemperature[i], lowTemperature[i]);

	} 

	int totalDay;
	while (close!=1) {
		printf("\n");
		printf("Enter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", day);
		scanf("%d", &totalDay);
		printf("\n");

		
		if (totalDay < 0) {
			printf("Goodbye!\n");
			close = 1;
		}
		
		while (totalDay == 0 || totalDay>day) {
			if (close != 1) {
				printf("Invalid entry, please enter a number between 1 and 4, inclusive: ");
				scanf("%d", &totalDay);
				printf("\n");
			}
		
			if (totalDay < 0) {
				printf("Goodbye!\n");
				close = 1;
			}
		}

		for (i = 0; i < totalDay; i++) {
			sum += highTemperature[i] + lowTemperature[i];
		}
		if (close != 1){
			average = (double)(sum / (2.0 * totalDay));
			printf("The average temperature up to day %d is: %.2lf\n", totalDay, average);
		   }
		sum = 0;
	
	} 
	
	return 0;

}


