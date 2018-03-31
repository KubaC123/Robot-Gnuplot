#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

__start__: robot_na_scenie
	./robot_na_scenie

robot_na_scenie: obj obj/main.o obj/Obiekt2D.o obj/Macierz2x2.o obj/Wektor2D.o\
           obj/lacze_do_gnuplota.o obj/Wierzcholki.o obj/Robot.o obj/Sciezka.o\
	   obj/Scena.o obj/Menu.o obj/Przeszkoda.o
	g++ -Wall -pedantic -std=c++0x -o robot_na_scenie obj/main.o obj/Obiekt2D.o obj/Macierz2x2.o obj/Wektor2D.o\
           obj/lacze_do_gnuplota.o obj/Wierzcholki.o obj/Robot.o obj/Sciezka.o\
	   obj/Scena.o obj/Menu.o obj/Przeszkoda.o

obj:
	mkdir obj

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Obiekt2D.o: src/Obiekt2D.cpp inc/Obiekt2D.hh
	g++ -c ${CXXFLAGS} -o obj/Obiekt2D.o src/Obiekt2D.cpp

obj/Macierz2x2.o: src/Macierz2x2.cpp inc/Macierz2x2.hh 
	g++ -c ${CXXFLAGS} -o obj/Macierz2x2.o src/Macierz2x2.cpp

obj/Wektor2D.o: src/Wektor2D.cpp inc/Wektor2D.hh
	g++ -c ${CXXFLAGS} -o obj/Wektor2D.o src/Wektor2D.cpp

obj/Wierzcholki.o: src/Wierzcholki.cpp inc/Wierzcholki.hh
	g++ -c ${CXXFLAGS} -o obj/Wierzcholki.o src/Wierzcholki.cpp

obj/Robot.o: src/Robot.cpp inc/Robot.hh
	g++ -c ${CXXFLAGS} -o obj/Robot.o src/Robot.cpp

obj/Sciezka.o: src/Sciezka.cpp inc/Sciezka.hh
	g++ -c ${CXXFLAGS} -o obj/Sciezka.o src/Sciezka.cpp

obj/Scena.o: src/Scena.cpp inc/Scena.hh
	g++ -c ${CXXFLAGS} -o obj/Scena.o src/Scena.cpp

obj/Menu.o: src/Menu.cpp inc/Menu.hh
	g++ -c ${CXXFLAGS} -o obj/Menu.o src/Menu.cpp

obj/Przeszkoda.o: src/Przeszkoda.cpp inc/Przeszkoda.hh
	g++ -c ${CXXFLAGS} -o obj/Przeszkoda.o src/Przeszkoda.cpp

clean:
	rm -f obj/*.o robot_na_scenie
