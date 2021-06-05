/*
 * ricerca.h
 *
 *  Created on: May 27, 2020
 *      Author: Gruppo 2
 *
 * Modulo che si occupa delle funzioni di ricerca degli elementi presenti nel database
 */

#ifndef RICERCA_H_
#define RICERCA_H_
#include "gestione.h"

Utente RicercareUtenteId(Utente* elencoUtenti, int idUtenteCercato); //dato un idUtente, la funzione cerca la struttura utente corrispondente nel vettore di utenti del database;Se non lo trovo, restituisco una struttura non valida, cioè con id SENTINELLA
Playlist RicercarePlaylistId(Playlist* elencoPlaylist, int idPlaylistCercata);//dato un idPlaylist, la funzione cerca la struttura playlist corrispondente nel vettore di playlist del database;Se non lo trovo, restituisco una struttura non valida, cioè con id SENTINELLA
Brano RicercareBranoId(Brano* elencoBrani, int idBranoCercato);//dato un idBrano, la funzione cerca la struttura brano corrispondente nel vettore di brani del database;Se non lo trovo, restituisco una struttura non valida, cioè con id SENTINELLA
Artista RicercareArtistaId(Artista* elencoArtisti, int idArtistaCercato);//dato un idArtista, la funzione cerca la struttura artista corrispondente nel vettore di artisti del database;Se non lo trovo, restituisco una struttura non valida, cioè con id SENTINELLA
Album RicercareAlbumId(Album* elencoAlbum, int idAlbumCercato);//dato un idAlbum, la funzione cerca la struttura album corrispondente nel vettore di album del database;Se non lo trovo, restituisco una struttura non valida, cioè con id SENTINELLA


void RicercareBrano(Database *musica); //Ricerca brani nel database, chiedendo all'utente come cercarli. Stampa in output quello trovato
void RicercareAlbum(Database *musica); //Ricerca album nel database, chiedendo all'utente come cercarli. Stampa in output quello trovato
void RicercareArtista(Database *musica); //Ricerca artisti nel database, chiedendo all'utente come cercarli. Stampa in output quello trovato
void RicercarePlaylist(Database *musica); //Ricerca playlist nel database, chiedendo all'utente come cercarle. Stampa in output quello trovato
void RicercareUtente(Database *musica); //Ricerca utenti nel database, chiedendo all'utente come cercarli. Stampa in output quello trovato


void RicercareBranoTitolo(Database Musica, int *VettoreIdBrani, char *TitoloScelto);//cerca tutti i brani aventi nome uguale a TitoloScelto, e ne salva gli id in un vettoreIdBrani
void RicercareBranoAnno(Database Musica, int *VettoreIdBrani, int Anno);//cerca tutti i brani aventi anno uguale a Anno, e ne salva gli id in un vettoreIdBrani
void RicercarePlaylistNome(Database Musica, int *VettoreIdPlaylist, char *NomeScelto);//cerca tutte le playlist aventi nome uguale a NomeScelto, e ne salva gli id in un vettoreIdPlaylist
void RicercarePlaylistUtente(Database Musica, int *VettoreIdPlaylist, char *NomeScelto); //cerca tutte le playlist appartenenti all'utente di nome NomeScelto, e ne salva gli id in un vettoreId
void RicercarePlaylistIdUtente(int utenteCorrente, Database* musica, int* vettoreId); //cerca tutte le playlist aventi idUtente uguale a utenteCorrente, e ne salva gli id in un vettoreId

void RicercareAlbumTitolo(Database Musica,int *vetAlbumIdTitolo,char *titolo);//cerca tutti gli album aventi il campo titolo uguale a titolo, e ne salva gli id in un vettoreAlbumIdTitolo
void RicercareAlbumAnno(Database Musica,int *vetAlbumIdAnno,int anno); //cerca tutti gli album aventi il campo anno uguale a anno, e ne salva gli id in un vettoreAlbumIdAnno
void RicercareArtistaNome(Database Musica,int *vetArtistaIdNome,char *artistaNome);//cerca tutti gli artisti aventi il campo nome uguale a artistaNome, e ne salva gli id in un vettoreArtistaIdNome
void RicercareArtistaCognome(Database Musica,int *vetArtistaIdCognome,char *artistaCognome);//cerca tutti gli artisti aventi il campo cognome uguale a artistaCognome, e ne salva gli id in un vettoreArtistaIdCognome
void RicercareArtistaNomeArte(Database Musica,int *vetArtistaIdNomeArte,char *artistaNomeArte);//cerca tutti gli artisti aventi il campo NomeArte uguale a artistaNomeArte, e ne salva gli id in un vettoreArtistaIdNomeArte
void RicercareUtenteNome(Database Musica,int *vetUtenteIdNome,char *nome);//cerca tutti gli utenti aventi il campo nome uguale a nome, e ne salva gli id in un vettoreUtenteIdNome


//utilità
void TrovaSostituisciBrano(Database *BaseDati, Brano sostituto); //trova la posizione di sostituto nel vettore di brani del database, e ci copia sostituto
void TrovaSostituisciArtista(Database *BaseDati, Artista sostituto); //trova la posizione di sostituto nel vettore di artisti del database, e ci copia sostituto
void TrovaSostituisciAlbum(Database *BaseDati, Album sostituto); //trova la posizione di sostituto nel vettore di album del database, e ci copia sostituto
void TrovaSostituisciUtente(Database *BaseDati, Utente sostituto); //trova la posizione di sostituto nel vettore di utenti del database, e ci copia sostituto
void TrovaSostituisciPlaylist(Database *BaseDati, Playlist sostituto); //trova la posizione di sostituto nel vettore di playlist del database, e ci copia sostituto
int ControllarePossessoPlaylist(Playlist* elencoPlaylist, int idUtenteCorrente,int idPlaylistDaVerificare); //controlla se il campo idUtente della struttura playlist con idPlaylist uguale a idPlaylistDaVerificare è uguale a idUtenteCorrente; Restituisce 1 se è uguale, 0 altrimenti

int RicercaPosizioneBranoPlaylistIdBrano(int idBrano, PlaylistBrano* vet); //cerca e restituisce la posizione nel vettore vet della struttura avente il campo idBrano uguale a idBrano dato in input
int RicercaPosizioneBranoPlaylistIdPlaylist(int IdPlaylist, PlaylistBrano* vet); //cerca e restituisce la posizione nel vettore vet della struttura avente il campo idPlaylist uguale a idPlaylist dato in input
int RicercaPosizioneBranoGenereIdGenere(int IdGenere, BranoGenere* vet);//cerca e restituisce la posizione nel vettore vet della struttura avente il campo idGenere uguale a idGenere dato in input
int RicercaPosizioneBranoArtistaIdBrano(int idBrano, BranoArtista* vet); //cerca e restituisce la posizione nel vettore vet della struttura avente il campo idBrano uguale a idBrano dato in input
int RicercaPosizioneBranoArtistaIdArtista(int idArtista, BranoArtista* vet);//cerca e restituisce la posizione nel vettore vet della struttura avente il campo idArtista uguale a idArtista dato in input
int RicercaPosizioneBranoAlbumIdAlbum(int idAlbum, BranoAlbum* vet);//cerca e restituisce la posizione nel vettore vet della struttura avente il campo idAlbum uguale a idAlbum dato in input
int RicercaPosizioneBranoAlbumIdBrano(int idBrano, BranoAlbum* vet); //cerca e restituisce la posizione nel vettore vet della struttura avente il campo idBrano uguale a idBrano dato in input

#endif /* RICERCA_H_ */
