/************************************************
*
*	Derniere MAJ : 16 Novembre
*		fonction choix1() : definition modifié
*		fonction test1 -> test1_menu()
*			choix de type char
*		
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
void test1_menu(){

	/*Variable locale : choix (type char *), taile 127, reserve en memoire le type d'utilisation*/ 
	char choix[REPONSE];

	do{
		printf("-------------Recherche-----------\n");
		printf("|\tA-Film\t\t\t|\n");
		printf("|\tB-Realisateur\t\t|\n");
		printf("|\tC-Acteurs/actrices\t|\n");
		printf("---------------------------------\n");
		
		fgets(choix, CHAR_MAX, stdin);
	}while(*choix !='A' && *choix !='a' && *choix !='B' && *choix !='b' && *choix != 'C' && *choix != 'c');

	if (*choix == 'A' || *choix == 'a'){
		choix1();
	}
	else if (*choix == 2){
		//choix2();
		;
	}
	else if (*choix == 3){
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

	char critere[REPONSE];
	char buffer[TAILLE];
	int year;
	int duree;
	Film film[TAILLE];


	do{
			printf("--------Type de recherche--------\n");
			printf("|\tA-Titre\t\t\t|\n");
			printf("|\tB-Annee\t\t\t|\n");
			printf("|\tC-Duree\t\t\t|\n");
			printf("|\tD-Realisateur\t\t|\n");
			printf("|\tE-Acteurs\t\t|\n");
			printf("|\tF-Genre\t\t\t|\n");
			printf("---------------------------------\n");

			fgets(critere, CHAR_MAX, stdin);
	}while(*critere !='A' && *critere !='a' && *critere !='B' && *critere !='b' && *critere != 'C' && *critere != 'c' && *critere != 'D' && *critere !='d' && *critere != 'E' && *critere !='e' && *critere != 'F' && *critere !='f');
	
	if (*critere == 'A' || *critere == 'a'){
		/**
		*Recherche d'un film par son titre
		*Affiche sa fiche
		**/
		printf("Quel est le film que vous cherchez ?\n");
		fgets(buffer, TAILLE, stdin);
		rechercheFilm(film, TAILLE, buffer);
	}
	else if (*critere == 'B' || *critere == 'b'){
		/**
		*Recherche les films sortie dans l'annee demande
		*Liste tous les films sortie durant cette annee
		**/
		printf("Quel est l'annee que vous cherchez ?\n");
		do{
			fgets(buffer, TAILLE, stdin);

			if(verification_digit(buffer)){
				year = atoi(buffer);
			}
		}while(verification_digit(buffer) == 0);

		rechercheAnnee(film, TAILLE, year);
	}
	else if (*critere == 'C' || *critere == 'c'){
		printf("Duree de film maximum (en min)?\n");
		fscanf(stdin, "%d", &duree);
		rechercheDuree(film, TAILLE, duree);
	}
	/**
	* Pour la rechercher acteru/realisateur
	* on ne fera pas la difference prenom/nom
	* on cherchera dans les deux criteres
	**/
	else if (*critere == 'D' || *critere == 'd'){
		printf("Quel est le nom ou le prenom du realisateur?\n");
		fgets(buffer, TAILLE, stdin);
		recherche_FilmRealisateur(film, TAILLE, buffer)
	}
	else if (*critere == 'E' || *critere == 'e'){

		;
	}
	else if (*critere == 'F' || *critere == 'f'){

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



