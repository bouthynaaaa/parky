#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "serviceComplementaire.h"
#include "reservation.h"
int radioTypeAjout = 1;
int checkDispoAjout = 1;
int radioTypeModif = 1;
int checkDispoModif = 1;
char filenameService[] = "services.txt";
char filenameReser[] = "reservation.txt";




void
on_treeviewServiceHome_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_buttonRechercheService_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
      GtkWidget *nom,*pInfo,*windowServiceHome,*w1,*treeview;
       int b = 1;
    char nom1[50];
    windowServiceHome = lookup_widget(button,"windowServiceHome");
     windowServiceHome = create_windowServiceHome();
    nom = lookup_widget(button,"serviceSearchTextField");
     strcpy(nom1,gtk_entry_get_text(GTK_ENTRY(nom)));
      if(strcmp(nom1,"")==0 ){
      
       pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"case est vide  ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
               break;}
     }else{

         
      w1=lookup_widget(button,"windowServiceHome");
      windowServiceHome=create_windowServiceHome();
       gtk_widget_show(windowServiceHome);
       gtk_widget_hide(w1);
       treeview=lookup_widget(windowServiceHome,"treeviewServiceHome");
       viderService(treeview);
       afficherServiceByNom(treeview, filenameService,nom1);
}
}

void
on_buttonAjouterServiceW_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *windowServiceAjout,*windowServiceHome;
     windowServiceHome = lookup_widget(button,"windowServiceHome");
      
     windowServiceAjout = lookup_widget(button,"windowServiceAjout");
     windowServiceAjout = create_windowServiceAjout();
     gtk_widget_show(windowServiceAjout);
     gtk_widget_destroy(windowServiceHome);

}


void
on_buttonModifierServiceW_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{  
    GtkWidget *windowServiceModif,*windowServiceHome;
     windowServiceHome = lookup_widget(button,"windowServiceHome");
      
     windowServiceModif = lookup_widget(button,"windowServiceModif");
     windowServiceModif = create_windowServiceModif();
     gtk_widget_show(windowServiceModif);
     gtk_widget_destroy(windowServiceHome);

}


void
on_buttonSupprimerServiceW_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *windowServiceSup,*windowServiceHome;
     windowServiceHome = lookup_widget(button,"windowServiceHome");
      
     windowServiceSup = lookup_widget(button,"windowServiceSup");
     windowServiceSup = create_windowServiceSup();
     gtk_widget_show(windowServiceSup);
     gtk_widget_destroy(windowServiceHome);

}


void
on_buttonActualiserServiceW_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
     GtkWidget *windowServiceHome,*w1,*treeview;
      w1=lookup_widget(button,"windowServiceHome");
      windowServiceHome=create_windowServiceHome();
       gtk_widget_show(windowServiceHome);
       gtk_widget_hide(w1);
       treeview=lookup_widget(windowServiceHome,"treeviewServiceHome");
       viderService(treeview);
       afficherService(treeview,"services.txt");

}


void
on_buttonStatistiqueServiceW_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *windowServiceAffectation,*windowServiceHome;
     windowServiceHome = lookup_widget(button,"windowServiceHome");
      
     windowServiceAffectation = lookup_widget(button,"windowServiceAffectation");
     windowServiceAffectation = create_windowServiceAffectation();
     gtk_widget_show(windowServiceAffectation);
     gtk_widget_destroy(windowServiceHome);
}


