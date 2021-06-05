/*
 * ricerca.c
 *
 *  Created on: May 27, 2020
 *      Author: Gruppo 2
 */
#include "ricerca.h"
#include "string.h"
#include "stampabasedati.h"

/*dato un idUtente, la funzione cerca la struttura utente corrispondente nel vettore di utenti del database;
 * Se non lo trovo, restituisco una struttura non valida
 */
Utente RicercareUtenteId(Utente* elencoUtenti, int idUtenteCercato){
	Utente ut;
	int i = 0;
	ut.idUtente = SENTINELLA; //lo imposto a valore non valido nel caso l'utente non esista
	while((elencoUtenti[i].idUtente != idUtenteCercato) && (i<ELEM_MAX)){
		i++;
	}
	ut = elencoUtenti[i];
	return ut;
}
/*dato un idPlaylist, la funzione cerca la struttura playlist corrispondente nel vettore di playlist del database;
 * Se non lo trovo, restituisco una struttura non valida
 */
Playlist RicercarePlaylistId(Playlist *elencoPlaylist, int idPlaylistCercata){
	Playlist pl;
	int i = 0;
	pl.idPlaylist = SENTINELLA;//lo imposto a valore non valido nel caso la playlist non esista
	while((elencoPlaylist[i].idPlaylist != idPlaylistCercata) && (i<ELEM_MAX)){
		i++;
	}
	pl = elencoPlaylist[i];
	return pl;
}

Brano RicercareBranoId(Brano* elencoBrani, int idBranoCercato){
	Brano br;
	int i = 0;
	br.idBrano = SENTINELLA;	//lo imposto a valore non valido nel caso  non esista
	while((elencoBrani[i].idBrano != idBranoCercato) && (i<ELEM_MAX)){
		i++;
	}
	br = elencoBrani[i];
	return br;
}

Artista RicercareArtistaId(Artista* elencoArtisti, int idArtistaCercato){
	Artista ar;
	int i = 0;
	ar.idArtista = SENTINELLA;	//lo imposto a valore non valido nel caso  non esista
	while((elencoArtisti[i].idArtista != idArtistaCercato) && (i<ELEM_MAX)){
		i++;
	}
	ar = elencoArtisti[i];
	return ar;
}

Album RicercareAlbumId(Album* elencoAlbum, int idAlbumCercato){
	Album al;
	int i = 0;
	al.idAlbum = SENTINELLA;	//lo imposto a valore non valido nel caso  non esista
	while((elencoAlbum[i].idAlbum != idAlbumCercato) && (i<ELEM_MAX)){
		i++;
	}
	al = elencoAlbum[i];
	return al;
}







void RicercareBrano(Database *musica){
	int scelta;
	int anno;
	char parola[STRING_MAX];
	int vettoreId[ELEM_MAX]; //da inizializzare a SENTINELLA. Conterrà degli id corrispondenti a strutture da stampare a video

	InizializzareVettore(vettoreId);
	do{
		printf("Digitare 1 per ricercare brano per titolo, 2 per ricercare brano per anno: ");
		scanf("%d", &scelta);
	}while((scelta != 1) && (scelta != 2));

	if(scelta == 1){
		printf("Inserire titolo brano cercato: ");
		scanf("%s", parola);
		RicercareBranoTitolo(*musica, vettoreId, parola); //salva in vettoreId i match trovati
	}else if(scelta == 2){
		printf("Inserire anno brano cercato: ");
		scanf("%d", &anno);
		RicercareBranoAnno(*musica, vettoreId, anno);
	}
	StampareRisultatiBrano(musica, vettoreId);//stampa a video i brani corrispondenti agli idBrano nel vettore
	return;
}

