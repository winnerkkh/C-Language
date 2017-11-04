
/*
Name: KYUNGHOON KIM
Student number: 056835100
Email: khkim12@myseneca.ca
Workshop: workshop 9 - lab
Section: IPC144
Date:
*/


#include <stdio.h>

#define MAX_BOOK 10
#define MAX_TITLE_SIZE 21


//Type the struct here
struct Book {
	int _isbn;
	float _price;
	int _year;
	int _qty;
	char _title[MAX_TITLE_SIZE];
};
/*	_isbn: International Standard Book Number.
	_price : Book price.
	_year : Publication year.
	_qty : Book Quantity.
	_title : Book title.
*/

//Type the function prototypes here
void menu();
void displayInventory(const char filename[]);
//void addBook(const char filename[], struct Book *b2Add);
void checkPrice(const char filename[], const int isbn2find);
//int searchInventory(FILE *fp, const int isbn2find);
float calculateCapital(const char filename[]);
int readRecord(FILE *fp, struct Book *b2read);



int main()
{
	char filename[] = "144_w9_inventory.txt";
	int option = 0;
	
	printf("Welcome to the Book Store\n=========================\n");


   //Type your code here:

	do {

		menu();
		scanf("%d", &option);

		switch (option) {
			case 0: //Good bye message and exit the switch function
				
				printf("Goodbye!\n");
				break;

			case 1:

				displayInventory(filename);
				break;
			case 2:

				break;

			case 3:

				break;
			case 4:

				printf("The total capital is: $%.2f.\n", calculateCapital(filename));
				break;

			default:
				printf("Invalid input, try again:\n");

		}


	} while (option != 0);

    return 0;
}

void menu() {
	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add a book to the inventory.\n");
	printf("3) Check price.\n");
	printf("4) Calculate total capital of the store.\n");
	printf("0) Exit.\n\n");
	printf("Select: ");
}



void displayInventory(const char filename[]) {
    //Define an object of struct Book
	struct Book mybook;

    //Open the file, and check for null pointer
	FILE *fp = NULL;
	fp = fopen(filename, "r");

	//If the file is properly opened, display headers, similar to workshop 8
	if (fp != NULL) {
		printf("\n\nInventory\n");
		printf("===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");

		/*call readRecord and check its return value*/
		//Use a while loop to call readRecord and display the records.
		//display the record
		while (readRecord(fp, &mybook) == 5) {
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", mybook._isbn, mybook._title, mybook._year, mybook._price, mybook._qty);
		}
			//Display the footer
			printf("===================================================\n\n");

			//Close the file
			fclose(fp);
		}




	else {
		printf("File is not available to open.\n\n");
	}

}


/*void addBook(const char filename[], struct Book *b2Add)
{
 //Not implemented!
}*/

void checkPrice(const char filename[],const int isbn2find)
{
    
 //Not implemented!

 
}

/*int searchInventory(FILE *fp,const int isbn2find)
{
 //Not implemented!
}*/


float calculateCapital(const char filename[])
{
    
    
    //Define an object of struct Book
	struct Book mybook;

    //Define and initialize total_capital
	float total_capital=0;  // float is needed due to the function declaires as float
    
    //Open the file, and check for null pointer
	FILE *fp = NULL;
	fp = fopen(filename, "r");
    
    //If the file is properly opened, use a while loop to call readRecord
	/*call readRecord and check its return value*/
	//Accumulate the multiplication of the price of each item to its quantity

	if (fp != NULL); {
		while (readRecord(fp, &mybook) == 5) {
			total_capital = total_capital + (double)(mybook._price * mybook._qty);
		}
	}
	
	//Display the footer  // do not understadn for this comment why we need a footer in this total_capital function

	//Close the file
	fclose(fp);

    //return the total_capital
	return total_capital;
    
}

int readRecord(FILE *fp, struct Book *b2read)
{
    //Define a variable int rv = 0
	int rv = 0;
    
    rv = fscanf(fp, "%d;%f;%d;%d;%19[^\n]", &(b2read->_isbn), &(b2read->_price), &(b2read->_year), &(b2read->_qty), b2read->_title);
   
    return rv;

}
