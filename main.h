#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Les structures
struct clients{
	char CIN[20];
	char Nom[20];
	char Prenom[20];
	float Montant;
}clients;
//}clients[TAILLE_MAX];

//----------LES Prototypes des fonctions
void Affichage();
void choisir(int *choix);
void MenuPrincipale();
void info();
//void Minfo(int nb);
void Minfo(int nb);
int rechercherIndiceParCIN(struct clients c);
int MenuOp();

