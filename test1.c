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

		fgets(critere, REPONSE, stdin);
	}while(*critere !='A' && *critere !='a' && *critere !='B' && *critere !='b' && *critere != 'C' && *critere != 'c' && *critere != 'D' && *critere !='d' && *critere != 'E' && *critere !='e' && *critere != 'F' && *critere !='f');
	
	if (*critere == 'A' || *critere == 'a'){

		/**
		*Recherche d'un film par son titre
		*Affiche sa fiche
		**/
		clean(critere);
		printf("Quel est le film cherchez vous?\n");
		fgets(buffer, TAILLE, stdin);
		echange_chariot_espace(buffer);
		rechercheFilm(tab, taille, buffer);

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

		rechercheAnnee(tab, taille, year);
	}
	else if (*critere == 'C' || *critere == 'c'){
		printf("Duree de film (en min)?\nNote le resultat sera plus ou moins a 10min pres\n");
		do{
			fgets(buffer, TAILLE, stdin);

			if(verification_digit(buffer)){
				duree = atoi(buffer);
			}
		}while(verification_digit(buffer) == 0);
		rechercheDuree(tab, taille, duree);
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
		printf("Quel est le nom du realisateur?\n");
		fgets(buffer, TAILLE, stdin);
		recherche_FilmRealisateur(tab, taille, buffer);
	}
	else if (*critere == 'E' || *critere == 'e'){
		clean(critere);
		printf("Quel est le nom de l'acteur/actrice?\n");
		fgets(buffer, TAILLE, stdin);
		recherche_FilmActeur(tab, taille, buffer);
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
		*Affiche sa fiche s'il y en a qu'un
		*sinon une liste
		**/
		clean(critere);
		printf("Quel est le nom du realisateur que vous cherchez ?\n");
		fgets(buffer, TAILLE, stdin);
		rechercheNom(tab, taille, buffer, REALISATEUR);
	}
	else if (*critere == 'B' || *critere == 'b'){

		/**
		*Recherche d'un realisateur par son prenom
		*Affiche sa fiche s'il y en a qu'un
		*sinon une liste
		**/
		clean(critere);
		printf("Quel est le prenom du realisateur que vous cherchez ?\n");
		fgets(buffer, taille, stdin);
		recherchePrenom(tab, taille, buffer, REALISATEUR);
	}

	/** Recherche l'année de naissance du relalisateur/acteur **/
	else if (*critere == 'C' || *critere == 'c'){
		printf("Quelle est l'annee recherchee?\n");
		do{
			fgets(buffer, TAILLE, stdin);
			if(verification_digit(buffer)){
				year = atoi(buffer);
			}
		}while(verification_digit(buffer) == 0);
		recherche_naissance_Annee(tab, taille, year, REALISATEUR);
	}
	
	/**
	* Recherche par rapport a la nationalite de l'acteur
	**/
	else if (*critere == 'D' || *critere == 'd'){
		clean(critere);
		printf("Quel est la nationalite?\n");
		fgets(buffer, TAILLE, stdin);
		rechercheNationalite(tab, taille, buffer, REALISATEUR);
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
		*Affiche sa fiche s'il y en a qu'un
		*sinon une liste
		**/
		clean(critere);
		printf("Quel est le nom de l'acteur/actrice que vous cherchez ?\n");
		fgets(buffer, TAILLE, stdin);
		rechercheNom(tab, taille, buffer, ACTEUR);
	}
	else if (*critere == 'B' || *critere == 'b'){

		/**
		*Recherche d'un realisateur par son prenom
		*Affiche sa fiche s'il y en a qu'un
		*sinon une liste
		**/
		clean(critere);
		printf("Quel est le prenom de l'acteur/actrice que vous cherchez ?\n");
		fgets(buffer, TAILLE, stdin);
		recherchePrenom(tab, taille, buffer, ACTEUR);
	}

	/** Recherche l'année de naissance du relalisateur/acteur **/
	else if (*critere == 'C' || *critere == 'c'){
		printf("Quelle est l'annee de naissance recherchee?\n");
		do{
			fgets(buffer, TAILLE, stdin);

			if(verification_digit(buffer)){
				year = atoi(buffer);
			}
		}while(verification_digit(buffer) == 0);
		recherche_naissance_Annee(tab, taille, year, ACTEUR);
	}

	/** Recherche par rapport a la nationalite de l'acteur **/
	else if (*critere == 'D' || *critere == 'd'){
		clean(critere);
		printf("Quel est la nationalite?\n");
		fgets(buffer, TAILLE, stdin);
		rechercheNationalite(tab, taille, buffer, ACTEUR);
	}
	
}