void
on_btnAjoutService_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *id ,*nom,*description,*prix_service,*windowServiceAjout,*windowServiceHome,*labelControl;
    // initialisation de varibale de controlle saisie
       int b = 1;
   // declaration de notre struct 
       Service s;
       // declaration des variables 
 	windowServiceHome = lookup_widget(button,"windowServiceHome");
 	windowServiceAjout = lookup_widget(button,"windowServiceAjout");
 	id = lookup_widget(button,"textIdAjoutService");
 	
 	nom = lookup_widget(button,"textNomAjoutService");
 	
 	description = lookup_widget(button,"textDescriptionAjoutService");
 	labelControl = lookup_widget(button,"windowServiceAjoutControl");
 	prix_service = lookup_widget(button,"spinPrixAjoutService");
 	  // recuperation des information d apres interfaces graphique 
            // recuperation de textField
     strcpy(s.id,gtk_entry_get_text(GTK_ENTRY(id)));
          // recuperation de combobox
     strcpy(s.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
          // recuperation de textField
     strcpy(s.description,gtk_entry_get_text(GTK_ENTRY(description)));
           // recuperation de spinButton
     s.prix_service = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prix_service));
       // recuperation des information d apres check box  
           
         // A faire
         if(checkDispoAjout == 1){
           strcpy(s.Service_disponible,"oui");

          }else{

           strcpy(s.Service_disponible,"non");
          }

    // recuperation des information d apres radio box
          
           // A faire
         if(radioTypeAjout == 1){
           strcpy(s.Type_service,"base");

          }else{

           strcpy(s.Type_service,"premium");
          }
        // controlle saisie 
        if(strcmp(s.id,"")==0 ){
            
           b=0;
             }
           if(strcmp(s.nom,"")==0 ){
           b=0;
             }
            if(strcmp(s.description,"")==0 ){
            
           b=0;
             }

     //  ajouter et logique de programme 

          if (b == 0){
         

               gtk_label_set_text(GTK_LABEL(labelControl),"  Veuillez vérifier vos données  ");



         }else{
       int t =  ajouterService(filenameService,s);
       if(t == 1){
       
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                      gtk_entry_set_text(GTK_ENTRY(nom),"");
			gtk_entry_set_text(GTK_ENTRY(description),"");
                   gtk_label_set_text(GTK_LABEL(labelControl),"");
                
          		 
              
             windowServiceHome = create_windowServiceHome();
             gtk_widget_show(windowServiceHome);
              gtk_widget_destroy(windowServiceAjout);
                 
       
     
       }else{

   


         gtk_label_set_text(GTK_LABEL(labelControl),"❌ Une erreur   ");

      }


}

   
 
   
}


void
on_btnCancelAjoutService_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{  
    GtkWidget *windowServiceAjout,*windowServiceHome;
     windowServiceHome = lookup_widget(button,"windowServiceHome");
      
     windowServiceAjout = lookup_widget(button,"windowServiceAjout");
     windowServiceHome = create_windowServiceHome();
     gtk_widget_show(windowServiceHome);
     gtk_widget_destroy(windowServiceAjout);

}


void
on_radioTypeBaseAjoutService_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
 {radioTypeAjout=1;}
}


void
on_radioTypePremiumAjoutService_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
 {radioTypeAjout=0;}
}


void
on_checkDispoOuiAjoutService_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(togglebutton))
 {checkDispoAjout=1;}
}


void
on_checkDispoNonAjoutService_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(togglebutton))
 {checkDispoAjout=0;}
}


void
on_btnModifService_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *id ,*nom,*description,*prix_service,*windowServiceModif,*windowServiceHome,*labelControl;
    // initialisation de varibale de controlle saisie
       int b = 1;
   // declaration de notre struct 
       Service s;
       // declaration des variables 
 	windowServiceHome = lookup_widget(button,"windowServiceHome");
 	windowServiceModif = lookup_widget(button,"windowServiceModif");
 	id = lookup_widget(button,"textIdModifService");
 	
 	nom = lookup_widget(button,"textNomModifService");
 	
 	description = lookup_widget(button,"textDescriptionModifService");
 	labelControl = lookup_widget(button,"windowServiceModifControl");
 	prix_service = lookup_widget(button,"spinPrixModifService");
 	  // recuperation des information d apres interfaces graphique 
            // recuperation de textField
     strcpy(s.id,gtk_entry_get_text(GTK_ENTRY(id)));
          // recuperation de combobox
     strcpy(s.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
          // recuperation de textField
     strcpy(s.description,gtk_entry_get_text(GTK_ENTRY(description)));
           // recuperation de spinButton
     s.prix_service = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(prix_service));
       // recuperation des information d apres check box  
           
         // A faire
         if(checkDispoModif == 1){
           strcpy(s.Service_disponible,"oui");

          }else if(checkDispoModif == 0){

           strcpy(s.Service_disponible,"non");
          }

    // recuperation des information d apres radio box
          
           // A faire
         if(radioTypeModif == 1){
           strcpy(s.Type_service,"base");

          }else if(radioTypeModif == 0){

           strcpy(s.Type_service,"premium");
          }
        // controlle saisie 
        if(strcmp(s.id,"")==0 ){
            
           b=0;
             }
           if(strcmp(s.nom,"")==0 ){
           b=0;
             }
            if(strcmp(s.description,"")==0 ){
            
           b=0;
             }

     //  ajouter et logique de programme 

          if (b == 0){
         

               gtk_label_set_text(GTK_LABEL(labelControl),"  Veuillez vérifier vos données  ");



         }else{
       int t =  modifierService(filenameService,s.id,s);
       if(t == 1){
         
               
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                      gtk_entry_set_text(GTK_ENTRY(nom),"");
			gtk_entry_set_text(GTK_ENTRY(description),"");
                   gtk_label_set_text(GTK_LABEL(labelControl),"");
                
          		 
              
             windowServiceHome = create_windowServiceHome();
             gtk_widget_show(windowServiceHome);
              gtk_widget_destroy(windowServiceModif);
                 
      
       }else{

   


         gtk_label_set_text(GTK_LABEL(labelControl),"❌ Une erreur   ");

      }
}


}


