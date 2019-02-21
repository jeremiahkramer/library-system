#ifndef LIBRARY_H
#define LIBRARY_H

#include "librarian.h"
#include "patron.h"

using namespace std;

class library{
	private:
		hours week[7];
		int num_books;
		book *books;
		cart _cart;
		librarian _librarian;
		patron _patron;
	public:
		library();
		library(int, string, string);
		library(const library &);
		~library();
		void operator=(const library &);
		hours * get_hours();
		void set_hours(string, string);
		int get_num_books();
		void set_num_books(int);
		book * get_books();
		void set_books(book &);
		cart get_cart();
		void set_cart(cart &);
		librarian get_librarian();
		void set_librarian(librarian &);
		patron get_patron();
		void set_patron(patron &);
		void display_daily_hours(string);
		void display_weekly_hours();
		
		void is_valid_int(int, int, int);
		int menu(library);
		int menu_2(library);
		void is_valid_day(string);
		int read_librarian_id();
		bool is_valid_l_id(library, int);
		int read_patron_id();
		bool is_valid_p_id(library, int);
		int action_menu(library);
		int lib_login(library, int);
		int patron_login(library, int);
		int login_menu(library);
		void lib_menu(library, int);
		void pat_menu(library, int);
		void function_menu(library);
		void change_hours(library);
		void print_books();
		void add_books();
};
#endif
