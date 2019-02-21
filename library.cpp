/******************************************************
 ** Program: library.cpp
 ** Author: Jeremiah Kamer
 ** Date: 04/30/2017
 ** Description: function definitions for library file
 ** Input: menu ("1","2", etc.), id to login, etc.
 ** Output: library hours, books array, etc.
 ****************************************************/
#include "library.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

/****************************
 ** Function: library default constructor
 ** Description: constructs object library and intializes everything to 0/ NULL
 ** Parameters: none
 ** Pre- Conditions: none
 ** Post- Conditions: You've created an object
 ** Return: none
 ****************************/
library::library() {
	for (int i = 0; i < 7; i++){
		week[i].begin_time = " ";
		week[i].end_time = " ";
	}
	num_books = 0;
	books = NULL;
}
/****************************
 ** Function: library non-default constructor
 ** Description: constructs object library and intializes members to values of the parameters
 ** Parameters: int, string, string
 ** Pre- Conditions: none
 ** Post- Conditions: You've created an object with certain member values/ it has memory that needs to be freed
 ** Return: none
 ****************************/
library::library(int tot_books, string begin, string end) {
	ifstream inp;
	for (int i = 0; i < 7; i++){
		week[i].begin_time = begin;
		week[i].end_time = end;
	}
	num_books = tot_books;
	books = new book[num_books];
	inp.open("books.txt");
	for (int i = 0; i < num_books; i++){
		getline(inp, books[i].title, '|');
		inp >> books[i].num_authors;
		books[i].authors = new string[books[i].num_authors];
		for (int j = 0; j < books[i].num_authors; j++){
			getline(inp, books[i].authors[j], '|');
		}
		inp >> books[i].year;
		inp >> books[i].copies;
	}
	inp.close();
}
/****************************
 ** Function: library copy constructor

 ** Description: constructs object library and deeps copies members from existing object
 ** Parameters: const library &
 ** Pre- Conditions: need to have an object already created
 ** Post- Conditions: You've created another object, with the same values as a pre- existing object/ it has memory that needs to be freed
 ** Return: none
 ****************************/
library::library(const library &other){
	if (num_books == 0)

		books = NULL;
	else
		num_books = other.num_books;
		books = new book[num_books];
		for (int i = 0; i < num_books; i++){
			books[i] = other.books[i];
			books[i].authors = new string[books[i].num_authors];
			for (int j = 0; j < books[i].num_authors; j++){
				books[i].authors[j] = other.books[i].authors[j];
			}
		}
		for (int i = 0; i < 7; i++){
			week[i].begin_time = other.week[i].begin_time;
			week[i].end_time = other.week[i].end_time;
		}
		_cart = other._cart;
		_librarian = other._librarian;
		_patron = other._patron;
}
/****************************
 ** Function: library destructor
 ** Description: destructs library object by freeing memory
 ** Parameters: none
 ** Pre- Conditions: objected already created with memory allocated on it
 ** Post- Conditions: no memory leaks
 ** Return: none
 ****************************/
library::~library(){
	if (num_books == 0)
		books = NULL;
	else{
		for (int i = 0; i < num_books; i++){
			delete [] books[i].authors;
		}
		delete [] books;
	}
}
/****************************
 ** Function: library assignment overload
 ** Description: frees memory then constructs 
 ** Parameters: const library &
 ** Pre- Conditions: none
 ** Post- Conditions: You've created an object and have allocated memory/ need to free memory
 ** Return: none
 ****************************/
