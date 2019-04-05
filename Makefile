main: main.o employee_class.o
	g++ -pedantic-errors -std=c++11 main.o employee_class.o -o main

main.o: main.cpp
	g++ -pedantic-errors -std=c++11 -c main.cpp

employee_class.o: employee_class.h employee_class.cpp
	g++ -pedantic-errors -std=c++11 -c employee_class.cpp

clean:
	rm main main.o employee_class.o

.PHONY: clean
