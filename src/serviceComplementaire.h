#ifndef SERVICECOMPLEMENTAIRE_H_INCLUDED
#define SERVICECOMPLEMENTAIRE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct{
char id[50];
char nom[50];
char description[50];
float prix_service;
char Type_service[50];
char Service_disponible[50];
}Service;

typedef struct{
 int jj;
 int mm;
 int aa;
}Date;




int ajouterService(char *, Service );
int modifierService( char *, char *, Service );
int supprimerService(char *,char * );
Service chercherServiceByID(char *, char *);
int isServiceExist(char *, char *);
int  listeService(char *, Service *);
void viderService(GtkWidget *liste);
void afficherService(GtkWidget *liste, char *filename);
void afficherServiceByNom(GtkWidget *liste, char *filename,char * nom);

#endif // SERVICECOMPLEMENTAIRE_H_INCLUDED
