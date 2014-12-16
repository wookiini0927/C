#ifndef TEST3_H_INCLUDED
#define TEST3_H_INCLUDED 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include "film.h"
#include "personne.h"

#define BUFFER 128

int verification_lien(char *link, char *type);
void test3_menu();
void fichier_film(char *type);
void fichier_acteur_real(char *type);

#endif
