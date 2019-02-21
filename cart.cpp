/******************************************************
  ** Program: cart.cpp
  ** Author: Jeremiah Kamer
  ** Date: 04/30/2017
  ** Description: function definitions for cart file
  ** Input: nothing really
  ** Output: nothing really
  ****************************************************/
#include "cart.h"

/****************************
 ** Function: cart()
 ** Description: default constructor for cart
 ** Parameters: none
 ** Pre- Conditions: none
 ** Post- Conditions: cart object created
 ** Return: none
 ****************************/
cart::cart(){
	books = NULL;
	num_books = 0;
}
/****************************
 ** Function: copy constructor
 ** Description: copy constructor for cart
 ** Parameters: none
 ** Pre- Conditions: other cart already created
 ** Post- Conditions: cart object created, copied from other cart
 ** Return: none
 ****************************/
cart::cart(const cart &other){
	if (num_books == 0)
		books = NULL;
	else
		books = new book[other.num_books];
		num_books = other.num_books;
		for (int i = 0; i < num_books; i++){
			books[i] = other.books[i];
			books[i].authors = new string[books[i].num_authors];
			for (int j = 0; j < books[i].num_authors; j++){
				books[i].authors[j] = other.books[i].authors[j];
			}
		}
}
/****************************
 ** Function: cart destructor
 ** Description: destructor for cart
 ** Parameters: none
 ** Pre- Conditions: none
 ** Post- Conditions: cart memory freed
 ** Return: none
 ****************************/
cart::~cart(){
	for (int i = 0; i < num_books; i++){
			delete [] books[i].authors;
	}
	delete [] books;

}
/****************************
 ** Function: cart assignment overload
 ** Description: destruct, then copy construct cart
 ** Parameters: const cart &
 ** Pre- Conditions: cart object created
 ** Post- Conditions: cart object set to other
 ** Return: none
 ****************************/
void cart::operator=(const cart &other){
	for (int i = 0; i < num_books; i++){
		for (int j = 0; j < books[i].num_authors; j++){
			delete [] books[i].authors;
		}
		delete [] books;
	}

	if (num_books == 0)
		books = NULL;
	else
		books = new book[other.num_books];
		num_books = other.num_books;
		for (int i = 0; i < num_books; i++){
			books[i] = other.books[i];
			books[i].authors = new string[books[i].num_authors];
			for (int j = 0; j < books[i].num_authors; j++){
				books[i].authors[j] = other.books[i].authors[j];
			}
		}
}
/****************************
 ** Function: set_book
 ** Description: sets book array pointer equal to book array in parameter
 ** Parameters: book &
 ** Pre- Conditions: book array
 ** Post- Conditions: changed book array
 ** Return: none
 ****************************/
void cart::set_book(book &book_arr){
	books = &book_arr;
}
/****************************
 ** Function: get_book
 ** Description: gets book array pointer
 ** Parameters: none
 ** Pre- Conditions: book array
 ** Post- Conditions: access to book array
 ** Return: book *
 ****************************/
book * cart::get_books(){
	return books;
}
/****************************
 ** Function: set_book
 ** Description: sets book array pointer equal to book array in parameter
 ** Parameters: int &
 ** Pre- Conditions: book array
 ** Post- Conditions: changed book array
 ** Return: none
 ****************************/
void cart::set_num_books(int &num){
	num_books = num;
}
/****************************
 ** Function: get_num_book
 ** Description: gets num books
 ** Parameters: none
 ** Pre- Conditions: num books
 ** Post- Conditions: access to num books
 ** Return: book *
 ****************************/
int cart::get_num_books(){
	return num_books;
}
/****************************
 ** Function: add_to_cart
 ** Description: appends books to cart file
 ** Parameters: none
 ** Pre- Conditions: cart file (not neccessarily)
 ** Post- Conditions: new books in cart file
 ** Return: none
 ****************************/
void cart::add_to_cart(){
	//append to cart file
}
/****************************
 ** Function: display_books
 ** Description: prints books in cart
 ** Parameters: none
 ** Pre- Conditions: books in cart file to print out
 ** Post- Conditions: prints books to screen
 ** Return: none
 ****************************/
void cart::display_books(){
	//(call read function to read from cart file)
	//cout cart books
}
/****************************
 ** Function: empty_cart()
 ** Description: remove and rename cart file
 ** Parameters: none
 ** Pre- Conditions: cart file (not neccessarily)
 ** Post- Conditions: cart file empty
 ** Return: none
 ****************************/
void cart::empty_cart(){
	//delete cart file
}
