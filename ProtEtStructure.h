#ifndef ProtEtStructure
#define ProtEtStructure


typedef struct{
	char nomPage[30];
	char* TLiens[10];
	char lienPerso[100];
	int dimensionTLiens;
	char* pathImage;
	char* couleurBoutton;
	char* pathImagebkGr;
	char* fontSize;
	char* colorTitre;
	int theme;
} PageHTML;


typedef struct{
	int idLivre;
	char titreLivre[30];
	char auteur[30];
	int nbrExemplaire;
}Livre;
typedef struct{
	int idEmprunteur;
	char nomEmprunteur[30];
	int siBlackList;
}Emprunteur;
typedef struct{
	int idEmprunteur;
	int idLivre;
	char dateEmpreinte[30];
}Empreinte;
typedef struct{
	char nomSite[20];
	int nbrDepage;
	char login[10];
}Site;
typedef struct{
	char motDepass[20];
	char login[10];
}Admin;

int VerfierAdmin();

char* cryptcesar(const char *mssg,int key,char *cipertext );

char* decrypte(char *cipertext,int key,char *text);

long recherche(char login[50]);

int EnregistrerDansFile();

void functionCssFormulaire(FILE* fAuthentif, char* pathImage, char* pathImagebkGr, char* couleurBoutton, char* colorTitre, char* fontSize);

int nbrLivreDansFichier(char* nomFichier);

int ajouterLivreInFichier(char* nomFichier);

void AfficherTousLivreInFichier(char* nomFichier, Livre* T);

int rechercherLivreInFichier(char* nomFichier, int code);

void fonctionNavBarCss(FILE* f1);

PageHTML initialiserPage();

void creerpageAccueil(char *str, char* nomFichier);

int gestionLienPages(char* nomPage, char* nomFichier, char** Tliens, int dimTliens);

int nbrPageDansFichier(char* nomFichier);

void MenuGestionLiens(char* nomFichier);

int rechercherPage(char* nomFichier, char* nomPage);

void creerpageGestionLivre(char *str, int theme, char* pathImage,char* color);

void AjouterLivre(char *str, int theme, char* pathImage, char* couleurBoutton,char* pathImagebkGr,char* color, char* colorTitre);

void SuppressionLivre(char *str, int theme, char* pathImage, char* couleurBoutton,char* pathImagebkGr,char* color, char* colorTitre);

void creerPageLister(char *str, Livre* T, char* pathLivres);

void CreerPageAuthentification(char *str, char* nomFichier, PageHTML p);

PageHTML miseEnPgeAuthentif(char* nomFichier, int pos);

#endif
