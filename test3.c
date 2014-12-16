#include "test3.h"

/*A partir d'un fichier*/

int verification_lien(char *link, char *type){
    int verif = 0;
    regex_t lien;
    char buffer[100];

    if (*type == 'A' || *type == 'a'){

        regcomp(&lien, "[A-Za-z]*.film$", REG_EXTENDED|REG_NOSUB);
        verif = regexec(&lien, link, 0,0,0);
        regfree(&lien);
    }
    else if (*type == 'B' || *type == 'b'){
        regcomp(&lien, "[A-Za-z]*.real$", REG_EXTENDED|REG_NOSUB);
        verif = regexec(&lien, link, 0,0,0);
        regfree(&lien);
    }
    else if (*type == 'C' || *type == 'c'){
        regcomp(&lien, "[A-Za-z]*.acteur$", REG_EXTENDED|REG_NOSUB);
        verif = regexec(&lien, link, 0,0,0);
        regfree(&lien);
    }

    if(verif == 0){
        return verif;
    }
    else {
        regerror(verif,&lien,buffer, 100);
        printf("error : %s\n",buffer );
        return verif;
    }
}

void test3_menu(){

    char choix[REPONSE];

    do{
        printf("Type du fichier à ouvrir : \n\tA-Fichier Film\n\tB-Fichier Realisateur\n\tC-Fichier Acteurs\n");
        fgets(choix, REPONSE, stdin);
    }while(*choix !='A' && *choix !='a' && *choix !='B' && *choix !='b' && *choix !='C' && *choix !='c');

    echange_chariot_espace(choix);


    if (*choix == 'A' || *choix == 'a'){
        //BDD déja existante
        clean(choix); // evite le conflit entre la variable choix du main et la variable choix de test1.c
        fichier_film(choix);
    }
    else if (*choix == 'B' || *choix == 'b' || *choix == 'C' || *choix == 'c'){
        //saisie manuelle
        clean(choix);
        fichier_acteur_real(choix);
    }

}


void fichier_film(char *type){
    char link[BUFFER];
   
    do{
        printf("chemin du fichier : ");
        fgets(link, BUFFER, stdin);
        echange_chariot_espace(link);
    }while(verification_lien(link, type) != 0);

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
    
    fichier_ouvert = fopen(link, "r");

    if (fichier_ouvert != NULL){
        printf("Le fichier \"%s\" à bien été ouvert\n", link); //confirme que le fichier est ouvert et qu'on peut travailler dessus

        while(fgets(ligne_lue, BUFFER, fichier_ouvert) != NULL){ //boucle qui recupere le nombre de lignes du fichier
            nb_lignes++;
        }
        printf("Il y a %d lignes\n",nb_lignes );

       // fseek(fichier_ouvert,0,SEEK_SET); //remet au debut du fichier le pointeur
        rewind(fichier_ouvert); //remet au debut du fichier le pointeur

        while(i<nb_lignes){
            printf("i : %d\n", i );
            film = (Film*) malloc(nb_lignes * sizeof(Film)); //alloue la memoire du tableau par rapport au nombre de lignes lues

            fscanf(fichier_ouvert, "%d :%d :%d :", &titre, &genre, &nb_act);
            if (titre == 1){
                fscanf(fichier_ouvert,"%s :", film[i].titre);
            }
            if (titre == 2){
                fscanf(fichier_ouvert,"%s %s :", t1, t2);

                strcat(t1," ");
                strcpy(film[i].titre, strcat(t1, t2));

            }  

            if (titre == 3){
                fscanf(fichier_ouvert,"%s %s %s :", t1, t2, t3);

                strcat(t1," ");
                strcat(t1, t2);
                strcat(t1," ");
                strcpy(film[i].titre, strcat(t1, t3));
            }

            fscanf(fichier_ouvert,"%d :%s %s :%d :", &film[i].annee, film[i].realisateur.prenom, film[i].realisateur.nom, &film[i].duree);

            if (genre == 1){
                fscanf(fichier_ouvert,"%s :", g1);
                conv_g1 = conversionChartoEnum(g1);
                film[i].genre[0] = conv_g1;
            }
            
            if (genre == 2){
                fscanf(fichier_ouvert,"%s :%s :", g1, g2);
                conv_g1 = conversionChartoEnum(g1);
                conv_g2 = conversionChartoEnum(g2);

                film[i].genre[0] = conv_g1;
                film[i].genre[1] = conv_g2;
            }       
                    
            if(nb_act == 1){
                fscanf(fichier_ouvert, "%s %s :", film[i].casting[j].prenom, film[i].casting[j].nom);
            }

            j=0;                                      
            if(nb_act == 2){
                while(j<nb_act){
                    fscanf(fichier_ouvert, "%s %s :", film[i].casting[j].prenom, film[i].casting[j].nom);
                    j++;
                }
            }              
                
            j=0;
            if(nb_act == 3){

                while(j<nb_act){
                    fscanf(fichier_ouvert, "%s %s :", film[i].casting[j].prenom, film[i].casting[j].nom);
                    j++;
                }
            }

            affichageFilm(&film[i]);
            i++;

        }
              
    }
    else{
        printf("Impossible d'ouvrir le fichier de configuration\n");
       // return 1;
    }
    fclose(fichier_ouvert);

}

void fichier_acteur_real(char *type){

    char link[BUFFER];
   
    do{
        printf("chemin du fichier : ");
        fgets(link, BUFFER, stdin);
        echange_chariot_espace(link);
    }while(verification_lien(link, type) != 0);

    FILE *fichier_ouvert; //fichier pointeur tmp sur lequel on va travailler
    char ligne_lue[BUFFER];
    int nb_lignes =0;
    int i = 0;

    Personne *realisateur = NULL;
    Personne *acteur = NULL;
    
    fichier_ouvert = fopen(link, "r");

    if (fichier_ouvert != NULL){
        printf("Le fichier \"%s\" à bien été ouvert\n", link); //confirme que le fichier est ouvert et qu'on peut travailler dessus

        while(fgets(ligne_lue, BUFFER, fichier_ouvert) != NULL){ //boucle qui recupere le nombre de lignes du fichier
            //printf("%s\n",ligne_lue );
            nb_lignes++;
        }

        printf("Il y a %d lignes\n",nb_lignes );

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
               
        }
    }
    else{
        printf("Impossible d'ouvrir le fichier de configuration\n");
    }

    fclose(fichier_ouvert);

}


