#ifndef TEST2_H_INCLUDED
#define TEST2_H_INCLUDED 

#include <stdio.h>
#include <stdlib.h>
#include "film.h"
#include "date.h"
#include "personne.h"
#include "test1.h"

#define TAILLE_DEFAUT 100

void test2(Film tab[], Personne real[], Personne acteur[]);

void test2extern(Film tab[], Personne real[], Personne acteur[], int taille_film, int taille_r, int taille_act);

#endif
