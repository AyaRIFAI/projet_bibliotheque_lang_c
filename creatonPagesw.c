#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ProtEtStructure.h"

	void functionCssFormulaire(FILE* fAuthentif, char* pathImage, char* pathImagebkGr, char* couleurBoutton, char* colorTitre, char* fontSize){
	fprintf(fAuthentif, "<style>\n*{ padding: 0;\nmargin: 0;\n box-sizing: border-box;\n font-family: 'Quicksand' sans-serif;\n}\n body{\n width: 100%%;\nheight: 100vh;\n}\n"); 
	fprintf(fAuthentif,".container\n{ position:relative;\ndisplay: flex;\njustify-content: center;\n align-items: center;\n width: 100%%;\nheight: 100%%;\n padding: 20px 100px;\n}\n");
	fprintf(fAuthentif, ".container:after{\n content:'';\n position: absolute;\n left: 0;\n top: 0;\n width: 90%%;\n  height: 100%%;\n background: url(\"%s\") no-repeat center;\n background-size: cover;\nz-index: -1;\n filter: blur(20px);\n}\n", pathImagebkGr);
	fprintf(fAuthentif,".Contact-box{\nmax-width: 850px;\n display: grid;\n justify-content: center;\n align-items: center;\n text-align: center;\n background-color: #fff;\nbox-shadow:0px 0px 19px 5px rgba(0,0,0, 0.19);\ngrid-template-columns: repeat(2,1fr);\n}\n");
	fprintf(fAuthentif, ".left{\n background: url(\"%s\") no-repeat center;\n background-size: auto;\n margin: 20px;\n height: 500px;\n}\n", pathImage);
	fprintf(fAuthentif, ".right{\n padding: 25px 40px;\n}\n h2{\n position: relative;\n padding-bottom:10px ;\n margin-bottom: 10px;\n}\n");
	fprintf(fAuthentif, " .Titre {\n text-align: center;\n font-weight: bolder;\n font-size: 60px;\n color: %s;\n }\nh2:after{\ncontent: '';\n position: absolute;\n  left: 50%%;\n bottom: 0;\n transform: translateX(-50%%);\n height: 4px;\n width: 50px;\n}\n", colorTitre);
	fprintf(fAuthentif, ".field{\nwidth: 100%%;\n padding: 0.5rem 1rem;\n outline: none;\n border: 2px solid rgba(0, 0, 0, 0);\n background-color: rgba(230, 230, 230,0.6);\n font-size: %s;\n margin-bottom: 22px;\n transition: .3s;\n }\n", fontSize);
	fprintf(fAuthentif, ".field:hover{\n background-color: rgba(0,0,0,0.1);\n }\n .field:focus{\n background-color: #fff;\n border: 2px solid rgb(30,85,250, 0.47);\n}\n");
	fprintf(fAuthentif, " .btn{\n width: 100%%;\n padding: 0.5rem 1rem;\n font-size: 1.3rem;\n background-color: %s;\n color: #fff;\n font-weight: bolder;\n cursor: pointer;\n outline: none;\n border: none;\ntransition: .3s;\n}\n", couleurBoutton);
	fprintf(fAuthentif, ".btn:hover{\n background-color:  black;\n}\n @media screen and (max-width:880px){\n .Contact-box{\n grid-template-columns: 1fr;\n }\n.left{ \nheight: 200px;}}\n</style>\n");  
	}
	void fonctionNavBarCss(FILE* f1){
		fprintf(f1, ".navbar{position: fixed;\nheight: 80px;\nwidth: 100%%;\ntop: 0;\nleft: 0;\nbackground: rgba(0,0,0,0.4);\n}\n .navbar .logo{\nheight: 80px;\npadding: 20px 100px;\n}\n");
		fprintf(f1, ".navbar ul{\nfloat: right;\nmargin-right: 20px;\n}\n.navbar ul li{\n list-style: none;\n margin: 0 8px;\n display: inline-block;\n	line-height: 80px;\n}.navbar ul li a{\nfont-size: 20px;\nfont-family: 'Roboto', sans-serif;\ncolor: wheat;padding: 6px 13px;\ntext-decoration: none;\ntransition: .4s;\n}\n.navbar ul li a.active, .navbar ul li a:hover{\n	background:orange;\nborder-radius: 2px;\n}\n");	
	
	}
