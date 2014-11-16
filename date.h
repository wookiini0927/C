#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/************************************
*
*	Fichier dépendant de personne.c
*
*************************************/

/********************************
DEFINITION D'UNE DATE
*********************************/
typedef struct Date{
	int jour;
	int mois;
	int annee;
}Date;



/******************************
FONCTIONS
*******************************/

/**
* Verifie si la chaine de caractere rentré est bien un chiffre
*
* Parametre d : chaine de caractere a verifier
*
* Resultat : retourn 1 si c'est bien toute la chaine est composé de chiffre
*			Sinon 0 
*
**/
int verification_digit(const char *d);

/**
 * Saisie manuelle de la date de naissance d'une personne
 *
 * Paramètre d : date de naissance a rajouter
 *
 **/
void saisirDate(Date *d);

/**
 * Affiche la date de naissance d'une personne
 *
 * Paramètre d : date de naissance à afficher
 *.
 **/
void affichageDate(const Date *d);

/**
 * Dans la BDD, la date de naissance du mois est un int
 * A l'affichage on aura le mois correspondant en toute lettre
 *
 * Paramètre mois : le mois a convertir
 *
 **/
void conversionMois(int mois);

/**
* Je sais pas encore a quoi ca sert ....
* 
* Parametre d1 : premiere date a comparer
* Parametre d2 : deuxieme date a comparer a d1
*
**/
int comparaisonDate(const Date *d1, const Date *d2);


#endif
