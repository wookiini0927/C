/******************************
*
*	Derniere MAJ 10/11 :
*		Commentaires	
*
*******************************/

#include "film.h"
#include "personne.h"
#include "test1.h"
#include "test2.h"
#include "test3.h"

int main(int argc, char const *argv[])
{
	/* code */
	int choix;

	/*On choisis de quel maniere on va utiliser les BDD*/
	do{
		printf("----------------------Choix----------------------\n");
		printf("|\t1-Recherche dans une BDD prédefini\t|\n");
		printf("|\t2-Créez votre propre BDD\t\t|\n");
		printf("|\t3-Creez votre BDD a partir d'un fichier\t|\n");
		printf("-------------------------------------------------\n");
		
		scanf("%d", &choix);
	}while(choix !=1 && choix !=2 && choix !=3);

	if (choix == 1){
		//BDD déja existante
		test1();
	}
	else if (choix == 2){
		//saisie manuelle
		test2();
	}
	else if (choix == 3){
		//creation d'une BDD a partir d'un fichier
		test3_menu();
	}


	return 0;
}
