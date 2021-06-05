/*
 * playlist.h
 *
 *  Created on: May 31, 2020
 *      Author: Gruppo 2
 *
 *  Modulo che si occupa della gestione delle playlist
 */

#ifndef PLAYLIST_H_
#define PLAYLIST_H_
#include "gestione.h"
#include "ricerca.h"

void InserirePlaylist(Database *BaseDati, Playlist NuovoPlaylist); //funzione che inserisce una stuttura di tipo Playlist nel database
void InserirePlaylistBrano(Database* musica, int chiavebrano, int chiaveplaylist); /* Funzione che inserisce nel vettore Playlist-Brano le due chiavi ricevute in input */
void ModificarePlaylist(int id, int campo, Database *musica); //funzione che modifica il campo di una playlist nel database. Riceve in input l'id della playlist, l'identificativo numerico del campo e il database
void CancellarePlaylist(Database *BaseDati, int idPlaylistDaCancellare); //funzione che avvia la procedura di cancellazione di una playlist dal database. Cancella anche le tabelle di associazione brano-playlist
void CancellareBranoDaPlaylist(Database *BaseDati, int idBranoDaCancellare, int idPlaylistDaAggiornare); //cancella dalla tabella brano-playlist le associazioni idBranoDaCancellare e idPlaylistDaAggiornare
void SpostareSinistraVettorePlaylist(Playlist* vet, int i); //sposta a sinistra il vettore in input a partire dalla posizione i
void SpostareSinistraVettoreBranoPlaylist(PlaylistBrano* vet, int i); //sposta a sinistra il vettore in input a partire dalla posizione i

#endif /* PLAYLIST_H_ */
