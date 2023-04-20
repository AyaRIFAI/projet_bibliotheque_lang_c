#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ProtEtStructure.h"

char menu(){
	printf("Si vous voulez s\'identifier tapper a\n");
	printf("Si vous voulez Quiter taper q\n");
	printf("Entrer votre choix: \n");
	return getchar();
	
}
char menuPrincipal(){
	printf("__Gestion des livres ___ 1\n") ;
	printf("__Gestion des emprunteurs ___2\n") ;
	printf("__Importer un fichier html___ 3\n") ;
	printf("__Exporter un fichier html vers fichier Excell___ 4\n") ;
	printf("__Exporter un fichier html vers fichier texte___ 5\n") ;
	printf("__Stocker un fichier html dans une liste doublement chainee___ 6\n") ;
	printf("__Crer la page d'authentification de votre site___ 7\n") ;
	printf("__Crer la page d'accueil___ 8\n");
	printf("__Gestion des liens entre les pages web___ 9\n") ;
	printf("__quitter ___10\n") ;
	printf("entrer votre choix : ") ;
	return getchar();
}
char menuSite(){
	printf("Pour créer un nouveau site, tapez sur n\nSi vous voulez gerer un site existant tapez sur e\n");
	return getchar();
	}

int main(int argc, char *argv[]) {
	//char login[50];
	//char motdepasse[50];
	//char lecture[50];
	//char cripertext[50];
//    char decryptmot[50];
//    char motdpasse[50];
    char choix;
    Livre T[100];
    int theme;
     char choix2;
     char nomSite[20];
    char pathSystem[50]="mkdir C:\\projetFinalLangc\\";
    char pathPagesWeb[50];
     char pathLivres[50];
     char pathEmprunteur[50];
    char pathNomSite[50]="C:\\projetFinalLangc\\";
    do{
    fflush(stdin);
    choix = menu();
    char loginAdmin[50];
    switch(choix){
    		
    	case 'a' : 
					if(VerfierAdmin(loginAdmin)){ 
					printf("la login: %s\n", loginAdmin);
					strcat(pathSystem, loginAdmin);
					strcat(pathNomSite, loginAdmin);
					system(pathSystem);
					strcat(pathSystem,"\\");
					strcat(pathNomSite,"\\");
					choix2=menuSite();
					switch(choix2){
						case 'n':
							printf("Veuillez entrer le nom de votre site\n");
							scanf("%s", nomSite);
							fflush(stdin);
							strcat(pathSystem, nomSite);
							strcat(pathNomSite, nomSite);
							system(pathSystem);
							strcpy(pathPagesWeb, pathNomSite);
							strcat(pathPagesWeb, "\\pagesHtmlCss");
							strcat(pathSystem, "\\pagesHtmlCss");
							printf("pathPagesWeb=%s\n", pathPagesWeb);
							system(pathSystem);
							printf("On va maintenant créer votre page d'authentification et d'accueil'\n");
							strcpy(pathLivres, pathNomSite);
							strcat(pathLivres, "\\livres.bin");
							//creerpageAccueil(pathPagesWeb, pathNomSite);
							PageHTML p=initialiserPage();
							CreerPageAuthentification(pathPagesWeb, pathNomSite, p);
							
							//creerpageGestionLivre(pathPagesWeb, theme,NULL, NULL);
							//ajouterLivreInFichier(pathLivres);
							//supprimerLivreInFichier(pathLivres);
							//creerPageLister(pathPagesWeb, T, pathLivres);
							//printf("Veuillez entrer le theme de votre choix(pour la page d'identifiation'):\n1-theme moderne\t2-Theme ancien\t3-theme enfantin\n");
							//scanf("%d", &theme);
							//CreerPageAuthentification(pathPagesWeb, theme, NULL, NULL, NULL,NULL, NULL);
							//printf("Veuillez entrer le theme de votre choix(pour la page de suppression de livres):\n1-theme moderne\t2-Theme ancien\t3-theme enfantin\n");
							//scanf("%d", &theme);
							//SuppressionLivre(pathPagesWeb, theme, NULL, NULL , NULL,NULL, NULL);
//							printf("Veuillez entrer le theme de votre choix(pour la page d'ajout de livres):\n1-theme moderne\t2-Theme ancien\t3-theme enfantin\n");
//							scanf("%d", &theme);
//							AjouterLivre(pathPagesWeb, theme, NULL, NULL , NULL,NULL, NULL);
//							printf("Veuillez entrer le theme de votre choix(pour la page de recherche de livres):\n1-theme moderne\t2-Theme ancien\t3-theme enfantin\n");
//							scanf("%d", &theme);
							//rechercherLivre(pathPagesWeb, theme, NULL, NULL , NULL,NULL, NULL);
						//	printf("%s\n", pathNomSite);
							
						/*	char name[20];
							PageHTML p2;
//								printf("donne name\n");
//								fflush(stdin);
//								gets(name);
								fflush(stdin);
								FILE* f2=fopen("C:\\projetBiblio\\aya\\biblio3\\pages.bin", "rb");
								if(f2==NULL) exit(0);
								int pos=rechercherPage("C:\\projetBiblio\\aya\\biblio3\\pages.bin", "sara");
								fseek(f2, pos, 0);
								fread(&p2, sizeof(PageHTML), 1, f2);
								printf("nom=%s p2.lienPerso=%s, theme=%d\n", p2.nomPage, p2.lienPerso, p2.theme);
								fclose(f2);*/
								//MenuGestionLiens("C:\\projetBiblio\\aya\\biblio3\\pages.bin");
							//on a suivi le scénario 2, on commence par la creation de la page d'authentification
							menuPrincipal();
							break;
						case 'e':
						//on n'a pas encore traite ce choix
						break;
					}
					}
					
			 		break;//menu aya
    	case 'q' : printf("Merci Pour Votre Visite\n");
				 	break;    			
    	default :  printf("Merci de donner un choix valide\n");
					break;
		}
	}while(choix != 'q');
	return 0;
}