void RicercareAlbum(Database *musica){
	int scelta;
	int anno;
	char parola[STRING_MAX];
	int vettoreId[ELEM_MAX]; //da inizializzare a SENTINELLA. Conterrà degli id corrispondenti a strutture da stampare a video

	InizializzareVettore(vettoreId);
	do{
	printf("Digitare 1 per ricercare album per titolo, 2 per ricercare album per anno: ");
	scanf("%d", &scelta);
	}while((scelta != 1) && (scelta != 2));

	if(scelta == 1){
		printf("Inserire titolo album cercato: ");
		scanf("%s", parola);
		RicercareAlbumTitolo(*musica, vettoreId, parola);	//salva in vettoreId i match trovati
	}else if(scelta == 2){
		printf("Inserire anno brano cercato: ");
		scanf("%d", &anno);
		RicercareAlbumAnno(*musica, vettoreId, anno);
	}
	StampareRisultatiAlbum(musica, vettoreId);	//stampa a video gli album corrispondenti agli idAlbum nel vettore

	//chiedere se si vuole visualizzare i brani di questi album
	do{
		printf("Vuoi visualizzare il contenuto di questi album? 1 si, 0 no");
		scanf("%d", &scelta);
	}while((scelta != 1) && (scelta != 0));
	if(scelta == 1){
			StampareBraniDaAlbum(musica, vettoreId); 			//stampa i brani corrispondenti agli idAlbum nel vettore
	}
	return;
}

void RicercareArtista(Database *musica){
	int scelta;
	char parola[STRING_MAX];
	int vettoreId[ELEM_MAX]; //da inizializzare a SENTINELLA. Conterrà degli id corrispondenti a strutture da stampare a video

	InizializzareVettore(vettoreId);
	do{
		printf("Digitare 1 per ricercare artista per nome, 2 per ricercare artista per cognome, 3 per ricercare artista per nome d'arte: ");
		scanf("%d", &scelta);
	}while((scelta != 1) && (scelta != 2) && (scelta != 3));

	if(scelta == 1){
		printf("Inserire nome artista cercato: ");
		scanf("%s", parola);
		RicercareArtistaNome(*musica, vettoreId, parola);		//salva in vettoreId i match trovati
	}else if(scelta == 2){
		printf("Inserire cognome artista cercato: ");
		scanf("%s", parola);
		RicercareArtistaCognome(*musica, vettoreId, parola);
	}else if(scelta == 3){
		printf("Inserire nome d'arte artista cercato: ");
		scanf("%s", parola);
		RicercareArtistaNomeArte(*musica, vettoreId, parola);
	}
	StampareRisultatiArtista(musica, vettoreId); 	//stampa a video gli artisti corrispondenti agli idArtista nel vettore

	//chiedere se si vuole visualizzare i brani di uno di questi artisti
	do{
	printf("Vuoi visualizzare i brani di questi artisti? 1 si, 0 no");
	scanf("%d", &scelta);
	}while((scelta != 1) && (scelta != 0));
	if(scelta==1){
			StampareBraniDaArtista(musica, vettoreId); 				//stampa i brani corrispondenti agli idArtista nel vettore
	}
	return;
}

void RicercarePlaylist(Database *musica){
	int scelta;
	char parola[STRING_MAX];
	int vettoreId[ELEM_MAX]; //da inizializzare a SENTINELLA. Conterrà degli id corrispondenti a strutture da stampare a video

	InizializzareVettore(vettoreId);
	do{
		printf("Digitare 1 per ricercare playlist per nome, 2 per ricercare playlist per utente: ");
		scanf("%d", &scelta);
	}while((scelta != 1) && (scelta != 2));

	if(scelta==1){
		printf("Inserire nome playlist cercata: ");
		scanf("%s", parola);
		//solo playlist pubbliche, tutte se sono admin
		RicercarePlaylistNome(*musica, vettoreId, parola);		//salva in vettoreId i match trovati
	}else if(scelta==2){
		printf("Inserire nome utente creatore della playlist cercata: ");
		scanf("%s", parola);
		//solo playlist pubbliche, tutte se sono admin
		RicercarePlaylistUtente(*musica, vettoreId, parola);
	}
	StampareRisultatiPlaylist(musica, vettoreId); //stampa a video le playlist corrispondenti agli idPlaylist nel vettore

	//chiedere se si vuole visualizzare i brani di una delle playlist
	do{
		printf("Vuoi visualizzare il contenuto di queste playlist? 1 si, 0 no");
		scanf("%d", &scelta);
	}while((scelta != 1) && (scelta != 0));
	if(scelta==1){
			StampareBraniDaPlaylist(musica, vettoreId); 		//stampa i brani corrispondenti agli idPlaylist nel vettore
	}
	return;
}

