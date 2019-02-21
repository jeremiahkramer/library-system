 /****************************
  ** Program: driver.cpp
  ** Author: Jeremiah Kramer
  ** Date: 4/30/17
  ** Description: runs the library.cpp, librarian.cpp, patron.cpp, cart.cpp functions. Simulates online library system
  ** Input: ints (menu navigation), librarian/ patron id, strings for books to remove, change library hours, etc.
  ** Output: Various things from: books in database to library hours
  ***************************/
#include <iostream>
#include "library.h"
#include <string>
#include <cstdlib>

using namespace std;

int main(){
	
	library lib(3, "8 am", "10 pm"); //non- default constructor

	lib.function_menu(lib);

	return 0;
}
