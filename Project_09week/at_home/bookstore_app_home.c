/*
Name:
Student number:
Email:
Workshop:
Section:
Date:
*/


#include <stdio.h>


#define MAX_BOOKS 10
#define MAX_TITLE_SIZE 20

struct Book {
	int _isbn;
	float _price;
	int _year;
	char _title[MAX_TITLE_SIZE];
	int _qty;
};

//prototypes
void menu();
void displayInventory(const struct Book book[], const int size);
int searchInventory(const struct Book book[], const int isbn, const int size);
void addBook(struct Book book[], int *size);
void checkPrice(const struct Book book[], const int size);


void flushKeyboard();



//implemetations
void menu() {

	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add a book to the inventory.\n");
	printf("3) Check price.\n");
	printf("0) Exit.\n");
	printf("\n");



}

void displayInventory(const struct Book book[], const int size) {
	int i = 0;

	if (size == 0) {
		printf("The inventory is empty!\n===================================================\n\n");
	}
	else {
		printf("\n\nInventory\n");
		printf("===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");

		for (i = 0; i < size; i++) {
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book[i]._isbn, book[i]._title, book[i]._year, book[i]._price, book[i]._qty);
		}

		printf("===================================================\n\n");

	}
}

// need this function for home part
int searchInventory(const struct Book book[], const int isbn, const int size) {
	
	int i = 0;
	int temp = -1; //falg concept

	for (i = 0; i < size; i++) {
		if (isbn == book[i]._isbn) {
			temp = i;
			
		}
	}
	return temp;

}


void flushKeyboard() {
	while (getchar() != '\n');
}

void addBook(struct Book book[], int *size) {    // pointer changes size in main function automatically when changed ibn

	int quantity = 0;
	int temp = -1;

	if (*size == MAX_BOOKS) {
		printf("the inventory is full");
	}

	else {
		printf("ISBN:");
		scanf("%d", &book[*size]._isbn);
		flushKeyboard();
	
		// if the temp is -1, then there is no book added so far; so need to add
		temp = searchInventory(book, book[*size]._isbn, *size);
		if (temp == -1) {

		printf("Quantity:");
		scanf("%d", &book[*size]._qty);
		flushKeyboard();

		printf("Title:");
		scanf("%20[^\n]", book[*size]._title);
		flushKeyboard();

		printf("Year:");
		scanf("%d", &book[*size]._year);
		flushKeyboard();

		printf("Price:");
		scanf("%f", &book[*size]._price);
		flushKeyboard();

		*size += 1;
		printf("The book is successfully added to the inventory.\n\n");
		}
		else {
			printf("Quantity:");
			scanf("%d", &quantity);
			book[temp]._qty = quantity + book[temp]._qty;
			printf("The book exists in the repository, quantity is updated.\n\n");
		}
	}
};

void checkPrice(const struct Book book[], const int size) {
	int isbn = 0;
	int temp = 0;
	printf("Please input the ISBN number of the book:\n\n");
	scanf("%d", &isbn);
	temp = searchInventory(book, isbn, size);

	if (temp == -1){
		printf("Book does not exist in the bookstore! Please try again.");
	}

	else{
		printf("Book %d costs $%.2f\n\n", book[temp]._isbn, book[temp]._price);
	}
}



int main(void) {

	struct Book book[MAX_BOOKS];
	int size = 0;
	int option;

	printf("Welcome to the Book Store\n");
	printf("=========================\n");

	do {

		menu();
		printf("Select: ");
		scanf("%d", &option);

		switch (option) {

		case 1:

			displayInventory(book, size);
			break;
		case 2:

			addBook(book, &size);
			break;

		case 3:

			checkPrice(book, size);
			break;

		case 0:
			printf("Goodbye!\n");
			break;


		default:
			printf("Invalid input, try again:\n");
			break;
		}

	} while (option != 0);


	return 0;
}


