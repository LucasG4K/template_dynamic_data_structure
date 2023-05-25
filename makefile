output: main.o methods.o
	g++ main.cpp methods.cpp -o output

methods.o: methods.cpp methods.hpp
	g++ -c methods.cpp

main.o: main.cpp
	g++ -c main.cpp

run:
	./output

remove:
	rm *.o

clean:
	rm *.o output