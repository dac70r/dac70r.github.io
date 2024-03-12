# Write the make file here USE mingw32-make to make and mingw32-make clean to clean

all: lab8.exe

main.o: main.cpp lab8.h
	g++ -c main.cpp

lab8.o: lab8.cpp lab8.h
	g++ -c lab8.cpp

lab8.exe: main.o lab8.o
	g++ -o lab8.exe main.o lab8.o

clean:
	del lab8.exe main.o lab8.o