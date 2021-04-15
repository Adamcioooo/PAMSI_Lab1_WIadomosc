#ifndef STOS_HH
#define STOS_HH


//Lista dwukierunkowa
struct Node {
   int licz;			//Zmienna przechowyjaca liczbe
   char znak;			//Zmienna przechowyjaca znak
   Node* next;			//wskaznik na nastepny element
   Node* prev;			//wskaznik na poprzedni element
};



//Funkcja wstawia nowy element na poczatek listy
void wstaw(Node **head, int new_licz, char new_znak);

// Funkcja umozliwia wyswietlanie listy
void wyswietl(Node *node);

//Funkcja dodaje nowy element do listy w zaleznosci od wartosci paramteru new_licz
void dodaj(Node **head, int new_licz, char new_znak);

//Funkcja kopije zawartosc 1 listy i wstawia ja zgodnie z kolejnoscia na 2 liste
void Ustaw(Node **head_1, Node **head_2, int licznik);

#endif
