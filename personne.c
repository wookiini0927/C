#include "personne.h"
#include "date.h"

/**************************
*
*	Derniere MAJ : 10/11
*		commentaires (.h)
*
***************************/

void purger(void){   
	int c;

	while ((c = getchar()) != '\n' && c != EOF)
	{
		;
	}
}

void clean (char *chaine)
{
    char *p = strchr(chaine, '\n');

    if (p)
    {
        *p = 0;
    }

    else
    {
        purger();
    }
}

void echange_chariot_espace(char *chaine){
	unsigned int len;
	len = strlen(chaine);

	if (chaine[len-1] == '\n'){
		chaine[len-1] = '\0';
	}
}

void saisirPersonne(Personne *personne){

	char temp[TAILLE];

	printf("Entrez le nom de la personne : ");
	fgets(personne->nom, TAILLE, stdin);
	echange_chariot_espace(personne->nom);
	//printf("%s\n",personne->nom );

	printf("Entre le prenom de la personne : ");
	fgets(personne->prenom, TAILLE, stdin);
	echange_chariot_espace(personne->prenom);
	//printf("%s\n", personne->prenom );

	printf("Entrez la date de naissance (JJ/M/AAAA)\n");
	saisirDate(&personne->dob);

	printf("Entrez la nationalite : ");
	fgets(personne->nationalite, TAILLE, stdin);

	do{
		do{
			printf("Est ce un acteur ou un realisateur\n1-Realisateur\n0-Acteur\n");
			fgets(temp, TAILLE, stdin);
		}while(verification_digit(temp) == 0 || strlen(temp)>2);
		//scanf(" %c", &personne->statut);
		personne->statut = atoi(temp);
	}while(personne->statut != ACTEUR && personne->statut != REALISATEUR);

}

void affichagePersonne(const Personne *personne){

	printf("--------------Fiche ");
	if (personne->statut == ACTEUR){
		printf("ACTEUR---------------\n");
	}
	if (personne->statut == REALISATEUR)
	{
		printf("REALISATEUR-----------\n");
	}
	printf("| Nom : %s %s\t\t|\n", personne->prenom, personne->nom );
	affichageDate(&personne->dob);
	printf("| Nationalite : %s\t\t|\n",personne->nationalite );
	printf("-----------------------------------------\n");
}

/*void recherchePersonne(Personne tab[], int taille, const char *nom){

}*/


void conversionMetier(Metier statut){
	switch(statut){
		case 0 : printf("REALISATEUR\n");
			break;
		case 1 : printf("ACTEUR\n");
			break;
		default : 
			printf("AUCUN\n");
			break;
	}

}

