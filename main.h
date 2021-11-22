#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Les structures
struct clients{
	char CIN[20];
	char Nom[20];
	char Prenom[20];
	float Montant;
};


//----------LES Prototypes des fonctions
void choisir(int *choix);
void MenuPrincipale();
//void info(FILE *f,struct Clients *c);
void info(FILE *fichier,struct clients *c);
void Minfo(FILE *fichier,struct clients c[]);

