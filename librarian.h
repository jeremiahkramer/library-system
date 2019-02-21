#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "cart.h"
#include <string>

using namespace std;

class librarian {
	private:
		string name;
		int id;
	public:
		librarian();
		string get_name() const;
		void set_name(const string &);
		int get_id() const;
		void set_id(const int &);
		
		void change_library_hours();
		void add_new_books(const cart &);
		int search_title(book *, int);
		void remove_old_books(book *, int);
		void view_all_books_checked_out();
		void view_specific_book_checked_out(string);

};

#endif
