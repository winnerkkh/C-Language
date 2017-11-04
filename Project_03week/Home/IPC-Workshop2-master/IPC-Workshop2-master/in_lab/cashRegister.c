// Kyunghoon Kim, 056845100, IPC144SJJ

#include <stdio.h>
int main(void)
{
	double amountDue;
	double GST;
	int Loonies;
	int Quarters;
	int Dimes;
	int Nickels;
	int Pennies;

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amountDue);

	GST = amountDue*.13 + .005;
	printf("GST: %.2lf\n", GST);
	amountDue = amountDue + GST;
	printf("Balance owing: $%.2lf\n", amountDue);

	Loonies = (int)amountDue / 1;
	amountDue = amountDue - (Loonies * 1);
	printf("Loonies required: %d, balance owing $%.2lf\n", Loonies, amountDue);

	Quarters = amountDue / 0.25;
	amountDue = amountDue - (Quarters*0.25);
	printf("Quarters required: %d, balance owing $%.2lf\n", Quarters, amountDue);

	Dimes = amountDue / 0.10;
	amountDue = amountDue - (Dimes*0.10);
	printf("Dimes required: %d, balance owing $%.2lf\n", Dimes, amountDue);

	Nickels = amountDue / 0.05;
	amountDue = amountDue - (Nickels*0.05);
	printf("Nickels required: %d, balance owing $%.2lf\n",Nickels, amountDue);

	Pennies = amountDue / 0.01;
	amountDue = amountDue - (Pennies*0.01);
	printf("Pennies required: %d, balance owing $%.2lf\n", Pennies, amountDue);

	return 0;
}