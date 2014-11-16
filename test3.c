#include "test3.h"

/*A partir d'un fichier*/

/*int main(int argc, char const *argv[])
{
	test3("./liste.film");
	return 0;
}*/

void test3_menu(){
    ;
}

int test3(const char *fic){
	FILE *fichier_ouvert;
    FILE *fichier_tmp;
	char ligne_lue[BUFFER];
	int nb_lignes =0;
	char *token, *strtmp, *cpy;
	int choix;
    int i = 0;
    int j = 0;

    Film *film = NULL;
    Personne *realisateur;
    Personne *acteur;


	do{
		printf("Type du fichier à ouvrir : \n\t1-Fichier Film\n\t2-Fichier Personne\n");
		scanf("%d",&choix);
	}while(choix != 1 && choix !=2);

	fichier_ouvert = fopen(fic, "r");

	if (fichier_ouvert != NULL){
        printf("Le fichier \"%s\" à bien été ouvert\n", fic);

        if (choix == 1){
        	while(fgets(ligne_lue, BUFFER, fichier_ouvert) != NULL){
        		nb_lignes++;
        	}

        	film = (Film*) malloc(nb_lignes * sizeof(Film));

            fseek(fichier_ouvert,0,SEEK_SET);


        	/*while(fgets(ligne_lue, BUFFER, fichier_ouvert) != NULL){

                printf("ligne_lue %d = %s\n",i,ligne_lue);

        		strtmp = ligne_lue;
                printf("tmp = %s\n",strtmp );

        		while((token = strtok(&strtmp, ","))){
                    switch(i){
                        case 0 : 
                            strcpy(cpy,token);
                            film[j].titre = cpy;
                            break;
                        case 1 : 
                            int a = atoi(token);
                            film[j].annee = a;
                            break;
                        case 2 : 
                            strcpy(cpy,token);
                            film[j].realisateur = cpy;
                            break;
                        case 3 :
                            int d = atoi(token);
                            film[j].duree = d;
                            break;
                       /* case 4:     
                            film[j].genre = ;
                        default :
                            printf("Erreur\n");
                            break;
                    }
                   printf("%s\n",token );
                   printf("==\n");
	        	}
                i++;

        	}*/

        }
        if (choix == 2){
        	while(fgets(ligne_lue, BUFFER, fichier_ouvert) != NULL){
        		strtmp = ligne_lue;

        		while((token = strsep(&strtmp, ","))){
	        		printf("%s\n",token );
	        }

       	 }
        }

        /*while(fgets(ligne_lue, BUFFER, fichier_ouvert) != NULL){
        	strtmp = ligne_lue;

        	while((token = strsep(&strtmp, ","))){
	        	printf("%s\n",token );
	        }

        	nb_lignes++;
        }*/

        printf("Il y a %d lignes\n",nb_lignes );
        
     	fclose(fichier_ouvert);

     	  }
    else{
        printf("Impossible d'ouvrir le fichier de config\n");
        return 1;
    }

       
        return 0;
  


}