void CreerPageAuthentification(char *str, char* nomFichier, PageHTML p){
	int i=0;
	int pos;
	fflush(stdin);
	printf("Quelle nom voulez vous donner à votre page d'authentification?");
	gets(p.nomPage);
	fflush(stdin);
	printf("Quelle theme voulez vous donner à votre page d'authentification?\n1-Theme moderne\t2-Theme classique\t3-Theme d'enfants\n");
	scanf("%d", &p.theme);
	char strCopie[100];
	char strCopie2[100];
	strcpy(strCopie, str);
	strcpy(strCopie2, nomFichier);
	strcat(strCopie2, "\\pages.bin");
	strcat(strCopie,"\\Authentification.html");
	for(i=0; i<=100; i++){
		p.lienPerso[i]=strCopie[i];
	}
	//char A[]=strCopie;
	//p.lienPerso=A;
	//p.lienPerso=strCopie;
//	sprintf(p.lienPerso, "%s\\Authentification.html", str);
	printf("pathAuthent=%s\n", p.lienPerso);
	FILE* f1=fopen(p.lienPerso, "w+");
	if(f1!=NULL){
		fprintf(f1, "<!DOCTYPE html>\n<html>\n<head>\n<title>%s</title>\n<meta charset=\"utf-8\">\n<link href=\"https://fonts.googleapis.com/css2?family=Quicksand:wght@600&display=swap\">", p.nomPage);
			if(p.theme==1){
				if(p.pathImage==NULL)
				p.pathImage="../../../cleModerne.jpg";
				if(p.couleurBoutton==NULL)
				p.couleurBoutton="#0440a0";
				if(p.pathImagebkGr==NULL)
				p.pathImagebkGr= "../../../cleModerne.jpg";
				if(p.fontSize==NULL)
				p.fontSize="1.1rem";
				if(p.colorTitre==NULL)
				p.colorTitre="#0440a0";
			}
			else if(p.theme==2){
			if(p.pathImage==NULL)
			p.pathImage="../../../Cle-Ancienne-Decapsuleur-Les-Decapsuleurs-2_600x.webp";
				if(p.couleurBoutton==NULL)
				p.couleurBoutton="#c9ac35";
				if(p.pathImagebkGr==NULL)
				p.pathImagebkGr="../../../couleurdore.jpg";
				if(p.fontSize==NULL)
				p.fontSize="1.1rem";
				if(p.colorTitre==NULL)
				p.colorTitre="black";
			}
			else if(p.theme==3){
				if(p.pathImage==NULL)
				p.pathImage="../../../cleEnfant.jpg"; 
				if(p.couleurBoutton==NULL)
				p.couleurBoutton="rgb(30,85,250)";
				if(p.pathImagebkGr==NULL)
				p.pathImagebkGr="../../../backGroundColorEnf2.jpg";
				if(p.fontSize==NULL)
				p.fontSize="1.1rem";
				if(p.colorTitre==NULL)
				p.colorTitre="#0440a0";
			}
		FILE* f2=fopen(strCopie2, "ab+");
		if(f2==NULL) exit(0);
		printf("(authent)reelp2=%s\n", p.lienPerso);
		pos=rechercherPage(strCopie2, p.nomPage);
		if(pos ==-1)
		fwrite(&p, sizeof(PageHTML), 1, f2);
		else{
			fseek(f2, pos, 0);
			fwrite(&p, sizeof(PageHTML), 1, f2);
		}
		fclose(f2);
	//	printf("Ayaa le nombre de pages est(authentif): %d\n", nbrPageDansFichier(strCopie2));
		functionCssFormulaire(f1, p.pathImage, p.pathImagebkGr, p.couleurBoutton, p.colorTitre, p.fontSize);
		fprintf(f1,"</head><body>\n<div class=\"container\">\n<div class=\"Contact-box\">\n<div class=\"left\"></div><div class=\"right\">\n<h2 class=\"Titre\"> Authentification</h2>\n<input type=\"text\" class=\"field\" placeholder=\"Login\">");
		fprintf(f1, "<input type=\"text\" class=\"field\" placeholder=\"Mot de passe\">\n<input type=\"submit\" class=\"btn\" value=\"Envoyer\"></div></div></div></body></html>");
	}
	fclose(f1);
}
PageHTML miseEnPgeAuthentif(char* nomFichier, int pos){
	PageHTML p2;
	int choix=0;
	FILE* f2=fopen("C:\\projetBiblio\\aya\\biblio3\\pages.bin", "rb");
	if(f2==NULL) exit(0);
	fseek(f2, pos, 0);
	fread(&p2, sizeof(PageHTML), 1, f2);
	printf("nom=%s p2.lienPerso=%s, theme=%d\n", p2.nomPage, p2.lienPerso, p2.theme);
	printf("Le theme de %s est %d, voulez vous le changer?(1/0)\n",p2.nomPage, p2.theme );
	scanf("%d", &choix);
	if(choix==1){
		printf("Donner le nouveau theme\n");
		scanf("%d", &p2.theme);
	}
	printf("La couleur du Boutton de %s est %s, voulez vous la changer?(1/0)\n", p2.nomPage, p2.couleurBoutton);
	scanf("%d", &choix);
	if(choix==1){
		printf("Donner la nouvelle couleur du Boutton\n");
		scanf("%s", p2.couleurBoutton);
	}
	printf("La taille d'ecriture des champs de %s est %s, voulez vous la changer?(1/0)\n", p2.nomPage, p2.fontSize);
	scanf("%d", &choix);
	if(choix==1){
		printf("Donner la nouvelle taille d'ecriture \n");
		scanf("%s", p2.fontSize);
	}
	printf("La taille d'ecriture des champs de %s est %s, voulez vous la changer?(1/0)\n", p2.nomPage, p2.fontSize);
	scanf("%d", &choix);
	if(choix==1){
		printf("Donner la nouvelle taille d'ecriture \n");
		scanf("%s", p2.fontSize);
	}
	printf("La couleur du titre  de %s est %s, voulez vous la changer?(1/0)\n", p2.nomPage, p2.colorTitre);
	scanf("%d", &choix);
	if(choix==1){
		printf("Donner la nouvelle couleur du titre  \n");
		scanf("%s", p2.colorTitre);
	}
	return p2;
	fclose(f2);
}
/*void creerpageAccueil(char *str, char* nomFichier){
	PageHTML p=initialiserPage();
	int i=0;
	fflush(stdin);
	printf("Quelle nom voulez vous donner à votre page d'accueil?");
	gets(p.nomPage);
	fflush(stdin);
	printf("Quelle theme voulez vous donner à votre page d'accueil?\n1-Theme moderne\t2-Theme classique\t3-Theme d'enfants\n");
	scanf("%d", &p.theme);
	char strCopie[50];
	char strCopie2[50];
	strcpy(strCopie, str);
	strcpy(strCopie2, nomFichier);
	strcat(strCopie2, "\\pages.bin");
	strcat(strCopie,"\\accueil.html");
	//char A[]=strCopie;
//	p.lienPerso=A;
	//p.lienPerso="C:\\projetBiblio\\aya\\biblio3\\pagesHtmlCss\\accueil.html";
	//sprintf(p.lienPerso, "%s\\accueil.html", str);
	for(i=0; i<100; i++){
		p.lienPerso[i]=strCopie[i];
	}
	printf("pathAccueil=%s\n", p.lienPerso);
	FILE* f1=fopen(p.lienPerso, "w+");
	if(f1!=NULL){
		fprintf(f1, "<!DOCTYPE html>\n<html>\n<head>\n<title>%s</title>\n<meta charset=\"utf-8\">\n<link href=\"https://fonts.googleapis.com/css2?family=Quicksand:wght@600&display=swap\">", p.nomPage);
			if(p.theme==1){
				if(p.pathImage==NULL)
				p.pathImage="../../../bibliothequemoderne.jpg";
				if(p.color ==NULL)
				p.color="orange";
			}
			if(p.theme==2){
				if(p.pathImage==NULL)
				p.pathImage="../../../bibliothequeancien.jpg";
				if(p.color ==NULL)
					p.color="#c9ac35";
			}
			if(p.theme==3){
				if(p.pathImage==NULL)
				p.pathImage="../../../biblioEEnfantwholePicture.jpg"; 
				if(p.color ==NULL)
				p.color="#0062ff";
				
			}
		FILE* f2=fopen(strCopie2, "ab+");
		if(f2==NULL) exit(0);
		printf("(accruil)reelp2=%s\n", p.lienPerso);
		fwrite(&p, sizeof(PageHTML), 1, f2);
		fclose(f2);	
	//	printf("Ayaa le nombre de pages est: %d\n", nbrPageDansFichier(strCopie2));			
		fprintf(f1,"\n<style>\n@import url('https://fonts.googleapis.com/css?family=Roboto:700&display=swap');\n*{\npadding: 0;\nmargin: 0;}\n .wrapper{background: url(\"%s\") no-repeat;\nbackground-size: cover;\nheight: 100vh;\n}\n", p.pathImage);
		fprintf(f1, ".wrapper .center{\nposition: absolute;\nleft: 50%%;\ntop: 55%%;\ntransform: translate(-50%%, -50%%);\nfont-family: sans-serif;\nuser-select: none;\n}\n.center h1{\ncolor:%s;\nfont-size: 70px;\nwidth: 900px;\nfont-weight: bold;\ntext-align:center;}\n.center h2{color:%s;\nfont-size: 70px;\nfont-weight: bold;\nmargin-top: 10px;\nwidth: 885px;\ntext-align:center;\n}\na{text-decoration: none;}\n.center {margin: 35px 20px;}", p.color, p.color);
		fonctionNavBarCss(f1);
		fprintf(f1,"</style>\n</head>\n<body>\n<div class=\"wrapper\">\n<nav class=\"navbar\">\n<img class=\"logo\" src=\"../../../logo.jpg\">\n<ul>\n<li>\n<a class=\"active\" href=\"acceuil.html\" target=\"_blank\">Acceuil</a>\n</li>\n");
		fprintf(f1, "</ul>\n</nav>\n<div class=\"center\">\n<h1>Lire fait vivre</h1>\n<marquee>\n<h2>Bienvenue Dans l'Espace Administrateur</h2>\n</marquee>\n</div>\n</div>\n</body>\n</html>");
	}
	fclose(f1);
}
void creerpageGestionLivre(char *str, int theme, char* pathImage,char* color){
		char pageName[30];
	fflush(stdin);
	printf("Quelle nom voulez vous donner à votre page d'accueil?");
	gets(pageName);
	fflush(stdin);
	char strCopie[50];
	strcpy(strCopie, str);
	strcat(strCopie,"\\gestionLivre.html");
	printf("pathgestionLivre=%s\n", strCopie);
	FILE* f1=fopen(strCopie, "w+");
	if(f1!=NULL){
		char ch[]="h1";
		int var=2;
		fprintf(f1, "<!DOCTYPE html>\n<html>\n<head>\n<title>%s</title>\n<meta charset=\"utf-8\">\n<link href=\"https://fonts.googleapis.com/css2?family=Quicksand:wght@600&display=swap\">", pageName);
			if(theme==1){
				if(pathImage==NULL)
				pathImage="../../../gestiondelivre.jpg";
				if(color ==NULL)
				color="orange";
			}
			if(theme==2){
				if(pathImage==NULL)
				pathImage="../../../bibliothequeancien.jpg";
				if(color ==NULL)
					color="#c9ac35";
			}
			if(theme==3){
				if(pathImage==NULL)
				pathImage="../../../biblioEEnfantwholePicture.jpg"; 
				if(color ==NULL)
				color="#0062ff";
				
			}
						
		fprintf(f1,"\n<style>\n@import url('https://fonts.googleapis.com/css?family=Roboto:700&display=swap');\n*{\npadding: 0;\nmargin: 0;}\n .wrapper{background: url(\"%s\") no-repeat;\nbackground-size: cover;\nheight: 100vh;\n}\n", pathImage);
		fonctionNavBarCss(f1);
		fprintf(f1, ".wrapper .center{position: absolute;left: 50%%;top: 55%%;transform: translate(-50%%, -50%%);font-family: sans-serif;user-select: none;}");
		fprintf(f1,".center h1{ font-size: 80px;color:orange;width: 900px;font-weight: bold;text-align:center;}\n.center h3{color:orange;font-size: 70px;font-weight: 50px;text-align:center;justify-content: space-between;}");
		fprintf(f1, ".center .buttons{margin: 35px 280px; justify-content: space-between;}.buttons{height: 10px;width: 400px;font-size: 20px;font-weight: 600;background:orange;outline: none;cursor: pointer;border: 1px solid orange;justify-content: space-between;border-radius: 25px;margin-left: 25px;transition: .4s;}\n.buttons:hover{background: orangered;}\n a{ text-decoration: none;}");
		fprintf(f1,"</style>\n</head>\n<body>\n<div class=\"wrapper\">\n<nav class=\"navbar\">\n<img class=\"logo\" src=\"../../../logo.jpg\">\n<ul>\n<li>\n<a class=\"active\" href=\"accueil.html\" target=\"_blank\">Accueil</a>\n</li>\n");
		fprintf(f1, "</ul></nav><div class=\"center\">\n<h1>Espace Livres</h1>\n<h3><a class=\"buttons\" href=\"AjouterLivre.html\" target=\"_blank\">Ajouter Un Livre</a><br>\n</h3>\n<h3><a class=\"buttons\" href=\"#\" target=\"_blank\">Lister Les Livre</a><br></h3><h3><a class=\"buttons\" href=\"RechercheLivre.html\" target=\"_blank\">Rechercher Un Livre</a><br></h3><h3><a class=\"buttons\" href=\"SuppressionLivre.html\" target=\"_blank\">Supprimer Un Livre</a><br></h3></div></div></body></html>");	
	}
	fclose(f1);
	
}
void AjouterLivre(char *str, int theme, char* pathImage, char* couleurBoutton,char* pathImagebkGr,char* color, char* colorTitre){
	char pageName[30];
	fflush(stdin);
	printf("Quelle nom voulez vous donner à votre page d'ajout de livre?");
	gets(pageName);
	fflush(stdin);
	char strCopie[50];
	strcpy(strCopie, str);
	strcat(strCopie,"\\ajoutLivre.html");
	printf("pathAjoutLivre=%s\n", strCopie);
	FILE* f1=fopen(strCopie, "w+");
	if(f1!=NULL){
		
		fprintf(f1, "<!DOCTYPE html>\n<html>\n<head>\n<title>%s</title>\n<meta charset=\"utf-8\">\n<link href=\"https://fonts.googleapis.com/css2?family=Quicksand:wght@600&display=swap\">", pageName);
		//printf("Veuillez choisir le theme de la page web:\n1-Theme classique\n2-Theme d'enfants 3- Theme moderne\n");
		//scanf("%d", &choix);
		//if((""))
			if(theme==1){
				if(pathImage==NULL)
				pathImage="../../../ajoutLivreModerne.png";
				if(couleurBoutton==NULL)
				couleurBoutton="#0440a0";
				if(pathImagebkGr==NULL)
				pathImagebkGr="../../../cleModerne.jpg";
				if(color ==NULL)
				color="#0440a0";
				if(colorTitre==NULL)
				colorTitre="#0440a0";
			}
			if(theme==2){
				if(pathImage==NULL)
				pathImage="../../../bookCase.jpg";
				if(couleurBoutton==NULL)
				couleurBoutton="#c9ac35";
				if(pathImagebkGr==NULL)
				pathImagebkGr="../../../couleurdore.jpg";
				if(color ==NULL)
				color="#c9ac35";
				if(colorTitre==NULL)
				colorTitre="black";
			}
			if(theme==3){
				if(pathImage==NULL)
				pathImage="../../../ajoutLivreEnfant.png"; 
				if(couleurBoutton==NULL)
				couleurBoutton="rgb(30,85,250)";
				if(pathImagebkGr==NULL)
				pathImagebkGr="../../../backGroundColorEnf2.jpg";
				if(color ==NULL)
				color="#0062ff";
				if(colorTitre==NULL)
				colorTitre="#0440a0";
			}		
		functionCssFormulaire(f1, pathImage, pathImagebkGr, couleurBoutton, colorTitre);
		fprintf(f1, "</head><body>\n<div class=\"container\">\n<div class=\"Contact-box\">\n<div class=\"left\"></div><div class=\"right\">\n<h2 class=\"Titre\"> Ajouter un livre</h2>\n<input type=\"text\" class=\"field\" placeholder=\"Code du livre\">");
		fprintf(f1, "<input type=\"text\" class=\"field\" placeholder=\"Nom d'auteur\">\n<input type=\"text\" class=\"field\" placeholder=\"Titre de livre\">\n<input type=\"text\" class=\"field\" placeholder=\"Nombre d'exemplaires\"><input type=\"submit\" class=\"btn\" value=\"Ajouter\"></div></div></div></body></html>");
	}
	fclose(f1);
}


void SuppressionLivre(char *str, int theme, char* pathImage, char* couleurBoutton,char* pathImagebkGr,char* color, char* colorTitre){
	char pageName[30];
	fflush(stdin);
	printf("Quelle nom voulez vous donner à votre page de suppression de livre?");
	gets(pageName);
	fflush(stdin);
	char strCopie[50];
	strcpy(strCopie, str);
	strcat(strCopie,"\\supressLivre.html");
	printf("pathSuppLivre=%s\n", strCopie);
	FILE* f1=fopen(strCopie, "w+");
	if(f1!=NULL){
		
		fprintf(f1, "<!DOCTYPE html>\n<html>\n<head>\n<title>%s</title>\n<meta charset=\"utf-8\">\n<link href=\"https://fonts.googleapis.com/css2?family=Quicksand:wght@600&display=swap\">", pageName);
		//printf("Veuillez choisir le theme de la page web:\n1-Theme classique\n2-Theme d'enfants 3- Theme moderne\n");
		//scanf("%d", &choix);
		//if((""))
			if(theme==1){
				if(pathImage==NULL)
				pathImage="../../../suppModerne.jpg";
				if(couleurBoutton==NULL)
				couleurBoutton="#0440a0";
				if(pathImagebkGr==NULL)
				pathImagebkGr="../../../cleModerne.jpg";
				if(color ==NULL)
				color="#0440a0";
				if(colorTitre==NULL)
				colorTitre="#0440a0";
			}
			if(theme==2){
				if(pathImage==NULL)
				pathImage="../../../suppAncien.jpg";
				if(couleurBoutton==NULL)
				couleurBoutton="#c9ac35";
				if(pathImagebkGr==NULL)
				pathImagebkGr="../../../couleurdore.jpg";
				if(color ==NULL)
				color="#c9ac35";
				if(colorTitre==NULL)
				colorTitre="black";
			}
			if(theme==3){
				if(pathImage==NULL)
				pathImage="../../../suppEnfantLivre2.jpg"; 
				if(couleurBoutton==NULL)
				couleurBoutton="rgb(30,85,250)";
				if(pathImagebkGr==NULL)
				pathImagebkGr="../../../backGroundColorEnf2.jpg";
				if(color ==NULL)
				color="#0062ff";
				if(colorTitre==NULL)
				colorTitre="#0440a0";
			}		
		functionCssFormulaire(f1, pathImage, pathImagebkGr, couleurBoutton, colorTitre);
		fprintf(f1, "</head><body>\n<div class=\"container\">\n<div class=\"Contact-box\">\n<div class=\"left\"></div><div class=\"right\">\n<h2 class=\"Titre\"> Supprimer un livre</h2>\n<input type=\"text\" class=\"field\" placeholder=\"Code du livre\">");
		fprintf(f1, "\n<input type=\"submit\" class=\"btn\" value=\"Supprimer\"></div></div></div></body></html>");
	}
	fclose(f1);
}
void rechercherLivre(char *str, int theme, char* pathImage, char* couleurBoutton,char* pathImagebkGr,char* color, char* colorTitre){
	char pageName[30];
	fflush(stdin);
	printf("Quelle nom voulez vous donner à votre page de recherche de livre?");
	gets(pageName);
	fflush(stdin);
	char strCopie[50];
	strcpy(strCopie, str);
	strcat(strCopie,"\\rechercherLivre.html");
	printf("pathRechLivre=%s\n", strCopie);
	FILE* f1=fopen(strCopie, "w+");
	if(f1!=NULL){
		
		fprintf(f1, "<!DOCTYPE html>\n<html>\n<head>\n<title>%s</title>\n<meta charset=\"utf-8\">\n<link href=\"https://fonts.googleapis.com/css2?family=Quicksand:wght@600&display=swap\">", pageName);
		//printf("Veuillez choisir le theme de la page web:\n1-Theme classique\n2-Theme d'enfants 3- Theme moderne\n");
		//scanf("%d", &choix);
		//if((""))
			if(theme==1){
				if(pathImage==NULL)
				pathImage="../../../rechLivreModerne.png";
				if(couleurBoutton==NULL)
				couleurBoutton="#0440a0";
				if(pathImagebkGr==NULL)
				pathImagebkGr="../../../cleModerne.jpg";
				if(color ==NULL)
				color="#0440a0";
				if(colorTitre==NULL)
				colorTitre="#0440a0";
			}
			if(theme==2){
				if(pathImage==NULL)
				pathImage="../../../rechercherLivre.png";
				if(couleurBoutton==NULL)
				couleurBoutton="#c9ac35";
				if(pathImagebkGr==NULL)
				pathImagebkGr="../../../couleurdore.jpg";
				if(color ==NULL)
				color="#c9ac35";
				if(colorTitre==NULL)
				colorTitre="black";
			}
			if(theme==3){
				if(pathImage==NULL)
				pathImage="../../../loupeEnfant.png"; 
				if(couleurBoutton==NULL)
				couleurBoutton="rgb(30,85,250)";
				if(pathImagebkGr==NULL)
				pathImagebkGr="../../../backGroundColorEnf2.jpg";
				if(color ==NULL)
				color="#0062ff";
				if(colorTitre==NULL)
				colorTitre="#0440a0";
			}		
		functionCssFormulaire(f1, pathImage, pathImagebkGr, couleurBoutton, colorTitre);
		fprintf(f1, "</head><body>\n<div class=\"container\">\n<div class=\"Contact-box\">\n<div class=\"left\"></div><div class=\"right\">\n<h2 class=\"Titre\"> Rechercher un livre</h2>\n<input type=\"text\" class=\"field\" placeholder=\"Code du livre\">");
		fprintf(f1, "\n<input type=\"submit\" class=\"btn\" value=\"Rechercher\"></div></div></div></body></html>");
	}
	fclose(f1);
}


void creerPageLister(char *str, Livre* T, char* pathLivres){
	int nbr=nbrLivreDansFichier(pathLivres);
	AfficherTousLivreInFichier(pathLivres,T);
	char pageName[30];
	int i=0;
	char strCopie[50];
	strcpy(strCopie, str);
	strcat(strCopie,"\\Lister.html");
	FILE* fLister=fopen(strCopie, "w+");
	if(fLister==NULL)
	exit(EXIT_FAILURE);
	printf("Veuillez entrer le nom de votre page\n");
	scanf("%s", pageName);
	fprintf(fLister, "<!DOCTYPE html>\n<html>\n<head>\n<title>%s</title>\n<meta charset=\"utf-8\">\n<link href=\"https://fonts.googleapis.com/css2?family=Quicksand:wght@600&display=swap\"><style>*, ::before, ::after{ box-sizing: border-box; margin: 0; padding: 0;}", pageName);
	fprintf(fLister,"body{ height: 100vh; font-family: Arial, Helvetica, sans-serif; background: url('../../../bk7.jpeg') no-repeat; background-size: cover;}.tableau-style { border-collapse: collapse; min-width: 400px; width: auto; box-shadow: 0 5px 50px rgba(0,0,0,0,15); cursor: pointer; margin: 100px auto; border: 1px solid #ddd;}");
	fprintf(fLister, "thead tr{\nbackground-color: midnightblue;\n color: #fff;\n text-align: left;\n}\n th, td {\n padding: 15px 20px;\n }\n tbody tr, td, th {\nborder: 1px solid #ddd;\n}\n");
	fprintf(fLister, "tbody tr:nth-child(even){\nbackground-color: #f3f3f3; \n}\ntbody tr:last-of-type{border-bottom: 2px solid midnightblue;\n}\nh1{ color:midnightblue; text-align: center;}\n table{ margin: auto; background-color: #f09b56;}</style>");
	fprintf(fLister, "</head><body><h1>Liste de tous les livres</h1><br><br>\n<table class=\"tableauStyle\">\n<thead><tr>\n<th>Code de livre</th>\n<th>Auteur de livre</th>\n<th>Titre du livre</th>\n<th>Nombre d'exemplaire</th>\n</tr></thead><tbody>");
	for(i=0; i<nbr; i++){
		fprintf(fLister, "<tr>\n<td>%d</td>\n<td>%s</td>\n<td>%s</td>\n<td>%d</td>\n</tr>\n", T[i].idLivre, T[i].auteur, T[i].titreLivre, T[i].nbrExemplaire);
	}
	fprintf(fLister, "</tbody></table></body></html>");
	fclose(fLister);
}*/
