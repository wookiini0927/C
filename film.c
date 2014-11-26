#include "film.h"
#include "personne.h"

/**************************
*
*	Derniere MAJ 16/11 :
*	Ajout : recherche_FilmRealisateur()
*
***************************/

void init_tableau_film(Film *f, const char *titre, const int date, Personne *real, const int duree, const Genre genre, Personne *a1, Personne *a2, Personne *a3, Personne *a4)
{
	strcpy(f->titre, titre);
	f->annee = date;
	f->realisateur = *real;
	f->duree = duree;
	f->genre = genre;

	f->casting[0] = *a1;
	f->casting[1] = *a2;
	f->casting[2] = *a3;
	f->casting[3] = *a4;

}

void saisirFilm(Film *film){

	int taille_utile=0;
	int i=0;
	int arret = 1; /*continue sinon 0 et stop*/
	char rep[REPONSE];
	char temp[TAILLE]; //variable temporaire pour avoir l'annee

	printf("Entrez le titre :\n");
	fgets(film->titre, TAILLE, stdin);

	do{
		printf("Annee de sortie :\n");
		fgets(temp, sizeof(temp),stdin );

	}while(verification_digit(temp) ==0);
	film->annee = atoi(temp);
	clean(temp);
	printf("%d\n", film->annee );

	printf("Information du realisateur\n");
	saisirPersonne(&film->realisateur);

	do{
		printf("Information Casting\n");
		saisirPersonne(&film->casting[i]);
		
		if(i >= 0){
			do{
				printf("Voulez vous rentrez un(e) autre acteur/actrice (o/n) ?\n");
				fgets(rep, sizeof(rep), stdin);			
				if(rep[0] == 'o' || rep[0] == 'O'){
					arret = 1;
				}
				else if (rep[0] == 'n' || rep[0] == 'N'){
					arret = 0;
				}

			}while(rep[0] == 'o' && rep[0] == 'O' && rep[0] == 'n' && rep[0] == 'N');

		}
		taille_utile++;
		i++;
	}while (i<T_C && arret == 1);


	printf("Durée en minutes\n");
	scanf("%d",&film->duree);

	printf("Genre du film (choisir le chiffre): \n0-AUCUN\n1-ACTION\n2-HORREUR\n3-COMEDIE\n4-DOCUMENTAIRE\n5-POLICIER\n");
	printf("6-DRAME\n7-ANIMATION\n8-SCIENCE_FICTION\n");
	scanf("%d", &film->genre);

}

void affichageFilm(const Film *film){
	int i = 0;
	printf("Fiche FILM\n");
	printf("%s (%d)\n", film->titre, film->annee);
	printf("Realisateur : %s %s\n", film->realisateur.prenom, film->realisateur.nom );
	printf("Acteurs principaux : ");
	for (i = 0; i< sizeof(film->casting)/sizeof(film->casting[0]); i++){
		printf("%s %s, ", film->casting[i].prenom, film->casting[i].nom );
		if(i==1){
			printf("\n");
		}
	}
	printf("\n");
	printf("Durée : ");
	conversionDuree(film);
	printf("Genre : ");
	conversionGenre(film->genre);
}

void rechercheFilm(Film tab[], int taille, char *chercheTitre){
	
	int i = 0;
	int j = 0;
	int taille_utile = 0;

	char mot[TAILLE];
	char tab_cp[TAILLE];
	char *tmp;

	printf("chaine : %s\n",chercheTitre );


	//transformer cette boucle en une fonction
	while(*chercheTitre !='\0'){
		//convertis en lowercase le titre
		mot[i] = tolower(*chercheTitre);
		chercheTitre++;
		i++;
	}
	mot[i] = '\0'; //ajout caractere de fin del igne
	printf("chaine : %s\n", mot);

	i=0;
	while(i<2){
		printf("\n");
		printf("chaine a comparer :%s\n", mot );
		printf("boucle \n");
		printf("tab titre : %s\n", tab[i].titre );

		while(tab[i].titre[j] !='\0'){
			printf("taille_utile\n");
			//recupere la taille du titre dans le tableau
			taille_utile++;
			j++;
		}
		printf("%d\n", taille_utile );
		tmp = tab[i].titre;

		printf("tmp %s\n",  tab[i].titre);
		j=0;
		while(j<taille_utile){
			//convertis le titre dans le tableau en lowercase
			tab_cp[j] = tolower(tmp[j]);
			j++;	
		}
		tab_cp[j] = '\0'; //ajout caractere de finde ligne
			printf("tab : %s\n", tab_cp);

		if(strcmp(tab_cp, mot) == 0){
			int comp = strcmp(tab_cp, mot);
			printf("%d\n", comp );
			printf("\n");
			printf("Compare\n");
			affichageFilm(&tab[i]);
		}
			i++;
	}

}

void rechercheAnnee(Film tab[], int taille, int chercheAnnee){
	;
}

void rechercheDuree(Film tab[], int taille, int critDur){
	;
}

void recherche_FilmRealisateur(Film tab[], int taille, const char *name){
	;
}

void recherche_FilmActeur(Film tab[], int taille, const char *name){
	;
}
/*void rechercheGenre(Film tab[], int taille, int genre);*/

void conversionDuree(const Film *film){

	int heure = 0;
	int min = 0;

	if (film->duree < 60) {
		printf("%d min\n", film->duree);
	}
	else{
		heure = film->duree/60;
		min = film->duree%60;

		printf("%dh%d\n", heure, min );
	}

}

void conversionGenre(Genre genre){
	switch(genre){
		case 1 : printf("ACTION\n");
			break;
		case 2 : printf("HORREUR\n");
			break;
		case 3 : printf("COMEDIE\n"); 
			break;
		case 4 : printf("DOCUMENTAIRE\n");
			break;
		case 5: printf("POLICIER\n");
			break;
		case 6 : printf("DRAME\n");
			break;
		case 7 : printf("ANIMATION\n");
			break;
		case 8 : printf("SCIENCE_FICTION\n");
			break;
		default : 
			printf("AUCUN\n");
			break;
	}

}
