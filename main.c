#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#define TAILLE_MAX 100
struct comptes  cl[TAILLE_MAX];
int main(int argc, char *argv[]) {
	int choix,nb;
	
	char RCIN[20];
	int i,indice=-1;
	
	do{
		choisir(&choix);
		
		switch (choix){
			case 1:
				info(cl);
				break;
			case 2:
				printf("Donner le nombres des comptes que vous voulez introduire: ");
				scanf("%d",&nb);
				Minfo(nb);
				break;
			case 3:
				//Retrait depot
				RetraitDepot(MenuOp(),rechercherParCIN(nb));
				break;
			case 4://Affichage par ordre
				TriAsc(nb);
				AfficherParOrdre(MenuTri(),nb);
				
				//Affichage(nb);
				break;
			case 5:	
				//Recherche par CIN
				AffichageParIndice(rechercherParCIN(nb));
				break;
			case 6://Fidelisation
			
				break;
			case 7://Quitter
				break;	
		}
				
	}while(choix!=7);
		
		
	return 0;
}
//--------Menus---------------------------------------------------------
//Afficher le Menu principale 
void MenuPrincipale(){

	puts("\n\t------------Menu Principale------------\n");
	puts("\t1.Introduire un seul compte\n");
	puts("\t2.Introduire plusieurs comptes\n");
	puts("\t3.Effectuer une operation banquaire\n");
	puts("\t4.Afficher les comptes par ordre\n");
	puts("\t5.Rechercher un compte par CIN\n");
	puts("\t6.Operation de fidelisation\n");
	puts("\t7.Quitter");			
}
//AffichageMenu des categories d'ordre pour afficher
int MenuTri()
{
	int ch;
	do
	{
		printf("\t--Veuiller choisir la categorie de l affichage--\n ");
		printf("1.Affichage par montant en Ordre Ascendant\n ");
		printf("2.Affichage par montant en Ordre Descendant\n ");
		printf("3.Affichage a partir de la montant donnee en Ordre Ascendant\n ");
		printf("4.Affichage a partir de la montant donnee en Ordre Descendant\n ");
		printf("->Donner votre choix : ");
		scanf("%d",&ch);
		if(ch<1 || ch>5)
		{
			printf("\nVotre choix est invalide veuillez entrer un nombre entre 1 et 7,Ressayer!\n\n");
		}
	}while(ch<1 || ch>5);
	return ch;
}
//Menu Operations
int MenuOp()
{
	int op;
	do{
		printf("1.Retrait\n2.Depot\n");
		scanf("%d",&op);
 		if(op==1 || op==2)
		{
			return op;
		}
		else
		{
			printf("Votre choix est invalide!!Ressayer\n");
		}
	}while(op!=1 && op!=2);
	
}
//Choix du menu principale
void choisir(int *choix)
{
	do{
		MenuPrincipale();
		printf("Veuillez entrer votre choix : ");
		scanf("%d",choix);
		if(*choix<0 || *choix>7)
		{
			printf("\n--> Attention!!Veuillez entrer un choix valide entre 1 et 7 .\n\n");
		}		
	}while(*choix<0 || *choix>7);
}

//-----------------Recuperation des infos-----------------------
//Recuperer les info d'un seul compte
void info(){
	printf("-CIN : ");
	scanf("%s",cl[0].CIN);
	printf("-Nom : ");
	scanf("%s",cl[0].Nom);
	printf("-Prenom : ");
	scanf("%s",cl[0].Prenom);
	printf("-Montant : ");
	scanf("%f",&cl[0].Montant);
	//ecrire dans le fichier
	//fputs("HIiiiiiii",fichier);
	//fputs(c->Nom,fichier);
	//fputs(c->Prenom,fichier);
	//fprintf(fichier,"%d",c->Montant);	
}
//Recuperer plusieurs cpt
void Minfo(int nb){
	int i;
	
	for(i=0;i<nb;i++)
	{
		printf("\nCompte numero %d\n",i+1);
		printf("-CIN : ");
		scanf("%s",cl[i].CIN);
		printf("-Nom : ");
		scanf("%s",cl[i].Nom);
		printf("-Prenom : ");
		scanf("%s",cl[i].Prenom);
		printf("-Montant : ");
		scanf("%f",&cl[i].Montant);
	}	
}
//--------------Recherche d'indice-------------------
//Chercher par CIN 
int rechercherParCIN(int taille)
{
	int i,indice=-1;
	char RCIN[20];
	printf("Donner le CIN du client : ");
	scanf("%s",RCIN);
	for(i=0;i<taille;i++)
	{
		if(strcmp(RCIN,cl[i].CIN) == 0)
		{
			indice=i;
			break;
		}
	}
	return indice;
	
}
//Chercher par Montant
int rechercherParMontant(int taille)
{
	//Chercher le premier montant inferieur a la montant du debut
	int i,indice=-1;
	float mt;
	printf("Donner le montant initiale : ");
	scanf("%f",&mt);
	for(i=0;i<taille;i++)
	{
		if(cl[i].Montant<mt )
		{
			indice=i+1;
			break;
		}
	}
	return indice;
	
}

