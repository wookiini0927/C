#include "test1.h"
/*
*Fichier test1.c 
*On a une BDD prealablement defini
*	Donnee rentree en dur
*
*/

/*
*	Envoi un menu de choix de recherche
*	
*	Renvoi vers une autre fonction
*/
void test1_menu(Film tab[], Personne real[], Personne acteur[], int taille_film, int taille_r, int taille_act){

	/*Variable locale : choix (type char *), taile 127, reserve en memoire le type d'utilisation*/ 
	char choix[REPONSE];

	do{
		printf("-------------Recherche-----------\n");
		printf("|\tA-Film\t\t\t|\n");
		printf("|\tB-Realisateur\t\t|\n");
		printf("|\tC-Acteurs/actrices\t|\n");
		printf("---------------------------------\n");
		
		fgets(choix, REPONSE, stdin);

	}while(*choix !='A' && *choix !='a' && *choix !='B' && *choix !='b' && *choix != 'C' && *choix != 'c');

	if (*choix == 'A' || *choix == 'a'){
		clean(choix);
		choix1(tab, taille_film);
	}
	else if (*choix == 'B' || *choix == 'b'){
		clean(choix);
		choix2(real, taille_r);
		
	}
	else if (*choix == 'C' || *choix == 'c'){
		clean(choix);
		choix3(acteur, taille_act);
		
	}
	
}

/*
*	Choix de recherche
*
*	Renvoi a la fonction de recherche dans le fichier film
*/
void choix1(Film tab[], int taille){

	char critere[REPONSE];
	char buffer[TAILLE];
	int year;
	int duree;

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
		echange_chariot_espace(buffer);
		rechercheFilm(tab, TAILLE, buffer);

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

		rechercheAnnee(tab, TAILLE, year);
	}
	else if (*critere == 'C' || *critere == 'c'){
		printf("Duree de film maximum (en min)?\n");
		do{
			fgets(buffer, TAILLE, stdin);

			if(verification_digit(buffer)){
				duree = atoi(buffer);
			}
		}while(verification_digit(buffer) == 0);
		rechercheDuree(tab, TAILLE, duree);
	}

	/**
	* Pour la rechercher acteur/realisateur
	* on ne fera pas la difference prenom/nom
	* on cherchera dans les deux criteres
	*
	* ou distinguer prenom et nom a en discuter
	**/
	else if (*critere == 'D' || *critere == 'd'){
		printf("Quel est le nom ou le prenom du realisateur?\n");
		fgets(buffer, TAILLE, stdin);
		recherche_FilmRealisateur(tab, TAILLE, buffer);
	}
	else if (*critere == 'E' || *critere == 'e'){
		printf("Quel est le nom ou le prenom de l'acteur/actrice?\n");
		fgets(buffer, TAILLE, stdin);
		recherche_FilmActeur(tab, TAILLE, buffer);
	}
	else if (*critere == 'F' || *critere == 'f'){
		choix_genre(tab, taille);
	}

}

void choix_genre(Film tab[], int taille){

	char buffer[TAILLE];

	printf("--------------Genre--------------\n");
	printf("|\t-Action\t\t\t|\n");
	printf("|\t-Horreur\t\t|\n");
	printf("|\t-Comedie\t\t|\n");
	printf("|\t-Docuementaire\t\t|\n");
	printf("|\t-Policier\t\t|\n");
	printf("|\t-Drame\t\t\t|\n");
	printf("|\t-Animation\t\t|\n");
	printf("|\t-Science-Fiction\t|\n");
	printf("---------------------------------\n");

	printf("Quel genre?\n");
	fgets(buffer, TAILLE, stdin);
	//rechercheGenre(tab, TAILLE, buffer);

}

