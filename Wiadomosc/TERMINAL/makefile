#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

TRGDIR=/tmp/Wiadomosc

__start__: ./Wiadomosc
	./Wiadomosc

./Wiadomosc: obj obj/main.o obj/kolejka.o 
                        
	g++ -Wall -pedantic -std=c++11 -o ./Wiadomosc obj/main.o obj/kolejka.o 

obj:
	mkdir -p obj

obj/main.o: src/main.cpp inc/kolejka.hh 
        
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/kolejka.o: inc/kolejka.hh src/kolejka.cpp
	g++ -c ${CXXFLAGS} -o obj/kolejka.o src/kolejka.cpp

clean:
	rm -f obj/*.o ./Wiadomosc