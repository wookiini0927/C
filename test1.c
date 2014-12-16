#include "test1.h"
#include "fonction_extern.h"


/**
* Envoi un menu de choix de recherche	
* Renvoi vers une autre fonction
*/
void test1_menu(Film tab[], Personne real[], Personne acteur[], int taille_film, int taille_r, int taille_act){
    nettoie();
	/*Variable locale : choix (type char *), taile 127, reserve en memoire le type d'utilisation*/ 
	char choix[REPONSE];

	do{
		printf("-------------Recherche-----------\n");
		printf("|\tA-Film\t\t\t|\n");
		printf("|\tB-Realisateur\t\t|\n");
		printf("|\tC-Acteurs/actrices\t|\n");
        printf("|\t\t\t\t|\n");
        printf("|\tM-Menu principal\t|\n");
        printf("|\tE-Fin du programme\t|\n");
		printf("---------------------------------\n");
		
		fgets(choix, REPONSE, stdin);
        nettoie();
	}while(*choix !='A' && *choix !='a' && *choix !='B' && *choix !='b' && *choix != 'C' && *choix != 'c' && *choix != 'M' && *choix != 'm' && *choix != 'E' && *choix != 'e');

	if (*choix == 'A' || *choix == 'a'){
		clean(choix); // nettoie la zone memoire
        //Recherche film
		choix1(tab, real, acteur, taille_film, taille_r, taille_act);
	}
	else if (*choix == 'B' || *choix == 'b'){
		clean(choix);
        //Recherche realisateur
		choix2(real, taille_r, REALISATEUR);
		
	}
	else if (*choix == 'C' || *choix == 'c'){
		clean(choix);
        //Recherche acteur
		choix3(acteur, taille_act, ACTEUR);
		
	}
    else if (*choix == 'M' || *choix == 'm'){
        clean(choix);
        menu_principal(tab, real, acteur, taille_film, taille_r, taille_act);      
    }
    else if (*choix == 'E' || *choix == 'e'){
        clean(choix);
        exit(1);
    }
	
}

/**
* Choix de recherche sur une BDD de film
* Renvoi a une fonction de saisie
**/
void choix1(Film tab[], Personne real[], Personne acteur[], int taille_f, int taille_r, int taille_a){
    nettoie();
	char critere[REPONSE];

	do{
		printf("--------Type de recherche--------\n");
		printf("|\tA-Titre\t\t\t|\n");
		printf("|\tB-Annee\t\t\t|\n");
		printf("|\tC-Duree\t\t\t|\n");
		printf("|\tD-Realisateur\t\t|\n");
		printf("|\tE-Acteurs\t\t|\n");
		printf("|\tF-Genre\t\t\t|\n");
        printf("|\t\t\t\t|\n");
        printf("|\tP-Menu precedent\t|\n");
        printf("|\tM-Menu principal\t|\n");
        printf("|\tE-Fin du programme\t|\n");
		printf("---------------------------------\n");

		fgets(critere, REPONSE, stdin);
	}while(*critere !='A' && *critere !='a' && *critere !='B' && *critere !='b' && *critere != 'C' && *critere != 'c' && *critere != 'D' && *critere !='d' && *critere != 'E' && *critere !='e' && *critere != 'F' && *critere !='f' && *critere != 'M' && *critere != 'm' && *critere != 'E' && *critere != 'e' && *critere != 'P' && *critere != 'p');
	
	if (*critere == 'A' || *critere == 'a'){

		/**
		* Recherche d'un film par son titre
		* Affiche sa fiche
		**/
		clean(critere); //nettoie la zone memoire
		choix_film(tab, real,acteur, taille_f,taille_r,taille_a);

	}
	else if (*critere == 'B' || *critere == 'b'){

        /**
        * Recherche les films sortie dans l'annee demande
        * Liste tous les films sortie durant cette annee
        **/
        clean(critere);
        appelRechercheAnneeFilm(tab, real,acteur, taille_f,taille_r,taille_a);
    }
    else if (*critere == 'C' || *critere == 'c'){
        clean(critere);
        appelRechercheDureeFilm(tab, real, acteur, taille_f, taille_r, taille_a);
    }

    /**
    * Recherche le NOM du realisateur ou de l'acteur
    * Affiche a liste des films realise
    **/
    else if (*critere == 'D' || *critere == 'd'){
        clean(critere);
        appelRechercheRealisateurFilm(tab, real,acteur, taille_f,taille_r,taille_a);
    }
    else if (*critere == 'E' || *critere == 'e'){
        clean(critere);
        appelRechercheActeurFilm(tab, real,acteur, taille_f,taille_r,taille_a);
    }

    else if (*critere == 'F' || *critere == 'f'){
        clean(critere);
        /**
        * Envoie vers un menu de genre 
        ***/
        choix_genre(tab, real,acteur, taille_f,taille_r,taille_a);
    }
    else if (*critere == 'M' || *critere == 'm'){
        clean(critere);
        menu_principal(tab, real, acteur, taille_f, taille_r, taille_a);      
    }
     else if (*critere == 'E' || *critere == 'e'){
        clean(critere);
        exit(1);
    }
    else if (*critere == 'P' || *critere == 'p'){
        clean(critere);
        test1_menu(tab, real, acteur, taille_f, taille_r, taille_a);      
    }
    

}

