#include <iostream>
#include "kolejka.hh"
using namespace std;




//inserts node at the front of the list
void wstaw(Node **head, int new_licz, char new_znak){

   struct Node *new_Node = new Node;	//Alkowoanie pamieci dla nowego elementu

   new_Node->licz = new_licz;			//Wstawianie parametrow wartosci
   new_Node->znak = new_znak;			//Wstawianie parametrow znaku

   new_Node->next = (*head);			//Wskaznik next nowego obiektu wskazuje na Head
   new_Node->prev = NULL;				//Wskaznik prev nowego obiektu wskazuje na NULL

   if ((*head) != NULL)					//Sprawdza czy wskaznik Head wskazuje na jakas zawartosc
   (*head)->prev = new_Node;

   (*head) = new_Node;					//Glowny wskaznik Head wskzuje na nowy element
}




// Funkcja umozliwia wyswietlanie listy
void wyswietl(Node *lista){

   while (lista != NULL){				//Petla dziala tak dlugo az ostatni element bedzie wskazywal na NULL

	  cout << lista->znak ;				//Wyswietla znak z tablicy
      lista = lista->next;				//Wskaznik wskazuje na kolejny element listy
   }
}




//Funkcja dodaje zgodnie z kolejnoscia nowy element do listy w zaleznosci od wartosci paramteru new_licz

void dodaj(Node **head, int new_licz, char new_znak){

	Node *temp = *head;							//Pomocniczy wskaznik wskazujacy na Head

	if((temp == NULL)||(new_licz < temp->licz)){	//Sprawdza czy nowo dodany element jest 1 dodawanym elmentem do tablicy
		wstaw(head, new_licz, new_znak);			//Wstawianie nowego elementu na 1 miejscu

		return;
	}

   while ((temp->next != nullptr)&&(new_licz > (temp -> next -> licz))){	//Petla dziala tak dlugo az wskaznik nie natrafi na NULL lub
	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	// wartosc nowego elmentu jest wieksza od nastepnego elementu
	   temp = temp->next;						//Tymczasowy wskaznik wskazuje na kolejny element listy
   }
	Node *new_Node = new Node;					//Alkowoanie pamieci dla nowego modulu
	new_Node->licz = new_licz;					//Wstawianie parametrow wartosci i znak
	new_Node->znak = new_znak;

	new_Node->next = temp->next;				//Wskaznik next dla nowego elementu
	   	   	   	   	   	   	   	   	   	   	   	//wskazuje modul przed tym elmentem
	temp->next = new_Node;						//Poprzeni modul wskazuje na nowo dodany

	new_Node->prev = temp;						//Wskaznik prev poprzedniego modulu wskazuje na nowy

	if (new_Node->next != NULL){				//Sprawdza czy modul jest na koncu
	   new_Node->next->prev = new_Node;
	}
}



//Funkcja kopije zawartosc 1 listy i wstawia ja zgodnie z kolejnoscia na 2 liste
void Ustaw(Node **head_1, Node **head_2, int licznik){

	Node *temp = *head_1;							//Zmienna tymczasowa wskazujaca na ten sam element co Head

	for (int i = 0; i < licznik; i++){				//Petla powtarza sie "licznik" razy

		dodaj(head_2, temp -> licz, temp -> znak);	//Ustawianie wiadomosci w opowiedniej kolejnosci
		temp = temp->next;							//Pomocniczy wskaznik wskazuje na nastepny element

	}

}