void library::operator=(const library &other){
	
	if (num_books == 0)
		books = NULL;
	
	else{
		for (int i = 0; i < num_books; i++){
			for (int j = 0; j < books[i].num_authors; j++){
				delete [] books[i].authors;
			}
			delete [] books;
		}
		books = new book[other.num_books];
		num_books = other.num_books;
		for (int i = 0; i < num_books;i++){
			books[i] = other.books[i];
			books[i].authors = new string[books[i].num_authors];
			for (int j = 0; i < books[i].num_authors; j++){
				books[i].authors[j] = other.books[i].authors[j];
			}
		}
		for (int i = 0; i < 7; i++){
			week[i].begin_time = other.week[i].begin_time;
			week[i].end_time = other.week[i].end_time;
		}
		_cart = other._cart;
		_librarian = other._librarian;
		_patron = other._patron;
	}
}
/****************************
 ** Function: get_hours
 ** Description: returns a pointer that points to the hours of the week the library is open/closed 
 ** Parameters: none
 ** Pre- Conditions: hours set to something
 ** Post- Conditions: none
 ** Return: hours* / week
 ****************************/
hours * library::get_hours(){
	return week;
}
/****************************
 ** Function: set_hours
 ** Description: sets the member of this class 
 ** Parameters: string, string
 ** Pre- Conditions: object created
 ** Post- Conditions: hours are set to something
 ** Return: none
 ****************************/
void library::set_hours(string begin, string end){
	for (int i = 0; i < 7; i++) { //7 days of the week loop
		week[i].begin_time = begin;
 		week[i].end_time = end;
	}
}
/****************************
 ** Function: get_num_books
 ** Description: returns num_books of the book array 
 ** Parameters: none
 ** Pre- Conditions: num_books set to something
 ** Post- Conditions: none
 ** Return: num_books
 ****************************/
int library::get_num_books() {
	return num_books;
}
/****************************
 ** Function: set_num_books
 ** Description: sets the member of this class 
 ** Parameters: int
 ** Pre- Conditions: object created
 ** Post- Conditions: num_books are set to something
 ** Return: none
 ****************************/
void library::set_num_books(int n) { //set num_books
	num_books = n;
}
/****************************
 ** Function: get_books
 ** Description: returns a pointer that points to the book array 
 ** Parameters: none
 ** Pre- Conditions: book array set to something
 ** Post- Conditions: none
 ** Return: books / book *
 ****************************/
book * library::get_books(){	
	return books;
}
/****************************
 ** Function: set_books
 ** Description: sets the member of this class 
 ** Parameters: book &
 ** Pre- Conditions: object created
 ** Post- Conditions: book array is set to something
 ** Return: none
 ****************************/
void library::set_books(book &b){ //populates book array
	books = &b;
}
/****************************
 ** Function: get_cart
 ** Description: returns cart 
 ** Parameters: none
 ** Pre- Conditions: cart set to something
 ** Post- Conditions: none
 ** Return: cart
 ****************************/
cart library::get_cart(){
	return _cart;
}
/****************************
 ** Function: set_cart
 ** Description: sets the member of this class 
 ** Parameters: cart &
 ** Pre- Conditions: object created
 ** Post- Conditions: cart is set to something
 ** Return: none
 ****************************/
void library::set_cart(cart &c){
	_cart = c;
}
/****************************
 ** Function: get_librarian
 ** Description: returns librarian
 ** Parameters: none
 ** Pre- Conditions: librarian set to something
 ** Post- Conditions: none
 ** Return: librarian
 ****************************/
librarian library::get_librarian(){
	return _librarian;
}
/****************************
 ** Function: set_librarian
 ** Description: sets the member of this class 
 ** Parameters: librarian &
 ** Pre- Conditions: object created
 ** Post- Conditions: librarian is set to something
 ** Return: none
 ****************************/
void library::set_librarian(librarian &l){
	_librarian = l;
}
/****************************
 ** Function: get_patron
 ** Description: returns patron
 ** Parameters: none
 ** Pre- Conditions: patron set to something
 ** Post- Conditions: none
 ** Return: patron
 ****************************/
patron library::get_patron(){
	return _patron;
}
/****************************
 ** Function: set_patron
 ** Description: sets the member of this class 
 ** Parameters: patron &
 ** Pre- Conditions: object created
 ** Post- Conditions: patron is set to something
 ** Return: none
 ****************************/
