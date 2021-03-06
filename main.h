//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//Les structures
struct comptes{
	char CIN[20];
	char Nom[20];
	char Prenom[20];
	float Montant;
}comptes;

//----------LES Prototypes des fonctions
//Les fcts d'affichage
void Affichage(int taille);
void AffichageParIndice(int i);
void AfficherParOrdre(int choix,int taille);
void AffichageAsc(int taille);
void AffichageDesc(int taille);
void AfficherAPartirDe_Asc(int debut,int taille);
void AfficherAPartirDe_Desc(int debut,int taille);

//Les menus
void MenuPrincipale();
int MenuOp();
int MenuTri();


void choisir(int *choix);

void RetraitDepot(int choix,int indice);
//Introduction des comptes
void info();
void Minfo(int nb);

//Les fcts de recherche
int rechercherParCIN(int taille);
int rechercherParMontant(int taille);
bool ExistCIN(int taille,char RCIN[20]);

//tri
void TriAsc(int taille);
//Fidelisation
void Fidelisation(int taille);