void
on_btnCancelModifService_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *windowServiceModif,*windowServiceHome;
     windowServiceHome = lookup_widget(button,"windowServiceHome");
      
     windowServiceModif = lookup_widget(button,"windowServiceModif");
     windowServiceHome = create_windowServiceHome();
     gtk_widget_show(windowServiceHome);
     gtk_widget_destroy(windowServiceModif);
}


void
on_radioTypeBaseModifService_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(togglebutton))
 {radioTypeModif=1;}
}


void
on_radioTypePremiumModifService_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(togglebutton))
 {radioTypeModif=0;}
}


void
on_checkDispoNonModifService_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton))
 {checkDispoModif=1;}
}


void
on_checkDispoOuiModifService_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton))
 {checkDispoModif=0;}
}


void
on_btnRechercheModifService_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *id ,*nom,*description,*prix_service,*windowServiceModif,*base,*premuim,*dispoOui,*dispoNon,*labelId;

        // initialisation de varibale de controlle saisie
       int b = 1;
   // declaration de notre struct 
       Service s;
	char id1[50];
       // declaration des variables 
 	windowServiceModif = lookup_widget(button,"windowServiceModif");
 	id = lookup_widget(button,"textIdModifService");
 	
 	nom = lookup_widget(button,"textNomModifService");
 	
 	description = lookup_widget(button,"textDescriptionModifService");
 	
 	prix_service = lookup_widget(button,"spinPrixModifService");
	base = lookup_widget(button,"radioTypeBaseModifService");
	premuim = lookup_widget(button,"radioTypePremiumModifService");
	dispoOui = lookup_widget(button,"checkDispoOuiModifService");
	dispoNon = lookup_widget(button,"checkDispoNonModifService");
	labelId = lookup_widget(button,"textIdModifServiceControl");
                // recuperation de textField
     strcpy(id1,gtk_entry_get_text(GTK_ENTRY(id)));


                // controlle saisie 
        if(strcmp(id1,"")==0 ){
            
           b=0;
             }
      
         if(b==0){
            gtk_label_set_text(GTK_LABEL(labelId),"   Veuillez vérifier vos données  ");
          }else{
          if(!isServiceExist(filenameService,id1)){
              gtk_label_set_text(GTK_LABEL(labelId),"   il n existe pas ... ");

	   }else{
		s = chercherServiceByID(filenameService,id1);
                
               gtk_entry_set_text(GTK_ENTRY(id),s.id);
		gtk_entry_set_text(GTK_ENTRY(nom),s.nom);
		gtk_entry_set_text(GTK_ENTRY(description),s.description);
                gtk_spin_button_set_value(prix_service,s.prix_service);
		// Set Radio Button Value
                if(strcmp(s.Type_service,"base")==0)
		gtk_toggle_button_set_active(GTK_RADIO_BUTTON(base),TRUE);
		gtk_toggle_button_set_active(GTK_RADIO_BUTTON(premuim),FALSE);
		if(strcmp(s.Type_service,"premium")==0)
		gtk_toggle_button_set_active(GTK_RADIO_BUTTON(premuim),TRUE);
                gtk_toggle_button_set_active(GTK_RADIO_BUTTON(base),FALSE);
                  // Set check Box Value
                 

		if(strcmp(s.Service_disponible,"non")==0){
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(dispoNon), TRUE);
                  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(dispoOui), FALSE);
                }
		

               
           }


         }



}