//-------------------Operations
void RetraitDepot(int choix,int indice)
{
	float montantR_D,montant;
	if(indice!=-1)
	{
		montant=cl[indice].Montant;
		if(choix==1)
	    {//Retrait
	    	printf("Donner la montant a retirer : ");
	    	scanf("%f",&montantR_D);
	    	if(montant>montantR_D)
	    	{
	    		montant-=montantR_D;
	    		printf("Operation effectuee avec succees\n");
	    		cl[indice].Montant=montant;
			}
			else
			{
				printf("Le solde est insuffisant\n");
			}
		}
		else
		{
			printf("Donner la montant a deposer : ");
	    	scanf("%f",&montantR_D);
			montant+=montantR_D;
	    	printf("Operation effectuee avec succees\n");
	    	cl[indice].Montant=montant;
		}
	}
	else
	{
		printf("CIN introuvable!!\n");
	}
   
}

//----------------Tri Asc du min au max
void TriAsc(int taille)
{
	int i, j;
    struct comptes temp;
	for (i = 0; i < taille; i++)
    {
        for (j =i+1; j < taille; j++)
        {
            if (cl[j].Montant < cl[i].Montant)
            {
                temp = cl[i];
                cl[i] = cl[j];
                cl[j] = temp;
            } 
        }
    }
}
//----------------------------Affichages
//Afficher par indice
void AffichageParIndice(int i)
{
	printf("\tCIN : %s\t|\tNom : %s\t|\tPrenom : %s\t|\tMontant : %0.2f\n",cl[i].CIN,cl[i].Nom,cl[i].Prenom,cl[i].Montant);

	//printf("-CIN : %s  | Nom : %s  | Prenom : %s  | Montant : %f\n",cl[i].CIN,cl[i].Nom,cl[i].Prenom,cl[i].Montant);
		
}
//Afficher Asc
void AffichageAsc(int taille)
{
	int i;
	for(i=0;i<taille;i++)
	{
		printf("\tCIN : %s\t|\tNom : %s\t|\tPrenom : %s\t|\tMontant : %0.2f\n",cl[i].CIN,cl[i].Nom,cl[i].Prenom,cl[i].Montant);
	}	
}
//Afficher Desc
void AffichageDesc(int taille)
{
	int i;
	for(i=taille-1;i>=0;i--)
	{
		printf("\tCIN : %s\t|\tNom : %s\t|\tPrenom : %s\t|\tMontant : %0.2f\n",cl[i].CIN,cl[i].Nom,cl[i].Prenom,cl[i].Montant);
	}	
}

//Afficher à partir d'unr montant
void AfficherAPartirDe_Asc(int debut,int taille)
{
	int i;
	for(i=debut;i<taille;i++)
	{
		printf("\tCIN : %s\t|\tNom : %s\t|\tPrenom : %s\t|\tMontant : %0.2f\n",cl[i].CIN,cl[i].Nom,cl[i].Prenom,cl[i].Montant);
	}	
}
void AfficherAPartirDe_Desc(int debut,int taille)
{
	int i;
	for(i=debut;i>=0;i--)
	{
		printf("\tCIN : %s\t|\tNom : %s\t|\tPrenom : %s\t|\tMontant : %0.2f\n",cl[i].CIN,cl[i].Nom,cl[i].Prenom,cl[i].Montant);
	}	
}
//Afficher tous par ordre
void AfficherParOrdre(int choix,int taille)
{
	if(choix==1)
    {//Acsendant
    	AffichageAsc(taille);
    	
	}
	else if(choix==2)
	{//Descendant
		AffichageDesc(taille);
	}
	else if(choix==3)
	{//Acsendant apartir de
		 AfficherAPartirDe_Asc(rechercherParMontant(taille),taille);
	}
	else if(choix==4)
	{//Descendant apartir de
		 AfficherAPartirDe_Desc(rechercherParMontant(taille),taille);
	}
	else
	{
		printf("Choix invalide\n");
		
	}
}

void Fidelisation()
{
}
