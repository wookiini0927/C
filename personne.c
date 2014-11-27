#include "personne.h"
#include "date.h"

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

	printf("Entre le prenom de la personne : ");
	fgets(personne->prenom, TAILLE, stdin);
	echange_chariot_espace(personne->prenom);

	printf("Entrez la date de naissance (JJ/M/AAAA)\n");
	saisirDate(&personne->dob);

	printf("Entrez la nationalite : ");
	fgets(personne->nationalite, TAILLE, stdin);

	do{
		do{
			printf("Est ce un acteur ou un realisateur\n0-Realisateur\n1-Acteur\n");
			fgets(temp, TAILLE, stdin);
		}while(verification_digit(temp) == 0 || strlen(temp)>2);
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
	int cmpt = 0; /*compteur pour savoir si on affiche la liste ou la fiche
					si cmpt == 1 : fiche
					sinon : liste
				   */ 
	int j =0; /*Si cmpt == 1, il faut une variable d'indice pour garder la case du tableau a afficher*/

	char *chaine_tmp; //garde en minuscule le nom de recherche
	char *tmp; //garde en minuscule le nom du tableau realisateur ou acteur

	chaine_tmp = (char*) malloc(TAILLE*sizeof(char));
	chaine_tmp = minuscules(nom); 

	while(i<taille){

		tmp = minuscules(tab[i].nom); 
		echange_chariot_espace(chaine_tmp);

		if(strcmp(chaine_tmp, tmp) == 0){

			printf("%s %s\n", tab[i].prenom, tab[i].nom );
			cmpt++;
			j = i;

		/*	int comp = strcmp(tmp, chaine_tmp);
			printf("comp : %d\n", comp );
			printf("\n");
			printf("Compare\n");
			affichagePersonne(&tab[i]);*/
		}
		i++;
	}

	if (cmpt == 1){
		printf("dg\n");
		affichagePersonne(&tab[j]);
	}

}

void recherchePrenom(Personne tab[], int taille, const char *nom){
	
	int i = 0;
	int cmpt = 0; /*compteur pour savoir si on affiche la liste ou la fiche
					si cmpt == 1 : fiche
					sinon : liste
				   */ 
	int j =0; /*Si cmpt == 1, il faut une variable d'indice pour garder la case du tableau a afficher*/

	char *chaine_tmp; //garde en minuscule le prenom chercher
	char *tmp; // garde en minusucles les prenom du tableau a chaque appel	

	chaine_tmp = (char*) malloc(TAILLE*sizeof(char));
	chaine_tmp = minuscules(nom);

	while(i<taille){

		tmp = minuscules(tab[i].prenom);
		echange_chariot_espace(chaine_tmp);

		if(strcmp(chaine_tmp, tmp) == 0){

			printf("%s %s\n", tab[i].prenom, tab[i].nom );
			cmpt++;
			j = i;
			/*int comp = strcmp(tmp, chaine_tmp);
			printf("comp : %d\n", comp );
			printf("\n");
			printf("Compare\n");*/
			//affichagePersonne(&tab[i]);
		}
		i++;
	}
	printf("dgdh\n");
	if (cmpt == 1){
		printf("dg\n");
		affichagePersonne(&tab[j]);
	}

	
}

void recherche_naissance_Annee(Personne tab[], int taille, int chercheAnnee){
	int i = 0;

	printf("cherche annee : %d\n", chercheAnnee );

	while(i<6){
		printf("\n");
		printf("boucle \n");
		printf("tab annee %d\n", tab[i].dob.annee );

		if(tab[i].dob.annee == chercheAnnee){

			printf("tab annee %d\n", tab[i].dob.annee );
			printf("\n");
			printf("Compare\n");
			
			printf("%s %s (%d)\n", tab[i].prenom, tab[i].nom, tab[i].dob.annee );
		}
		i++;
	}
}

void rechercheNationalite(Personne tab[], int taille, const char *nationality){
	
	int i = 0;

	char *chaine_tmp;
	char *tmp;
	chaine_tmp = (char*) malloc(TAILLE*sizeof(char));

	chaine_tmp = minuscules(nationality);

	while(i<3){
		printf("\n");
		printf("boucle \n");
		tmp = minuscules(tab[i].nationalite);

		echange_chariot_espace(chaine_tmp);

		if(strcmp(chaine_tmp, tmp) == 0){
			printf("%s %s (%s)\n", tab[i].prenom, tab[i].nom, tab[i].nationalite );
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

