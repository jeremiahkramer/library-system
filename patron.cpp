/******************************************************
  ** Program: patron.cpp
  ** Author: Jeremiah Kamer
  ** Date: 04/30/2017
  ** Description: function definitions for patron file
  ** Input: nothing really
  ** Output: nothing really
  ****************************************************/
#include "patron.h"

/****************************
 ** Function: patron()
 ** Description: default constructor for patron// set memebrs to 0
 ** Parameters: none
 ** Pre- Conditions: none
 ** Post- Conditions: patron object created
 ** Return: none
 ****************************/
patron::patron(){
	name = " ";
	id = 0;
	books_checked_out = 0;
}
/****************************
 ** Function: get_name
 ** Description: gets the name of the patron
 ** Parameters: none
 ** Pre- Conditions: name to get
 ** Post- Conditions: access to patron name
 ** Return: string
 ****************************/
string patron::get_name() const{
	return name;
}
/****************************
 ** Function: set_name
 ** Description: sets the name of the patron
 ** Parameters: const string &
 ** Pre- Conditions: name to set
 ** Post- Conditions: new patron name
 ** Return: none
 ****************************/
void patron::set_name(const string &s){
	name = s;
}
/****************************
 ** Function: get_id
 ** Description: gets the id of the patron
 ** Parameters: none
 ** Pre- Conditions: id to get
 ** Post- Conditions: access to patron id
 ** Return: int
 ****************************/
int patron::get_id() const{
	return id;
}
/****************************
 ** Function: set_id
 ** Description: sets the id of the patron
 ** Parameters: const int &
 ** Pre- Conditions: id to set
 ** Post- Conditions: new patron id
 ** Return: none
 ****************************/
void patron::set_id(const int &i){
	id = i;
}
/****************************
 ** Function: get_books_checked_out
 ** Description: gets the num of books checked out
 ** Parameters: none
 ** Pre- Conditions: books checked out to get
 ** Post- Conditions: access to books checked out
 ** Return: int
 ****************************/
int patron::get_books_checked_out(){
	return books_checked_out;
}
/****************************
 ** Function: set_books_checked_out
 ** Description: sets the num of books checked out
 ** Parameters: int &
 ** Pre- Conditions: books checked out to set
 ** Post- Conditions: new books checked out
 ** Return: none
 ****************************/
void patron::set_books_checked_out(int &b){
	books_checked_out = b;
}
/****************************
 ** Function: check_out_books
 ** Description: checks out books out of database
 ** Parameters: const cart &
 ** Pre- Conditions: books to check out
 ** Post- Conditions: books checked out
 ** Return: none
 ****************************/
void check_out_books(const cart &c){
	//
}
/****************************
 ** Function: check_in_books
 ** Description: checks books into the database
 ** Parameters: const cart &
 ** Pre- Conditions: books to check in
 ** Post- Conditions: books checked in
 ** Return: none
 ****************************/
void check_in_books(const cart &c){
	//
}
/****************************
 ** Function: view_my_books_out
 ** Description: prints books checked out
 ** Parameters: none
 ** Pre- Conditions: books checked out
 ** Post- Conditions: printed out books checked out
 ** Return: none
 ****************************/
void view_my_books_out(){
	//
}
