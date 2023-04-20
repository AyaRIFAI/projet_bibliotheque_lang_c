#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ProtEtStructure.h"

/*Dans ce fichier, on trouve les opérations d'ajout,  de suppression,  d'affichage,  de recherche des livres existants dans le fichier "livres"
Concernant ces fonctions, ils vont intergir directement avec le fichier "livres" donc il n'auront aucun contact avec les pages web
sauf la fonction d'affichage qui va permettre aussi de changer le contenu de la page web lister mais jusqu'a maitenant, elle affiche les resultats
d'affichage dans la console mais on va l'adapter pour que ces resultats soient utilsés par la page web lister.*/
int ajouterLivreInFichier(char* nomFichier){
	Livre livre;
	Livre livreExistant;
	int newExemp;
	int pos;
	FILE* f1=fopen(nomFichier, "ab+");
	printf("Veuillez entrer le code du livre\n");
	scanf("%d", &livre.idLivre);
	if(rechercherLivreInFichier(nomFichier, livre.idLivre)!=-1){
		pos=rechercherLivreInFichier(nomFichier, livre.idLivre);
			fseek(f1, pos, 0);
			fread(&livreExistant, sizeof(Livre), 1, f1);
			printf("Ce livre existe deja dans la bibliotheque, on a %d exemplaires\n Combien d'exemplaire vous voulez ajouter?(tapez 0 sinon)\n", livreExistant.nbrExemplaire);
			scanf("%d", &newExemp);
			noyauModifier(-1,NULL, NULL, (livreExistant.nbrExemplaire)+newExemp, nomFichier, livre.idLivre);
			fclose(f1);
	}
	else{
		fflush(stdin);
		printf("Veuillez entrer l'auteur du livre\n");
		gets(livre.auteur);
		fflush(stdin);
		printf("Veuillez entrer le titre du livre\n");
		gets(livre.titreLivre);
		fflush(stdin);
		printf("Veuillez entrer le nombre exemplaire du livre\n");
		scanf("%d", &livre.nbrExemplaire);
		fflush(stdin);
		fwrite(&livre, sizeof(Livre), 1,f1);
		fclose(f1);
	}
	
}

int supprimerLivreInFichier(char* nomFichier){
	Livre livre;
	Livre livreExistant;
	int newExemp;
	int pos;
	char choix;
	FILE* f1=fopen(nomFichier, "ab+");
	if(f1!=NULL){
		printf("Veuillez entrer le code du livre\n");
	scanf("%d", &livre.idLivre);
	if(rechercherLivreInFichier(nomFichier, livre.idLivre)!=-1){
		pos=rechercherLivreInFichier(nomFichier, livre.idLivre);
			fseek(f1, pos, 0);
			fread(&livreExistant, sizeof(Livre), 1, f1);
			printf("Ce livre existe dans la bibliotheque, on a %d exemplaires\n Combien d'exemplaire vous voulez supprimer?\n", livreExistant.nbrExemplaire);
			scanf("%d", &newExemp);
			if(newExemp<livreExistant.nbrExemplaire){
				noyauModifier(-1,NULL, NULL, (livreExistant.nbrExemplaire)-newExemp, nomFichier, livre.idLivre);
				fclose(f1);
			}
			else if(newExemp==livreExistant.nbrExemplaire){
				fflush(stdin);
				printf("Pour supprimer totalement ce livre taper sur t\n Pour le garder et rendre son nombre d'exemplaire=0 tapez sur g\n");
				scanf("%c", &choix);
				if(choix=='T'|| choix=='t'){
					FILE* f2=fopen("temp.bin", "ab+");
					if(f2!=NULL){
						fseek(f1,0,0);
						while(!feof(f1)){
							if(fread(&livre, sizeof(Livre), 1, f1)!=0){
								if(livre.idLivre!=livreExistant.idLivre){
									fwrite(&livre, sizeof(Livre), 1, f2);
								}
							}
						}
						fclose(f1);
						fclose(f2);
						remove(nomFichier);
						rename("temp.bin", nomFichier);	
					}
				}
				else if(choix=='g'|| choix=='G'){
					noyauModifier(-1,NULL, NULL, (livreExistant.nbrExemplaire)-newExemp, nomFichier, livre.idLivre);
					fclose(f1);
				}
				else
					printf("veuillez entrer un choix valide"); 		
				}
			}
	
			else{
				printf("Ce livre n'existe pas dans la bibliotheque\n");
			}
	}
}
int nbrLivreDansFichier(char* nomFichier){
	Livre livre;
	int nbr=0;
	FILE* f1=fopen(nomFichier, "rb");
	if(f1==NULL)
	exit(EXIT_FAILURE);
	fflush(stdin);
	while(!feof(f1)){
		if(fread(&livre, sizeof(Livre), 1, f1)!=0){
			fflush(stdin);
			nbr++;
		}
	}
	fflush(stdin);
	fclose(f1);
	return nbr;
}
void AfficherTousLivreInFichier(char* nomFichier, Livre* T){
	int i=0;
	FILE* f1=fopen(nomFichier, "rb");
	if(f1==NULL)
	exit(EXIT_FAILURE);
		fflush(stdin);
	while(!feof(f1)){
		if(fread(&T[i], sizeof(Livre), 1, f1)!=0){
			fflush(stdin);
			i++;
		}
	}
	for(i=0; i<4;i++){
			printf("T[%d]: %d %s %s %d\n", i, T[i].idLivre, T[i].auteur, T[i].titreLivre, T[i].nbrExemplaire);
	}
	fflush(stdin);
	fclose(f1);
}
int rechercherLivreInFichier(char* nomFichier, int code){
	Livre livre;
	int pos;
	FILE* f1=fopen(nomFichier,"rb");
	while(!feof(f1)){
		if(fread(&livre, sizeof(Livre), 1, f1)!=0){
			if(livre.idLivre==code){
				pos=ftell(f1)-sizeof(Livre);
				fclose(f1);
				return pos;
			}
		}
	}
	fclose(f1);
	return -1;
}
int noyauModifier(int newCode, char* auteur, char* titreLivre, int nbrExemplaire, char* nomFichier, int codeAncien){
	Livre livre;
	int pos;
	pos=rechercherLivreInFichier(nomFichier, codeAncien);
	FILE* f1=fopen(nomFichier, "rb+");
	printf("pos1=%d\n", pos);
	fseek(f1, pos,0);
	fread(&livre, sizeof(Livre),1,f1);
	fseek(f1, pos,0);
	if(newCode!=-1){
		if((rechercherLivreInFichier(nomFichier, newCode))==-1){
			livre.idLivre=newCode;
			printf("cc1=%d\n", livre.idLivre);
		}
		else{
			printf("La modification du code de livre n'est pas possible car on aura une replication de code\n");
			return -1;
		}
	}
	if(auteur!=NULL){	
		strcpy(livre.auteur, auteur);
	}
	if(titreLivre!=NULL){
		strcpy(livre.titreLivre, titreLivre);
	}
	if(nbrExemplaire!=-1){
		livre.nbrExemplaire=nbrExemplaire;
	}
	fseek(f1, pos,0);
	fwrite(&livre, sizeof(Livre), 1, f1);
	
	fclose(f1);	
}