void RicercareUtente(Database *musica){
	char parola[STRING_MAX];
	int vettoreId[ELEM_MAX]; //da inizializzare a SENTINELLA. Conterrà degli id corrispondenti a strutture da stampare a video

	printf("Inserire nome utente cercato: ");
	scanf("%s", parola);

	InizializzareVettore(vettoreId);
	RicercareUtenteNome(*musica, vettoreId, parola);
	StampareRisultatiUtente(musica, vettoreId); 		//stampa a video le informazioni sull'utente corrispondente all'idUtente nel vettore
	return;
}

void RicercareBranoTitolo(Database Musica, int *VettoreIdBrani, char *TitoloScelto){ //funzione che effettua la ricerca del brano tramite il titolo
	int i; //contatore del vettore degli Id
	int c; //contatore del vettore dei brani
	i=0; //setto il valore di i a 0
	c=0; //setto il valore di c a 0
	do {
		if ((strcmp(TitoloScelto,Musica.brano[c].nome)==0)){ //controllo se il nome cercato è identico a un'altro presente nel vettore dei brani
			VettoreIdBrani[i]=Musica.brano[c].idBrano; //se la condizione è vera allora inserisco l'id del brano nel vettore nella posizione i
			i=i+1; //aumento il valore di i
		}
		c=c+1; //aumento il valore di c
	} while (c!=ELEM_MAX); //esegue le operazioni finchè c è diverso dal valore di ELEM_MAX ovvero 100
	return;
}

void RicercareBranoAnno(Database Musica, int *VettoreIdBrani, int Anno){ //funzione che effettua la ricerca del brano tramite l'anno
	int i; //contatore del vettore degli Id
	int c; //contatore del vettore dei brani
	i=0; //setto il valore di i a 0
	c=0; //setto il valore di c a 0
	do {
		if (Anno==Musica.brano[c].anno){ //controllo se l'anno del brano nella posizione c  è identico a l'anno inserito dall'utente
			VettoreIdBrani[i]=Musica.brano[c].idBrano; //se la condizione è vera allora inserisco l'id del brano nel vettore nella posizione i
			i=i+1; //aumento il valore di i
		}
		c=c+1; //aumento il valore di c
	} while (c!=ELEM_MAX); //esegue le operazioni finchè c è diverso dal valore di ELEM_MAX ovvero 100
	return;
}

void RicercareAlbumTitolo(Database Musica,int *vetAlbumIdTitolo,char *titolo){
	int i = 0;
	int k = 0;

	while(k < ELEM_MAX){
		if (strcmp(titolo,Musica.album[k].titolo) == 0){
			vetAlbumIdTitolo[i] = Musica.album[k].idAlbum;
			i = i + 1;
		}
		k = k + 1;
	}
	return;
}

void RicercareAlbumAnno(Database Musica,int *vetAlbumIdAnno,int anno){
	int i = 0;
	int k = 0;

	while(k < ELEM_MAX){
		if (anno == Musica.album[k].anno){
			vetAlbumIdAnno[i] = Musica.album[k].idAlbum;
			i = i + 1;
		}
		k = k + 1;
	}

    return;
}

void RicercareArtistaNome(Database Musica,int *vetArtistaIdNome,char *artistaNome){
	int i = 0;
	int k = 0;

	while(k < ELEM_MAX){
			if (strcmp(artistaNome,Musica.artista[k].nome) == 0){
				vetArtistaIdNome[i] = Musica.artista[k].idArtista;
				i = i + 1;
			}
			k = k + 1;
	}
	return;
}

void RicercareArtistaCognome(Database Musica,int *vetArtistaIdCognome,char *artistaCognome){
	int i = 0;
	int k = 0;

	while(k < ELEM_MAX){
			if (strcmp(artistaCognome,Musica.artista[k].cognome) == 0){
				vetArtistaIdCognome[i] = Musica.artista[k].idArtista;
				i = i + 1;
			}
			k = k + 1;
	}
	return;
}

void RicercareArtistaNomeArte(Database Musica,int *vetArtistaIdNomeArte,char *artistaNomeArte){
	int i = 0;
	int k = 0;

	while(k < ELEM_MAX){
			if (strcmp(artistaNomeArte,Musica.artista[k].NomeArte) == 0){
				vetArtistaIdNomeArte[i] = Musica.artista[k].idArtista;
				i = i + 1;
			}
			k = k + 1;
	}
	return;

}

