/******************************************************
  ** Program: librarian.cpp
  ** Author: Jeremiah Kamer
  ** Date: 04/30/2017
  ** Description: function definitions for librarian file
  ** Input: string to search for books, etc.
  ** Output: library hours, books array, etc.
  ****************************************************/
#include "library.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

 /****************************
  ** Function: librarian default constructor
  ** Description: constructs object librarian and intializes everything to 0/ NULL
  ** Parameters: none
  ** Pre- Conditions: none
  ** Post- Conditions: You've created an object
  ** Return: none
  ****************************/
librarian::librarian(){
	name = " ";
	id = 0;
}
 /****************************
  ** Function: get_name
  ** Description: returns private member name
  ** Parameters: none
  ** Pre- Conditions: librarian constructed
  ** Post- Conditions: you've returned a string name
  ** Return: string
  ****************************/
string librarian::get_name() const{
	return name;
}
 /****************************
  ** Function: set_name
  ** Description: sets the name to the value passed into parameter
  ** Parameters: const string &
  ** Pre- Conditions: librarian constructed
  ** Post- Conditions: new name
  ** Return: none
  ****************************/
void librarian::set_name(const string &n){
	name = n;
}
 /****************************
  ** Function: get_id
  ** Description: returns private member id
  ** Parameters: none
  ** Pre- Conditions: librarian constructed
  ** Post- Conditions: you've returned an int id
  ** Return: int
  ****************************/
int librarian::get_id() const{
	return id;
}
 /****************************
  ** Function: set_id
  ** Description: sets the id to the value passed into parameter
  ** Parameters: const int &
  ** Pre- Conditions: librarian constructed
  ** Post- Conditions: new id
  ** Return: none
  ****************************/
void librarian::set_id(const int &i){
	id = i;
}
 /****************************
  ** Function: search_title
  ** Description: searches for a book title in the database
  ** Parameters: book *, int
  ** Pre- Conditions: book array
  ** Post- Conditions: an index
  ** Return: int
  ****************************/
int librarian::search_title(book *books_array, int number_books){

	int index;
	string check_title;
	cout << "Input the title of a book to remove: ";
	cin.ignore();
	getline(cin, check_title); //account for spaces
	for (int i = 0; i < number_books; i++){
		if (check_title == books_array[i].title){
			cout << "you found it!" << endl; //found book you're searching for
			index = i;
		}
		else {
			cout << "book doesn't exist!" << endl; //couldn't find book
		}
	}
	return index;
	
}
 /****************************
  ** Function: remove_old_books
  ** Description: removes the book that the user serahced for in the database
  ** Parameters: book *, int
  ** Pre- Conditions: book array
  ** Post- Conditions: one less book in database
  ** Return: none
  ****************************/
void librarian::remove_old_books(book *books_array, int number_books){

	ifstream in;
	ofstream out;

	//read into books array
	int index = search_title(books_array, number_books);
	//think it only works for first book for some reason

	string empty;
	book *book_array; //different from book array in parameter
	int num_books = number_books;
	book_array = new book[num_books];
	in.open("books.txt"); //read from books.txt
	out.open("temp.txt"); //write to temp.txt
	for (int i = 0; i < num_books; i++){
		if (i == index){
			i++;
			getline(in, empty); //at index, skip over reading into file
		}
		getline(in, book_array[i].title, '|'); //read
		out << book_array[i].title << '|'; //write
		in >> book_array[i].num_authors; //read..
		out << " " << book_array[i].num_authors; //write..
		book_array[i].authors = new string[book_array[i].num_authors];
		for (int j = 0; j < book_array[i].num_authors; j++){
			getline(in, book_array[i].authors[j], '|');
			out << book_array[i].authors[j] << '|';
		}
		in >> book_array[i].year;
		out << " " << book_array[i].year;
		in >> book_array[i].copies;
		out << " " << book_array[i].copies << endl;
	}
	in.close();
	out.close();

	remove("books.txt");
	rename("temp.txt", "books.txt");

	//free memory
	for (int k = 0; k < num_books; k++){
		if (k != index)
			delete [] book_array[k].authors;
	}
	delete [] book_array;
}
