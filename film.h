#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "personne.h"

/********************************
DEFINITION D'UN FILM et GENRE
*********************************/

#define TAILLE 64
#define REPONSE 2
#define T_C 4


typedef enum genre{
	AUCUN,
	ACTION,
	HORREUR,
	COMEDIE,
	DOCUMENTAIRE,
	POLICIER,
	DRAME,
	ANIMATION,
	SCIENCE_FICTION
}Genre;

typedef struct Film{
	char titre[TAILLE];
	int annee;
	Personne realisateur;
	Personne casting[T_C];
	int duree;
	Genre genre;
}Film;

/******************************
FONCTIONS
*******************************/

/**
 * Saisie manuelle des films dans la BDD
 *
 * Paramètre film : le film a rajouter
 *
 **/
void saisirFilm(Film* film);

/**
 * Affiche les informations du film
 *
 * Paramètre film : le film dont on veut les elements.
 **/
void affichageFilm(const Film *film);

/**
 * Recherche dans la BDD des films le titre du film 
 *
 * Paramètre tab : tableau de films à parcourir.
 * Paramètre taille : taille du tableau de film.
 * Paramètre chercheTitre : titre du film à trouver.
 *
 * Affiche : la fiche du film demandé 
 * sinon : envoi un message d'erreur et propose de rajotuer une nouvelle fiche
 **/
void rechercheFilm(Film tab[], int taille, char *chercheTitre);

/**
 * Recherche dans la BDD des films
 * tous les films sortie dans une annee donne
 *
 * Paramètre tab : tableau de films à parcourir.
 * Paramètre taille : taille du tableau de film.
 * Paramètre chercheAnnee : annee des film à trouver.
 *
 * Affiche : la liste des film sortie sur l'annee demande
 * sinon : envoi un message d'erreur
 **/
void rechercheAnnee(Film tab[], int taille, int chercheAnnee);

/**
 * Recherche dans la BDD des films,
 * tous les films qui dure moins qu'une duree donnee 
 *
 * Paramètre tab : tableau de films à parcourir.
 * Paramètre taille : taille du tableau de film.
 * Paramètre critDur : duree max.
 *
 * Affiche : la liste des film qui dure moins que la duree demande
 * sinon : envoi un message d'erreur
 **/
void rechercheDuree(Film tab[], int taille, int critDur);

/**
 * Recherche dans la BDD des films,
 * tous les films du genre demandé
 *
 * Paramètre tab : tableau de films à parcourir.
 * Paramètre taille : taille du tableau de film.
 * Paramètre genre : genre recherché.
 *
 * Affiche : la liste des film qui dure moins que la duree demande
 * sinon : envoi un message d'erreur
 **/
void rechercheGenre(Film tab[], int taille, const char* genre);

/**
 * Recherche dans la BDD des films,
 * tous les films du realisateur demandé
 *
 * Paramètre tab : tableau de films à parcourir.
 * Paramètre taille : taille du tableau de film.
 * Paramètre name : nom ou prenom du realisateur.
 *
 * Affiche : la liste des film fait par le realisateur
 * sinon : envoi un message d'erreur
 **/
void recherche_FilmRealisateur(Film tab[], int taille, const char *name);

/**
 * Recherche dans la BDD des films,
 * tous les films de l'acteur/actrice demandé
 *
 * Paramètre tab : tableau de films à parcourir.
 * Paramètre taille : taille du tableau de film.
 * Paramètre name : nom ou prenom du realisateur.
 *
 * Affiche : la liste des film dans lequel joue l'acteur/actrice
 * sinon : envoi un message d'erreur
 **/

void recherche_FilmActeur(Film tab[], int taille, const char *name);



/*convertie la duree rentree en minutes en heures et minutes
*	@param : film de type Film
*	parametre sur lequel on va recuperer la duree pour pouvoir convertir
*/
void conversionDuree(const Film *film);

/*convertie le genre du film en charactere
*
* Parametre genre : genre du film à convertir
*
* Affiche : le genre en chaine de caractere*/
void conversionGenre(Genre genre);




#endif
