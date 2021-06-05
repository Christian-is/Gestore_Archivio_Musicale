/*
 * gestione.h
 *
 *  Created on: May 9, 2020
 *      Author: Gruppo 2
 *
 *  Modulo che si occupa della gestione delle funzioni di base dell'archivio musicale
 */

#ifndef GESTIONE_H_
#define GESTIONE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_MAX 30
//massima lunghezza di una stringa
#define ELEM_MAX 100
//massimo numero di elementi di una tabella del file
#define SENTINELLA -1
//valore che indica la fine di un vettore
#define OP_RIUSCITA 0
#define INS_FALLITO 1
#define LUNG_MIN 6
#define GEN_MIN 1

typedef struct{
	int idBrano;
	char nome[STRING_MAX];
	int durata;
	int anno;
	int ascolti;
}Brano;

typedef struct{
	int idArtista;
	char nome[STRING_MAX];
	char cognome[STRING_MAX];
	char NomeArte[STRING_MAX];
	char linkBio[STRING_MAX];
}Artista;

//identifica da chi è cantato questo brano
typedef struct{
	int idBrano;
	int idArtista;
}BranoArtista;

typedef struct{
	int idAlbum;
	char titolo[STRING_MAX];
	int anno;
}Album;

//da che brani è formato l’album
typedef struct{
	int idAlbum;
	int idBrano;
}BranoAlbum;

//genere della canzone: pop, rock,…
typedef struct{
	int idGenere;
	char nome[STRING_MAX];
}Genere;

//brano che appartiene al genere considerato
typedef struct{
	int idBrano;
	int idGenere;
}BranoGenere;

typedef struct{
	int idPlaylist;
	int idUtente;
	char nome[STRING_MAX];
	char descrizione[(STRING_MAX *8)+10];
	int pubblica;
}Playlist;

//brani da cui è composta una playlist
typedef struct{
	int idPlaylist;
	int idBrano;
}PlaylistBrano;

typedef struct{
	int idUtente;
	char nomeUtente[STRING_MAX *2];
	char password[STRING_MAX *2];
	int admin;
}Utente;

typedef struct{
	int utenteCorrente;
	Brano brano[ELEM_MAX];
	Artista artista[ELEM_MAX];
	BranoArtista branoArtista[ELEM_MAX];
	Album album[ELEM_MAX];
	BranoAlbum branoAlbum[ELEM_MAX];
	Genere genere[ELEM_MAX];
	BranoGenere branoGenere[ELEM_MAX];
	Playlist playlist[ELEM_MAX];
	PlaylistBrano playlistBrano[ELEM_MAX];
	Utente utente[ELEM_MAX];
	int ultimoEsito;
}Database;

//questo database va inizializzato con tutti gli elementi a -1 (l'ultima struttura con valore -1 indica la fine del vettore)
void InizializzareDatabaseVuoto(Database *musica); //inizializza le ELEM_MAX strutture di ogni campo del database a valori id SENTINELLA
void CaricareFile(Database *musica); //carica i file binari nella struttura database
void SalvareSuFile(Database musica); //salva su file il database in memoria
void RipristinareFile(Database *musica); //copia un precedente backup in memoria
void BackupFile(Database musica); //copia lo stato attuale del database in file binari

//funzioni secondarie
int ContareStruttureValideBrano(Brano *brano); //riceve un vettore di brani e conta le strutture con id diverso da SENTINELLA
int ContareStruttureValideArtista(Artista *artista); //riceve un vettore di artista e conta le strutture con id diverso da SENTINELLA
int ContareStruttureValideAlbum(Album *album); //riceve un vettore di album e conta le strutture con id diverso da SENTINELLA
int ContareStruttureValidePlaylist(Playlist *playlist); //riceve un vettore di playlist e conta le strutture con id diverso da SENTINELLA
int ContareStruttureValideUtente(Utente *utente); //riceve un vettore di utente e conta le strutture con id diverso da SENTINELLA
int ContareStruttureValideGenere(Genere *genere); //riceve un vettore di genere e conta le strutture con id diverso da -SENTINELLA
int ContareStruttureValideBranoArtista(BranoArtista *branoArtista); //riceve un vettore di branoartista e conta le strutture con id diverso da SENTINELLA
int ContareStruttureValideBranoAlbum(BranoAlbum *branoAlbum); //riceve un vettore di branoalbum e conta le strutture con id diverso da SENTINELLA
int ContareStruttureValidePlaylistBrano(PlaylistBrano *playlistBrano); //riceve un vettore di playlistbrano e conta le strutture con id diverso da SENTINELLA
int ContareStruttureValideBranoGenere(BranoGenere *branoGenere); //riceve un vettore di branogenere e conta le strutture con id diverso da SENTINELLA
int ContareCollegamentiBranoArtistaIdBrano(int idBrano, BranoArtista* vettoreBranoArtista); //conta il numero di associazioni di un brano con un artista
void InizializzareVettore(int* vet); //inizializza un vettore al valore SENTINELLA