void library::set_patron(patron &p){
	_patron = p;
}
/****************************
 ** Function: display_daily_hours
 ** Description: displays the daily hours to the screen
 ** Parameters: string
 ** Pre- Conditions: hours of the week set
 ** Post- Conditions: none
 ** Return: none
 ****************************/
void library::display_daily_hours(string day){
	//when this function is called, there should be a check to see if the correct day of the week is inputted
	if (day == "Monday" || day == "monday")
		cout << "Begin Time: " << week[0].begin_time << " End Time: " << week[0].end_time << endl;
	if (day == "Tuesday" || day == "tuesday")
		cout << "Begin Time: " << week[1].begin_time << " End Time: " << week[1].end_time << endl;
	if (day == "Wednesday" || day == "wednesday")
		cout << "Begin Time: " << week[2].begin_time << " End Time: " << week[2].end_time << endl;
	if (day == "Thursday" || day == "thursday")
		cout << "Begin Time: " << week[3].begin_time << " End Time: " << week[3].end_time << endl;
	if (day == "Friday" || day == "friday")
		cout << "Begin Time: " << week[4].begin_time << " End Time: " << week[4].end_time << endl;
	if (day == "Saturday" || day == "saturday")
		cout << "Begin Time: " << week[5].begin_time << " End Time: " << week[5].end_time << endl;
	if (day == "Sunday" || day == "sunday")
		cout << "Begin Time: " << week[6].begin_time << " End Time: " << week[6].end_time << endl;
	// can't necessarily loop through it because the names of the days are different
	else
		return;
}
/****************************
 ** Function: display_weekly_hours
 ** Description: displays the weekly hours to the screen
 ** Parameters: none
 ** Pre- Conditions: hours of the week set
 ** Post- Conditions: none
 ** Return: none
 ****************************/
void library::display_weekly_hours(){
	for (int i = 0; i < 7; i++){ //for 7 days of the week
		if (i == 0)
			cout << "Monday" << endl;
		if (i == 1)
			cout << "Tuesday" << endl;
		if (i == 2)
			cout << "Wednesday" << endl;
		if (i == 3)
			cout << "Thursday" << endl;
		if (i == 4)
			cout << "Friday" << endl;
		if (i == 5)
			cout << "Saturday" << endl;
		if (i == 6)
			cout << "Sunday" << endl;
		cout << "Begin Time: " << week[i].begin_time << " End Time: " << week[i].end_time << endl; //print when it opens and closes
	}
}
/****************************
 ** Function: is_valid_int
 ** Description: checks if integer is inputted, and checks that it is between a range
 ** Parameters: int, int, int
 ** Pre- Conditions: none/ supply integers to function (pass by value)
 ** Post- Conditions: none
 ** Return: none
 ****************************/
void library::is_valid_int(int choice, int x, int y){
	while (!cin || choice > x || choice < y){ //while the incorrect type is inputted or the value is above or below the range//while wrong
		cout << "Please enter a valid integer between " << y << "-" << x << ". " << endl; 
	   cin.clear(); //clear wrong input
		cin.ignore(); //clear buffer
		cin >> choice;
	}
}
/****************************
 ** Function: menu
 ** Description: first of the many menus you see. You can view hours or login or quit
 ** Parameters: library
 ** Pre- Conditions: library object created
 ** Post- Conditions: int choice returned
 ** Return: int
 ****************************/
int library::menu(library l){
	int choice = 0;
  
	cout << "Would you like to view hours(1), login (2), or quit(0)?: ";
   cin >> choice;
	
	l.is_valid_int(choice, 2, 0); //error handle and recover. range 0-2
	
	if (choice == 0){
		exit(0); //quit program
	}
	else{
		return choice; //return int
	}
}
/****************************
 ** Function: menu_2
 ** Description: second menu. Daily hours or weekly/ librarian or patron login
 ** Parameters: library
 ** Pre- Conditions: menu
 ** Post- Conditions: returns a choice (int)
 ** Return: int
 ****************************/