void
on_btnCancelSupService_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *windowServiceSup,*windowServiceHome;
     windowServiceHome = lookup_widget(button,"windowServiceHome");
      
     windowServiceSup = lookup_widget(button,"windowServiceSup");
     windowServiceHome = create_windowServiceHome();
     gtk_widget_show(windowServiceHome);
     gtk_widget_destroy(windowServiceSup);

}


void
on_btnSupService_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *id ,*windowServiceSup,*windowServiceHome,*labelControl,*pInfo;
    // initialisation de varibale de controlle saisie
       int b = 1;
	char id1[50];
   // declaration de notre struct 
       Service s;
       // declaration des variables 
 	windowServiceHome = lookup_widget(button,"windowServiceHome");
 	windowServiceSup = lookup_widget(button,"windowServiceSup");
 	id = lookup_widget(button,"textIdSupService");
 	
 	labelControl = lookup_widget(button,"textIdSupServiceControl");
 	
 	  // recuperation des information d apres interfaces graphique 
            // recuperation de textField
     strcpy(id1,gtk_entry_get_text(GTK_ENTRY(id)));
          // recuperation de combobox
  
           

        // controlle saisie 
        if(strcmp(id1,"")==0 ){
            
           b=0;
             }
         

     //  ajouter et logique de programme 

          if (b == 0){
         

               gtk_label_set_text(GTK_LABEL(labelControl),"  Veuillez vérifier vos données ");



         }else{
          if(!isServiceExist(filenameService,id1)){
              gtk_label_set_text(GTK_LABEL(labelControl),"  il n existe pas ... ");

	   }else{
       int t =  supprimerService(filenameService,id1);
       if(t == 1){
        
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                     
                   gtk_label_set_text(GTK_LABEL(labelControl),"");
                
          		 
              
             windowServiceHome = create_windowServiceHome();
             gtk_widget_show(windowServiceHome);
              gtk_widget_destroy(windowServiceSup);
                 
       
       
       }else{

   


         gtk_label_set_text(GTK_LABEL(labelControl),"❌ Une erreur est survenue ");

      }
}
}
}


void
on_btnAffecService_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *idRes,*idServ ,*windowServiceAffectation,*windowServiceHome,*labelControl,*pInfo;
    // initialisation de varibale de controlle saisie
       int b = 1;
	char idReservation[50];
	char idService[50];
      int idR;
       // declaration des variables 
 	windowServiceHome = lookup_widget(button,"windowServiceHome");
 	windowServiceAffectation = lookup_widget(button,"windowServiceAffectation");
 	idRes = lookup_widget(button,"comboIdReservationService");
 	idServ = lookup_widget(button,"comboIdseviceService");
 	labelControl = lookup_widget(button,"textIdAffecServiceControl");
        // recuperation des donne
         strcpy(idReservation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(idRes)));
         strcpy(idService,gtk_combo_box_get_active_text(GTK_COMBO_BOX(idServ)));

           // controlle saisie 
        if(strcmp(idReservation,"")==0 ){
            
           b=0;
             }

        if(strcmp(idService,"")==0 ){
            
           b=0;
             }
         
         //  ajouter et logique de programme 

          if (b == 0){
         

               gtk_label_set_text(GTK_LABEL(labelControl),"   Veuillez vérifier vos données ");



         }else{
      idR = atoi(idReservation);
       int t =  affecterService_reservation(filenameReser,idR,idService);
       if(t == 1){
        
                
                     
                   gtk_label_set_text(GTK_LABEL(labelControl),"");
                
          		 
              
             windowServiceHome = create_windowServiceHome();
             gtk_widget_show(windowServiceHome);
              gtk_widget_destroy(windowServiceAffectation);
                 
       
        
       }else{

   


         gtk_label_set_text(GTK_LABEL(labelControl),"❌ Une erreur est survenue  ");

      }
}



}


void
on_btnCancelAffecService_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *windowServiceAffectation,*windowServiceHome;
     windowServiceHome = lookup_widget(button,"windowServiceHome");
      
     windowServiceAffectation = lookup_widget(button,"windowServiceAffectation");
     windowServiceHome = create_windowServiceHome();
     gtk_widget_show(windowServiceHome);
     gtk_widget_destroy(windowServiceAffectation);
}

