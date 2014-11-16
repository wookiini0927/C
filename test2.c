#include "test2.h"
/*rentrer par l'utilisateur*/

void test2(){
	int taille_utile_film=0;
	int taille_utile_real=0;
	int taille_utile_acteur=0;

	char *choix;
	int numero;
	char rep;

	Film film[TAILLE_DEFAUT];
	Personne realisateur[TAILLE_DEFAUT];
	Personne acteur[TAILLE_DEFAUT];

	/*do{
		do{
			do{
				printf("-------------Saisie--------------\n|\t1-Film\t\t\t|\n|\t2-Realisateur\t\t|\n|\t3-Acteur/Actrice\t|\n");
				printf("---------------------------------\n");

				fgets(choix, TAILLE_DEFAUT, stdin);
			}while(verification_digit(choix) == 0);



			if (choix == 1){
				saisirFilm(&film[taille_utile_film]);
				taille_utile_film++;
			}
			else if (choix == 2){
				saisirPersonne(&realisateur[taille_utile_real]);
				taille_utile_real++;
			}
			else if (choix == 3){
				saisirPersonne(&acteur[taille_utile_acteur]);
				taille_utile_acteur++;
			}



		printf("Voulez-vous saisir une nouvelle entree? (o/n)\n");
		scanf(" %c", &rep);

	}while(rep == 'o' && rep == 'O' && rep =='n' && rep =='N');*/

	/*saisirFilm(&film[0]);
	affichageFilm(&film[0]);*/
}

/*int main(int argc, char const *argv[])
{
	test2();

	return 0;
}*/

