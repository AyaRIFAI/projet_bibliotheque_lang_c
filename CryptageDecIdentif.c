#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ProtEtStructure.h"

char* cryptcesar(const char *mssg,int key,char *cipertext ){
	 int i = 0;

	short int rang;
	while(mssg[i] != '\0'){
		
		if(mssg[i] >= 'a' && mssg[i]<= 'z' ){
			rang = ((mssg[i] - 'a')+key) % 26;
			if(rang < 0) rang += 26;
				//printf("salut");
			cipertext[i] = 'a' +rang;
		}
		else if(mssg[i] >= 'A' && mssg[i]<= 'Z' ){
			rang = ((mssg[i] - 'A')+key) % 26;
			if(rang < 0) rang += 26;
				//printf("salut");
			cipertext[i] = 'A' +rang;
		}
		else{
			cipertext[i] = mssg[i];
		
		}
			i++;
	}

	cipertext[i] ='\0';
	return cipertext;
}

char* decrypte(char *cipertext,int key,char *text){
		//printf("Moii\n");
	cryptcesar(cipertext,-key,text);
			
   return text;
}

long recherche(char login[50]){
	FILE* f1;
	int i=0;
	Admin* a = (Admin*)malloc(sizeof(Admin));
	//printf("Le login enter est: %s\n",login);
	long pos = 0;
	f1= fopen("Cryptemotdepasse.txt","r");
	do{
		//for(i=0;i!='\0',i++){
		
		//fseek(f1,0,0);
		pos = ftell(f1);
		fscanf(f1,"%s\t%s\n",a->login,a->motDepass);
	    //printf("Le login est :%s\n",a->logein);
	    //printf("Mon loginesr :%s\n ",login);
	   // printf("hiiii");
	   	//printf("egale: %d\n",);
	   //printf("de fichier: %d\n",strlen(a->logein));
	   //printf("de login: %d\n",strlen(login));
	   
		if(!strcmp(a->login,login)){
		
		  
		   //printf("la position est de recherche: %d\n",pos);
			fclose(f1);
			return pos;}
		
	
	}while(!feof(f1));
	fclose(f1);
	return -1;
}

int VerfierAdmin(char* loginAdmin){
	char login[50];
	char motdepasse[50];
	Admin *a = (Admin*)malloc(sizeof(Admin));
	
	char cryptemotdepasee[50];
	int tentative =1;
	int pos =0;
	int existe = 0;
	FILE* f;
	f=fopen("Cryptemotdepasse.txt","r");
	do{
			printf("Entrer Votre LogIn: \n");
	        scanf("%s",login);
	        fflush(stdin);
          	printf("Entrer votre mot de passe sous forme de chaine de caractere (tentative %d/3) \n",tentative);
	         scanf("%s",motdepasse);
	         fflush(stdin);
	

	if(recherche(login)!=-1){
			//printf("hiiiiiiiii\n");
		pos = recherche(login);
		
		fseek(f,pos,0);
		//printf("ftell::%d\n", ftell(f));
			fscanf(f,"%s\t%s\n",a->login,a->motDepass);
			fflush(stdin);
			//printf("Le motdepasseetlogin:%s\t%s\n",a->logein,a->motDepass);
	    	//printf("le motdepa::%s\n",decrypte(a->motDepass,5,cryptemotdepasee));
	
		
		if(!strcmp((decrypte(a->motDepass,5,cryptemotdepasee)),motdepasse)){
			existe = 1;
		}     
	}
	if(existe == 1){
             printf("Bien authentifie\n");
             strcpy(loginAdmin, login);
             fflush(stdin);
			 return	1;
			 }
	else{
		if(tentative!=3 )
		printf("Desole mot de passe incorrect! essaye a nouveau!\n");
		}
		}while(tentative++ <3 );
			fclose(f);
			return 0;	
}
int EnregistrerDansFile(){
	char login[50];
	char motdepasse[50];
	char cipertext[50];
	char motreel[50];
	int fois =0;
	FILE*f1;
	f1 = fopen("Cryptemotdepasse.txt","a+");
	if(f1 != NULL){
		while(fois<=0){
	         fflush(stdin);
			//printf("hii");
			printf("Entrer login: ");
			scanf("%s",login);
			fflush(stdin);
			fprintf(f1,"%s\t",login);
			 
			printf("Entrer votre motdepasse: ");
			scanf("%s",motdepasse);
			fflush(stdin);
			fprintf(f1,"%s\n",cryptcesar(motdepasse,5,cipertext ));
			printf("le mot de passe reel:%s\n", decrypte(cipertext,5,motreel));
			printf("le mot de passe crypte:%s\n",cryptcesar(motdepasse,5,cipertext ));
			fois++;
		}
		printf("Vos information sont bien copier!\n");
		fclose(f1);
	}
	else{
		printf("Fichier non existant");
		fclose(f1);
	}
	
}
