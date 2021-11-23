#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#define TAILLE_MAX 100
struct clients  cl[TAILLE_MAX];
int main(int argc, char *argv[]) {
	int choix,nb;
	

//	struct clients cl;
	//struct clients cls[TAILLE_MAX];
	char RCIN[20];
	int i,indice=NULL;
	
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
				MenuOp();
				//printf("%d",rechercherIndiceParCIN(cls[10]));
				break;
			case 4:
				//Affichage
				//TriSelection(cls);
				Affichage(cl);
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				//Quitter
				break;	
		}
				
	}while(choix!=8);
		
		
	return 0;
}
void choisir(int *choix)
{
	do{
		MenuPrincipale();
		printf("Veuillez entrer votre choix : ");
		scanf("%d",choix);
		if(*choix<0 || *choix>8)
		{
			printf("\n--> Attention!!Veuillez entrer un choix valide entre 1 et 7 .\n\n");
		}		
	}while(*choix<0 || *choix>8);
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
//Afficher tous
//void Affichage(struct clients cl[])
void Affichage()
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("-CIN : %s  | Nom : %s  | Prenom : %s  | Montant : %f\n",cl[i].CIN,cl[i].Nom,cl[i].Prenom,cl[i].Montant);
	}	
}
//Recuperer les info d'un seul compte
void info(struct clients c){
	printf("-CIN : ");
	scanf("%s",c.CIN);
	printf("-Nom : ");
	scanf("%s",c.Nom);
	printf("-Prenom : ");
	scanf("%s",c.Prenom);
	printf("-Montant : ");
	scanf("%f",&c.Montant);
	//ecrire dans le fichier
	//fputs("HIiiiiiii",fichier);
	//fputs(c->Nom,fichier);
	//fputs(c->Prenom,fichier);
	//fprintf(fichier,"%d",c->Montant);	
}
//Infos de plusieurs comptes
/*void Minfo(int taille){
	int i;
	struct clients cls[taille];
	for(i=0;i<taille;i++)
	{
		printf("\nCompte numero %d\n",i+1);
		printf("-CIN : ");
		scanf("%s",c[i].CIN);
		printf("-Nom : ");
		scanf("%s",c[i].Nom);
		printf("-Prenom : ");
		scanf("%s",c[i].Prenom);
		printf("-Montant : ");
		scanf("%f",&c[i].Montant);
	}	
}*/
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
//AffichageMenu des categories d'ordre pour afficher
void AfficherMenu()
{
	printf("\t->Veuiller choisir la categorie de l affichage : \n");
	printf("1.Affichage par montant en Ordre Ascendant\n ");
	printf("2.Affichage par montant en Ordre Descendant\n ");
	printf("3.Affichage a partir de la montant donn�e en Ordre Ascendant\n ");
	printf("4.Affichage a partir de la montant donn�e en Ordre Descendant\n ");


}
//Chercher indice du compte 
/*int rechercherIndiceParCIN(struct clients c)
{
	
	printf("Donner le CIN du client : ");
	scanf("%s",RCIN);
	for(i=0;i<TAILLE_MAX;i++)
	{
		if(RCIN==(c[i]).CIN)
		{
			indice=i;
		}
	}
	return indice;
	
}*/
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

//Operations
void RetraitDepot(int choix,int indice,float montant,float montant_R_D)
{
	float montantRetrait,montantDepot;
    if(choix==1)
    {//Retrait
    	montantRetrait=montant_R_D;
    	if(montant>montantRetrait)
    	{
    		montant-=montantRetrait;
    		printf("Operation effectuee avec succes\n");
		}
		else
		{
			printf("Le solde est insuffisant");
		}
	}
	else if(choix==2)
	{
		montantDepot=montant_R_D;
		montant+=montantDepot;
    	printf("Operation effectuee avec succes\n");
	}
	else
	{
		printf("Choix invalide\n");
	}
}
//Tri par Selection
/*void TriSelection(struct clients t[100])
{
	int i,j,min,temp;
	int n=100;
	
	//Tri par selection
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			//trouver la valeur min
			if(t[j]<t[min])
			{
				min=j;
			}	
		}	
		//Faire la permutation
		if(i!=min)
		{
			temp=t[i];
			t[i]=t[min];
			t[min]=temp;
		}
	}
	//Afficher
	for(i=0;i<100;i++)
	{
		printf("-CIN : %s,Nom : %s, Prenom : %s, Montant : %f\n",t[i].CIN,t[i].Nom,t[i].Prenom,t[i].Montant);
		printf("____________________________________________________________________________________________");
	}
}
*/
//Affichage
void AfficherParOrdre(int choix)
{
	if(choix==1)
    {//Acsendant
    	
	}
	else if(choix==2)
	{//Descendant
		
	}
	else if(choix==3)
	{//Acsendant apartir de
		
	}
	else if(choix==4)
	{//Descendant apartir de
		
	}
	else
	{
		printf("Choix invalide\n");
		
	}
}
//Recherche
void Rechercher(char CIN[])
{
	
}
void Fidelisation()
{
}
