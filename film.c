#include "film.h"
#include "personne.h"

/**************************
*
*	Derniere MAJ 9/11 :
*	rechercheFilm() changement des paraemtres a rajouter
*	commentaire dans film.h
*
***************************/

void saisirFilm(Film *film){

	int taille_utile=0;
	int i=0;
	int arret = 1; /*continue sinon 0 et stop*/
	char rep[1];
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
