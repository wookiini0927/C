#include "personne.h"
#include "date.h"
#include "test1.h"

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

void saisirPersonne(Personne tab[], int taille,Personne *pers){

	char temp[TAILLE];
	int metier;

	printf("Entrez le nom de la personne : ");
	fgets(pers->nom, TAILLE, stdin);
	echange_chariot_espace(pers->nom);

	printf("Entrez le prenom de la personne : ");
	fgets(pers->prenom, TAILLE, stdin);
	echange_chariot_espace(pers->prenom);

	printf("Entrez la date de naissance (JJ/M/AAAA)\n");
	saisirDate(&pers->dob);

	printf("Entrez la nationalite : ");
	fgets(pers->nationalite, TAILLE, stdin);
	echange_chariot_espace(pers->nationalite);


	do{
		do{
			do{
				printf("Est ce un acteur ou un realisateur\n0-Realisateur\n1-Acteur\n");
				fgets(temp, TAILLE, stdin);

			}while(verification_digit(temp) == 0 || strlen(temp)>2);
			metier = atoi(temp);
		}while(metier>2);
		pers->statut = metier;
	}while(pers->statut != ACTEUR && pers->statut != REALISATEUR);
	clean(temp);

	tab[taille] = *pers;

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

char* majuscules(const char *chaine){
	int i = 0; //compteur pour le tableau temporaire
	char *mot; //pointeur temporaire qui  garde la version minuscule

	mot = (char*) malloc(TAILLE * (sizeof(char)));

	/**
	*on convertis chaque lettre en minuscule et le stock dans un tableau temporaire
	**/
	while(*chaine !='\0'){
		//convertis en lowercase le titre
		mot[i] = toupper(*chaine);
		chaine++;
		i++;
	}
	mot[i] = '\0'; //ajout caractere de fin de ligne

	return mot;
}

void rechercheNom(Personne tab[], int taille, const char *nom, Metier stat){
	
	int i = 0;
	int cmpt = 0; /*compteur pour savoir si on affiche la liste ou la fiche
					si cmpt == 1 : fiche
					si cmpt == 0 : message erreur
					sinon : liste
				   */ 
	int j =0; /*Si cmpt == 1, il faut une variable d'indice pour garder la case du tableau a afficher*/

	char *chaine_tmp; //garde en minuscule le nom de recherche
	char *chaine_res; //garde en majuscule le nom de recherche
	char *tmp; //garde en minuscule le nom du tableau realisateur ou acteur

	chaine_tmp = (char*) malloc(TAILLE*sizeof(char));
	chaine_res = (char*) malloc(TAILLE*sizeof(char));

	chaine_tmp = minuscules(nom); 
	chaine_res = majuscules(nom); //passe la chaine en majuscules
	echange_chariot_espace(chaine_res);

	
	printf("Resultats : %s \n", chaine_res );

	while(i<taille){

		tmp = minuscules(tab[i].nom); 
		echange_chariot_espace(chaine_tmp);

		if(strcmp(chaine_tmp, tmp) == 0){
			printf(" |%s %s\n", tab[i].prenom, tab[i].nom );
			cmpt++;
			j = i;
		}
		i++;
	}

	if (cmpt == 1){
		affichagePersonne(&tab[j]);
	}

	if(cmpt == 0){
		printf("ERROR : no ");
		conversionMetier(stat);
		printf(" with that name : %s\n", nom);
        appelRechercheNom(tab, taille,stat);
	}
}

void recherchePrenom(Personne tab[], int taille, const char *nom, Metier stat){
	
	int i = 0;
	int cmpt = 0; /*compteur pour savoir si on affiche la liste ou la fiche
					si cmpt == 1 : fiche
					si cmpt == 0 : message erreur
					sinon : liste
				   */
	int j =0; /*Si cmpt == 1, il faut une variable d'indice pour garder la case du tableau a afficher*/

	char *chaine_tmp; //garde en minuscule le prenom chercher
	char *tmp; // garde en minusucles les prenom du tableau a chaque appel	
	char *chaine_res; //garde en majuscule le nom de recherche

	chaine_tmp = (char*) malloc(TAILLE*sizeof(char));
	chaine_res = (char*) malloc(TAILLE*sizeof(char));

	chaine_tmp = minuscules(nom);
	chaine_res = majuscules(nom); //passe la chaine en majuscules
	echange_chariot_espace(chaine_res);

	
	printf("Resultats : %s \n", chaine_res );

	while(i<taille){

		tmp = minuscules(tab[i].prenom);
		echange_chariot_espace(chaine_tmp);

		if(strcmp(chaine_tmp, tmp) == 0){
			printf(" |%s %s\n", tab[i].prenom, tab[i].nom );
			cmpt++;
			j = i;
		}

		i++;
	}

	if (cmpt == 1){
		affichagePersonne(&tab[j]);
	}	
	if(cmpt == 0){
		printf("ERROR : no ");
		conversionMetier(stat);
		printf(" with that name : %s\n", nom);
        appelRecherchePrenom(tab, taille,stat);

	}
}

void recherche_naissance_Annee(Personne tab[], int taille, int chercheAnnee, Metier stat){
	int i = 0;
	int cmpt = 0; /*compteur pour savoir si on affiche la liste ou la fiche
					si cmpt == 1 : fiche
					si cmpt == 0 : message erreur
					sinon : liste
				   */

	if(chercheAnnee < 1799){
		printf("ERROR : YEAR NOT FOUND\n");	
	}
	printf("Resultats : %d\nPrenom Nom (JJ/M)\n", chercheAnnee);
	while(i<taille &&chercheAnnee!=0){
		if(tab[i].dob.annee == chercheAnnee){
			printf(" |%s %s (%d/%d)\n", tab[i].prenom, tab[i].nom, tab[i].dob.jour, tab[i].dob.mois );
			cmpt++;
		}
		i++;
	}

	if(cmpt == 0 && chercheAnnee!=0){
		printf("ERROR : no ");
		conversionMetier(stat);
		printf(" born in : %d\n", chercheAnnee);
		appelRechercheNaissance(tab, taille,stat);

	}
}

void rechercheNationalite(Personne tab[], int taille, const char *nationality, Metier stat){
	
	int i = 0;
	int cmpt = 0; /*compteur pour savoir si on affiche la liste ou la fiche
					si cmpt == 1 : fiche
					si cmpt == 0 : message erreur
					sinon : liste
				   */

	char *chaine_tmp; //garde en minuscule le nom de recherche
	char *tmp; //garde en minuscule le nom du tableau realisateur ou acteur
	char *chaine_res; //garde en majuscule le nom de recherche

	chaine_tmp = (char*) malloc(TAILLE*sizeof(char));
	chaine_res = (char*) malloc(TAILLE*sizeof(char));

	chaine_tmp = minuscules(nationality);
	chaine_res = majuscules(nationality); //passe la chaine en majuscules
	echange_chariot_espace(chaine_res);

	
	printf("Resultats : %s (Prenom Nom (annee))\n", chaine_res );

	
	while(i<taille){
		tmp = minuscules(tab[i].nationalite);
		echange_chariot_espace(chaine_tmp);

		if(strcmp(chaine_tmp, tmp) == 0){
			printf(" |%s %s (%d)\n", tab[i].prenom, tab[i].nom, tab[i].dob.annee );
			cmpt++;
		}
		i++;
	}

	if(cmpt == 0){
		printf("ERROR : no ");
		conversionMetier(stat);
		printf(" with that nationality : %s\n", nationality);
        appelRechercheNationalite(tab, taille,stat);

	}
}

void conversionMetier(Metier statut){
	switch(statut){
		case 0 : printf("REALISATEUR");
			break;
		case 1 : printf("ACTEUR");
			break;
		default : 
			printf("AUCUN\n");
			break;
	}
}

