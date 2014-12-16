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
* Fonction qui nettoie le buffer lors des fgets pour eviter tout conflit
*
* @src : openclassroom
**/
void purger();
void clean(char *chaine);

/**
* Enleve le retour chariot et le remplace par l'espace dans la chaine
* Ameliore l'affichage
*
* Parametre chaine : chaine de caractere sur lequel on doit enlever le retour à la ligne
*
**/
void echange_chariot_espace(char *chaine);

/**
*
* initialisation de la BDD en dur
*
* Parametre p : pointeur qui sera la case du tableau
* Param nom : nom de la personne
* Param prenom : prenom de la personne
* Param j : jour de naissance
* Param m : mois de naissance
* Param a : annee de naissance
* Param nationality : nationalite de la personne
* Param stat : metier de la personne
*
**/
void init_tableau_Personne(Personne *p, const char *nom, const char *prenom, const int j, const int m, const int a, const char *nationality, const Metier stat);

/**
 * Saisie manuelle des personnes dans la BDD
 *
 * Paramètre personne : la personne a rajouter
 *
 **/
void saisirPersonne(Personne tab[], int taille, Personne *pers);

/**
 * Affiche les informations de la personne
 *
 * Paramètre personne : la personne dont on veut les elements.
 **/
void affichagePersonne(const Personne *personne);

/**
*
* Change la chaine de caractere en minuscules
* Fonction pour pouvoir par la suite comparer sans sensitive case deux chaines
*
* Param chaine : chaine de caractere que l'on veut avoir en minuscule
*
* Retourne cette chaine en minuscule
**/
char* minuscules(const char *chaine);

/**
*
* Change la chaine de caractere en majuscules
* Fonction pour pouvoir par la suite comparer sans sensitive case deux chaines
*
* Param chaine : chaine de caractere que l'on veut avoir en majuscule
*
* Retourne cette chaine en majuscule
**/
char* majuscules(const char *chaine);

/**
 * Recherche dans la BDD des personnes (acteur ou realisateur) 
 * l'acteur ou relaisateur ayant le nom demande
 *
 * Paramètre tab : tableau de realisateur ou acteur à parcourir.
 * Paramètre taille : taille du tableau de realisateur ou acteur.
 * Paramètre nom : trouver la fiche de la personne par son nom
 * Parametre stat : precise le metier de la personne
 *
 * Affiche : une liste s'il y en a plusieurs,
 *			sinon affiche la fiche direct
 * 			sinon : envoi un message d'erreur et demande une nouvelle recherche
 **/
void rechercheNom(Personne tab[], int taille, const char *nom, Metier stat);

/**
 * Recherche dans la BDD des personnes (acteur ou realisateur) 
 * l'acteur ou relaisateur ayant le prenom demande
 *
 * Paramètre tab : tableau de realisateur ou acteur à parcourir.
 * Paramètre taille : taille du tableau de realisateur ou acteur.
 * Paramètre prenom : trouver la fiche de la personne par son prenom
 * Parametre stat : precise le metier de la personne
 *
 * Affiche : une liste s'il y en a plusieurs,
 *			sinon affiche la fiche direct
 * 			sinon : envoi un message d'erreur et demande une nouvelle recherche
 **/
void recherchePrenom(Personne tab[], int taille, const char *prenom, Metier stat);

/**
 * Recherche dans la BDD des personnes (acteur ou realisateur) 
 * les acteurs ou relaisateurs nee en l'annee donnee
 *
 * Paramètre tab : tableau de realisateur ou acteur à parcourir.
 * Paramètre taille : taille du tableau de realisateur ou acteur.
 * Paramètre chercheAnnee : trouver la fiche de la personne par son annee de naissance
 * Parametre stat : precise le metier de la personne
 * Affiche : une liste d'acteur ou realisateur nee dans l'annee demande
 * 			 sinon demande une nouvelle recherche
 *			
 **/
void recherche_naissance_Annee(Personne tab[], int taille, int chercheAnnee, Metier stat); 

/**
 * Recherche dans la BDD des personnes (acteur ou realisateur) 
 * les acteurs ou relaisateurs de la nationalite voulu
 *
 * Paramètre tab : tableau de realisateur ou acteur à parcourir.
 * Paramètre taille : taille du tableau de realisateur ou acteur.
 * Paramètre nationality : trouver la fiche de la personne par sa nationalite
 * Parametre stat : precise le metier de la personne
 * Affiche : une liste d'acteur ou realisateur de la nationalite voulu
 * 			 sinon demande une nouvelle recherche
 *			
 **/
void rechercheNationalite(Personne tab[], int taille, const char *nationality, Metier stat); 

/*convertie le metier de la personne en charactere
*
* Parametre statut : metier de la personne
*
* Affiche : le metier en chaine de caractere*/
void conversionMetier(Metier statut);

#endif
