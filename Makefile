Objects = main.o employee_class.o file_manipulation.o navigation.o array_manipulation.o

main: $(Objects)
	g++ -pedantic-errors -std=c++11 $^ -o $@

main.o: main.cpp employee_class.h file_manipulation.h navigation.h array_manipulation.h
	g++ -pedantic-errors -std=c++11 -c $<

employee_class.o: employee_class.cpp employee_class.h
	g++ -pedantic-errors -std=c++11 -c $<

file_manipulation.o: file_manipulation.cpp file_manipulation.h employee_class.h
	g++ -pedantic-errors -std=c++11 -c $<

navigation.o: navigation.cpp navigation.h employee_class.h array_manipulation.h
	g++ -pedantic-errors -std=c++11 -c $<

array_manipulation.o: array_manipulation.cpp array_manipulation.h
	g++ -pedantic-errors -std=c++11 -c $<

clean:
	rm main $(Objects)

.PHONY: clean
