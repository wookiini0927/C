/************************************************
*
*	Derniere MAJ : 16 Novembre
*		fonction choix1() : fscanf->scanf
*		Definition fonction choix1 
*		Commentaires (.h)
*
*	Pas sur de l'utilité de la fonction choix2() choix3()
*	A discuter
*
*************************************************/

#include "test1.h"
/*
*Fichier test1.c 
*On a une BDD prealablement defini
*	Donnee rentree en dur
*
*/

/*void BDD_predefini(){
	int taille_utile = 0;
	Film[] film;
	Personne[] realisateur;
	Personne[] acteur;	
}*/

/*
*	Envoi un menu de choix de recherche
*	
*	Renvoi vers uen autre fonction
*/
void test1(){
	int choix;
	do{
		printf("-------------Recherche-----------\n");
		printf("|\t1-Film\t\t\t|\n");
		printf("|\t2-Realisateur\t\t|\n");
		printf("|\t3-Acteurs/actrices\t|\n");
		printf("---------------------------------\n");
		
		scanf("%d", &choix);
	}while(choix !=1 && choix !=2 && choix !=3);

	if (choix == 1){
		choix1();
	}
	else if (choix == 2){
		//choix2();
		;
	}
	else if (choix == 3){
		//choix3();
		;
	}

	
}

/*
*	Choix de recherche
*
*	Renvoi a la fonction de recherche dans le fichier film
*/
void choix1(){
	int critere;
	char buffer[TAILLE];
	int year;

	do{
			printf("--------Type de recherche--------\n");
			printf("|\t1-Titre\t\t\t|\n");
			printf("|\t2-Annee\t\t\t|\n");
			printf("|\t3-Duree\t\t\t|\n");
			printf("|\t4-Realisateur\t\t|\n");
			printf("|\t5-Acteurs\t\t|\n");
			printf("|\t6-Genre\t\t|\n");
			printf("---------------------------------\n");

			scanf("%d",&critere);
	}while(critere != 1 && critere != 2 && critere!=3 && critere != 4 && critere != 5 && critere !=6);

	if(critere == 1){
		printf("Quel est le film que vous cherchez ?\n");
		fgets(buffer, TAILLE, stdin);
		rechercheFilm(film, TAILLE, buffer);
	}
	else if(critere == 2){
		printf("Quel est l'annee que vous cherchez ?\n");
		fscanf(stdin, "%d", &year);
		rechercheAnnee(film, TAILLE, year);
	}
	else if(critere == 3){
		;
	}
	else if(critere == 4){
		;
	}
	else if(critere == 5){
		;
	}
	else if(critere == 6){
		;
	}




}

/*int main(){
	Personne realisateur = {"Whedon","Joss", {23,6,1964},"Americaine",REALISATEUR};
	Personne iron_man= {"Downey Jr", "Robert", {4,4,1965}, "Americaine", ACTEUR};
	Personne captain_america={"Evans", "Chris", {13,6,1981}, "Americiane", 0};
	Personne thor = {"Hemsworth","Chris", {11,8,1983}, "Australienne", 0};
	Personne black_widow = {"Johansson", "Scarlett", {22,11,1984}, "Americaine", 0};
	Film film1 = {"Avengers", 2012, realisateur, {iron_man, captain_america, thor, black_widow}, 144, ACTION};

	affichagePersonne(&iron_man);
	affichageFilm(&film1);

	test1();

	return 0;
}*/



