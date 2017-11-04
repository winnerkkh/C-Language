#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Define statements:
#define LINEAR 1
#define FORM 0
#define STOCK 1
#define CHECKOUT 0
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100
#define MAX_ITEM_NO 500
#define DATAFILE "items.txt"


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


// Function Prototypes Milesone 3:
void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item* itemptr);
void addItem(struct Item item[], int *NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int* NoOfRecs);
void adjustQuantity(struct Item item[], int NoOfRecs, int stock);


// Function Prototypes Milesone 3:
void saveItem(struct Item item, FILE* dataFile);
int loadItem(struct Item* item, FILE* dataFile);
int saveItems(const struct Item item[], char fileName[], int NoOfRecs);
int loadItems(struct Item item[], char fileName[], int* NoOfRecsPtr);



// Function Implementations Milestone 1:
void welcome(void) {
	printf("---=== Grocery Inventory System ===---\n\n");
}


// print the tile on the screen
void printTitle(void) {
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}

// print the footer on the screen
void printFooter(double gTotal) {
	printf("--------------------------------------------------------+----------------\n");

	if (gTotal > 0)
		printf("                                           Grand Total: |%12.2lf\n", gTotal); // changed to space instead of \t(asked by prof)

}


// need flushkeyboard function to get rid of buffer
void flushKeyboard(void) {
	while (getchar() != '\n');
}

// pause function after flushkey 
void pause(void) {
	printf("Press <ENTER> to continue...");
	flushKeyboard();
}


//  This checks the integer value if the value is okay or not
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


// give the limit for integer value from lower to upper; so the value doens't go over more and less
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



//This checks the double value if the value is okay or not
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
// give the limit for double from lower to upper; so the value doens't go over more and less
double getDoubleLimited(double lowerLimit, double upperLimit) {

	double valueLimit;
	valueLimit = getDouble();
	while (valueLimit < lowerLimit || valueLimit > upperLimit) {
		printf("Invalid value, %lf <value < %lf: ", lowerLimit, upperLimit);
		valueLimit = getDouble();
	}
	return valueLimit;
}




// yes function to receive the response from user yes or no
int yes(void) {
	char response;
	int result;

	scanf("%c", &response);
	flushKeyboard();
	while (response != 'Y' && response != 'y' && response != 'N' && response != 'n') {
		printf("Only (Y)es or (N)o are acceptable: ");

		scanf(" %c", &response); // need space before %C to work flushkeyboard well
		flushKeyboard();
	}

	if (response == 'Y' || response == 'y')
		result = 1;

	if (response == 'N' || response == 'n')
		result = 0;

	return result;
}


// menu list, so user can see the menu list 
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