int library::menu_2(library l){
	int choice = l.menu(l); //call last function
  	if (choice == 1){
		cout << "Daily Hours(1) or Weekly Hours(2)?: ";
		cin >> choice;
		is_valid_int(choice, 2, 1); //error handle and recover
		return choice;
	}
   if (choice  == 2){
		cout << "Librarian(3) or Patron(4): ";
		cin >> choice;
		is_valid_int(choice, 4, 3); //error handle and recover
		return choice;
	}
}
/****************************
 ** Function: is_valid_day
 ** Description: checks for valid day input. used in action_menu
 ** Parameters: string
 ** Pre- Conditions: input a string to check
 ** Post- Conditions: will get a valid string because it recovers
 ** Return: none
 ****************************/
void library::is_valid_day(string day){
	bool check = false;
	while (check == false){
		if (day == "Monday" || day == "monday" || day == "Tuesday" || day == "tuesday" || day == "Wednesday" || day == "wednesday" || day == "Thursday" || day == "thursday" || day == "Friday" || day == "friday"){
			check = true;
			//if they inputted a correct day of the week, then continue
		}
		else{
			check = false;
			cout << "wrong input" << endl; //error handle and recover
			cin.clear();
			cin.ignore();
			cout << "What day whould you like to view?: ";
			cin >> day;
		}
	}
}
/****************************
 ** Function: read_lbrarian_id
 ** Description: reads the correct id from the library system
 ** Parameters: none
 ** Pre- Conditions: login_info.txt
 ** Post- Conditions: returns an id (int)
 ** Return: int
 ****************************/
int library::read_librarian_id(){
	int id;
	string name;
	ifstream inp;
	inp.open("login_info.txt");
	inp >> id; //get the id
	getline(inp, name);
	inp.close();
	return id;
}
/****************************
 ** Function: is_valid_l_id
 ** Description: checks for successful or unsuccessful login 
 ** Parameters: library, int
 ** Pre- Conditions: they need to input an id and the program needs to have read the correct id in the system
 ** Post- Conditions: returns true or false if the login is successful/ unsuccessful
 ** Return: bool
 ****************************/
bool library::is_valid_l_id(library l, int login_id){
	int correct_id = l.read_librarian_id(); //read from system
	if (login_id == correct_id){ //if they are equal, then return true
		return true;
	}
	else{
		return false;
	}
}
/****************************
 ** Function: read_patron_id
 ** Description: reads the correct id from the library system
 ** Parameters: none
 ** Pre- Conditions: login_info.txt
 ** Post- Conditions: returns an id (int)
 ** Return: int
 ****************************/
int library::read_patron_id(){
	int id;
	string temp, name;
	ifstream inp;
	inp.open("login_info.txt");
	getline(inp, temp); //ignore first line in text file
	inp >> id; //get the id
	getline(inp, name);
	inp.close();
	return id;
}
/****************************
 ** Function: is_valid_p_id
 ** Description: checks for successful or unsuccessful login 
 ** Parameters: library, int
 ** Pre- Conditions: they need to input an id and the program needs to have read the correct id in the system
 ** Post- Conditions: returns true or false if the login is successful/ unsuccessful
 ** Return: bool
 ****************************/
bool library::is_valid_p_id(library l, int login_id){
	int correct_id = l.read_patron_id(); //read from the system
	if (login_id == correct_id){ //if they are equal, then return true
		return true;
	}
	else{
		return false;
	}
}
/****************************
 ** Function: action_menu
 ** Description: another menu for after they chose if they want to view daily/ weekly hours or librarian/ patron login 
 ** Parameters: library
 ** Pre- Conditions: menu_2
 ** Post- Conditions: returns an int based on what they chose
 ** Return: int
 ****************************/