void RicercarePlaylistNome(Database Musica, int *VettoreIdPlaylist, char *NomeScelto){ //funzione per ricercare una playlist tramite il nome della palylist
	int i; //contatore del vettore degli Id
	int c; //contatore del vettore delle playlist
	Utente elencoUtenti[ELEM_MAX];

	LeggereVettoreUtente(elencoUtenti, &Musica);
	i=0; //setto il valore di i a 0
	c=0; //setto il valore di c a 0
	do {
		if ((strcmp(NomeScelto,Musica.playlist[c].nome))==0){ //controllo se il nome inserito dall'utente è uguale a un qualsiasi altro nome presente nel vettore degli utenti
			//solo admin e playlist pubbliche
			if((Musica.playlist[c].pubblica == 1) ||
			(LeggereAdmin(RicercareUtenteId(elencoUtenti,LeggereUtenteCorrente(&Musica))) == 1)){
				VettoreIdPlaylist[i]=Musica.playlist[c].idPlaylist; //se la condizione è vera, alla posizione i di VettoreIdPlaylist viene assegnato il valore IdPlaylist nella posizioen c
			}
			i=i+1; //aumento il valore di i
		}
		c=c+1; //aumento il valore di c
	} while (c!=ELEM_MAX); //esegue le operazioni finchè c è diverso dal valore di ELEM_MAX ovvero 100
	return;
}


void RicercarePlaylistUtente(Database Musica, int *VettoreIdPlaylist, char *NomeScelto){ //funzione per ricercare una playlist tramite il nome del creatore
	int vettoreIdUtente[ELEM_MAX]; //variabile a cui viene assegnato l'Id degli utenti nel caso vanga trovato in nome nel vettore degli utenti
	int i; //contatore del vettore degli IdUtente
	int c; //contatore del vettore delle playlist
	int k; //contatore del vettore di idPlaylist in output
	Utente elencoUtenti[ELEM_MAX];

	LeggereVettoreUtente(elencoUtenti, &Musica);
	InizializzareVettore(vettoreIdUtente);
	RicercareUtenteNome(Musica, vettoreIdUtente, NomeScelto);  //salvo in vettoreIdUtente gli id degli utenti con nome NomeScelto
	k=0; //setto il valore di k a 0, aumenterà solo se inserisco qualcosa
	i=0; //setto il valore di i a 0
	while(vettoreIdUtente[i] != SENTINELLA){
		c=0; //setto il valore di c a 0
		while(Musica.playlist[c].idPlaylist != SENTINELLA){
			if(vettoreIdUtente[i] == Musica.playlist[c].idPlaylist){
				//solo admin e playlist pubbliche
				if((Musica.playlist[c].pubblica == 1) ||
				(LeggereAdmin(RicercareUtenteId(elencoUtenti,LeggereUtenteCorrente(&Musica))) == 1)){
					VettoreIdPlaylist[k] = Musica.playlist[c].idPlaylist; //se la condizione è vera, alla posizione i di VettoreIdPlaylist viene assegnato il valore IdPlaylist nella posizioen c
				}
				k =k+1;
			}
			c =c+1;
		}
		i =i+1;
	}
	return;
}

void RicercarePlaylistIdUtente(int utenteCorrente, Database* musica, int* vettoreId){
	int i = 0;
	int k = 0;
	while(musica->playlist[i].idPlaylist != SENTINELLA){	//scorro le playlist
		if(musica->playlist[i].idUtente == utenteCorrente){	//se la playlist è dell'utente, salvo il suo id in un vettore
			vettoreId[k] = musica->playlist[i].idPlaylist;
			k++;
		}
		i++;
	}

	return;
}


void RicercareUtenteNome(Database Musica,int *vetUtenteIdNome,char *nome){
	int i = 0;
	int k = 0;

	while(k < ELEM_MAX){
			if (strcmp(nome,Musica.utente[k].nomeUtente) == 0){
				vetUtenteIdNome[i] = Musica.utente[k].idUtente;
				i = i + 1;
			}
			k = k + 1;
	}
	return;
}

//funzioni di utilità
void TrovaSostituisciBrano(Database *BaseDati, Brano sostituto){
	int i = 0;
	//cerco la posizione del brano e lo sostituisco con quello aggornato
	while(BaseDati->brano[i].idBrano != sostituto.idBrano){
		i++;
	}
	BaseDati->brano[i] = sostituto; 		//inserisco la struttura aggiornata nel database
	return;
}

