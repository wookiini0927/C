#include "fonction_extern.h"
#include "test1.h"
#include "test2.h"
#include "test3.h"

void menu_principal(Film film[], Personne real[], Personne acteur[], int taille_f, int taille_r, int taille_a){
    /*On choisis de quel maniere on va utiliser les BDD*/

    char choix[REPONSE];

    do{
        printf("----------------------Choix----------------------\n");
        printf("|\tA-Recherche dans une BDD predefinie\t|\n");
        printf("|\tB-Creez votre propre BDD\t\t|\n");
        printf("|\tC-Creez votre BDD a partir d'un fichier\t|\n");
        printf("|\tE-Fin du programme\t\t\t|\n");
        printf("-------------------------------------------------\n");
        
        fgets(choix,REPONSE,stdin);

    }while(*choix !='A' && *choix !='a' && *choix !='B' && *choix !='b' && *choix != 'C' && *choix != 'c' && *choix != 'E' && *choix != 'e');

    if (*choix == 'A' || *choix == 'a'){
        //BDD déja existante
        clean(choix); // evite le conflit entre la variable choix du main et la variable choix de test1.c
        test1_menu(film, real, acteur, taille_f, taille_r, taille_a);
    }
    else if (*choix == 'B' || *choix == 'b'){
        //saisie manuelle
        clean(choix);
        test2(film, real, acteur);
    }
    else if (*choix == 'C' || *choix == 'c'){
        //creation d'une BDD a partir d'un fichier
        clean(choix);
        test3_menu();
    }

    else if (*choix == 'E' || *choix == 'e'){
        //creation d'une BDD a partir d'un fichier
        clean(choix);
        exit(1);
    }   
}
