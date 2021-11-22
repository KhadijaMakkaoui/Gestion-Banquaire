#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Les structures
typedef struct clients{
	char CIN[20];
	char Nom[20];
	char Prenom[20];
	float Montant;
}Clients;


//----------LES Prototypes des fonctions

void MenuPrincipale();
void info(FILE *f,struct Client c);