void TrovaSostituisciArtista(Database *BaseDati, Artista sostituto){
	int i = 0;
	//cerco la posizione dell'artista e lo sostituisco con quello aggornato
	while(BaseDati->artista[i].idArtista != sostituto.idArtista){
		i++;
	}
	BaseDati->artista[i] = sostituto; 		//inserisco la struttura aggiornata nel database
	return;
}

void TrovaSostituisciAlbum(Database *BaseDati, Album sostituto){
	int i = 0;
	while(BaseDati->album[i].idAlbum != sostituto.idAlbum){
		i++;
	}
	BaseDati->album[i] = sostituto;
	return;
}

void TrovaSostituisciUtente(Database *BaseDati, Utente sostituto){
	int i = 0;
	while(BaseDati->utente[i].idUtente != sostituto.idUtente){
		i++;
	}
	BaseDati->utente[i] = sostituto;
	return;
}

void TrovaSostituisciPlaylist(Database *BaseDati, Playlist sostituto){
	int i = 0;
	while(BaseDati->playlist[i].idPlaylist != sostituto.idPlaylist){
		i++;
	}
	BaseDati->playlist[i] = sostituto;
	return;
}

int ControllarePossessoPlaylist(Playlist* elencoPlaylist, int idUtenteCorrente,int idPlaylistDaVerificare){
	int esito = 0;
	Playlist pl;
	pl = RicercarePlaylistId(elencoPlaylist, idPlaylistDaVerificare);
	if((pl.idUtente == idUtenteCorrente) && (pl.idPlaylist != SENTINELLA)){
		esito = 1;
	}
	return esito;
}

int RicercaPosizioneBranoPlaylistIdBrano(int idBrano,PlaylistBrano* vet){
	int pos = SENTINELLA;
	int i = 0;
	while((i < ELEM_MAX)&&(pos == SENTINELLA)){
		if( LeggereIdBranoPlaylistBrano(vet[i]) == idBrano){
		pos=i;
		}
		i++;
	}
	return pos;
}

int RicercaPosizioneBranoPlaylistIdPlaylist(int IdPlaylist,PlaylistBrano* vet){
	int pos = SENTINELLA;
	int i = 0;
	while((i < ELEM_MAX)&&(pos == SENTINELLA)){
		if( LeggereIdPlaylistPlaylistBrano(vet[i]) == IdPlaylist){
		pos=i;
		}
		i++;
	}
	return pos;
}

int RicercaPosizioneBranoGenereIdGenere(int IdGenere, BranoGenere* vet){
	int pos = SENTINELLA;
	int i = 0;
	while((i < ELEM_MAX)&&(pos == SENTINELLA)){
		if( LeggereIdGenereBranoGenere(vet[i]) == IdGenere){
		pos=i;
		}
		i++;
	}
	return pos;
}

int RicercaPosizioneBranoArtistaIdBrano(int idBrano, BranoArtista* vet){
	int pos = SENTINELLA;
	int i = 0;
	while((i < ELEM_MAX)&&(pos == SENTINELLA)){
		if( LeggereIdBranoBranoArtista(vet[i]) == idBrano){
		pos=i;
		}
		i++;
	}
	return pos;
}

int RicercaPosizioneBranoArtistaIdArtista(int idArtista, BranoArtista* vet){
	int pos = SENTINELLA;
	int i = 0;
	while((i < ELEM_MAX)&&(pos == SENTINELLA)){
		if( LeggereIdArtistaBranoArtista(vet[i]) == idArtista){
		pos=i;
		}
		i++;
	}
	return pos;
}

int RicercaPosizioneBranoAlbumIdAlbum(int idAlbum, BranoAlbum* vet){
	int pos = SENTINELLA;
	int i = 0;
	while((i < ELEM_MAX)&&(pos == SENTINELLA)){
		if( LeggereIdAlbumBranoAlbum(vet[i]) == idAlbum){
		pos=i;
		}
		i++;
	}
	return pos;
}

int RicercaPosizioneBranoAlbumIdBrano(int idBrano, BranoAlbum* vet){
	int pos = SENTINELLA;
	int i = 0;
	while((i < ELEM_MAX)&&(pos == SENTINELLA)){
		if( LeggereIdBranoBranoAlbum(vet[i]) == idBrano){
		pos=i;
		}
		i++;
	}
	return pos;
}