//funzioni inserimento
void ProceduraInserimentoDaBrano(Database* musica); //funzione che avvia la procedura di inserimento di un elemento nel database a partire dal brano
void ProceduraInserimentoAlbum(Database* musica); //funzione che avvia la procedura di inserimento di un elemento nel database a partire dall'album
void ProceduraInserimentoArtista(Database* musica); //funzione che avvia la procedura di inserimento di un elemento nel database a partire dall'artista

Genere ChiediInserimentoGenere(); //chiede all'utente di inserire il nome di un genere, e ritorna in output una struttura di tipo Genere con un idGenere non ancora impostato

void InserireBrano(Database* musica, Brano* nuovo); //funzione che inserisce una struttura di tipo Brano nel database
void InserireAlbum(Database* musica, Album* nuovo); //funzione che inserisce una struttura di tipo Album nel database
void InserireArtista(Database* musica, Artista* nuovo); //funzione che inserisce una struttura di tipo Artista nel database

int CercaEsistenzaNomeBrano(Brano* elenco, char* nuovo);	//Cerca la presenza del brano all'interno del database confrontandolo con quello ricevuto in input, in caso negativo restituisce SENTINELLA, in caso positivo restituisce la posizione del brano cercato all'interno del vettore brano
int CercaEsistenzaNomeArtista(Artista* elenco, char* nuovo);// Cerca la presenza dell'artista all'interno del database confrontandolo con quello ricevuto in input, in caso negativo restituisce SENTINELLA, in caso positivo restituisce la posizione dell'artista cercato all'interno del vettore artista
int CercaEsistenzaTitoloAlbum(Album* elenco, char* nuovo);	//Cerca la presenza dell'album all'interno del database confrontandolo con quello ricevuto in input, in caso negativo restituisce SENTINELLA, in caso positivo restituisce la posizione dell'album cercato all'interno del vettore album
int CercaEsistenzaGenere(Genere* elenco, char* genereinput); //Cerca la presenza del genere all'interno del database confrontandolo con quello ricevuto in input, in caso negativo restituisce SENTINELLA, in caso positivo restituisce la posizione del genere cercato all'interno del vettore genere

int CalcolaMaxBrano(Brano* elenco); //Calcola e restituisce il più grande fra gli idBrano del vettore brano presente nel database
int CalcolaMaxAlbum(Album* elenco); //Calcola il più grande fra gli idAlbum del vettore album del database
int CalcolaMaxArtista(Artista* elenco); //Calcola il più grande fra gli idArtista del vettore artista del database
int CalcolaMaxGenere(Genere* elenco); //Cerca il più grande fra gli idGenere del vettore genere del database

void InserireBranoArtista(Database* musica, int chiavebrano, int chiaveartista); /* Funzione che inserisce nel vettore Brano-Artista le due chiavi ricevute in input */
void InserireBranoAlbum(Database* musica, int chiavebrano, int chiavealbum); /* Funzione che inserisce nel vettore Brano-Album le due chiavi ricevute in input */
void InserireBranoGenere(Database* musica, int chiavebrano, int chiavegenere); /* Funzione che inserisce nel vettore Brano-Genere le due chiavi ricevute in input */

int ControlloValiditaAnno(int anno); //Funzione che controlla che l'anno inserito rispetti il vincolo > 1000, restituisce il valore 1 se non è rispettata la condizione, 0 nel caso opposto
int ControlloValiditaDurata(int durata); // Funzione che controlla che la durata inserita rispetti il vincolo > 0, restituisce il valore 1 se non è rispettata la condizione, 0 nel caso opposto

