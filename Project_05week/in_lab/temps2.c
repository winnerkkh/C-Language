#include <stdio.h>

#define MAXDAYS 10

int main(void)

{
	int day = 0;
	int highTemperature[MAXDAYS];
	int lowTemperature[MAXDAYS];
	int i;

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
	/*while (i < 4) {
	printf("Day %d - High:", i + 1);
	scanf("%d", &highTemperature[i]);
	printf("Day %d - Low:", i + 1);
	scanf("%d", &lowTemperature[i]);
	i++;
	}*/

	printf("Day  Hi  Low\n");
	for (i = 0; i < day; i++) {
		printf("%d    %d    %d\n", i + 1, highTemperature[i], lowTemperature[i]);
	}

	return 0;
}