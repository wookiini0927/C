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

void init_tableau_Personne(Personne *p, const char *nom, const char *prenom, const int j, const int m, const int a, const char *nationality, const Metier stat)
{
	strcpy(p->nom, nom);
	strcpy(p->prenom, prenom);
	p->dob.jour = j;
	p->dob.mois = m;
	p->dob.annee = a;
	strcpy(p->nationalite, nationality);
	p->statut = stat;

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
			printf("Est ce un acteur ou un realisateur\n0-Realisateur\n1-Acteur\n");
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

char* minuscules(const char *chaine){
	int i = 0; //compteur pour le tableau temporaire
	char *mot; //pointeur temporaire qui  garde la version minuscule

	mot = (char*) malloc(TAILLE * (sizeof(char)));

	/**
	*on convertis chaque lettre en minuscule et le stock dans un tableau temporaire
	**/
	while(*chaine !='\0'){
		//convertis en lowercase le titre
		mot[i] = tolower(*chaine);
		chaine++;
		i++;
	}
	mot[i] = '\0'; //ajout caractere de fin de ligne

	return mot;
}

void rechercheNom(Personne tab[], int taille, const char *nom){
	
	int i = 0;

	char *chaine_tmp;
	char *tmp;

	chaine_tmp = (char*) malloc(TAILLE*sizeof(char));

	printf("chaine : %s longueur : %d\n",nom, strlen(nom) );

	chaine_tmp = minuscules(nom);


	i=0;
	while(i<3){
		printf("\n");
		printf("chaine a comparer :%s %d\n", chaine_tmp, strlen(chaine_tmp) );
		printf("boucle \n");
		printf("tab longueur nom : %d\n", strlen(tab[i].nom) );

		tmp = minuscules(tab[i].nom);

		printf("chaine tmp : %s et longueur : %d\n", chaine_tmp, strlen(chaine_tmp));

		echange_chariot_espace(chaine_tmp);

		printf("tmp %s et longueur : %d\n",  tmp, strlen(tmp));
			int comp = strcmp(chaine_tmp, tmp);
			printf("comp : %d\n", comp );

		if(strcmp(chaine_tmp, tmp) == 0){
			int comp = strcmp(tmp, chaine_tmp);
			printf("comp : %d\n", comp );
			printf("\n");
			printf("Compare\n");
			affichagePersonne(&tab[i]);
		}
			i++;
	}

}

void recherchePrenom(Personne tab[], int taille, const char *nom){
	
	int i = 0;

	char *chaine_tmp;
	char *tmp;

	chaine_tmp = (char*) malloc(TAILLE*sizeof(char));

	printf("chaine : %s longueur : %d\n",nom, strlen(nom) );

	chaine_tmp = minuscules(nom);


	i=0;
	while(i<3){
		printf("\n");
		printf("chaine a comparer :%s %d\n", chaine_tmp, strlen(chaine_tmp) );
		printf("boucle \n");
		printf("tab longueur nom : %d\n", strlen(tab[i].nom) );

		tmp = minuscules(tab[i].nom);

		printf("chaine tmp : %s et longueur : %d\n", chaine_tmp, strlen(chaine_tmp));

		echange_chariot_espace(chaine_tmp);

		printf("tmp %s et longueur : %d\n",  tmp, strlen(tmp));
			int comp = strcmp(chaine_tmp, tmp);
			printf("comp : %d\n", comp );

		if(strcmp(chaine_tmp, tmp) == 0){
			int comp = strcmp(tmp, chaine_tmp);
			printf("comp : %d\n", comp );
			printf("\n");
			printf("Compare\n");
			affichagePersonne(&tab[i]);
		}
			i++;
	}

}


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