int library::action_menu(library l){
 	bool check = false;
	string day;
	int choice = l.menu_2(l); //call menu_2
	int lib_id, pat_id;
 	if (choice == 1){
		cout << "What day whould you like to view?: ";
		cin >> day;
		l.is_valid_day(day); //error handle and recover for correct day input
		l.display_daily_hours(day); //display daily hours at certain day
		return 0;
	}
	else if (choice == 2){
		l.display_weekly_hours(); //display weekly hours
		return 0;
	}
	else if (choice == 3){
		cout << "Enter your id: ";
		cin >> lib_id;
		check = l.is_valid_l_id(l, lib_id); //check if id they inputted matches id in the system
		if (check == true){
			cout << "Login Successful." << endl;
			return 1;
		}
		else{
			cout << "Incorrect." << endl;
			return 0;
		}
	}
	else if (choice == 4){
		cout << "Enter your id: ";
		cin >> pat_id;
		check = l.is_valid_p_id(l, pat_id); //check if id they inputted matches id in the system
		if (check = true){
			cout << "Login Successful." << endl;
			return 2;
		}
		else{
			cout << "Incorrect." << endl;
			return 0;
		}
		//a bunch of if/ else statements. Don't know how to minimize lines in function
	}
}
/****************************
 ** Function: lib_login
 ** Description: once the librarian successfully logged in, this is the menu for them 
 ** Parameters: library, int
 ** Pre- Conditions: librarian needs to have logged in
 ** Post- Conditions: does what they want to do
 ** Return: int
 ****************************/
int library::lib_login(library l, int choice){
	int decision;
	cout << "Do you want to: change library hours(1), add books to the database(2), remove old books(3), view books checked out(4), or logout(0)? ";
	cin >> decision;
	is_valid_int(decision, 4, 0); //error handle and recover for range 0-4
	return decision;
}
/****************************
 ** Function: patron_login
 ** Description: once the patron successfully logged in, this is the menu for them 
 ** Parameters: library, int
 ** Pre- Conditions: patron needs to have logged in
 ** Post- Conditions: does what they want to do
 ** Return: int
 ****************************/
int library::patron_login(library l, int choice){
	int decision;
	cout << "Do you want to: view all the books in the library(5), search the database of books(6), check in books(7), check out books(8), view all the books checked out(9), or logout(10) ";
	cin >> decision;
	is_valid_int(decision, 10, 5); //error handle and recover for range 5-10
	return decision;
}
/****************************
 ** Function: login_menu
 ** Description: calls librarian login and patron login in one function. also handles when the login is unsuccessful 
 ** Parameters: library
 ** Pre- Conditions: action_menu
 ** Post- Conditions: returns their decision for each of their menus
 ** Return: int
 ****************************/
int library::login_menu(library l){
	int choice, decision;
	choice = l.action_menu(l); //call action_menu
	if (choice == 0){
		l.login_menu(l); //take it back to the login_menu
	}
	else if (choice == 1){
		decision = l.lib_login(l, choice); //librarian
	}
	else if (choice == 2){
		decision = l.patron_login(l, choice); //patron
	}
	return decision;
}
/****************************
 ** Function: lib_menu
 ** Description: calls login_menu calls other functions to do what they want to do 
 ** Parameters: library
 ** Pre- Conditions: login_menu
 ** Post- Conditions: returns their decision for each of their menus
 ** Return: none
 ****************************/
void library::lib_menu(library l, int choice){
	while(choice != 0){
		if (choice == 1){
			l.change_hours(l);
			choice = l.lib_login(l, choice);
		}
		if (choice == 2){
			cin.ignore();
			cout << "add books" << endl;
			l.add_books();
			choice = l.lib_login(l, choice);
		}
		if (choice == 3){
			cout << "remove books" << endl;
			l._librarian.remove_old_books(books, num_books);
			choice = l.lib_login(l, choice);
		}
		if (choice == 4){
			cout << "view books checked out" << endl;
			choice = l.lib_login(l, choice); //
		}
	}
	if (choice == 0 || choice == 10){
		choice = l.login_menu(l);
	}
}
/****************************
 ** Function: pat_menu
 ** Description: calls login_menu calls other functions to do what they want to do 
 ** Parameters: library
 ** Pre- Conditions: login_menu
 ** Post- Conditions: returns their decision for each of their menus
 ** Return: none
 ****************************/
