#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_MAX 1000
//Les structures
struct clients{
	char CIN[20];
	char Nom[20];
	char Prenom[20];
	float Montant;
}clients;
//}clients[TAILLE_MAX];

//----------LES Prototypes des fonctions
void choisir(int *choix);
void MenuPrincipale();
void info(struct clients c);
//void Minfo(int nb);
void Minfo(int taille);

int MenuOp();

