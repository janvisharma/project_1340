main: main.o employee_class.o file_manipulation.o navigation.o
	g++ -pedantic-errors -std=c++11 main.o employee_class.o file_manipulation.o navigation.o -o main

main.o: main.cpp employee_class.h file_manipulation.h navigation.h
	g++ -pedantic-errors -std=c++11 -c main.cpp

employee_class.o: employee_class.h employee_class.cpp
	g++ -pedantic-errors -std=c++11 -c employee_class.cpp

file_manipulation.o: file_manipulation.h file_manipulation.cpp
	g++ -pedantic-errors -std=c++11 -c file_manipulation.cpp

navigation.o: file_manipulation.h navigation.h navigation.cpp
	g++ -pedantic-errors -std=c++11 -c navigation.cpp

clean:
	rm main main.o employee_class.o file_manipulation.o navigation.o

.PHONY: clean
