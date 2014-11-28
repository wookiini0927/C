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
	printf("\t\tFiche FILM\n");
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
	int cmpt = 0; /*compteur pour savoir si on affiche la liste ou la fiche
					si cmpt == 1 : fiche
					si cmpt == 0 : message erreur
				   */

	char *chaine_tmp; //garde en minuscule le nom de recherche
	char *tmp; //garde en minuscule le nom du tableau realisateur ou acteur

	chaine_tmp = (char*) malloc(TAILLE*sizeof(char));
	chaine_tmp = minuscules(chercheTitre); 


	while(i<taille){

		tmp = minuscules(tab[i].titre); 
		echange_chariot_espace(chaine_tmp);

		if(strcmp(chaine_tmp, tmp) == 0){
			cmpt++;
			affichageFilm(&tab[i]);
		}
		i++;
	}

	if(cmpt == 0){
		printf("ERROR : no FILM with that title : %s\n", chercheTitre);
	}
}


void rechercheAnnee(Film tab[], int taille, int chercheAnnee){
	int i = 0;
	int cmpt = 0; /*compteur pour savoir si on affiche la liste ou la fiche
					si cmpt == 1 : fiche
					si cmpt == 0 : message erreur
				   */	

	while(i<taille){
		if(tab[i].annee == chercheAnnee){
			cmpt++;
			printf("%s\n", tab[i].titre);
		}
		i++;
	}

	if(cmpt == 0){
		printf("ERROR : no FILM out %d\n", chercheAnnee);
	}
}

void rechercheDuree(Film tab[], int taille, int critDur){
	int i = 0;
	int cmpt = 0; /*compteur pour savoir si on affiche la liste ou la fiche
					si cmpt == 1 : fiche
					si cmpt == 0 : message erreur
				   */	
	int plus_dix = 0; //plage d'horaire plus 10min par rapport a critDur
	int moins_dix = 0; //plage d'horaire moins 10min par rapport a critDur

	plus_dix = critDur+10;
	moins_dix = critDur-10;

	printf("Intervalle de Duree : [%d,%d] \n", moins_dix, plus_dix);
	while(i<taille){
		if(tab[i].duree == critDur || (tab[i].duree < plus_dix && tab[i].duree > moins_dix)){
			cmpt++;
			printf("%s (%d)\n", tab[i].titre, tab[i].duree );
		}
		i++;
	}

	if(cmpt == 0){
		printf("ERROR : no FILM last between [%d,%d]\n", moins_dix, plus_dix);
	}
}

void recherche_FilmRealisateur(Film tab[], int taille, const char *name){
	int i = 0;
	int j =0; /*Si res == 0, il faut une variable d'indice pour garder la case du tableau a afficher*/
	int res; //resultat de strcmp()
	int cmpt = 0; /*compteur pour savoir si on affiche la liste ou la fiche
					si cmpt == 1 : fiche
					si cmpt == 0 : message erreur
				   */

	char *chaine_tmp; //garde en minuscule le nom de recherche
	char *tmp; //garde en minuscule le nom du tableau realisateur ou acteur
	char *chaine_res; //garde en majuscule le nom de recherche

	chaine_tmp = (char*) malloc(TAILLE*sizeof(char));
	chaine_res = (char*) malloc(TAILLE*sizeof(char));
	chaine_tmp = minuscules(name); 
	chaine_res = majuscules(name);
	echange_chariot_espace(chaine_res);

	do{

		tmp = minuscules(tab[i].realisateur.nom); 
		echange_chariot_espace(chaine_tmp);

		if(strcmp(chaine_tmp, tmp) == 0){
			cmpt++;
			res = strcmp(chaine_tmp, tmp); 
			j = i;
		}
		i++;
	}while(i<taille || strcmp(chaine_tmp, tmp) == 0);

	if(res == 0){
		printf("Resultats : %s (%s)\n", chaine_res, tab[j].realisateur.prenom  );

	}

	i=0;
	cmpt = 0;
	while(i<taille){

		tmp = minuscules(tab[i].realisateur.nom); 
		echange_chariot_espace(chaine_tmp);

		if(strcmp(chaine_tmp, tmp) == 0 && cmpt < 5){
			cmpt++;
			printf("%s (%d)\n", tab[i].titre, tab[i].annee );
		}
		i++;
	}

	if(cmpt == 0){
		printf("ERROR : no FILM made by : %s\n", chaine_res);
	}
}

void recherche_FilmActeur(Film tab[], int taille, const char *name){
	int i = 0;
	int j1 =0; /*Si res == 0, il faut une variable d'indice pour garder la case du tableau a afficher*/
	int j2 =0; /*Si res == 0, il faut une variable d'indice pour garder la case du tableau a afficher*/
	int k = 0; //compteur pour le tableau des casting
	int res; //resultat de strcmp()
	int cmpt = 0; /*compteur pour savoir si on affiche la liste ou la fiche
					si cmpt == 1 : fiche
					si cmpt == 0 : message erreur
				   */

	char *chaine_tmp; //garde en minuscule le nom de recherche
	char *tmp; //garde en minuscule le nom du tableau realisateur ou acteur
	char *chaine_res; //garde en majuscule le nom de recherche

	chaine_tmp = (char*) malloc(TAILLE*sizeof(char));
	chaine_res = (char*) malloc(TAILLE*sizeof(char));
	chaine_tmp = minuscules(name); 
	chaine_res = majuscules(name);
	echange_chariot_espace(chaine_res);

	do{
		k=0;
		do{
			tmp = minuscules(tab[i].casting[k].nom); 
			echange_chariot_espace(chaine_tmp);

			if(strcmp(chaine_tmp, tmp) == 0){
				cmpt++;
				res = strcmp(chaine_tmp, tmp); 
				j1 = i;
				j2 = k;
			}
			k++;

		}while(k<T_C || strcmp(chaine_tmp, tmp) == 0);
		i++;
	}while(i<taille || strcmp(chaine_tmp, tmp) == 0);

	if(res == 0){
		printf("Resultats : %s (%s)\n", chaine_res, tab[j1].casting[j2].prenom);

	}

	i=0;
	cmpt = 0;
	while(i<taille){
		k=0;
		while(k<T_C){

			tmp = minuscules(tab[i].casting[k].nom); 
			echange_chariot_espace(chaine_tmp);

			if(strcmp(chaine_tmp, tmp) == 0 && cmpt < 10){
				cmpt++;
				printf("%s (%d)\n", tab[i].titre, tab[i].annee );
			}
			k++;
		}
		i++;
	}

	if(cmpt == 0){
		printf("ERROR : no FILM played by : %s\n", chaine_res);
	}
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
