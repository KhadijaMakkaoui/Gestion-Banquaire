#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


int main(int argc, char *argv[]) {
	int choix;
	//Declaration
	FILE *file;
	//Ouvrir le fichier
	file=fopen("Banque.txt","a");
	
	
	do{
		MenuPrincipale();
		printf("Veuillez entrer votre choix : ");
		scanf("%d",&choix);
		if(choix<0 || choix>8)
		{
			printf("\n--> Attention!!Veuillez entrer un choix valide entre 1 et 7 .\n\n");
		}		
	}while(choix<0 || choix>8);
	fclose(file);
	return 0;
}
//Afficher le Menu principale 
void MenuPrincipale(){

	puts("\t------------Menu Principale------------");
	puts("\t1.Introduire un seul compte\n");
	puts("\t2.Introduire plusieur comptes\n");
	puts("\t3.Effectuer une operation banquaire\n");
	puts("\t4.Afficher les comptes par montant\n");
	puts("\t5.Afficher les compte a partir d'une montant\n");
	puts("\t6.Rechercher par CIN\n");
	puts("\t7.Operation de fidelisation\n");
	puts("\t8.Quitter");
			
}

