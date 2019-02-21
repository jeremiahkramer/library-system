#ifndef CART_H
#define CART_H

#include "structs.h"

using namespace std;

class cart {
	private:
		book * books;
		int num_books;
		void resize_books(int);
	public:
		cart();
		cart(const cart &);
		~cart();
		void operator=(const cart &);
		void set_book(book &);
		book * get_books();
		void set_num_books(int &);
		int get_num_books();
		void add_to_cart();
		void display_books();
		void empty_cart();
};
#endif
