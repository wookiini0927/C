/******************************
*
*	Derniere MAJ 26/11 :
*		Debut initialisation de la BDD en dur
*
*******************************/

#include "film.h"
#include "personne.h"
#include "test1.h"
#include "test2.h"
#include "test3.h"

int main(int argc, char const *argv[])
{
	/* code */

	/*Variable locale : choix (type char *), taille 1, reserve en memoire le type d'utilisation*/ 
	char choix[REPONSE];

	/*Personne *realisateur = NULL;
	Personne *acteur = NULL;
	Film *film = NULL;

	film = (Film*)malloc(10*sizeof(Film));

	realisateur = (Personne*)malloc(16*sizeof(Personne));
	acteur = (Personne*)malloc(33*sizeof(Personne));*/

	Personne realisateur[16];
	Personne acteur[33];
	Film film[10]; 

	/******************
    **  REALISATEUR  **
    ******************/

    init_tableau_Personne(&realisateur[0], "Cuaron\0", "Alfonso\0", 28,11,1961, "Mexicaine\0", REALISATEUR);
    init_tableau_Personne(&realisateur[1], "Scott\0", "Ridley\0", 30,11,1937, "Britannique\0", REALISATEUR);
    /* realisateur[2]={{"Nolan\0", "Christopher\0", {30,7,1970}, "Britannique\0", REALISATEUR}};
     realisateur[3]={{"Hazanavicius\0", "Michel\0", {29,3,1967}, "Francaise\0", REALISATEUR}};
     realisateur[4]={{"Jackson\0", "Peter\0", {31,10,1961}, "Neo zelandaise\0", REALISATEUR}};
     realisateur[5]={{"Allen\0", "Woody\0", {1,12,1935}, "Americaine\0", REALISATEUR}};
     realisateur[6]={{"Scorsese\0", "Martin\0", {17,11,1942}, "Americaine\0", REALISATEUR}};
     realisateur[7]={{"Kubrick\0", "Stanley\0", {26,7,1928}, "Americaine\0", REALISATEUR}};
     realisateur[8]={{"Eastwood\0", "Clint\0", {31,5,1930}, "Americaine\0", REALISATEUR}};
     realisateur[9]={{"Hitchcock\0", "Alfred\0", {13,8,1899}, "Britannique\0", REALISATEUR}};*/
    init_tableau_Personne(&realisateur[10], "Whedon\0", "Joss\0", 23,6,1964, "Americaine\0", REALISATEUR);
     /*realisateur[11]={{"Toledano\0", "Eric\0", {3,7,1971}, "Francaise\0", REALISATEUR}};
     realisateur[12]={{"Tarantino\0", "Quentin\0", {27,3,1963}, "Americaine\0", REALISATEUR}};
     realisateur[13]={{"Leterrier\0", "Louis\0", {17,6,1973}, "Francaise\0", REALISATEUR}};
     realisateur[14]={{"Blomkamp\0", "Neill\0", {17,9,1979}, "Sud africaine\0", REALISATEUR}};
     realisateur[15]={{"Luhrmann\0", "Baz\0", {17,9,1962}, "Australienne\0", REALISATEUR}};*/

    /*************
    **  ACTEUR  **
    *************/

	 /*acteur[0]={{"Dujardin\0", "Jean\0", {19,6,1972}, "Francaise\0", ACTEUR}};
	 acteur[1]={{"Roberts\0", "Julia\0", {28,10,1967}, "Americaine\0", ACTEUR}};
	 acteur[2]={{"Bellucci\0", "Monica\0", {30,9,1964}, "Italienne\0", ACTEUR}};
	 acteur[3]={{"Phoenix\0", "Joaquin\0", {28,10,1974}, "Americaine\0", ACTEUR}};
	 acteur[4]={{"Crowe\0", "Russell\0", {7,4,1964}, "Neo zelandaise\0", ACTEUR}};*/
	init_tableau_Personne(&acteur[5], "Johansson\0", "Scarlett\0", 22,11,1984, "Francaise\0", ACTEUR);
	/* acteur[6]={{"Sy\0", "Omar\0", {20,1,1978}, "Francaise\0", ACTEUR}};
	 acteur[7]={{"Tyler\0", "Liv\0", {1,7,1977}, "Americaine\0", ACTEUR}};
	 acteur[8]={{"Bale\0", "Christian\0", {30,1,1974}, "Britannique\0", ACTEUR}};
	 acteur[9]={{"DiCaprio\0", "Leonardo\0", {11,12,1974}, "Americaine\0", ACTEUR}};
	 acteur[10]={{"Nielsen\0", "Connie\0", {3,7,1965}, "Danoise\0", ACTEUR}};
	 acteur[11]={{"Cluzet\0", "Francois\0", {21,9,1955}, "Francaise\0", ACTEUR}};
	 acteur[12]={{"Le Ny\0", "Anne\0", {16,12,1962}, "Francaise\0", ACTEUR}};
	 acteur[13]={{"Page\0", "Ellen\0", {21,2,1987}, "Canadienne\0", ACTEUR}};
	 acteur[14]={{"Bullock\0", "Sandra\0", {26,7,1964}, "Americaine\0", ACTEUR}};
	 acteur[15]={{"Clooney\0", "Georges\0", {6,5,1961}, "Americaine\0", ACTEUR}};
	 acteur[16]={{"Harris\0", "Ed\0", {28,11,1950}, "Americaine\0", ACTEUR}};
	 acteur[17]={{"McConaughey\0", "Matthew\0", {4,11,1969}, "Americaine\0", ACTEUR}};
	 acteur[18]={{"Hathaway\0", "Anne\0", {12,11,1982}, "Americaine\0", ACTEUR}};
	 acteur[19]={{"Caine\0", "Michael\0", {14,3,1933}, "Britannique\0", ACTEUR}};
	 acteur[20]={{"Foxx\0", "Jamie\0", {13,12,1967}, "Americaine\0", ACTEUR}};
	 acteur[21]={{"Waltz\0", "Christoph\0", {4,10,1956}, "Autrichienne\0", ACTEUR}};
	 acteur[22]={{"Eisenberg\0", "Jesse\0", {5,10,1983}, "Americaine\0", ACTEUR}};*/
	init_tableau_Personne(&acteur[23], "Ruffalo\0", "Mark\0", 22,11,1967, "Americaine\0", ACTEUR);
	 /*acteur[24]={{"Harrelson\0", "Woody\0", {23,7,1961}, "Americaine\0", ACTEUR}};
	 acteur[25]={{"Damon\0", "Matt\0", {8,10,1970}, "Americaine\0", ACTEUR}};
	 acteur[26]={{"Foster\0", "Jodie\0", {19,11,1962}, "Americaine\0", ACTEUR}};
	 acteur[27]={{"Kidman\0", "Nicole\0", {20,6,1967}, "Australienne\0", ACTEUR}};
	 acteur[28]={{"Hugh\0", "Jackman\0", {12,10,1968}, "Australienne\0", ACTEUR}};
	 acteur[29]={{"Wenham\0", "David\0", {21,9,1965}, "Australienne\0", ACTEUR}};*/
	init_tableau_Personne(&acteur[30], "Downey Jr\0", "Robert\0", 4,4,1965, "Americaine\0", ACTEUR);
	init_tableau_Personne(&acteur[31], "Evans\0", "Chris\0", 13,6,1981, "Americaine\0", ACTEUR);
	/* acteur[32]={{"Copley\0", "Sharlto\0", {27,12,1973}, "Sud africaine\0", ACTEUR}};*/

	/***************
	***	  FILM   ***
	***************/

	init_tableau_film(&film[0], "Avengers\0", 2012, &realisateur[10], 144, ACTION, &acteur[30], &acteur[31], &acteur[23], &acteur[5]);
   /* film[1]={{"Gladiator\0", 2000, realisateur[1], {acteur[4], acteur[3], acteur[10]}, 155, ACTION}};
    film[2]={{"Intouchables\0", 2011, realisateur[11], {acteur[11], acteur[6], acteur[12]}, 112, COMEDIE}};
    film[3]={{"Inception\0", 2010, realisateur[2], {acteur[9], acteur[13]}, 188, SCIENCE_FICTION}};
    film[4]={{"Gravity\0", 2013, realisateur[0], {acteur[14], acteur[15], acteur[16]}, 90, SCIENCE_FICTION}};
    film[5]={{"Interstellar\0", 2014, realisateur[2], {acteur[17], acteur[18], acteur[19]}, 169, SCIENCE_FICTION}};
    film[6]={{"Django Unchained\0", 2013, realisateur[12], {acteur[20], acteur[21], acteur[9]}, 164, ACTION}};
    film[7]={{"Insaisissables\0", 2013, realisateur[13], {acteur[22], acteur[23], acteur[24]}, 116, POLICIER}};
    film[8]={{"Elysium\0", 2013, realisateur[14], {acteur[25], acteur[26], acteur[32]}, 110, ACTION}};
    film[9]={{"Australia\0", 2008, realisateur[15], {acteur[27], acteur[28], acteur[29]}, 155, DRAME}};	
	
    affichagePersonne(&realisateur[10]);
    printf("\n");
    affichagePersonne(&acteur[31]);
    printf("\n");
	affichageFilm(&film[0]);*/


	/*On choisis de quel maniere on va utiliser les BDD*/
	do{
		printf("----------------------Choix----------------------\n");
		printf("|\tA-Recherche dans une BDD prédefinie\t|\n");
		printf("|\tB-Creez votre propre BDD\t\t|\n");
		printf("|\tC-Creez votre BDD a partir d'un fichier\t|\n");
		printf("-------------------------------------------------\n");
		
		fgets(choix,REPONSE,stdin);

	}while(*choix !='A' && *choix !='a' && *choix !='B' && *choix !='b' && *choix != 'C' && *choix != 'c');

	if (*choix == 'A' || *choix == 'a'){
		//BDD déja existante
		clean(choix); // evite le conflit entre la variable choix du main et la variable choix de test1.c
		test1_menu(film, realisateur, acteur, 10);
	}
	else if (*choix == 'B' || *choix == 'b'){
		//saisie manuelle
		test2();
	}
	else if (*choix == 'C' || *choix == 'c'){
		//creation d'une BDD a partir d'un fichier
		test3_menu();
	}


	return 0;
}
