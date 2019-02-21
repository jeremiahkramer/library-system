#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>

using namespace std;

struct hours {
	string begin_time;
	string end_time;
};
struct book {
	string title;
	int num_authors;
	string * authors;
	int year;
	int copies;
};
#endif
