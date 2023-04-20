#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ProtEtStructure.h"

/*PageHTML initialiserPage(){
	PageHTML p;
	p.color[0]='\0';
	p.colorTitre[0]='\0';
	p.couleurBoutton[0]='\0';
	p.dimensionTsucc=0;
	p.pathImage[0]='\0';
	p.pathImagebkGr[0]='\0';
	p.theme=0;
	return p;
}*/
PageHTML initialiserPage(){
	PageHTML p;
	p.fontSize= NULL;
	p.colorTitre=NULL;
	p.couleurBoutton=NULL;
	p.dimensionTLiens=0;
	p.pathImage=NULL;
	p.pathImagebkGr=NULL;
	p.theme=0;
//	p.lienPerso=NULL;
	return p;
}
int rechercherPage(char* nomFichier, char* nomPage){
	PageHTML p;
	int pos;
	FILE* f1=fopen(nomFichier,"rb");
	while(!feof(f1)){
		if(fread(&p, sizeof(PageHTML), 1, f1)!=0){
			//printf("nomPage=%s rechercherlienperso=%s p.theme=%d\n",p.nomPage, p.lienPerso, p.theme);
			if(!strcmp(p.nomPage, nomPage)){
				pos=ftell(f1)-sizeof(PageHTML);
				fclose(f1);
				return pos;
			}
		}
	}
	fclose(f1);
	return -1;
}

void MenuGestionLiens(char* nomFichier){
	int i=0;
	PageHTML p;
	PageHTML pSortie;
	PageHTML T[10];
	char* TSortie[10];
	int dimTliens;
	int choix;
	int nbr;
	FILE* f1=fopen(nomFichier, "rb");
	if(f1==NULL)
	exit(EXIT_FAILURE);
		fflush(stdin);
	nbr=nbrPageDansFichier(nomFichier);
	for(i=0; i<nbr;i++){
		if(fread(&p, sizeof(PageHTML), 1, f1)!=0){
			fflush(stdin);
			printf("%d- %s\n", i+1, p.nomPage);
			T[i]=p;
		}
	}
	do{
			printf("Vous voulez gérer les liens de quelle page?");
			scanf("%d", &choix);
			fflush(stdin);
	}while(choix>nbr || choix<1);

	pSortie=T[choix-1];
	printf("Combien de liens vous voulez ajouter a la page %s?\n", pSortie.nomPage);
	scanf("%d", &dimTliens);
	fflush(stdin);
	printf("Vers quelle pages vous voulez arriver?(utiliser les numeros du meme menu)\n");
	for(i=0; i< dimTliens;i++){
			do{
				printf("\n->\t", i+1);
				scanf("%d", &choix);
				fflush(stdin);
			}while(choix>nbr || choix<1);
				TSortie[i]=T[choix-1].lienPerso;
				//printf("lien1:%s\n", TSortie[i]);
				//printf("lien2:%s\n", T[choix-1].lienPerso);
	}
	fflush(stdin);
	fclose(f1);
	/*for(i=0; i<6; i++){
		printf("lien: %s\n", TSortie[i]);
	}*/
	gestionLienPages(pSortie.nomPage, nomFichier, TSortie, dimTliens);
}

int gestionLienPages(char* nomPage, char* nomFichier, char** Tliens, int dimTliens){
	int pos;
	PageHTML p;
	int i=0, j=0;
	pos=rechercherPage(nomFichier, nomPage);
	if(pos== -1 ){
		printf("Page n'existe pas donc impossible de la modifier!");
		return -1;
	}
	else{
		FILE* f1=fopen(nomFichier, "rb+");
		if(f1==NULL) exit(EXIT_FAILURE);
		printf("pos1=%d\n", pos);
		fseek(f1, pos,0);
		fread(&p, sizeof(PageHTML),1,f1);
		fseek(f1, pos,0);
		
		for(i=p.dimensionTLiens, j=0; i<p.dimensionTLiens+dimTliens; i++, j++){
			p.TLiens[i]=Tliens[j];
			printf("Tliens[j]=%s\n", Tliens[j]);
			printf("p.TLiens[i]=%s\n", p.TLiens[i]);
		}
		p.dimensionTLiens+=dimTliens;
		fseek(f1, pos,0);
		fwrite(&p, sizeof(PageHTML), 1, f1);
		fclose(f1);
		printf("p.dimensionTLiens: %d\n", p.dimensionTLiens);
		for(i=0; i<p.dimensionTLiens; i++){
				printf("lienGestion: %s\n", p.TLiens[i]);
		}
	
		return 0;
	}
	}
int nbrPageDansFichier(char* nomFichier){
	PageHTML p;
	int nbr=0;
	FILE* f1=fopen(nomFichier, "rb");
	if(f1==NULL)
	exit(EXIT_FAILURE);
	fflush(stdin);
	while(!feof(f1)){
		if(fread(&p, sizeof(PageHTML), 1, f1)!=0){
			fflush(stdin);
			nbr++;
		}
	}
	fflush(stdin);
	fclose(f1);
	return nbr;
}

