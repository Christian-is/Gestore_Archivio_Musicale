/*
 * stampa.h
 *
 *  Created on: 19 mag 2020
 *      Author: Gruppo 2
 *
 *  Modulo che si occupa delle stampe a video
 */

#ifndef STAMPABASEDATI_H_
#define STAMPABASEDATI_H_

#include <stdio.h>
#include <stdlib.h>
#include "gestione.h"
#include "ricerca.h"

/* Tutte le funzioni per stampare le intere;
 * tabelle del database, la funzione "StampaDatabase" le richiama tutte
 * e serve per stampare l'intero database in un determinato momento */

void StampaDatabase(Database* musica); // Stampa ogni tabella del database
void StampaTabellaBrano(Database* musica); // Stampa tabella brano
void StampaTabellaArtisti(Database* musica); // Stampa tabella artisti
void StampaTabellaBranoArtista(Database* musica); // Stampa tabella brano-artista
void StampaTabellaAlbum(Database* musica); // Stampa tabella album
void StampaTabellaBranoAlbum(Database* musica); // Stampa tabella brano-album
void StampaTabellaGenere(Database* musica); // Stampa tabella genere
void StampaTabellaBranoGenere(Database* musica); // Stampa tabella brano-genere
void StampaTabellaPlaylist(Database* musica); // Stampa tabella Playlist
void StampaTabellaPlaylistBrano(Database* musica); // Stampa tabella Playlist-Brano
void StampaTabellaUtente(Database* musica); // Stampa tabella Utente
void StampaUtenteCorrente(Database* musica); // Stampa utente corrente
void StampaUltimoEsito(Database* musica); // Stampa ultimo esito

//funzioni che ricevono un vettore di id e stampano le strutture corrispondenti
void StampareRisultatiUtente(Database *BaseDati, int *vettoreId); //stampa gli utenti corrispondenti agli id in vettoreId
void StampareRisultatiPlaylist(Database *BaseDati, int *vettoreId); //stampa le playlist corrispondenti agli id in vettoreId
void StampareRisultatiBrano(Database *BaseDati, int *vettoreId); //stampa i brani corrispondenti agli id in vettoreId
void StampareRisultatiAlbum(Database *BaseDati, int *vettoreId);//stampa gli album corrispondenti agli id in vettoreId
void StampareRisultatiArtista(Database *BaseDati, int *vettoreId); //stampa gli artisti corrispondenti agli id in vettoreId
void StampareBraniDaAlbum(Database *BaseDati, int *vettoreId); //stampa i brani collegati agli album i cui id sono in vettoreId
void StampareBraniDaArtista(Database *BaseDati, int *vettoreId); //stampa i brani collegati all'artista i cui id sono in vettoreId
void StampareBraniDaPlaylist(Database *BaseDati, int *vettoreId); //stampa i brani collegati alla playlist i cui id sono in vettoreId


#endif /* STAMPABASEDATI_H_ */
