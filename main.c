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
				RetraitDepot(MenuOp(),rechercherIndiceParCIN());
				break;
			case 4:
				TriDesc(nb);
				Affichage(cl);
				break;
			case 5:
				break;
			case 6:
				//Recherche par CIN
				AffichageParIndice(rechercherIndiceParCIN());
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

	puts("\n\t------------Menu Principale------------\n");
	puts("\t1.Introduire un seul compte\n");
	puts("\t2.Introduire plusieur comptes\n");
	puts("\t3.Effectuer une operation banquaire\n");
	puts("\t4.Afficher les comptes par montant\n");
	puts("\t5.Afficher les compte a partir d'une montant\n");
	puts("\t6.Rechercher par CIN\n");
	puts("\t7.Operation de fidelisation\n");
	puts("\t8.Quitter");			
}
//Afficher par cin
//Afficher tous
void AffichageParIndice(int i)
{
	
	printf("-CIN : %s  | Nom : %s  | Prenom : %s  | Montant : %f\n",cl[i].CIN,cl[i].Nom,cl[i].Prenom,cl[i].Montant);
		
}
//Afficher tous
void Affichage()
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("-CIN : %s  | Nom : %s  | Prenom : %s  | Montant : %f\n",cl[i].CIN,cl[i].Nom,cl[i].Prenom,cl[i].Montant);
	}	
}
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
	printf("3.Affichage a partir de la montant donnée en Ordre Ascendant\n ");
	printf("4.Affichage a partir de la montant donnée en Ordre Descendant\n ");


}
//Chercher indice du compte 
int rechercherIndiceParCIN()
{
	int i,indice=-1;
	char RCIN[20];
	printf("Donner le CIN du client : ");
	scanf("%s",RCIN);
	for(i=0;i<TAILLE_MAX;i++)
	{
		if(strcmp(RCIN,cl[i].CIN) == 0)
		{
			indice=i;
		}
	}
	return indice;
	
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

//Operations
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
//Tri par Selection
/*void TriSelectionDesc(int taille)
{
	int i,j,min;
	int n=100;
	struct comptes temp[TAILLE_MAX];
	
	
	for(i=0;i<taille-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			//trouver la valeur min
			if(cl[j].Montant<cl[min].Montant)
			{
				min=j;
			}	
		}	
		//Faire la permutation
		if(i!=min)
		{
			temp.Montant[i]=cl[i].Montant;
			cl[i].Montant=cl[min].Montant;
			cl[min].Montant=temp.Montant;
		}
	}

}*/
void TriDesc(int taille)
{
	int i, j;
    struct comptes temp;
	for (i = 0; i < taille-1; i++)
    {
        for (j =0; j < (taille-1-i); j++)
        {
            if (cl[j].Montant < cl[j+1].Montant)
            {
                temp = cl[i];
                cl[i] = cl[j+1];
                cl[j+1] = temp;
            } 
        }
    }
}
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
