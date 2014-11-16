#include "date.h"
#include "personne.h"

/**************************
*
*	Derniere MAJ : 10/11
*		commentaires (.h)
*
***************************/

int verification_digit(const char *d){
	int i = 0; 
	int is_chiffre = 1; // continue tant que c'est un chiffre
	if (strlen(d) == 1) {
		if (d[0] == '\n') {
			is_chiffre = 0;
		}
	}
	while(i < strlen(d)-1 && is_chiffre == 1){
		if (isdigit(d[i]) == 0){ //si ce n'est pas chiffre
			is_chiffre = 0;
		}
		i++;
	}
	return is_chiffre;
}

void saisirDate(Date *d){
	char* tmp = malloc(sizeof(char)*300);

	printf("Entrez une date JJ/M/AAAA\n");
	do{
		do {
			printf("JJ :\n");
			fgets(tmp, TAILLE , stdin);
		} while (verification_digit(tmp) == 0 || strlen(tmp) > 3);
		d->jour = atoi(tmp);
	}while(d->jour > 31);
	clean(tmp);

	printf("%d\n", d->jour );
	//scanf("%d", &d->jour);
	do{
		do{
			printf("Mois (M 1 - 9, M 10-12)\n");
			fgets(tmp, TAILLE,stdin );
		}while(verification_digit(tmp) == 0 || strlen(tmp)>3);

		d->mois = atoi(tmp);
	}while(d->mois >12);
	clean(tmp);

	printf("%d\n", d->mois );

	//scanf("%d", &d->mois);
	do{
		printf("AAAA\n");
		fgets(tmp, TAILLE,stdin );	
	}while(verification_digit(tmp) == 0);

	d->annee = atoi(tmp);
	clean(tmp);

	printf("%d\n", d->annee );

	//scanf("%d", &d->annee);
}

void affichageDate(const Date *d){
	printf("| Date de naissance : %d ", d->jour);
	conversionMois(d->mois);
	printf(" %d \t|\n", d->annee);

}

void conversionMois(int mois){
	switch(mois){
		case 1 : printf("Janvier");
			break;
		case 2 : printf("Fevrier");
			break;
		case 3: printf("Mars");
			break;
		case 4 : printf("Avril");
			break;
		case 5 : printf("Mai");
			break;
		case 6 : printf("Juin");
			break;
		case 7 : printf("Juillet");
			break;
		case 8 : printf("Aout");
			break;
		case 9 : printf("Septembre");
			break;
		case 10 : printf("Octobre");
			break;
		case 11 : printf("Novembre");
			break;
		case 12 : printf("Decembre");
			break;
		default : printf("Aucun mois\n");
			break;
	}
}
