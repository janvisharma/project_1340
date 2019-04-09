main: main.o employee_class.o file_manipulation.o navigation.o dynamic_array.o
	g++ -pedantic-errors -std=c++11 main.o employee_class.o file_manipulation.o navigation.o dynamic_array.o -o main

main.o: main.cpp employee_class.h file_manipulation.h navigation.h dynamic_array.h
	g++ -pedantic-errors -std=c++11 -c main.cpp

employee_class.o: employee_class.h employee_class.cpp
	g++ -pedantic-errors -std=c++11 -c employee_class.cpp

file_manipulation.o: file_manipulation.h file_manipulation.cpp employee_class.h dynamic_array.h
	g++ -pedantic-errors -std=c++11 -c file_manipulation.cpp

navigation.o: navigation.h navigation.cpp
	g++ -pedantic-errors -std=c++11 -c navigation.cpp

dynamic_array.o: dynamic_array.h dynamic_array.cpp
	g++ -pedantic-errors -std=c++11 -c dynamic_array.cpp

clean:
	rm main main.o employee_class.o file_manipulation.o navigation.o dynamic_array.o

.PHONY: clean
