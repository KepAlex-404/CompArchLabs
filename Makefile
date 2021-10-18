# Makefile for World project
binary: HotelTest.o libDatabase.a
	g++ -o binary HotelTest.o -L. -lDatabase
HotelTest.o: HotelTest.cpp
	g++ -c HotelTest.cpp
libDatabase.a: Hotel.o Database.o
	ar cr libDatabase.a Hotel.o Database.o
Hotel.o: Hotel.cpp
	g++ -c Hotel.cpp
Database.o: Database.cpp
	g++ -c Database.cpp
clean:
	rm -f *.o *.a binary