void ChiediInserimentoNomeBrano(char* nuovo); //chiede all'utente di inserire il nome di un brano, salvandolo in una stringa ricevuta in input
int ChiediInserimentoDurataBrano(); //chiede all'utente di inserire una durata (valida) per un brano, e la restituisce in output
int ChiediInserimentoAnnoBrano(); //chiede all'utente di inserire un anno (valido) per un brano, e lo restituisce in output

void ChiediInserimentoNomeArteArtista(char* nuovo); //chiede all'utente di inserire il nome d'arte di un artista, salvandolo in una stringa ricevuta in input
void ChiediInserimentoNomeArtista(char* nuovo); //chiede all'utente di inserire il nome di un artista, salvandolo in una stringa ricevuta in input
void ChiediInserimentoCognomeArtista(char* nuovo);//chiede all'utente di inserire il cognome di un artista, salvandolo in una stringa ricevuta in input
void ChiediInserimentoLinkArtista(char* nuovo); //chiede all'utente di inserire il link della biografia di un artista, salvandolo in una stringa ricevuta in input

int ChiediInserimentoAnnoAlbum(); //chiede all'utente di inserire un anno (valido) per un album, e lo restituisce in output
void ChiediInserimentoTitoloAlbum(char* nuovo); //chiede all'utente di inserire il titolo di un album, salvandolo in una stringa ricevuta in input

void AggiungereGenere(Database *BaseDati); //funzione che avvia la procedura di inserimento di un nuovo genere nel database. Stampa a video se tale procedura va a buon fine o meno
void LeggereGenereDaTastiera(Genere* NuovoGenere); //acquisisce le informazoni del genere da tastiera
int RicercaGeneriSimili(Database* BaseDati, Genere NuovoGenere); //funzione che controlla se il nome di un genere che si vuole inserire nel database è già presente. Restituisce 1 se è già presente, 0 altrimenti
void InserireGenere(Database *BaseDati, Genere NuovoGenere); //inserisce una struttura di tipo Genere nel database

void AggiungerePlaylist(Database *BaseDati); //funzione che avvia la procedura di inserimento di una nuova playlist nel database. Stampa a video se tale procedura va a buon fine o meno
void LeggerePlaylistDaTastiera(Playlist* NuovoPlaylist); //acquisisce le informazoni della playlist da tastiera
int RicercaPlaylistSimili(Database* BaseDati, Playlist NuovoPlaylist); //funzione che controlla se il nome di una playlist dell'utente che si vuole inserire nel database è già presente. Restituisce 1 se è già presente, 0 altrimenti


//funzioni di modifica
void ModificareBrano(int id, int campo, Database *musica); //funzione che modifica il campo di un brano nel database. Riceve in input l'id del brano, l'identificativo numerico del campo e il database
void ModificareArtista(int id, int campo, Database *musica);//funzione che modifica il campo di un artista nel database. Riceve in input l'id dell'artista, l'identificativo numerico del campo e il database
void ModificareAlbum (int id, int campo, Database *musica);//funzione che modifica il campo di un album nel database. Riceve in input l'id dell'album, l'identificativo numerico del campo e il database


//funzioni di cancellazione
void CancellareBrano(Database* BaseDati,int idBranoDaCancellare); //funzione che avvia la procedura di cancellazione di un brano dal database. Cancella anche le tabelle di associazione brano-album, brano-artista e brano-playlist
void CancellareAlbum(Database* BaseDati,int idAlbumDaCancellare); //funzione che avvia la procedura di cancellazione di un album dal database. Cancella anche le tabelle di associazione brano-album
void CancellareArtista(Database* BaseDati,int idArtistaDaCancellare); //funzione che avvia la procedura di cancellazione di un artista dal database. Cancella anche le tabelle di associazione brano-artista e i brani senza artista
void CancellareGenere(Database* BaseDati,int idGenereDaCancellare); //funzione che avvia la procedura di cancellazione di un genere dal database. Cancella anche le tabelle di associazione brano-genere e tutti i brani associati al genere
void SpostareSinistraVettoreGenere(Genere* vet,int i); //sposta a sinistra il vettore in input a partire dalla posizione i
void SpostareSinistraVettoreBranoGenere(BranoGenere* vet, int i);//sposta a sinistra il vettore in input a partire dalla posizione i
void SpostareSinistraVettoreBrano(Brano* vet, int i);//sposta a sinistra il vettore in input a partire dalla posizione i
void SpostareSinistraVettoreBranoArtista(BranoArtista* vet, int i);//sposta a sinistra il vettore in input a partire dalla posizione i
void SpostareSinistraVettoreBranoAlbum(BranoAlbum* vet, int i);//sposta a sinistra il vettore in input a partire dalla posizione i
void SpostareSinistraVettoreArtista(Artista* vet, int i);//sposta a sinistra il vettore in input a partire dalla posizione i
void SpostareSinistraVettoreAlbum(Album* vet, int i);//sposta a sinistra il vettore in input a partire dalla posizione i

