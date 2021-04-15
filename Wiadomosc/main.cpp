#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <chrono>
#include "kolejka.hh"
using namespace std;

#define ROZMIAR 1000							//Stala zawierajaca maksymalny rozmiar wiadomosci


//Funkcja losuje liczby i wstawia przetasowana wiadomosc do listy
void losuj(Node **head, char tab[ROZMIAR], int licznik){

	int los[ROZMIAR];							//Tablica zapisujaca wylosoane wartosci

	for (int i = 0; i < licznik; i++){			//Petla FOR okresla ilosc wylosowanych liczb
		 los[i] = rand() % licznik;				//Zapisywanie w tabeli pseudo losowych liczb
		 for (int j = 0; j<i; j++){
			 if (los[j] == los[i]){				//Sprawdza czy nowo wylosowana liczba sie nie powtarza
				 los[i] = rand() % licznik;		//Ponowne losowanie liczby
		         j = -1;
		     }
		 }
		 wstaw(head,los[i], tab[los[i]]);		//Wstawainie potasowanej wiadomosci do listy
	}
}

//Funkcja liczy ilosc pakietow i zwraca ich wartosc
int policz(char tab[ROZMIAR]){

	int licznik;							//Zmienna pomocnicza

	for(int i = 0; tab[i] != '\0'; i++){	//Petla dziala tak dlugo az natrafi na '\0' - znak konca
		licznik = i;
	}
	licznik = licznik + 1;					//Wartosc 1 elementu tablicy jest zapisana pod tab[0]
											// dlatego musi byc +1
	return licznik;							//Zwraca ilosc pakietow
}


int main() {


	Node *head = NULL;					//Wskaznik Head wskazuje na NULL
	Node *wiadom = NULL;					//Wskaznik Wiadom wskazuje na NULL
	char tab[ROZMIAR];					//Tablica tab o rozmiarze ROZMIAR przechowuje wiadomosc
	int licznik;							//Zmienna zapamietujaca ilosc znakow w wiadomosci


	cout << endl << endl;
	cout << "Napisz wiadomosc: ";

	cin.get(tab,ROZMIAR);				//Wpisanie wiadomosci do tabeli

	//Poczatek mierzenia czasu
	chrono::steady_clock::time_point begin = chrono::steady_clock::now();

	licznik = policz(tab);				//Oblicza ilosc znakow w wiadomosci

	cout << endl << endl;
	cout << "Wiadomosc zostala podzielona na: " << licznik << " pakietow." << endl << endl;


	losuj(&head,tab, licznik);			//Losowanie liczb z zakresu "licznik" i wstawienie znakow w roznej kolejnosci
	cout << "\t Wysylanie wiadomosci " << endl;
	cout << "\t Odebranie wiadomosci " << endl << endl;



	cout << "***********************************************" << endl;
	cout << "Odebrana wiadomosc przed posortowaniem: " << endl << endl;
	wyswietl(head);						//Wyswietlanie wymieszanej wiadomosci
	cout << endl << endl << endl;
	Ustaw(&head, &wiadom, licznik);		//Ustawianie wiadomosci w zaleznosci od liczby "licz"

	cout << "***********************************************" << endl;
	cout << "\t Sortowanie pakietow" << endl << endl << endl;
	cout << "Wiadomosc:\t";
	wyswietl(wiadom);					//Wyswietlanie ustawionej wiadomosci
	cout << endl << endl << " Koniec programu" << endl << endl;

	//Koniec mierzenia czasu
	chrono::steady_clock::time_point end = chrono::steady_clock::now();
	cout << endl << endl;

	//Wypisywanie czasu trwania algorytmu
	cout << "Time = " << chrono::duration_cast<chrono::seconds>(end - begin).count() << " [s]  10^(-6)s" << endl;
	cout << "Time = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " [ms]  10^(-6)s" << endl;
	cout << "Time = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << " [us]  10^(-6)s" << endl;
	cout << "Time = " << chrono::duration_cast<chrono::nanoseconds> (end - begin).count() << " [ns]  10^(-9)s" << endl;


	return 0;



/*
	   	   	   	   	   	   	   	   	   //DRIVER



	Node *driver = NULL;					//Lista 1
	Node *driver_2 = NULL;					//Lista 2
	Node *driver_3 = NULL;					//Lista 3
	Node *driver_4 = NULL;					//Lista 4
	char tablica[] = "Driver";				//Tablica znakow o nieokreslonym rozmiarze
	int licznik = 6;						//Zmienna pomocnicza zawierajaca ilosc znakow
	int licznik_2;							//Zmienna pomocnicza zliczajaca ilosc znakow

	wstaw(&driver, 3, 'I'); 				//Wstawia element o liczie 3 i znaku 'I' do listy
	wstaw(&driver, 4, 'V');					//Wstawia element o liczie 4 i znaku 'V' do listy

	dodaj(&driver, 2, 'R');					//Dodaje element o liczbie 2 i znaku "R" do listy
	dodaj(&driver, 1, 'D');					//Dodaje element o liczbie 1 i znaku "D" do listy

	wstaw(&driver, 6, 'R');					//Wstawia element o liczie 6 i znaku 'R' do listy
	dodaj(&driver, 5, 'E');					//Dodaje element o liczie 5 i znaku 'E' do listy

	cout << endl << "Nieuporzadkowana lista" << endl;
	wyswietl(driver);						//Wyswietla zawartosc listy 1
	cout << endl << endl;

	Ustaw(&driver, &driver_2, licznik);		//Elementy sa ustawiane w odpowiedniej koljnosci

	cout << endl << "Uporzadkowana lista" << endl;
	wyswietl(driver_2);						//Wyswietla zawartosc listy 2
	cout << endl << endl << endl;

	licznik_2 = policz(tablica);			//Funkcja zwraca ilosc znakow w tablicy

	cout << "Liczba znakow w tablicy: " << licznik_2 << endl;

	losuj(&driver_3, tablica, licznik_2);

	cout << endl << "Nieuporzadkowana lista" << endl;
	wyswietl(driver_3);						//Wyswietla zawartosc listy 3
	cout << endl << endl;

	Ustaw(&driver_3, &driver_4, licznik_2);		//Elementy sa ustawiane w odpowiedniej koljnosci

	cout << endl << "Nieuporzadkowana lista" << endl;
	wyswietl(driver_4);						//Wyswietla zawartosc listy 4
	cout << endl << endl;

	return 0;
*/

}
