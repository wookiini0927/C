#include "test3.h"

/*A partir d'un fichier*/

void test3_menu(){

    char choix[REPONSE];
    char link[BUFFER];

    do{
        printf("Type du fichier à ouvrir : \n\tA-Fichier Film\n\tB-Fichier Personne\n\tC-Fichier Acteurs\n");
        fgets(choix, REPONSE, stdin);
    }while(*choix !='A' && *choix !='a' && *choix !='B' && *choix !='b' && *choix !='C' && *choix !='c');

        clean(choix);
        printf("chemin du fichier : ");
        fgets(link, BUFFER, stdin);
        echange_chariot_espace(link);

        test3(link, choix);
}

void test3(const char *fic, char *type){

	FILE *fichier_ouvert; //fichier pointeur tmp sur lequel on va travailler
	char ligne_lue[BUFFER];
    char t1[BUFFER], t2[BUFFER], t3[BUFFER];
    char g1[BUFFER], g2[BUFFER];
	int nb_lignes =0;
    int titre = 0;
    int genre = 0;
    int conv_g1 =0, conv_g2 = 0;
    int nb_act = 0;
    int i = 0;
    int j = 0;

    Film *film = NULL;
    Personne *realisateur = NULL;
    Personne *acteur = NULL;
	
	fichier_ouvert = fopen(fic, "r");

	if (fichier_ouvert != NULL){
        printf("Le fichier \"%s\" à bien été ouvert\n", fic); //confirme que le fichier est ouvert et qu'on peut travailler dessus

        	while(fgets(ligne_lue, BUFFER, fichier_ouvert) != NULL){ //boucle qui recupere le nombre de lignes du fichier
                //printf("%s\n",ligne_lue );
        		nb_lignes++;
        	}

           // fseek(fichier_ouvert,0,SEEK_SET); //remet au debut du fichier le pointeur
            rewind(fichier_ouvert); //remet au debut du fichier le pointeur


        	while(i<nb_lignes){

                if(*type == 'c' || *type == 'C'){

                    acteur = (Personne*) malloc(nb_lignes * sizeof(Personne)); //alloue la memoire du tableau par rapport au nombre de lignes lues

                    fscanf(fichier_ouvert, "%s ,%s ,%d ,%d ,%d ,%s ", acteur[i].prenom, acteur[i].nom, &acteur[i].dob.jour, &acteur[i].dob.mois, &acteur[i].dob.annee, acteur[i].nationalite);

                    acteur[i].statut = 1;
            
                    affichagePersonne(&acteur[i]);

                    i++;
                }

                if(*type == 'b' || *type == 'B'){
                    
                    realisateur = (Personne*) malloc(nb_lignes * sizeof(Personne)); //alloue la memoire du tableau par rapport au nombre de lignes lues

                    fscanf(fichier_ouvert, "%s ,%s ,%d ,%d ,%d ,%s ", realisateur[i].prenom, realisateur[i].nom, &realisateur[i].dob.jour, &realisateur[i].dob.mois, &realisateur[i].dob.annee, realisateur[i].nationalite);

                    realisateur[i].statut = 0;
            
                    affichagePersonne(&realisateur[i]);

                    i++;
                }

                if(*type == 'a' || *type == 'A'){
                    
                    film = (Film*) malloc(nb_lignes * sizeof(Film)); //alloue la memoire du tableau par rapport au nombre de lignes lues

                    fscanf(fichier_ouvert, "%d :%d :%d :", &titre, &genre, &nb_act);
                    
                    if (titre == 1){
                        printf("dkdjg\n");
                        if (genre == 1){
                             if(nb_act == 2){
                                fscanf(fichier_ouvert,"%s :%d :%s %s :%d :%s :", film[i].titre, &film[i].annee, film[i].realisateur.prenom, film[i].realisateur.nom, &film[i].duree, g1);
                                while(j<nb_act){
                                    fscanf(fichier_ouvert, "%s %s ", film[i].casting[j].prenom, film[i].casting[j].nom);
                                    j++;
                                }

                                conv_g1 = conversionChartoEnum(g1);
                                conv_g2 = conversionChartoEnum(g2);

                                film[i].genre[0] = conv_g1;
                                film[i].genre[1] = conv_g2;
                                affichageFilm(&film[i]);
                            }
                        }
                        if (genre == 2){
                            printf("dfkjjg\n");
                             if(nb_act == 3){

                                fscanf(fichier_ouvert,"%s :%d :%s %s :%d :%s :%s :", film[i].titre, &film[i].annee, film[i].realisateur.prenom, film[i].realisateur.nom, &film[i].duree, g1, g2);
                                while(j<nb_act){
                                    fscanf(fichier_ouvert, "%s %s :", film[i].casting[j].prenom, film[i].casting[j].nom);
                                    j++;
                                }

                                conv_g1 = conversionChartoEnum(g1);
                                conv_g2 = conversionChartoEnum(g2);

                                film[i].genre[0] = conv_g1;
                                film[i].genre[1] = conv_g2;
                                 printf("conv %d\n", conv_g1 );

                                affichageFilm(&film[i]);
                            }
                        }
                    }
                    printf("%d %d %d\n", titre, genre, nb_act);
                   // affichageFilm(&film[i]);

                    i++;
                }

            }


        printf("Il y a %d lignes\n",nb_lignes );
        
     	fclose(fichier_ouvert);

    }
    else{
        printf("Impossible d'ouvrir le fichier de configuration\n");
       // return 1;
    }

       
      //  return 0;

}

Genre conversionChartoEnum(const char *string_genre){

    int i =0;

    static struct{
        const char *chaine;
        Genre g;
    }hashmap[] = {{"ACTION", ACTION},{"HORREUR", HORREUR},{"COMEDIE",COMEDIE},{"DOCUMENTAIRE",DOCUMENTAIRE},{"POLICIER",POLICIER}, {"DRAME",DRAME}, {"ANIMATION", ANIMATION}, {"SCIENCE_FICTION", SCIENCE_FICTION}};

    while(strcmp(string_genre, hashmap[i].chaine) != 0){
        i++;
    }

    return hashmap[i].g;


}
