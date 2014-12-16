#ifndef TEST1_H_INCLUDED
#define TEST1_H_INCLUDED 

/**
*Fichier test1.c 
*On a une BDD prealablement defini
*	Donnee rentree en dur
**/

#include <stdio.h>
#include "film.h"
#include "personne.h"

#define nettoie() system("clear");

#define TAILLE 64

/**
* Propose un menu sur le type de recherche qu'on veut faire
*
* Param tab : tableau de type film pour la bdd des film
* Param real : tableau des realisateurs
* Param acteur : tableau des acteurs
* Param taille_film : taille du tableau film
* Param taille_r : taille du tableau realisateur
* Param taille_act : taille du tableau acteur
*
* Renvoi alors un nouveau menu en fonction du choix
**/
void test1_menu(Film tab[], Personne real[], Personne acteur[], int taille_film, int taille_r, int taille_act);

/**
* Le critere de recherche se porte sur les informations d'un film
* Propose un menu sur ce qu'on peut rechercher sur un film
*
* Param tab : tableau des films
* Param taille : taille du tableau film
*
* Renvoi à la fonction intermediaire
**/
void choix1(Film tab[], Personne real[], Personne acteur[], int taille_f, int taille_r, int taille_a);

/**
* Saisie de recherche par titre
* Param tab : teableau de film
* Param taille : taille du tableau
*
* Renvoie a la fonction de recherche dans film.c
**/
void choix_film(Film tab[], Personne real[], Personne acteur[], int taille_f, int taille_r, int taille_a);

/**
* Saisie de recherche par annee de sortie de film
* Param tab : teableau de film
* Param taille : taille du tableau
*
* Renvoie a la fonction de recherche dans film.c
**/
void appelRechercheAnneeFilm(Film tab[], Personne real[], Personne acteur[], int taille_f, int taille_r, int taille_a);

/**
* Saisie de recherche de film fait par un realisateur par son nom
* Param tab : teableau de film
* Param taille : taille du tableau
*
* Renvoie a la fonction de recherche dans film.c
**/
void appelRechercheRealisateurFilm(Film tab[], Personne real[], Personne acteur[], int taille_f, int taille_r, int taille_a);

/**
* Saisie de recherche de film dans lequel a joue un acteur
* Param tab : teableau de film
* Param taille : taille du tableau
*
* Renvoie a la fonction de recherche dans film.c
**/
void appelRechercheActeurFilm(Film tab[], Personne real[], Personne acteur[], int taille_f, int taille_r, int taille_a);

/**
* Saisie de recherche par duree de film (+/- 10min)
* Param tab : teableau de film
* Param taille : taille du tableau
*
* Renvoie a la fonction de recherche dans film.c
**/
void appelRechercheDureeFilm(Film tab[], Personne real[], Personne acteur[], int taille_f, int taille_r, int taille_a);


/**
* Menu pour savoir quel genre est recherche
*
* Param tab : tableau des films
* Param taille : taille du tableau film
*
**/
void choix_genre(Film tab[], Personne real[], Personne acteur[], int taille_f, int taille_r, int taille_a);

/**
* Le critere de recherche se porte sur les informations d'un realisatuer
* Propose un menu sur ce qu'on peut rechercher sur un realisateur
*
* Param tab : tableau des realisateur
* Param taille : taille du tableau realisateur
*
* Renvoi à la fonction de recherche demander, (dans le fichier personne.c)
**/
void choix2(Personne tab[], int taille, Metier stat);

/**
* Le critere de recherche se porte sur les informations d'un(e) acteur/actrice
* Propose un menu sur ce qu'on peut rechercher sur un(e) acteur/actrice
*
* Param tab : tableau des acteur
* Param taille : taille du tableau acteur
*
* Renvoi à la fonction de recherche demander, (dans le fichier personne.c)
**/
void choix3(Personne tab[], int taille, Metier stat);


/**
* Saisie de recherche par nom
* Param tab : teableau de personne
* Param taille : taille du tableau
*
* Renvoie a la fonction de recherche dans personne.c
**/
void appelRechercheNom(Personne tab[], int taille, Metier stat);

/**
* Saisie de recherche par prenom
* Param tab : teableau de personne
* Param taille : taille du tableau
*
* Renvoie a la fonction de recherche dans personne.c
**/
void appelRecherchePrenom(Personne tab[], int taille, Metier stat);

/**
* Saisie de recherche par annee de naissance
* Param tab : teableau de personne
* Param taille : taille du tableau
*
* Renvoie a la fonction de recherche dans personne.c
**/
void appelRechercheNaissance(Personne tab[], int taille, Metier stat);

/**
* Saisie de recherche par nationalire
* Param tab : teableau de personne
* Param taille : taille du tableau
*
* Renvoie a la fonction de recherche dans personne.c
**/
void appelRechercheNationalite(Personne tab[], int taille, Metier stat);

void nouvelle_recherche(Film film[], Personne real[], Personne acteur[], int taille_f, int taille_r, int taille_a);

#endif
