#include "test2.h"
/*rentrer par l'utilisateur*/

void test2(Film film[], Personne real[], Personne acteur[]){

	char choix[REPONSE];
	char rep[REPONSE];
	Film tmp;
	Personne real_tmp;
	Personne act_tmp;

	int i = 0; //compteur pour le tableau film.casting;
	/*int j = 0; //compteur pour le tableau real;
	int k = 0; //compteur pour le tableau act;*/

	int arret = 1; /* continu la saisie
					* 0 arrete la saisie
					*/

	int taille_utile_test2_film = 11; //pour savoir ou en est la taille du tableau film
    int taille_utile_test2_real = 17; //pour savoir ou en est la taille du tableau real
    int taille_utile_test2_acteur = 36; // pour savoir ou en est la taille du tableau act


	do{
		do{
			do{
				printf("-------------Saisie--------------\n|\tA-Film\t\t\t|\n|\tB-Realisateur\t\t|\n|\tC-Acteur/Actrice\t|\n");
				printf("---------------------------------\n");

				fgets(choix, REPONSE, stdin);
			}while(*choix !='A' && *choix !='a' && *choix !='B' && *choix !='b' && *choix != 'C' && *choix != 'c');

			if (*choix == 'A' || *choix == 'a'){
				clean(choix);
				saisirFilm(film, real, acteur, taille_utile_test2_film, taille_utile_test2_real, taille_utile_test2_acteur, &tmp);
				init_tableau_Personne(&real[taille_utile_test2_real], film[taille_utile_test2_film].realisateur.nom, film[taille_utile_test2_film].realisateur.prenom, film[taille_utile_test2_film].realisateur.dob.jour, film[taille_utile_test2_film].realisateur.dob.mois, film[taille_utile_test2_film].realisateur.dob.annee, film[taille_utile_test2_film].realisateur.nationalite, film[taille_utile_test2_film].realisateur.statut);

				//affichageFilm(&film[taille_utile_test2_film]);
				taille_utile_test2_film++;
				taille_utile_test2_real++;

			}
			else if (*choix == 'B' || *choix == 'b'){
				clean(choix);
				saisirPersonne(real, taille_utile_test2_real, &real_tmp);
				taille_utile_test2_real++;
			}
			else if (*choix == 'C' || *choix == 'c'){
				clean(choix);
				saisirPersonne(acteur, taille_utile_test2_acteur, &act_tmp);
				taille_utile_test2_acteur++;
			}
			clean(choix);

			printf("Voulez-vous saisir une nouvelle entree? (o/n)\n");
			fgets(rep, REPONSE, stdin);

			if(rep[0] == 'o' || rep[0] == 'O'){
				echange_chariot_espace(rep);

				arret = 1;
				clean(rep);
			}
			else if (rep[0] == 'n' || rep[0] == 'N'){
				echange_chariot_espace(rep);
				arret = 0;
				test2extern(film, real,acteur, taille_utile_test2_film,taille_utile_test2_real,taille_utile_test2_acteur);
				clean(rep);
			}
		
		}while(*rep == 'o' && *rep == 'O' && *rep =='n' && *rep =='N');
	}while(arret==1);

	/*saisirFilm(&film[0]);
	affichageFilm(&film[0]);*/

}

void test2extern(Film film[], Personne real[], Personne acteur[], int taille_film, int taille_r, int taille_act){
	nettoie();
    char choix[REPONSE];
    clean(choix);

    do{
        printf("Une nouvelle base de donnees a ete définie, voulez vous faire une recherche ?\n");
        printf("N-Non, fin du programme\n");
        printf("O-Oui, faire une recherche sur la base de donnees\n");

        fgets(choix,REPONSE,stdin);

    }while(*choix !='O' && *choix !='o' && *choix !='N' && *choix !='n');

    if (*choix == 'O' || *choix == 'o'){
       // stop = 1;
        clean(choix);
        test1_menu(film, real, acteur, taille_film, taille_r, taille_act);
    }
    else if (*choix == 'N' || *choix == 'n'){
       // stop = 0;
        clean(choix);
        exit(0);
    }

}

