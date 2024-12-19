#ifndef RESERVATION_H_INCLUDED
#define RESERVATION_H_INCLUDED

#include <stdio.h>
#include <string.h>
#define filename_reservation "reservation.txt"
//struct date

typedef struct
{
    int jj;
    int mm;
    int aa;
}Date1;


// Structure représentant une réservation

typedef struct
{
    int idParking;
    int idCitoyen  ;
    int idReservation;
    Date1 dateReservation;
    float dureeStationnement;
    char outil_paiement[30];        // Méthode de paiement
    char services[30];
    char abonnement[30];

} Reservation;


//structure parking

typedef struct
{
    int idParking;
    int places_disponibles;
}Parking;


int ajouter_reservation(char *filename, Reservation r);


int affecterService_reservation(char *filename, int id, char *idService);


#endif             // RESERVATION_H_INCLUDED
