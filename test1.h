#ifndef TEST1_H_INCLUDED
#define TEST1_H_INCLUDED 

#include <stdio.h>
#include <limits.h>
#include "film.h"
#include "personne.h"

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
* Renvoi à la fonction de recherche demander, (dans le fichier film.c)
**/
void choix1(Film tab[], int taille);

void choix_film(Film tab[], int taille);

/**
*
* Menu pour savoir quel genre est recherche
*
* Param tab : tableau des films
* Param taille : taille du tableau film
*
**/
void choix_genre(Film tab[], int taille);

/**
* Le critere de recherche se porte sur les informations d'un realisatuer
* Propose un menu sur ce qu'on peut rechercher sur un realisateur
*
* Param tab : tableau des realisateur
* Param taille : taille du tableau realisateur
*
* Renvoi à la fonction de recherche demander, (dans le fichier personne.c)
**/
void choix2(Personne tab[], int taille);

/**
* Le critere de recherche se porte sur les informations d'un(e) acteur/actrice
* Propose un menu sur ce qu'on peut rechercher sur un(e) acteur/actrice
*
* Param tab : tableau des acteur
* Param taille : taille du tableau acteur
*
* Renvoi à la fonction de recherche demander, (dans le fichier personne.c)
**/
void choix3(Personne tab[], int taille);

#endif
