/******************************
*
*	Derniere MAJ 16/11 :
*		Changement du type choix : int ->char[] et tous les changement qui vont avec	
*
*******************************/

#include <limits.h>
#include "film.h"
#include "personne.h"
#include "test1.h"
#include "test2.h"
#include "test3.h"

int main(int argc, char const *argv[])
{
	/* code */

	/*Variable locale : choix (type char *), taile 127, reserve en memoire le type d'utilisation*/ 
	char choix[REPONSE];

	/*On choisis de quel maniere on va utiliser les BDD*/
	do{
		printf("----------------------Choix----------------------\n");
		printf("|\tA-Recherche dans une BDD prédefini\t|\n");
		printf("|\tB-Créez votre propre BDD\t\t|\n");
		printf("|\tC-Creez votre BDD a partir d'un fichier\t|\n");
		printf("-------------------------------------------------\n");
		
		fgets(choix, CHAR_MAX, stdin);
	}while(*choix !='A' && *choix !='a' && *choix !='B' && *choix !='b' && *choix != 'C' && *choix != 'c');

	if (*choix == 'A' || *choix == 'a'){
		//BDD déja existante
		test1_menu();
	}
	else if (*choix == 'B' || *choix == 'b'){
		//saisie manuelle
		test2();
	}
	else if (*choix == 'C' || *choix == 'c'){
		//creation d'une BDD a partir d'un fichier
		test3_menu();
	}


	return 0;
}
