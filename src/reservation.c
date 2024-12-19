#include "reservation.h"
#include <stdio.h>
#include <string.h>
#define filename_reservation "reservation.txt"




int ajouter_reservation(char *filename, Reservation r) {
  FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %d %d %d %d %f %s %s %s\n",r.idReservation,r.idCitoyen,r.idParking,r.dateReservation.jj,r.dateReservation.mm,r.dateReservation.aa,
                r.dureeStationnement,r.outil_paiement,r.services,r.abonnement
                );
        fclose(f);
        return 1;
    }
    else return 0;

}









int affecterService_reservation(char *filename, int id, char *idService){
int tr=0;
    Reservation r;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %d %d %f %s %s %s\n",&r.idReservation,&r.idCitoyen,&r.idParking,&r.dateReservation.jj,&r.dateReservation.mm,&r.dateReservation.aa,
                &r.dureeStationnement,r.outil_paiement,r.services,r.abonnement)!=EOF)
        {
            if(r.idReservation == id)
            {
                fprintf(f2,"%d %d %d %d %d %d %f %s %s %s\n",r.idReservation,r.idCitoyen,r.idParking,r.dateReservation.jj,r.dateReservation.mm,r.dateReservation.aa,
                r.dureeStationnement,r.outil_paiement,idService,r.abonnement);
                tr=1;
            }
            else
                fprintf(f2,"%d %d %d %d %d %d %f %s %s %s\n",r.idReservation,r.idCitoyen,r.idParking,r.dateReservation.jj,r.dateReservation.mm,r.dateReservation.aa,
                r.dureeStationnement,r.outil_paiement,r.services,r.abonnement);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;




}