////////funzioni di struttura///////////
/*'leggere' e 'scrivere' elemento di ogni struttura*/
//funzioni di struttura
int LeggereUltimoEsito(Database* BaseDati);
void ScrivereUltimoEsito(Database* BaseDati, int ultimoEsito);
int LeggereUtenteCorrente(Database* BaseDati);
void ScrivereUtenteCorrente(Database* BaseDati, int idUtenteCorrente);
void LeggereVettoreUtente(Utente *vettoreUtente,Database* BaseDati); //legge vettore Utente dalla base dati
void ScrivereVettoreUtente(Utente *vettoreUtente, Database* BaseDati);//scrive in BaseDati vettoreUtente
void LeggereVettoreGenere(Genere *vettoreGenere,Database* BaseDati);//legge vettore Genere dalla base dati
void ScrivereVettoreGenere(Genere *vettoreGenere,Database* BaseDati);//scrive in BaseDati vettoreGenere
void LeggereVettorePlaylist(Playlist *vettorePlaylist,Database* BaseDati);
void ScrivereVettorePlaylist(Playlist *vettorePlaylist,Database* BaseDati);
void LeggereVettoreBranoPlaylist(PlaylistBrano *vettorePlaylistBrano, Database* BaseDati);
void ScrivereVettoreBranoPlaylist(PlaylistBrano *vettorePlaylistBrano, Database* BaseDati);
void LeggereVettoreBrano(Brano *vettoreBrano, Database* BaseDati);
void ScrivereVettoreBrano(Brano *vettoreBrano, Database* BaseDati);
void LeggereVettoreArtista(Artista *vettoreArtista, Database* BaseDati);
void ScrivereVettoreArtista(Artista *vettoreArtista, Database* BaseDati);
void LeggereVettoreAlbum(Album *vettoreAlbum, Database* BaseDati);
void ScrivereVettoreAlbum(Album *vettoreAlbum, Database* BaseDati);
void LeggereVettoreBranoAlbum(BranoAlbum *vettoreBranoAlbum, Database* BaseDati);
void ScrivereVettoreBranoAlbum(BranoAlbum *vettoreBranoAlbum, Database* BaseDati);
void LeggereVettoreBranoArtista(BranoArtista *vettoreBranoArtista, Database* BaseDati);
void ScrivereVettoreBranoArtista(BranoArtista *vettoreBranoArtista, Database* BaseDati);


Utente LeggereUtente(Utente *vettoreUtente, int i);
void ScrivereUtente(Utente *vettoreUtente, int i, Utente UtScelto);
void LeggereNomeUtente(Utente UtScelto, char* nomeUtente); //salva in nomeUtente quello letto
void ScrivereNomeUtente(Utente* UtScelto,char* nomeUtente);
int LeggereIdUtente(Utente UtScelto);
void ScrivereIdUtente(Utente* UtScelto,int idUtente);
void LeggerePassword(Utente UtScelto, char* password); //salva in password quello letto
void ScriverePassword(Utente* UtScelto, char* password);
int LeggereAdmin(Utente UtScelto);
void ScrivereAdmin(Utente* UtScelto,int admin);

Genere LeggereGenere(Genere* vettoreGenere, int i);
void ScrivereGenere(Genere* vettoreGenere,int i,Genere GenScelto);
int LeggereIdGenere(Genere GenScelto);
void ScrivereIdGenere(Genere* GenScelto,int idGenere);
void LeggereNomeGenere(Genere GenScelto, char* nomeGenere);//salva in nomeGenere quello letto
void ScrivereNomeGenere(Genere* GenScelto,char* nomeGenere);

