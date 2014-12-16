#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "personne.h"

/**********************************
** DEFINITION D'UN FILM et GENRE **
***********************************/

#define TAILLE 64
#define REPONSE 2
#define T_C 4


typedef enum Genre{
	AUCUN,
	ACTION,
	HORREUR,
	COMEDIE,
	FANTASTIQUE,
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
	Genre genre[2];
}Film;

/******************************
**         FONCTIONS         **
*******************************/

/**
* initialisation de la BDD en dur
*
* Parametre f : pointeur qui sera la case du tableau
* Param titre : titre du film
* Param date : annee de sortie
* Param real : case du tableau correspondant au realisateur
* Param duree : duree du film
* Param genre : Genre du film
* Param a1 : acteur 1
* Param a2 : acteur 2
* Param a3 : acteur 3
* Param a4 : acteur 4
**/
void init_tableau_film(Film *f, const char *titre, const int date, Personne *real, const int duree, const Genre g1, const Genre g2, Personne *a1, Personne *a2, Personne *a3, Personne *a4);

/**
 * Saisie manuelle des films dans la BDD
 *
 * Param tab : tableau de film sur lequel on rajoute la nouvelle fiche
 * Param real : tableau de realisateur
 * Param act : tableau d'acteur
 * Param taille_f : taille utile du tableau film
 * Param taille_r : taille utile du tableau realisateur
 * Param taille_a : taille utile du tableau acteur
 * Param film : pointeur de type Film, temporaire
 * 
 * Enregistre le pointeur temporaire dans le tableau film au rang taille_f
 **/
void saisirFilm(Film tab[], Personne real[], Personne act[], int taille_f, int taille_r, int taille_a, Film* film);

/**
 * Affiche les informations du film
 *
 * Paramètre film : le film dont on veut les elements.
 **/
void affichageFilm(const Film *film);

/**
 * Recherche dans la BDD des films le titre du film 
 * Affiche : la fiche du film demandé 
 * sinon : envoi un message d'erreur et propose de rajotuer une nouvelle fiche
 *
 * Paramètre tab : tableau de films à parcourir.
 * Param real : tableau de realisateur
 * Param act : tableau d'acteur
 * Param taille_f : taille utile du tableau film
 * Param taille_r : taille utile du tableau realisateur
 * Param taille_a : taille utile du tableau acteur
 * Param chercheTitre : titre recherche
 *
 * retourne 1 si la recherche a abouti
 * sinon 0 
 **/
int rechercheFilm(Film tab[], Personne real[], Personne acteur[], int taille_f, int taille_r, int taille_a, char *chercheTitre);

/**
 * Recherche dans la BDD des films
 * tous les films sortie dans une annee donne
 *
 * Paramètre tab : tableau de films à parcourir.
 * Param real : tableau de realisateur
 * Param act : tableau d'acteur
 * Param taille_f : taille utile du tableau film
 * Param taille_r : taille utile du tableau realisateur
 * Param taille_a : taille utile du tableau acteur
 * Paramètre chercheAnnee : annee des film à trouver.
 *
 * Affiche : la liste des film sortie sur l'annee demande
 * sinon : envoi un message d'erreur
 **/
void rechercheAnnee(Film tab[], Personne real[], Personne acteur[], int taille_f, int taille_r, int taille_a, int chercheAnnee);

/**
 * Recherche dans la BDD des films,
 * tous les films qui dure moins qu'une duree donnee 
 *
 * Paramètre tab : tableau de films à parcourir.
 * Param real : tableau de realisateur
 * Param act : tableau d'acteur
 * Param taille_f : taille utile du tableau film
 * Param taille_r : taille utile du tableau realisateur
 * Param taille_a : taille utile du tableau acteur
 * Paramètre critDur : duree max.
 *
 * Affiche : la liste des film qui dure plus ou moins 10min que la duree demande
 * sinon : envoi un message d'erreur
 **/
void rechercheDuree(Film tab[], Personne real[], Personne acteur[], int taille_f, int taille_r, int taille_a, int critDur);

/**
 * Recherche dans la BDD des films,
 * tous les films du genre demandé
 *
 * Paramètre tab : tableau de films à parcourir.
 * Param real : tableau de realisateur
 * Param act : tableau d'acteur
 * Param taille_f : taille utile du tableau film
 * Param taille_r : taille utile du tableau realisateur
 * Param taille_a : taille utile du tableau acteur
 * Paramètre genre : genre recherché.
 *
 * Affiche : la liste des film qui dure moins que la duree demande
 * sinon : envoi un message d'erreur
 **/
void rechercheGenre(Film tab[], Personne real[], Personne acteur[], int taille_f, int taille_r, int taille_a, Genre genre);

/**
 * Recherche dans la BDD des films,
 * tous les films du realisateur demandé
 *
 * Paramètre tab : tableau de films à parcourir.
 * Param real : tableau de realisateur
 * Param act : tableau d'acteur
 * Param taille_f : taille utile du tableau film
 * Param taille_r : taille utile du tableau realisateur
 * Param taille_a : taille utile du tableau acteur
 * Paramètre name : nom ou prenom du realisateur.
 *
 * Affiche : la liste des film fait par le realisateur
 * sinon : envoi un message d'erreur
 **/
void recherche_FilmRealisateur(Film tab[], Personne real[], Personne acteur[], int taille_f, int taille_r, int taille_a, const char *name);

/**
 * Recherche dans la BDD des films,
 * tous les films de l'acteur/actrice demandé
 *
 * Paramètre tab : tableau de films à parcourir.
 * Param real : tableau de realisateur
 * Param act : tableau d'acteur
 * Param taille_f : taille utile du tableau film
 * Param taille_r : taille utile du tableau realisateur
 * Param taille_a : taille utile du tableau acteur
 * Paramètre name : nom ou prenom du realisateur.
 *
 * Affiche : la liste des film dans lequel joue l'acteur/actrice
 * sinon : envoi un message d'erreur
 **/
void recherche_FilmActeur(Film tab[], Personne real[], Personne acteur[], int taille_f, int taille_r, int taille_a, const char *name);

/**
* convertie la duree rentree en minutes en heures et minutes
* Param film :  type Film
**/
void conversionDuree(const Film *film);

/**
* convertie le genre du film en charactere
*
* Parametre genre : genre du film à convertir
*
* Affiche : le genre en chaine de caractere
**/
void conversionGenre(Genre genre);

/**
*
*@src: commentcamarche.net
*
**/
Genre conversionChartoEnum(const char *string_genre);

#endif
