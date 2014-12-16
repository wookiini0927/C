#include "film.h"
#include "personne.h"
#include "test1.h"
#include "test2.h"
#include "test3.h"
#include "fonction_extern.h"


int main(int argc, char const *argv[])
{
    nettoie();

	/*Variable locale : choix (type char *), taille 1, reserve en memoire le type d'utilisation*/ 

	Personne realisateur[TAILLE_DEFAUT];
	Personne acteur[TAILLE_DEFAUT];
	Film *film;

	film = (Film*) malloc(TAILLE_DEFAUT * sizeof(Film));

	int taille_utile_film = 10;
	int taille_utile_real = 16;
	int taille_utile_acteur = 35;

    /****************************
    **  BASE DE DONNEE EN DUR  **
    *****************************/

	/******************
    **  REALISATEUR  **
    ******************/

    init_tableau_Personne(&realisateur[0], "Cuaron\0", "Alfonso\0", 28,11,1961, "Mexicaine\0", REALISATEUR);
    init_tableau_Personne(&realisateur[1], "Scott\0", "Ridley\0", 30,11,1937, "Britannique\0", REALISATEUR);
    init_tableau_Personne(&realisateur[2], "Nolan\0", "Christopher\0", 30,7,1970, "Britannique\0", REALISATEUR);
    init_tableau_Personne(&realisateur[3], "Hazanavicius\0", "Michel\0", 29,3,1967, "Francaise\0", REALISATEUR);
    init_tableau_Personne(&realisateur[5], "Allen\0", "Woody\0", 1,12,1935, "Americaine\0", REALISATEUR);
    init_tableau_Personne(&realisateur[6], "Scorsese\0", "Martin\0", 17,11,1942, "Americaine\0", REALISATEUR);
    init_tableau_Personne(&realisateur[7], "Kubrick\0", "Stanley\0", 26,7,1928, "Americaine\0", REALISATEUR);
    init_tableau_Personne(&realisateur[8], "Eastwood\0", "Clint\0", 31,5,1930, "Americaine\0", REALISATEUR);
    init_tableau_Personne(&realisateur[9], "Hitchcock\0", "Alfred\0", 13,8,1899, "Britannique\0", REALISATEUR);
    init_tableau_Personne(&realisateur[10], "Whedon\0", "Joss\0", 23,6,1964, "Americaine\0", REALISATEUR);
    init_tableau_Personne(&realisateur[11], "Toledano\0", "Eric\0", 3,7,1971, "Francaise\0", REALISATEUR);
    init_tableau_Personne(&realisateur[12], "Tarantino\0", "Quentin\0", 27,3,1963, "Americaine\0", REALISATEUR);
    init_tableau_Personne(&realisateur[13], "Leterrier\0", "Louis\0", 17,6,1973, "Francaise\0", REALISATEUR);
    init_tableau_Personne(&realisateur[14], "Blomkamp\0", "Neill\0", 17,9,1979, "Sud africaine\0", REALISATEUR);
    init_tableau_Personne(&realisateur[15], "Luhrmann\0", "Baz\0", 17,9,1962, "Australienne\0", REALISATEUR);



    /*************
    **  ACTEUR  **
    *************/

    init_tableau_Personne(&acteur[0], "\0", "\0", 0, 0, 0, "\0", ACTEUR);
    init_tableau_Personne(&acteur[1], "Roberts\0", "Julia\0", 28,10,1967, "Americaine\0", ACTEUR);
    init_tableau_Personne(&acteur[2], "Bellucci\0", "Monica\0", 30,9,1964, "Italienne\0", ACTEUR);
    init_tableau_Personne(&acteur[3], "Phoenix\0", "Joaquin\0", 28,10,1974, "Americaine\0", ACTEUR);
    init_tableau_Personne(&acteur[4], "Crowe\0", "Russell\0", 7,4,1964, "Neo zelandaise\0", ACTEUR);
    init_tableau_Personne(&acteur[5], "Johansson\0", "Scarlett\0", 22,11,1984, "Francaise\0", ACTEUR);
    init_tableau_Personne(&acteur[6], "Sy\0", "Omar\0", 20,1,1978, "Francaise\0", ACTEUR);
    init_tableau_Personne(&acteur[7], "Tyler\0", "Liv\0", 1,7,1977, "Americaine\0", ACTEUR);
    init_tableau_Personne(&acteur[8], "Bale\0", "Christian\0", 30,1,1974, "Britannique\0", ACTEUR);
    init_tableau_Personne(&acteur[9], "DiCaprio\0", "Leonardo\0", 11,12,1974, "Americaine\0", ACTEUR);
    init_tableau_Personne(&acteur[10], "Nielsen\0", "Connie\0", 3,7,1965, "Danoise\0", ACTEUR);
    init_tableau_Personne(&acteur[11], "Cluzet\0", "Francois\0", 21,9,1955, "Francaise\0", ACTEUR);
    init_tableau_Personne(&acteur[12], "Le Ny\0", "Anne\0", 16,12,1962, "Francaise\0", ACTEUR);
    init_tableau_Personne(&acteur[13], "Page\0", "Ellen\0", 21,2,1987, "Canadienne\0", ACTEUR);
    init_tableau_Personne(&acteur[14], "Bullock\0", "Sandra\0", 26,7,1964, "Americaine\0", ACTEUR);
    init_tableau_Personne(&acteur[15], "Clooney\0", "Georges\0", 6,5,1961, "Americaine\0", ACTEUR);
    init_tableau_Personne(&acteur[16], "Harris\0", "Ed\0", 28,11,1950, "Americaine\0", ACTEUR);
    init_tableau_Personne(&acteur[17], "McConaughey\0", "Matthew\0", 4,11,1969, "Americaine\0", ACTEUR);
    init_tableau_Personne(&acteur[18], "Hathaway\0", "Anne\0", 12,11,1982, "Americaine\0", ACTEUR);
    init_tableau_Personne(&acteur[19], "Caine\0", "Michael\0", 14,3,1933, "Britannique\0", ACTEUR);
    init_tableau_Personne(&acteur[20], "Foxx\0", "Jamie\0", 13,12,1967, "Americaine\0", ACTEUR);
    init_tableau_Personne(&acteur[21], "Waltz\0", "Christoph\0", 4,10,1956, "Autrichienne\0", ACTEUR);
    init_tableau_Personne(&acteur[22], "Eisenberg\0", "Jesse\0", 5,10,1983, "Americaine\0", ACTEUR);
    init_tableau_Personne(&acteur[23], "Ruffalo\0", "Mark\0", 22,11,1967, "Americaine\0", ACTEUR);
    init_tableau_Personne(&acteur[24], "Harrelson\0", "Woody\0", 23,7,1961, "Americaine\0", ACTEUR);
    init_tableau_Personne(&acteur[25], "Damon\0", "Matt\0", 8,10,1970, "Americaine\0", ACTEUR);
    init_tableau_Personne(&acteur[26], "Foster\0", "Jodie\0", 19,11,1962, "Americaine\0", ACTEUR);
    init_tableau_Personne(&acteur[27], "Kidman\0", "Nicole\0", 20,6,1967, "Australienne\0", ACTEUR);
    init_tableau_Personne(&acteur[28], "Hugh\0", "Jackman\0", 12,10,1968, "Australienne\0", ACTEUR);
    init_tableau_Personne(&acteur[29], "Wenham\0", "David\0", 21,9,1965, "Australienne\0", ACTEUR);
    init_tableau_Personne(&acteur[30], "Downey Jr\0", "Robert\0", 4,4,1965, "Americaine\0", ACTEUR);
    init_tableau_Personne(&acteur[31], "Evans\0", "Chris\0", 13,6,1981, "Americaine\0", ACTEUR);
    init_tableau_Personne(&acteur[32], "Copley\0", "Sharlto\0", 27,12,1973, "Sud africaine\0", ACTEUR);
    init_tableau_Personne(&acteur[33], "Hemsworth\0","Chris\0", 11,8,1983, "Australienne\0", ACTEUR);
    init_tableau_Personne(&acteur[34], "Dujardin\0", "Jean\0", 19,6,1972, "Francaise\0", ACTEUR);


	/*************
    ***  FILM  ***
    **************/

    init_tableau_film(&film[0], "Avengers\0", 2012, &realisateur[10], 144, ACTION, AUCUN,  &acteur[30], &acteur[31], &acteur[23], &acteur[5]);
    init_tableau_film(&film[1], "Gladiator\0", 2000, &realisateur[1], 155, ACTION, DRAME, &acteur[4], &acteur[3], &acteur[10], &acteur[0]);
    init_tableau_film(&film[2], "Intouchables\0", 2011, &realisateur[11], 112, COMEDIE, AUCUN, &acteur[11], &acteur[6], &acteur[12], &acteur[0]);
    init_tableau_film(&film[3], "Inception\0", 2010, &realisateur[2], 188, SCIENCE_FICTION, AUCUN, &acteur[9], &acteur[13], &acteur[0], &acteur[0]);
    init_tableau_film(&film[4], "Gravity\0", 2013, &realisateur[0], 90, SCIENCE_FICTION, AUCUN, &acteur[14], &acteur[15], &acteur[16], &acteur[0]);
    init_tableau_film(&film[5], "Interstellar\0", 2014, &realisateur[2], 169, SCIENCE_FICTION, DRAME, &acteur[17], &acteur[18], &acteur[19], &acteur[0]);
    init_tableau_film(&film[6], "Django Unchained\0", 2013, &realisateur[12], 164, ACTION, AUCUN, &acteur[20], &acteur[21], &acteur[9], &acteur[0]);
    init_tableau_film(&film[7], "Insaisissables\0", 2013, &realisateur[13], 116, POLICIER, AUCUN, &acteur[22], &acteur[23], &acteur[24], &acteur[0]);
    init_tableau_film(&film[8], "Elysium\0", 2013, &realisateur[14], 110, ACTION, SCIENCE_FICTION, &acteur[25], &acteur[26], &acteur[32], &acteur[0]);
    init_tableau_film(&film[9], "Australia\0", 2008, &realisateur[15], 155, DRAME, AUCUN, &acteur[27], &acteur[28], &acteur[29], &acteur[0]);

    menu_principal(film, realisateur, acteur, taille_utile_film, taille_utile_real, taille_utile_acteur);
	return 0;
}