/*
*	Choix de recherche
*
*	Renvoi a la fonction de recherche dans le fichier personne si c'est un realisateur
*/
void choix2(Personne tab[], int taille){

	char critere[REPONSE];
	char buffer[TAILLE];
	int year;

	do{
		printf("--------Type de recherche--------\n");
		printf("|\tA-Nom\t\t\t|\n");
		printf("|\tB-Prenom\t\t|\n");
		printf("|\tC-Date de naissance\t|\n");
		printf("|\tD-Nationalite\t\t|\n");
		printf("---------------------------------\n");

		fgets(critere, REPONSE, stdin);
	}while(*critere !='A' && *critere !='a' && *critere !='B' && *critere !='b' && *critere != 'C' && *critere != 'c' && *critere != 'D' && *critere !='d' && *critere != 'E' && *critere !='e' && *critere != 'F' && *critere !='f');
	
	if (*critere == 'A' || *critere == 'a'){
		
		/**
		*Recherche d'un realisateur par son nom
		*Affiche sa fiche
		**/
		clean(critere);
		printf("Quel est le nom du realisateur que vous cherchez ?\n");
		fgets(buffer, TAILLE, stdin);
		rechercheNom(tab, 34, buffer);
	}
	else if (*critere == 'B' || *critere == 'b'){

		/**
		*Recherche les films sortie dans l'annee demande
		*Liste tous les films sortie durant cette annee
		**/
		printf("Quel est le prenom du realisateur que vous cherchez ?\n");
		
		fgets(buffer, taille, stdin);

		//rechercheAnnee(tab, TAILLE, year);
	}

	/**
	* 
	* Recherche l'année de naissance du relalisateur/acteur
	*
	**/
	else if (*critere == 'C' || *critere == 'c'){
		printf("Quelle est l'annee recherchee?\n");
		do{
			fgets(buffer, TAILLE, stdin);

			if(verification_digit(buffer)){
				year = atoi(buffer);
			}
		}while(verification_digit(buffer) == 0);
		recherche_naissance_Annee(tab, TAILLE, year);
	}

	/**
	* Pour la rechercher acteur/realisateur
	* on ne fera pas la difference prenom/nom
	* on cherchera dans les deux criteres
	*
	* ou distinguer prenom et nom a en discuter
	**/
	else if (*critere == 'D' || *critere == 'd'){
		clean(critere);
		printf("Quel est la nationalite?\n");
		fgets(buffer, TAILLE, stdin);
		rechercheNationalite(tab, TAILLE, buffer);
	}
	
}

/*
*	Choix de recherche
*
*	Renvoi a la fonction de recherche dans le fichier personne si c'est un realisateur
*/
void choix3(Personne tab[], int taille){

	char critere[REPONSE];
	char buffer[TAILLE];
	int year;

	do{
		printf("--------Type de recherche--------\n");
		printf("|\tA-Nom\t\t\t|\n");
		printf("|\tB-Prenom\t\t|\n");
		printf("|\tC-Date de naissance\t|\n");
		printf("|\tD-Nationalite\t\t|\n");
		printf("---------------------------------\n");

		fgets(critere, REPONSE, stdin);
	}while(*critere !='A' && *critere !='a' && *critere !='B' && *critere !='b' && *critere != 'C' && *critere != 'c' && *critere != 'D' && *critere !='d' && *critere != 'E' && *critere !='e' && *critere != 'F' && *critere !='f');
	
	if (*critere == 'A' || *critere == 'a'){
		
		/**
		*Recherche d'un realisateur par son nom
		*Affiche sa fiche
		**/
		clean(critere);
		printf("Quel est le nom de l'acteur/actrice que vous cherchez ?\n");
		fgets(buffer, TAILLE, stdin);
		rechercheNom(tab, 34, buffer);
	}
	else if (*critere == 'B' || *critere == 'b'){

		/**
		*Recherche d'un realisateur par son prenom
		*Affiche sa fiche
		**/
		clean(critere);
		printf("Quel est le prenom de l'acteur/actrice que vous cherchez ?\n");
		fgets(buffer, TAILLE, stdin);
		recherchePrenom(tab, taille, buffer);
	}

	/**
	* 
	* Recherche l'année de naissance du relalisateur/acteur
	*
	**/
	else if (*critere == 'C' || *critere == 'c'){
		printf("Quelle est l'annee de naissance recherchee?\n");
		do{
			fgets(buffer, TAILLE, stdin);

			if(verification_digit(buffer)){
				year = atoi(buffer);
			}
		}while(verification_digit(buffer) == 0);
		recherche_naissance_Annee(tab, TAILLE, year);
	}

	/**
	* Pour la recherche acteur/realisateur
	* on ne fera pas la difference prenom/nom
	* on cherchera dans les deux criteres
	*
	* ou distinguer prenom et nom a en discuter
	**/
	else if (*critere == 'D' || *critere == 'd'){
		clean(critere);
		printf("Quel est la nationalite?\n");
		fgets(buffer, TAILLE, stdin);
		rechercheNationalite(tab, TAILLE, buffer);
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



