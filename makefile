CC = g++
exe_file = driver
$(exe_file): patron.cpp librarian.cpp cart.cpp library.cpp driver.cpp
	$(CC) -g patron.cpp librarian.cpp cart.cpp library.cpp driver.cpp -o driver