void library::pat_menu(library l, int choice){
	while (choice != 10){
		if (choice == 5){
			cout << "view all books" << endl;
			l.print_books();
			choice = l.patron_login(l, choice);
		}
		if (choice == 6){
			cout << "Search database by title(1), author(2), year(3): ";
			//search()
			choice = l.patron_login(l, choice);
		}
		if (choice == 7){
			cout << "Check in books" << endl;
			choice = l.patron_login(l, choice);
		}
		if (choice == 8){
			cout << "Check out books" << endl;
			choice = l.patron_login(l, choice);
		}
		if (choice == 9){
			cout << "View all books checked out" << endl;
			//print_cart();
			choice = l.patron_login(l, choice);
		}
	}
	if (choice == 10 || choice == 0){
		choice = l.login_menu(l);	
	}
}
/****************************
 ** Function: function_menu
 ** Description: calls lib_menu and pat_menu 
 ** Parameters: library
 ** Pre- Conditions: login_menu, lib_name, pat_menu
 ** Post- Conditions: none
 ** Return: none
 ****************************/
void library::function_menu(library l){
	int choice = l.login_menu(l);
	if (choice >= 0 && choice <= 4){
		l.lib_menu(l, choice);
	}
	else if (choice >= 5 && choice <= 10){
		l.pat_menu(l, choice);
	}
}
/****************************
 ** Function: change_hours
 ** Description: changes hours of operation
 ** Parameters: library
 ** Pre- Conditions: librarian to login successful and to choose this function
 ** Post- Conditions: hours are changed
 ** Return: none
 ****************************/
void library::change_hours(library l){
	string open, close;
	cin.ignore();
	cout << "Library opens: ";
	getline(cin, open);
	cout << endl;
	cout << "Library closes: ";
	getline(cin, close);
	cout << endl;
	for (int i = 0; i < 7; i++){
		week[i].begin_time = open; //change for begin_time and end_time
		week[i].end_time = close;
	}
}
/****************************
 ** Function: print_books
 ** Description: prints array of books
 ** Parameters: 
 ** Pre- Conditions: book array
 ** Post- Conditions: printed book array
 ** Return: none
 ****************************/
void library::print_books(){
	for (int i = 0; i < num_books; i++){ //for num_books
		cout << "Title: " << books[i].title << endl;
		cout << "Number of Authors: " << books[i].num_authors << endl;
		for (int j = 0; j < books[i].num_authors; j++){ //for num_authors
			cout << "Author name: " << books[i].authors[j] << endl;
		}
		cout << "Year: " << books[i].year << endl;
		cout << "Copies: " << books[i].copies << endl;
	}
}
/****************************
 ** Function: add_books
 ** Description: appends books to the library database
 ** Parameters: none
 ** Pre- Conditions: book.txt
 ** Post- Conditions: new books in book.txt
 ** Return: none
 ****************************/
void library::add_books(){
	string title_name, author_names;
	int number_books, number_authors, year_value, num_copies;
	ofstream out; //so i can write to a file
	cout << "How many books do you want to add? ";
	cin >> number_books;
	out.open("books.txt", ios::app);
	for (int i = 0; i < number_books; i++){
		cin.ignore();
		cout << "Title: ";
		getline(cin, title_name);
		out << title_name << "|";
		cout << endl;
		cout << "Number of authors: ";
		cin >> number_authors;
		out << " " << number_authors;
		cout << endl;
		for (int j = 0; j < number_authors; j++){
			cin.ignore();
			cout << "Author name: ";
			getline(cin, author_names);
			out << author_names << "|";
			cout << endl;
		}
		cout << "Year: ";
		cin >> year_value;
		out << " " << year_value << " ";
		cout << endl;
		cout << "Copies: ";
		cin >> num_copies;
		out << num_copies;
		cout << endl;
	}
	out.close();
}
