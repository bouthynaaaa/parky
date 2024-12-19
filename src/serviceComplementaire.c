#include "serviceComplementaire.h"


enum{SID,
     SNOM,
     SDESCRIPTION,
     SPRIXSERVICE,
     STYPESERVICE,
     SSERVICEDISPONIBLE,
     COLUMNS
      };


void afficherServiceByNom(GtkWidget *liste, char *filename,char * nom){

GtkCellRenderer *renderer; // afficheur de cellule (Cellule contient un texte, image, case à cocher)
      GtkTreeViewColumn *column; // visualisation des colonnes
       GtkTreeIter iter;          /**/
       GtkListStore *store;       // création du modèle de type liste

  char prix[50];
    store = NULL;
   Service service;
    FILE *f;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        
	renderer=gtk_cell_renderer_text_new();                                                               // cellule contenant du texte
        column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", SID, NULL); // création d'une colonne avec du texte
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);                                             // associer la colonne à l'afficheur (GtkTreeView)

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("NOM", renderer, "text", SNOM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Desciption", renderer, "text", SDESCRIPTION, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("PrixService", renderer, "text", SPRIXSERVICE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("TypeService", renderer, "text", STYPESERVICE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Disponible", renderer, "text", SSERVICEDISPONIBLE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

       

        // La liste contient 7 colonnes de type chaine de caractères
    }
   store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,-1);


     


              f = fopen(filename, "r");

    if (f == NULL)
    {
        return;
    }
    else
    {
       
        while (fscanf(f,"%s %s %s %f %s %s\n",service.id,service.nom,service.description,&service.prix_service,service.Type_service,service.Service_disponible)!=EOF)
        {  
            
           if(strcmp(service.id,nom)==0 || strcmp(service.nom,nom)==0 ){
         sprintf(prix,"%f",service.prix_service);
         
        





            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store,&iter,SID,service.id,SNOM,service.nom,SDESCRIPTION,service.description,SPRIXSERVICE,prix,STYPESERVICE,service.Type_service,SSERVICEDISPONIBLE,service.Service_disponible,-1);}
        }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }






















}
void afficherService(GtkWidget *liste, char *filename){

GtkCellRenderer *renderer; // afficheur de cellule (Cellule contient un texte, image, case à cocher)
      GtkTreeViewColumn *column; // visualisation des colonnes
       GtkTreeIter iter;          /**/
       GtkListStore *store;       // création du modèle de type liste

  char prix[50];
    store = NULL;
   Service service;
    FILE *f;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        
	renderer=gtk_cell_renderer_text_new();                                                               // cellule contenant du texte
        column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", SID, NULL); // création d'une colonne avec du texte
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);                                             // associer la colonne à l'afficheur (GtkTreeView)

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("NOM", renderer, "text", SNOM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Desciption", renderer, "text", SDESCRIPTION, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("PrixService", renderer, "text", SPRIXSERVICE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("TypeService", renderer, "text", STYPESERVICE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Disponible", renderer, "text", SSERVICEDISPONIBLE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

       

        // La liste contient 7 colonnes de type chaine de caractères
    }
   store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,-1);


     


              f = fopen(filename, "r");

    if (f == NULL)
    {
        return;
    }
    else
    {
       
        while (fscanf(f,"%s %s %s %f %s %s\n",service.id,service.nom,service.description,&service.prix_service,service.Type_service,service.Service_disponible)!=EOF)
        {  
            

         sprintf(prix,"%f",service.prix_service);
         
        





            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store,&iter,SID,service.id,SNOM,service.nom,SDESCRIPTION,service.description,SPRIXSERVICE,prix,STYPESERVICE,service.Type_service,SSERVICEDISPONIBLE,service.Service_disponible,-1);
        }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }


}



void viderService(GtkWidget *liste){

GtkCellRenderer *renderer; // afficheur de cellule (Cellule contient un texte, image, case à cocher)
      GtkTreeViewColumn *column; // visualisation des colonnes
       GtkTreeIter iter;          /**/
       GtkListStore *store;       // création du modèle de type liste

  char prix[50];
    store = NULL;
   Service service;
    FILE *f;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        
	renderer=gtk_cell_renderer_text_new();                                                               // cellule contenant du texte
        column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", SID, NULL); // création d'une colonne avec du texte
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);                                             // associer la colonne à l'afficheur (GtkTreeView)

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("NOM", renderer, "text", SNOM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Desciption", renderer, "text", SDESCRIPTION, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("PrixService", renderer, "text", SPRIXSERVICE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("TypeService", renderer, "text", STYPESERVICE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Disponible", renderer, "text", SSERVICEDISPONIBLE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

       

        // La liste contient 7 colonnes de type chaine de caractères
    }
   store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
}



int ajouterService(char *filename, Service service){


       FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %f %s %s\n",service.id,service.nom,service.description,service.prix_service,service.Type_service,service.Service_disponible);
        fclose(f);
        return 1;
    }
    else return 0;



}


int modifierService( char *filename, char *id, Service nouv ){
int tr=0;
    Service service;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %f %s %s\n",service.id,service.nom,service.description,&service.prix_service,service.Type_service,service.Service_disponible)!=EOF)
        {
            if(strcmp(service.id,id)==0)
            {
                fprintf(f2,"%s %s %s %f %s %s\n",nouv.id,nouv.nom,nouv.description,nouv.prix_service,nouv.Type_service,nouv.Service_disponible);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %f %s %s\n",service.id,service.nom,service.description,service.prix_service,service.Type_service,service.Service_disponible);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;



}


int supprimerService(char *filename,char *id ){

int tr=0;
     Service service;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %f %s %s\n",service.id,service.nom,service.description,&service.prix_service,service.Type_service,service.Service_disponible)!=EOF)
        {
            if(strcmp(service.id,id)==0)
                tr=1;
            else
                fprintf(f2,"%s %s %s %f %s %s\n",service.id,service.nom,service.description,service.prix_service,service.Type_service,service.Service_disponible);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;




}

Service chercherServiceByID(char *filename, char *id){

 Service service;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %s %f %s %s\n",service.id,service.nom,service.description,&service.prix_service,service.Type_service,service.Service_disponible)!=EOF)
        {
            if(strcmp(service.id,id)==0)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        strcpy(service.id,"-1");
    return service;



}

int  listeService(char *filename ,Service *resultat){


 Service service;

     int i = 0;
      FILE * f=fopen(filename, "r");
        if(f!=NULL)
    {
        while( fscanf(f,"%s %s %s %f %s %s\n",service.id,service.nom,service.description,&service.prix_service,service.Type_service,service.Service_disponible)!=EOF)
        {

             resultat[i] = service;
               i++;

        }
    }
    fclose(f);
    return i;




}

int isServiceExist(char *filename, char *id){
 Service service;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %s %f %s %s\n",service.id,service.nom,service.description,&service.prix_service,service.Type_service,service.Service_disponible)!=EOF)
        {
            if(strcmp(service.id,id)==0)
                tr=1;
        }
    }
    fclose(f);
    
    return tr;




}