void choix_film(Film tab[], Personne real[], Personne acteur[], int taille_f, int taille_r, int taille_a){
	char buffer[TAILLE];

	printf("Quel film cherchez vous?\n");
	fgets(buffer, TAILLE, stdin);
	echange_chariot_espace(buffer);

    //Appel a la fonction dans film.c
	rechercheFilm(tab, real,acteur, taille_f,taille_r,taille_a, buffer);
}

void appelRechercheAnneeFilm(Film tab[], Personne real[], Personne acteur[], int taille_f, int taille_r, int taille_a)
{
	char buffer[TAILLE];
	int year;
    
    printf("Quel annee de sortie cherchez vous ?\n");
    do{
        fgets(buffer, TAILLE, stdin);
    }while(verification_digit(buffer) == 0);
    year = atoi(buffer); //transforme la chaine en un int

    rechercheAnnee(tab, real,acteur, taille_f,taille_r,taille_a, year);
}

void appelRechercheDureeFilm(Film tab[], Personne real[], Personne acteur[], int taille_f, int taille_r, int taille_a)
{
	char buffer[TAILLE];
	int duree;

    printf("Duree du film (en min)?\nNote le resultat sera plus ou moins a 10min pres\n");
    do{
        fgets(buffer, TAILLE, stdin);
    }while(verification_digit(buffer) == 0);
    duree = atoi(buffer);

    rechercheDuree(tab, real, acteur, taille_f, taille_r, taille_a, duree);
}

void appelRechercheRealisateurFilm(Film tab[], Personne real[], Personne acteur[], int taille_f, int taille_r, int taille_a)
{
	char buffer[TAILLE];

    printf("Quel est le nom du realisateur?\n");
    fgets(buffer, TAILLE, stdin);
    echange_chariot_espace(buffer);

    recherche_FilmRealisateur(tab, real,acteur, taille_f,taille_r,taille_a, buffer);
}

void appelRechercheActeurFilm(Film tab[], Personne real[], Personne acteur[], int taille_f, int taille_r, int taille_a)
{
	char buffer[TAILLE];

    printf("Quel est le nom de l'acteur/actrice?\n");
    fgets(buffer, TAILLE, stdin);
    echange_chariot_espace(buffer);

    recherche_FilmActeur(tab, real,acteur, taille_f,taille_r,taille_a, buffer);
}


void choix_genre(Film tab[], Personne real[], Personne acteur[], int taille_f, int taille_r, int taille_a){

	char buffer[TAILLE];
	int tmp;
	Genre g;

	printf("--------------Genre--------------\n");
	printf("|\t0-Aucun\t\t\t|\n");
	printf("|\t1-Action\t\t|\n");
	printf("|\t2-Horreur\t\t|\n");
	printf("|\t3-Comedie\t\t|\n");
	printf("|\t4-Docuementaire\t\t|\n");
	printf("|\t5-Policier\t\t|\n");
	printf("|\t6-Drame\t\t\t|\n");
	printf("|\t7-Animation\t\t|\n");
	printf("|\t8-Science-Fiction\t|\n");
	printf("---------------------------------\n");

	printf("Quel genre de film rechercher vous?\n");
	do{
		do{
			fgets(buffer, TAILLE, stdin);
			
		}while(verification_digit(buffer) == 0);
		tmp = atoi(buffer); //trensforme en un entier
	}while(tmp>9);
	g = (Genre) tmp; //cast en type genre

	rechercheGenre(tab, real,acteur, taille_f,taille_r,taille_a, g);

}


