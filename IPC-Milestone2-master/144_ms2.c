#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



// Define statements:
#define LINEAR 1
#define FORM 0



// Constant TAX value:
const double TAX = 0.13;

// Item structure:

struct Item {

	double price;
	int sku;
	int isTaxed;
	int quantity;
	int minQuantity;
	char name[21];

};


// Function Prototypes Milestone 1:
// tools
void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);
// app interface
int yes(void);
void GroceryInventorySystem(void);
int menu(void);




// Function Prototypes Milesone 2:

double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int noOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);


// Function Implementations Milestone 1:
void welcome(void) {
	printf("---=== Grocery Inventory System ===---\n\n");
}

void printTitle(void) {
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}

void printFooter(double gTotal) {
	printf("--------------------------------------------------------+----------------\n");

	if (gTotal > 0)
		printf("                                           Grand Total: |%12.2lf\n", gTotal);

}

void flushKeyboard(void) {
	while (getchar() != '\n');
}

void pause(void) {
	printf("Press <ENTER> to continue...");
	flushKeyboard();
}

int getInt(void) {
	char nL = 'x';
	int value;

	while (nL != '\n') {
		scanf("%d%c", &value, &nL); //&nL only receives the declared nL= x even though I type something character
		if (nL != '\n') {
			while (nL != '\n') {
				flushKeyboard();
				printf("Invalid integer, please try again: ");
				scanf("%d%c", &value, &nL);
			}
		}
	}
	return value;
}

int getIntLimited(int lowerLimit, int upperLimit) {

	int valueLimit;
	valueLimit = getInt();
	// Inclusive the lower&upper value
	while (valueLimit < lowerLimit || valueLimit > upperLimit) {
		printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
		valueLimit = getInt();
	}
	return valueLimit;
}

double getDouble(void) {
	char nL = 'x';
	double value;

	while (nL != '\n') {
		scanf("%lf%c", &value, &nL);
		if (nL != '\n') {
			while (nL != '\n') {
				flushKeyboard();
				printf("Invalid number, please try again: ");
				scanf("%lf%c", &value, &nL);
			}
		}
	}
	return value;


}

double getDoubleLimited(double lowerLimit, double upperLimit) {

	double valueLimit;
	valueLimit = getDouble();
	while (valueLimit < lowerLimit || valueLimit > upperLimit) {
		printf("Invalid value, %lf <value < %lf: ", lowerLimit, upperLimit);
		valueLimit = getDouble();
	}
	return valueLimit;
}

int yes(void) {
	char response;
	int result;

	scanf("%c", &response);

	while (response != 'Y' && response != 'y' && response != 'N' && response != 'n') {
		printf("Only (Y)es or (N)o are acceptable: ");

		flushKeyboard();
		scanf("%c", &response);

	}

	if (response == 'Y' || response == 'y')
		result = 1;

	if (response == 'N' || response == 'n')
		result = 0;

	return result;
}

int menu(void) {
	int number;

	printf("1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("6- delete item\n");
	printf("7- Search by name\n");
	printf("0- Exit program\n");
	printf("> ");

	number = getIntLimited(0, 7);
	return number;

}

void GroceryInventorySystem(void) {

	int option;
	welcome();
	int exit = 0;
	do {
		option = menu();
		switch (option)
		{
		case 1:
			printf("List Items under construction!\n");
			pause();
			break;
		case 2:
			printf("Search Items under construction!\n");
			pause();
			break;
		case 3:
			printf("Checkout Item under construction!\n");
			pause();
			break;
		case 4:
			printf("Stock Item under construction!\n");
			pause();
			break;
		case 5:
			printf("Add/Update Item under construction!\n");
			pause();
			break;
		case 6:
			printf("Delete Item under construction!\n");
			pause();
			break;
		case 7:
			printf("Search by name under construction!\n");
			pause();
			break;
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			if (yes() == 1)

			{
				exit = 1;
			}
			break;
		default:
			printf("Invalid value, 0 < value < 7: ");
			flushKeyboard();
			break;
		}
	} while (exit != 1);

}



// Function Implementations Milestone 2:

double totalAfterTax(struct Item item) {
	
	double totalInventoryPrice;
	//False == 0
	if (item.isTaxed == 0) {
		totalInventoryPrice = (item.price)*((double)item.quantity);
	}
	//True == 1
	else if (item.isTaxed == 1) {
		totalInventoryPrice = (item.price*(double)item.quantity) + ((item.price*(double)item.quantity)*TAX);
	}

	return totalInventoryPrice;
}

int isLowQuantity(struct Item item) {
	
	int value = 0;
	if (item.quantity < item.minQuantity)
		value = 1; //true
	
	return value;
}

struct Item itemEntry(int sku) {

	struct Item item;

	printf("        SKU: %d\n", sku);
	printf("       Name: ");
	scanf("%20[^\n]", item.name);
	flushKeyboard();
	printf("      Price: ");
	item.price = getDouble();
	printf("   Quantity: ");
	item.quantity = getInt();
	printf("Minimum Qty: ");
	item.minQuantity = getInt();
	printf("   Is Taxed: ");
	item.isTaxed = yes();
	item.sku = sku; //  Assigning the value 999 to sku variable( after exiting the function, then 999 is not saved; so need to assgin the value again to save)
	flushKeyboard();
	return item;
}

void displayItem(struct Item item, int linear) {
	double totalPrice;
	totalPrice = totalAfterTax(item);

	// If the side of liner displays, then follw the instruction but yeah no mentioning of the side, then assume it's starting off from right side.
	if (linear == 1) { 
		printf("|%3d", item.sku);
		printf("|%-20s", item.name);
		printf("|%8.2lf", item.price);

		if (item.isTaxed == 1) {
			printf("|  Yes");
		}

		else if (item.isTaxed == 0) {
			printf("|   No");
		}

		printf("|%4d ", item.quantity);    //checking the spacing
		printf("|%4d ", item.minQuantity);
		printf("|%12.2lf|", totalPrice);
		
		if (item.quantity > item.minQuantity) {
			printf("\n");
		}

		else if (item.quantity < item.minQuantity) {
			printf("***\n");
		}
	}

	else if (linear == 0) {
		printf("        SKU: %d\n", item.sku);
		printf("       Name: %s\n", item.name);
		printf("      Price: %.2lf\n", item.price);
		printf("   Quantity: %d\n", item.quantity);
		printf("Minimum Qty: %d\n", item.minQuantity);
		
		if (item.isTaxed == 1) {
			printf("   Is Taxed: Yes\n");
		}

		else if (item.isTaxed == 0) {
			printf("   Is Taxed: No\n");
		}

		if (isLowQuantity(item) == 1) {
			printf("WARNING: Quantity low, please order ASAP!!!\n");
		}
	}


}

void listItems(const struct Item item[], int noOfItems) {

	int counter = 0;
	double grandTototal = 0.0;

	printTitle();
	while (counter < noOfItems) {
		printf("%-4d", counter+1);
		displayItem(item[counter], LINEAR);
		grandTototal += totalAfterTax(item[counter]); //add the total price of the current Item element in the array to the grand total value.
		counter++;
	}
	printFooter(grandTototal);
}

int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index) {

	for (*index = 0; *index < NoOfRecs; (*index)++) {
		if (item[*index].sku == sku) {
			return 1;
		}
	}

	return 0;
}