// it holds the swtich statement of menu list
void GroceryInventorySystem(void) {

	int option;
	int exit = 0;
	struct Item item[MAX_ITEM_NO] = { 0 };
	int arrayNumber;
	
	welcome();

	if (loadItems(item, DATAFILE, &arrayNumber) == 1) {
		do {
			option = menu();
			switch (option) {
			
			case 1:
				listItems(item, arrayNumber);
				pause();
				break;

			case 2:
				search(item, arrayNumber);
				pause();
				break;

			case 3:
				adjustQuantity(item, arrayNumber, CHECKOUT);
				saveItems(item, DATAFILE, arrayNumber);
				if (saveItems(item, DATAFILE, arrayNumber) == 0) {
					printf("could not update data file %s\n", DATAFILE);
				}
				pause();
				break;

			case 4:
				adjustQuantity(item, arrayNumber, STOCK);
				saveItems(item, DATAFILE, arrayNumber);

				if (saveItems(item, DATAFILE, arrayNumber) == 0) {
					printf("could not update data file %s\n", DATAFILE);
				}
				pause();
				break;

			case 5:
				addOrUpdateItem(item, &arrayNumber);
				saveItems(item, DATAFILE, arrayNumber);

				if (saveItems(item, DATAFILE, arrayNumber) == 0) {
					printf("could not update data file %s\n", DATAFILE);
				}

				pause();
				break;

			case 6:
				printf("Not implemented!\n");
				pause();
				break;

			case 7:
				printf("Not implemented!\n");
				pause();
				break;

			case 0:
				printf("Exit the program? (Y)es/(N)o: ");
				if (yes() == 1) {
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
	else {
		printf("Could not read from %s.\n", DATAFILE);
	}
}
	

	





// Function Implementations Milestone 2:


// caculate the tax part
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
	if (item.quantity <= item.minQuantity)
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
	item.price = getDoubleLimited(0.01, 1000.00);
	printf("   Quantity: ");
	item.quantity = getIntLimited(1, MAX_QTY);
	printf("Minimum Qty: ");
	item.minQuantity = getIntLimited(0, 100);
	printf("   Is Taxed: ");
	item.isTaxed = yes();
	item.sku = sku; //  Assigning the value 999 to sku variable( after exiting the function, then 999 is not saved; so need to assgin the value again to save)

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

		else if (item.quantity <= item.minQuantity) {
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
		printf("%-4d", counter + 1);
		displayItem(item[counter], LINEAR);
		grandTototal += totalAfterTax(item[counter]); //add the total price of the current Item element in the array to the grand total value.
		counter++;
	}
	printFooter(grandTototal);
}

int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index) {
	int i;
	int result = 0;
	for (i = 0; i < NoOfRecs; i++) {
		if (item[i].sku == sku) {
			*index = i; // if the sequence is found, then assign i to the pointer *index
			result = 1;
		}
	}

	return result;
}


// Function Implementations Milestone 3:
void search(const struct Item item[], int NoOfRecs) {

	int findSkuTemp; // to receive the return value, need a temp valriable
	int searchIndexTemp;

	printf("Please enter the SKU: ");
	findSkuTemp = getIntLimited(SKU_MIN, SKU_MAX);


	// When pointer variable called, putting & sign and might be a promise
	// Need " > 0" because without it, the locationitem function is always true and might be able to make a error 
	if (locateItem(item, NoOfRecs, findSkuTemp, &searchIndexTemp) > 0) {
		displayItem(item[searchIndexTemp], FORM);
	}
	else {
		printf("Item not found!");
		printf("\n");
	}
}


//update the contents of the struct by given
void updateItem(struct Item* itemptr) {

	struct Item item = *itemptr;

	printf("Enter new data:\n");
	item = itemEntry(item.sku);
	printf("Overwrite old data? (Y)es/(N)o: ");
	if (yes() == 1) {
		*itemptr = item;
		printf("--== Updated! ==--\n");
	}
	else {
		printf("--== Aborted! ==--\n");
	}
}


// add more book items and checks if the limit is over or not
void addItem(struct Item item[], int *NoOfRecs, int sku) {

	struct Item tempSku;


	if (*NoOfRecs == MAX_ITEM_NO) {
		printf("Can not add new item; Storage Full!\n");
	}

	else {
		tempSku = itemEntry(sku);
		printf("Add Item? (Y)es/(N)o: ");

		int addAnswer = yes(); // returs 1(true) or 0(false)
		if (addAnswer == 1) {

			item[*NoOfRecs] = tempSku;
			(*NoOfRecs)++;

			printf("--== Added! ==--\n"); //successs comment;
		}

		else {
			printf("--== Aborted! ==--\n"); //fail comment
		}

	}
}


//either item updates if it already existed otherwise it adds new item
void addOrUpdateItem(struct Item item[], int* NoOfRecs) {

	int findSkuTemp;
	int searchIndexTemp;
	int a = 0;

	printf("Please enter the SKU: ");
	findSkuTemp = getIntLimited(SKU_MIN, SKU_MAX);
	if (locateItem(item, *NoOfRecs, findSkuTemp, &searchIndexTemp)) {
		displayItem(item[searchIndexTemp], FORM);
		printf("Item already exists, Update? (Y)es/(N)o: ");
		a = yes();
		if (a == 1) {
			updateItem(&item[searchIndexTemp]);
		} // 1 is true, 0 is false but will receive 1, searchIndextemp is a temporary varaiable to receive a return value from located locateItem function.
		else {
			printf("--== Aborted! ==--\n");
		}
	}

	else {
		addItem(item, NoOfRecs, findSkuTemp);
	}
}


// checking the quantity
void adjustQuantity(struct Item item[], int NoOfRecs, int stock)
{
	int findSkuTemp;
	int searchIndexTemp;
	int userInput;

	printf("Please enter the SKU: ");
	findSkuTemp = getIntLimited(SKU_MIN, SKU_MAX); //checking the value whether it is in the right limit
	if (locateItem(item, NoOfRecs, findSkuTemp, &searchIndexTemp)) {
		displayItem(item[searchIndexTemp], FORM);

		if (stock == STOCK) {
			printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", "to stock", MAX_QTY - item[searchIndexTemp].quantity);
			userInput = getIntLimited(0, MAX_QTY - item[searchIndexTemp].quantity);
		}

		else if (stock == CHECKOUT) {
			printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", "to checkout", item[searchIndexTemp].quantity);
			userInput = getIntLimited(0, item[searchIndexTemp].quantity);
		}

		if (userInput == 0) {
			printf("--== Aborted! ==--\n");
			return;
		}

		else {
			if (stock == STOCK) {
				item[searchIndexTemp].quantity = item[searchIndexTemp].quantity + userInput;
				printf("--== Stocked! ==--\n");
			}
			else if (stock == CHECKOUT) {
				item[searchIndexTemp].quantity = item[searchIndexTemp].quantity - userInput;
				printf("--== Checked out! ==--\n");
			}
		}

		if (item[searchIndexTemp].quantity <= item[searchIndexTemp].minQuantity) {
			printf("Quantity is low, please reorder ASAP!!!\n");
		}
	}

	else {
		printf("SKU not found in storage!\n");
	}
}


// Function Implementations Milestone 4:

// save the item type in the text file
void saveItem(struct Item item, FILE* dataFile) {
	fprintf(dataFile,"%d,%d,%d,%.2lf,%d,%s\n", item.sku, item.quantity, item.minQuantity, item.price, item.isTaxed, item.name);
}// doesn't need arrow because the struct is not pointer

//[^\n] means reading new 


//read the saved item from the text file and save it to the struct
int loadItem(struct Item* item, FILE* dataFile) {

	int returnValue = 0;
	int rv = 6;

	if (dataFile != NULL) {
		if (rv == fscanf(dataFile, "%d,%d,%d,%lf,%d,%[^\n]", &item->sku, &item->quantity, &item->minQuantity, &item->price, &item->isTaxed, item->name)) { 
			returnValue = 1; // which is true if the return value is 6 so assign to returnValue
			// doens't need a newline, because it needs only for fprintf statement
			// %[^\n] means reading until new line, %20[^\n] means reading up to 20 characters
		}
	}
	return returnValue; // either 1 or 0
}


// save the multiple items with the type to the text file by using saveitem fucntion
int saveItems(const struct Item item[], char fileName[], int NoOfRecs) { 
	int counter;
	FILE *fp = NULL;
	fp = fopen(fileName, "w");
	int returnValue;

	//NoOfRecs is 3 in this case as the tester indicates
	if (fp != NULL) {
		for (counter = 0; counter < NoOfRecs; counter++) {
			saveItem(item[counter], fp);
			returnValue = 1;
		}

		fclose(fp);
	}

	else {
		returnValue = 0;
	}
	return returnValue;
}



// read the item type from the text file
int loadItems(struct Item item[], char fileName[], int* NoOfRecsPtr) {
	//NoOfrecsPtr doesn't assign to 3

	int returnValue;
	int temp;
	int i = 0;

	FILE *fp = NULL;
	fp = fopen(fileName, "r");

	if (fp != NULL) {

		temp = loadItem(&item[i], fp);
		while (temp == 1) {
			i++;
			temp = loadItem(&item[i], fp);
		}
		*NoOfRecsPtr = i;
		returnValue = 1;
		fclose(fp);
	}

	else {
		returnValue = 0;
	}


	/*

	for (counter = 0; counter < NoOfRecsPtr; counter++) {
	loadItem(&item[counter], fp);
	returnValue = 1;
	}
	
	*/

	return returnValue;
}





void deleteItem(struct Item* item, int* NoOfRecs)
{
	int findSkuTemp;
	int counter;
	int searchIndexTemp;

	printf("Please enter the SKU: ");
	findSkuTemp = getIntLimited(SKU_MIN, SKU_MAX);
	if (locateItem(item, *NoOfRecs, findSkuTemp, &searchIndexTemp)) {
		displayItem(item[searchIndexTemp], FORM);
		printf("This Item will be deleted, are you sure? (Y)es/(N)o: ");
		int a = yes();
		if (a == 1) {
			for (counter = searchIndexTemp; counter < *NoOfRecs; counter++) {
				item[counter] = item[counter + 1];
			}
			printf("Item deleted!\n");
			(*NoOfRecs)--;
		}
		else{
			printf("Delete aborted!\n");
		}
	}
	else {
		printf("Item not found!\n");
	}

}








int main(void) {


	GroceryInventorySystem();

	return 0;
}