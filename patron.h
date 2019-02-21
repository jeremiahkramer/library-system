#ifndef PATRON_H
#define PATRON_H

#include "cart.h"
#include <string>

using namespace std;

class patron {
	private:
		string name;
		int id;
		int books_checked_out;
	public:
		patron();
		string get_name() const;
		void set_name(const string &);
		int get_id() const;
		void set_id(const int &);
		int get_books_checked_out();
		void set_books_checked_out(int &);
		void check_out_books(const cart &);
		void check_in_books(const cart &);
		void view_my_books_out();
};
#endif