/**
* Choix de recherche de realisateur
* Renvoi a la fonction de recherche dans le fichier personne si c'est un realisateur
**/
void choix2(Personne tab[], int taille, Metier stat){

	char critere[REPONSE];
	
	do{
		printf("--------Type de recherche--------\n");
		printf("|\tA-Nom\t\t\t|\n");
		printf("|\tB-Prenom\t\t|\n");
		printf("|\tC-Date de naissance\t|\n");
		printf("|\tD-Nationalite\t\t|\n");
        printf("|\t\t\t\t|\n");
        printf("|\tE-Fin du programme\t|\n");
		printf("---------------------------------\n");

		fgets(critere, REPONSE, stdin);
	}while(*critere !='A' && *critere !='a' && *critere !='B' && *critere !='b' && *critere != 'C' && *critere != 'c' && *critere != 'D' && *critere !='d' && *critere != 'E' && *critere !='e' && *critere != 'F' && *critere !='f' && *critere != 'E' && *critere != 'e');
	
	if (*critere == 'A' || *critere == 'a'){

        /**
        * Recherche d'un realisateur par son nom
        * Affiche sa fiche s'il y en a qu'un
        * sinon une liste
        **/
        clean(critere); //nettoie la zone memoire
        appelRechercheNom(tab, taille, stat);
    }

    else if (*critere == 'B' || *critere == 'b'){

        /**
        * Recherche d'un realisateur par son prenom
        * Affiche sa fiche s'il y en a qu'un
        * sinon une liste
        **/
        clean(critere);
        appelRecherchePrenom(tab, taille, stat);
    }

    /** Recherche l'année de naissance du relalisateur/acteur **/
    else if (*critere == 'C' || *critere == 'c'){
        clean(critere);
        appelRechercheNaissance(tab, taille, stat);
    }

    /**
    * Recherche par rapport a la nationalite de l'acteur
    **/
    else if (*critere == 'D' || *critere == 'd'){
        clean(critere);
        appelRechercheNationalite(tab, taille, stat);
    }
    else if (*critere == 'E' || *critere == 'e'){
        clean(critere);
        exit(1);
    }
	
}

/*
* Choix de recherche des acteurs
* Renvoi a la fonction de recherche dans le fichier personne si c'est un realisateur
*/
void choix3(Personne tab[], int taille, Metier stat){

	char critere[REPONSE];
	

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
        *Recherche d'un acteur par son nom
        *Affiche sa fiche s'il y en a qu'un
        *sinon une liste
        **/
        clean(critere);
        appelRechercheNom(tab, taille, stat);
    }

    else if (*critere == 'B' || *critere == 'b'){

        /**
        *Recherche d'un acteur par son prenom
        *Affiche sa fiche s'il y en a qu'un
        *sinon une liste
        **/
        clean(critere);
        appelRecherchePrenom(tab, taille, stat);
    }

    /** Recherche l'année de naissance du acteur **/
    else if (*critere == 'C' || *critere == 'c'){
        clean(critere);
        appelRechercheNaissance(tab, taille, stat);
    }

    /**
    * Recherche par rapport a la nationalite de l'acteur
    **/
    else if (*critere == 'D' || *critere == 'd'){
        clean(critere);
        appelRechercheNationalite(tab, taille, stat);
    }
	
}

void appelRechercheNom(Personne tab[], int taille, Metier stat)
{
	char buffer[TAILLE];

    printf("Quel est le nom de l'acteur/actrice que vous cherchez ?\n");
    fgets(buffer, TAILLE, stdin);
    echange_chariot_espace(buffer);
    //Appel de la fonction dans le fichier personne.c
    rechercheNom(tab, taille, buffer, stat);
}

void appelRecherchePrenom(Personne tab[], int taille, Metier stat)
{
	char buffer[TAILLE];

    printf("Quel est le prenom de l'acteur/actrice que vous cherchez ?\n");
    fgets(buffer, TAILLE, stdin);
    echange_chariot_espace(buffer);

    recherchePrenom(tab, taille, buffer, stat);
}

void appelRechercheNaissance(Personne tab[], int taille, Metier stat)
{
	char buffer[TAILLE];
	int year;
    
    printf("Quelle est l'annee de naissance recherchee?\n");
    do{
        fgets(buffer, TAILLE, stdin);

        if(verification_digit(buffer)){
            year = atoi(buffer);
        }
    }while(verification_digit(buffer) == 0);
    recherche_naissance_Annee(tab, taille, year, stat);
}

void appelRechercheNationalite(Personne tab[], int taille, Metier stat)
{
	char buffer[TAILLE];

    printf("Quel est la nationalite recherchee?\n");
    fgets(buffer, TAILLE, stdin);
    echange_chariot_espace(buffer);

    rechercheNationalite(tab, taille, buffer, stat);
}

void nouvelle_recherche(Film film[], Personne real[], Personne acteur[], int taille_f, int taille_r, int taille_a){
    char rep[REPONSE];

    do{
        printf("Voulez-vous saisir une nouvelle recherche? (o/n)\n");
        fgets(rep, REPONSE, stdin);

        if(rep[0] == 'o' || rep[0] == 'O'){
            echange_chariot_espace(rep);
        }
        else if (rep[0] == 'n' || rep[0] == 'N'){
            echange_chariot_espace(rep);
        }
    }while(*rep !='O' && *rep !='o' && *rep !='N' && *rep !='n');

    if(*rep == 'O' || *rep == 'o'){
        clean(rep);
        test1_menu(film, real,acteur, taille_f,taille_r,taille_a);
    }
    if(*rep == 'N' || *rep == 'n'){
        exit(0);
    }
}