Playlist LeggerePlaylist(Playlist* vettorePlaylist, int i);
void ScriverePlaylist(Playlist* vettorePlaylist,int i,Playlist PlaylistScelto);
int LeggereIdPlaylist(Playlist PlaylistScelto);
void ScrivereIdPlaylist(Playlist* PlaylistScelto,int idPlaylist);
void ScrivereIdUtentePlaylist(Playlist* PlaylistScelto, int idUtenteCorrente);
int LeggereIdUtentePlaylist(Playlist PlaylistScelto);
void LeggereNomePlaylist(Playlist PlaylistScelto, char* nomePlaylist);
void ScrivereNomePlaylist(Playlist* PlaylistScelto,char* nomePlaylist);
void ScrivereDescrizionePlaylist(Playlist *PlaylistScelto, char* descrizionePlaylist);
void LeggereDescrizionePlaylist(Playlist PlaylistScelto, char* descrizionePlaylist);
int LeggereVisibilitaPlaylist(Playlist PlaylistScelto);
void ScrivereVisibilitaPlaylist(Playlist* PlaylistScelto, int n);

Brano LeggereBrano(Brano* vettoreBrano, int i);
int LeggereIdBrano(Brano br);
void ScrivereIdBrano(Brano* br, int id);
void LeggereNomeBrano(Brano br, char *parola);
void ScrivereNomeBrano(Brano* br, char *parola);
int LeggereDurataBrano(Brano br);
void ScrivereDurataBrano(Brano* br, int durata);
int LeggereAnnoBrano(Brano br);
void ScrivereAnnoBrano(Brano* br, int anno);
int LeggereAscoltiBrano(Brano br);
void ScrivereAscoltiBrano(Brano* br, int ascolti);

Album LeggereAlbum(Album* vettoreAlbum, int i);
int LeggereIdAlbum(Album al);
void ScrivereIdAlbum(Album* al, int id);
void LeggereTitoloAlbum(Album al, char *parola);
void ScrivereTitoloAlbum(Album* al, char *parola);
int LeggereAnnoAlbum(Album al);
void ScrivereAnnoAlbum(Album* al, int anno);

Artista LeggereArtista(Artista* vettoreArtista, int i);
int LeggereIdArtista(Artista ar);
void ScrivereIdArtista(Artista* ar, int id);
void LeggereNomeArtista(Artista ar, char *parola);
void ScrivereNomeArtista(Artista* ar, char *parola);
void LeggereCognomeArtista(Artista ar, char *parola);
void ScrivereCognomeArtista(Artista* ar, char *parola);
void LeggereNomeArteArtista(Artista ar, char *parola);
void ScrivereNomeArteArtista(Artista* ar, char *parola);

BranoAlbum LeggereBranoAlbum(BranoAlbum* vettoreBranoAlbum, int i);
int LeggereIdBranoBranoAlbum(BranoAlbum ba);
void ScrivereIdBranoBranoAlbum(BranoAlbum* ba,int id);
int LeggereIdAlbumBranoAlbum(BranoAlbum ba);
void ScrivereIdAlbumBranoAlbum(BranoAlbum* ba,int id);

BranoArtista LeggereBranoArtista(BranoArtista* vettoreBranoArtista, int i);
int LeggereIdBranoBranoArtista(BranoArtista ba);
void ScrivereIdBranoBranoArtista(BranoArtista* ba,int id);
int LeggereIdArtistaBranoArtista(BranoArtista ba);
void ScrivereIdArtistaBranoArtista(BranoArtista* ba,int id);

BranoGenere LeggereBranoGenere(BranoGenere* vettoreBranoGenere, int i);
int LeggereIdBranoBranoGenere(BranoGenere gen);
void ScrivereIdBranoBranoGenere(BranoGenere* gen,int id);
int LeggereIdGenereBranoGenere(BranoGenere gen);
void ScrivereIdGenereBranoGenere(BranoGenere* gen,int id);

PlaylistBrano LeggerePlaylistBrano(PlaylistBrano* vettorePlaylistBrano, int i);
int LeggereIdBranoPlaylistBrano(PlaylistBrano pl);
void ScrivereIdBranoPlaylistBrano(PlaylistBrano* pl,int id);
int LeggereIdPlaylistPlaylistBrano(PlaylistBrano pl);
void ScrivereIdPlaylistPlaylistBrano(PlaylistBrano* pl,int id);


/////////////////////////////////////////////


#endif /* GESTIONE_H_ */
