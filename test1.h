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
* Renvoi alors un nouveau menu en fonction du choix
**/
void test1_menu();

/**
* Le critere de recherche se porte sur les informations d'un film
* Propose un menu sur ce qu'on peut rechercher sur un film
*
* Renvoi à la fonction de recherche demander, (dans le fichier film.c)
**/
void choix1();

/**
* Le critere de recherche se porte sur les informations d'un realisatuer
* Propose un menu sur ce qu'on peut rechercher sur un realisateur
*
* Renvoi à la fonction de recherche demander, (dans le fichier personne.c)
**/
void choix2();

/**
* Le critere de recherche se porte sur les informations d'un(e) acteur/actrice
* Propose un menu sur ce qu'on peut rechercher sur un(e) acteur/actrice
*
* Renvoi à la fonction de recherche demander, (dans le fichier personne.c)
**/
void choix3();

#endif
