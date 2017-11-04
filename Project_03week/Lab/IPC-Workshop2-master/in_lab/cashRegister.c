//Kyunghoon Kim 056845100 IPC144SJJ
#include <stdio.h>
int main(void)

{
	double amountDue;
	int Loonies;
	int Quarters;

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amountDue); 

	Loonies = (int)amountDue / 1;
	amountDue = amountDue - (Loonies * 1);
	printf("Loonies required: %d, balance owing $%.2lf\n", Loonies, amountDue);

	Quarters = amountDue / 0.25;
	amountDue = amountDue - (Quarters * 0.25);
	printf("Quarters required: %d, balance owing $%.2lf\n", Quarters, amountDue);


	return 0;
}


