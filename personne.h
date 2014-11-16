#ifndef PERSONNE_H_INCLUDED
#define PERSONNE_H_INCLUDED

#include <stdio.h>
#include <string.h>

#include "date.h"

#define TAILLE 64

/************************************
DEFINITION D'UNE PERSONNE et METIER
*************************************/

typedef enum metier{
	REALISATEUR,
	ACTEUR
}Metier;

typedef struct Personne{
	char nom[TAILLE];
	char prenom[TAILLE];
	Date dob;
	char nationalite[TAILLE];
	Metier statut;
}Personne;


/******************************
FONCTIONS
*******************************/

/**
* Fonction purger et clean arevoir si l'utilisation est utile ou pas
*
**/
void purger();
void clean(char *chaine);

/**
* Enleve le retour chariot et le remplace par l'espace de la chaine
* Ameliore l'affichage
*
* Parametre chaine : chaine de caractere sur lequel on doit enlever le retour à la ligne
*
**/
void echange_chariot_espace(char *chaine);

/**
 * Saisie manuelle des personnes dans la BDD
 *
 * Paramètre personne : la personne a rajouter
 *
 **/
void saisirPersonne(Personne *personne);

/**
 * Affiche les informations de la personne
 *
 * Paramètre film : la personne dont on veut les elements.
 **/
void affichagePersonne(const Personne *personne);

/**
 * Recherche dans la BDD des personnes (acteur ou realisateur) 
 * l'acteur ou relaisateur ayant le nom ou le prenom demande
 * (affiche toute les possibilites dans nom ET prenom)
 *
 * Paramètre tab : tableau de realisateur ou acteur à parcourir.
 * Paramètre taille : taille du tableau de realisateur ou acteur.
 * Paramètre nom : trouver la fiche de la personne par son nom ou prenom
 *
 * Affiche : une liste s'il y en a plusieurs,
 *			sinon affiche la fiche direct
 * 			sinon : envoi un message d'erreur et propose de le rajouter dans la BDD
 **/
void recherchePersonne(Personne tab[], int taille, const char *nom);


/*convertie le metier de la personne en charactere
*
* Parametre statut : metier de la personne
*
* Affiche : le metier en chaine de caractere*/
void conversionMetier(Metier statut);

#endif
