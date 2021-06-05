/*
 * gestione.c
 *
 *  Created on: May 9, 2020
 *      Author: Christian
 */

#include "gestione.h"
#include "ricerca.h"
#include "playlist.h"

void InizializzareDatabaseVuoto(Database *musica){
	//imposto a un valore sentinella gli id di ogni struttura dei vettori
	int i = 0;
	while(i<ELEM_MAX){
		musica->brano[i].idBrano = SENTINELLA;
		musica->artista[i].idArtista = SENTINELLA;
		musica->album[i].idAlbum = SENTINELLA;
		musica->genere[i].idGenere = SENTINELLA;
		musica->playlist[i].idPlaylist = SENTINELLA;
		musica->utente[i].idUtente = SENTINELLA;
		musica->playlistBrano[i].idBrano = SENTINELLA;
		musica->playlistBrano[i].idPlaylist = SENTINELLA;
		musica->branoAlbum[i].idAlbum = SENTINELLA;
		musica->branoAlbum[i].idBrano = SENTINELLA;
		musica->branoArtista[i].idArtista = SENTINELLA;
		musica->branoArtista[i].idBrano = SENTINELLA;
		musica->branoGenere[i].idBrano = SENTINELLA;
		musica->branoGenere[i].idGenere = SENTINELLA;
		i++;
	}
	return;
}


//aggiungere tra gli input un vettore contenente i puntatori a FILE da aprire
void CaricareFile(Database *musica){
	FILE* fp;
	//il nome dei file può cambiare
	fp = fopen("ArchivioBrani.dat", "rb");
	if(fp == NULL) printf("\nERRORE CARICAMENTO FILE\n");
	fread(musica->brano, sizeof(Brano), ELEM_MAX, fp);
	fclose(fp);
	fp = fopen("ArchivioArtista.dat", "rb");
	if(fp == NULL) printf("\nERRORE CARICAMENTO FILE\n");
	fread(musica->artista, sizeof(Artista), ELEM_MAX, fp);
	fclose(fp);
	fp = fopen("ArchivioBranoArtista.dat", "rb");
	if(fp == NULL) printf("\nERRORE CARICAMENTO FILE\n");
	fread(musica->branoArtista, sizeof(BranoArtista), ELEM_MAX, fp);
	fclose(fp);
	fp = fopen("ArchivioAlbum.dat", "rb");
	if(fp == NULL) printf("\nERRORE CARICAMENTO FILE\n");
	fread(musica->album, sizeof(Album), ELEM_MAX, fp);
	fclose(fp);
	fp = fopen("ArchivioBranoAlbum.dat", "rb");
	if(fp == NULL) printf("\nERRORE CARICAMENTO FILE\n");
	fread(musica->branoAlbum, sizeof(BranoAlbum), ELEM_MAX, fp);
	fclose(fp);
	fp = fopen("ArchivioGenere.dat", "rb");
	if(fp == NULL) printf("\nERRORE CARICAMENTO FILE\n");
	fread(musica->genere, sizeof(Genere), ELEM_MAX, fp);
	fclose(fp);
	fp = fopen("ArchivioBranoGenere.dat", "rb");
	if(fp == NULL) printf("\nERRORE CARICAMENTO FILE\n");
	fread(musica->branoGenere, sizeof(BranoGenere), ELEM_MAX, fp);
	fclose(fp);
	fp = fopen("ArchivioPlaylist.dat", "rb");
	if(fp == NULL) printf("\nERRORE CARICAMENTO FILE\n");
	fread(musica->playlist, sizeof(Playlist), ELEM_MAX, fp);
	fclose(fp);
	fp = fopen("ArchivioPlaylistBrano.dat", "rb");
	if(fp == NULL) printf("\nERRORE CARICAMENTO FILE\n");
	fread(musica->playlistBrano, sizeof(PlaylistBrano), ELEM_MAX, fp);
	fclose(fp);
	fp = fopen("ArchivioUtente.dat", "rb");
	if(fp == NULL) printf("\nERRORE CARICAMENTO FILE\n");
	fread(musica->utente, sizeof(Utente), ELEM_MAX, fp);
	fclose(fp);

	return;
}

void SalvareSuFile(Database musica){
	FILE *fp;
	//il nome dei file può cambiare
	fp = fopen("ArchivioBrani.dat", "wb");
	if(fp == NULL) printf("\nERRORE SALVATAGGIO FILE\n");
	fwrite(musica.brano, sizeof(Brano), ContareStruttureValideBrano(musica.brano), fp);
	fclose(fp);
	fp = fopen("ArchivioArtista.dat", "wb");
	if(fp == NULL) printf("\nERRORE SALVATAGGIO FILE\n");
	fwrite(musica.artista, sizeof(Artista), ContareStruttureValideArtista(musica.artista), fp);
	fclose(fp);
	fp = fopen("ArchivioBranoArtista.dat", "wb");
	if(fp == NULL) printf("\nERRORE SALVATAGGIO FILE\n");
	fwrite(musica.branoArtista, sizeof(BranoArtista), ContareStruttureValideBranoArtista(musica.branoArtista), fp);
	fclose(fp);
	fp = fopen("ArchivioAlbum.dat", "wb");
	if(fp == NULL) printf("\nERRORE SALVATAGGIO FILE\n");
	fwrite(musica.album, sizeof(Album),ContareStruttureValideAlbum(musica.album), fp);
	fclose(fp);
	fp = fopen("ArchivioBranoAlbum.dat", "wb");
	if(fp == NULL) printf("\nERRORE SALVATAGGIO FILE\n");
	fwrite(musica.branoAlbum, sizeof(BranoAlbum),ContareStruttureValideBranoAlbum(musica.branoAlbum), fp);
	fclose(fp);
	fp = fopen("ArchivioGenere.dat", "wb");
	if(fp == NULL) printf("\nERRORE SALVATAGGIO FILE\n");
	fwrite(musica.genere, sizeof(Genere), ContareStruttureValideGenere(musica.genere), fp);
	fclose(fp);
	fp = fopen("ArchivioBranoGenere.dat", "wb");
	if(fp == NULL) printf("\nERRORE SALVATAGGIO FILE\n");
	fwrite(musica.branoGenere, sizeof(BranoGenere), ContareStruttureValideBranoGenere(musica.branoGenere), fp);
	fclose(fp);
	fp = fopen("ArchivioPlaylist.dat", "wb");
	if(fp == NULL) printf("\nERRORE SALVATAGGIO FILE\n");
	fwrite(musica.playlist, sizeof(Playlist),ContareStruttureValidePlaylist(musica.playlist), fp);
	fclose(fp);
	fp = fopen("ArchivioPlaylistBrano.dat", "wb");
	if(fp == NULL) printf("\nERRORE SALVATAGGIO FILE\n");
	fwrite(musica.playlistBrano, sizeof(PlaylistBrano), ContareStruttureValidePlaylistBrano(musica.playlistBrano), fp);
	fclose(fp);
	fp = fopen("ArchivioUtente.dat", "wb");
	if(fp == NULL) printf("\nERRORE SALVATAGGIO FILE\n");
	fwrite(musica.utente, sizeof(Utente), ContareStruttureValideUtente(musica.utente), fp);
	fclose(fp);

	return;
}

void RipristinareFile(Database *musica){
	FILE* fp;
	//il nome dei file può cambiare
	fp = fopen("ArchivioBraniBackup.dat", "rb");
	fread(musica->brano, sizeof(Brano), ELEM_MAX, fp);
	fclose(fp);
	fp = fopen("ArchivioArtistaBackup.dat", "rb");
	fread(musica->artista, sizeof(Artista), ELEM_MAX, fp);
	fclose(fp);
	fp = fopen("ArchivioBranoArtistaBackup.dat", "rb");
	fread(musica->branoArtista, sizeof(BranoArtista), ELEM_MAX, fp);
	fclose(fp);
	fp = fopen("ArchivioAlbumBackup.dat", "rb");
	fread(musica->album, sizeof(Album), ELEM_MAX, fp);
	fclose(fp);
	fp = fopen("ArchivioBranoAlbumBackup.dat", "rb");
	fread(musica->branoAlbum, sizeof(BranoAlbum), ELEM_MAX, fp);
	fclose(fp);
	fp = fopen("ArchivioGenereBackup.dat", "rb");
	fread(musica->genere, sizeof(Genere), ELEM_MAX, fp);
	fclose(fp);
	fp = fopen("ArchivioBranoGenereBackup.dat", "rb");
	fread(musica->branoGenere, sizeof(BranoGenere), ELEM_MAX, fp);
	fclose(fp);
	fp = fopen("ArchivioPlaylistBackup.dat", "rb");
	fread(musica->playlist, sizeof(Playlist), ELEM_MAX, fp);
	fclose(fp);
	fp = fopen("ArchivioPlaylistBranoBackup.dat", "rb");
	fread(musica->playlistBrano, sizeof(PlaylistBrano), ELEM_MAX, fp);
	fclose(fp);
	fp = fopen("ArchivioUtenteBackup.dat", "rb");
	fread(musica->utente, sizeof(Utente), ELEM_MAX, fp);
	fclose(fp);

	return;
}

void BackupFile(Database musica){
	FILE *fp;
	//il nome dei file può cambiare
	fp = fopen("ArchivioBraniBackup.dat", "wb");
	fwrite(musica.brano, sizeof(Brano), ContareStruttureValideBrano(musica.brano), fp);
	fclose(fp);
	fp = fopen("ArchivioArtistaBackup.dat", "wb");
	fwrite(musica.artista, sizeof(Artista), ContareStruttureValideArtista(musica.artista), fp);
	fclose(fp);
	fp = fopen("ArchivioBranoArtistaBackup.dat", "wb");
	fwrite(musica.branoArtista, sizeof(BranoArtista), ContareStruttureValideBranoArtista(musica.branoArtista), fp);
	fclose(fp);
	fp = fopen("ArchivioAlbumBackup.dat", "wb");
	fwrite(musica.album, sizeof(Album),ContareStruttureValideAlbum(musica.album), fp);
	fclose(fp);
	fp = fopen("ArchivioBranoAlbumBackup.dat", "wb");
	fwrite(musica.branoAlbum, sizeof(BranoAlbum),ContareStruttureValideBranoAlbum(musica.branoAlbum), fp);
	fclose(fp);
	fp = fopen("ArchivioGenereBackup.dat", "wb");
	fwrite(musica.genere, sizeof(Genere), ContareStruttureValideGenere(musica.genere), fp);
	fclose(fp);
	fp = fopen("ArchivioBranoGenereBackup.dat", "wb");
	fwrite(musica.branoGenere, sizeof(BranoGenere), ContareStruttureValideBranoGenere(musica.branoGenere), fp);
	fclose(fp);
	fp = fopen("ArchivioPlaylistBackup.dat", "wb");
	fwrite(musica.playlist, sizeof(Playlist),ContareStruttureValidePlaylist(musica.playlist), fp);
	fclose(fp);
	fp = fopen("ArchivioPlaylistBranoBackup.dat", "wb");
	fwrite(musica.playlistBrano, sizeof(PlaylistBrano), ContareStruttureValidePlaylistBrano(musica.playlistBrano), fp);
	fclose(fp);
	fp = fopen("ArchivioUtenteBackup.dat", "wb");
	fwrite(musica.utente, sizeof(Utente), ContareStruttureValideUtente(musica.utente), fp);
	fclose(fp);

	return;
}

int ContareStruttureValideBrano(Brano *brano){
	int i = 0;
	while(brano[i].idBrano != SENTINELLA){
		i++;
	}
	return i;
}

int ContareStruttureValideArtista(Artista *artista){
	int i = 0;
	while(artista[i].idArtista != SENTINELLA){
		i++;
	}
	return i;
}

int ContareStruttureValideAlbum(Album *album){
	int i = 0;
	while(album[i].idAlbum != SENTINELLA){
		i++;
	}
	return i;
}

int ContareStruttureValidePlaylist(Playlist *playlist){
	int i = 0;
	while(playlist[i].idPlaylist != SENTINELLA){
		i++;
	}
	return i;
}

int ContareStruttureValideUtente(Utente *utente){
	int i = 0;
	while(utente[i].idUtente != SENTINELLA){
		i++;
	}
	return i;
}

int ContareStruttureValideGenere(Genere *genere){
	int i = 0;
	while(genere[i].idGenere != SENTINELLA){
		i++;
	}
	return i;
}

int ContareStruttureValideBranoArtista(BranoArtista *branoArtista){
	int i = 0;
	while((branoArtista[i].idBrano != SENTINELLA) && (branoArtista[i].idArtista != SENTINELLA)){
		i++;
	}
	return i;
}

int ContareStruttureValideBranoAlbum(BranoAlbum *branoAlbum){
	int i = 0;
	while((branoAlbum[i].idBrano != SENTINELLA) && (branoAlbum[i].idAlbum != SENTINELLA)){
		i++;
	}
	return i;
}

int ContareStruttureValidePlaylistBrano(PlaylistBrano *playlistBrano){
	int i = 0;
	while((playlistBrano[i].idBrano != SENTINELLA) && (playlistBrano[i].idPlaylist != SENTINELLA)){
		i++;
	}
	return i;
}

int ContareStruttureValideBranoGenere(BranoGenere *branoGenere){
	int i = 0;
	while((branoGenere[i].idBrano != SENTINELLA) && (branoGenere[i].idGenere != SENTINELLA)){
		i++;
	}
	return i;
}

int ContareCollegamentiBranoArtistaIdBrano(int idBrano, BranoArtista* vettoreBranoArtista){
	int i = 0;
	int cont = 0;
	while(i<ELEM_MAX){
		if(LeggereIdBranoBranoArtista(vettoreBranoArtista[i]) == idBrano){
			cont++;
		}
		i++;
	}
	return cont;
}

void InizializzareVettore(int* vet){
	int i = 0;
	while(i<ELEM_MAX){
		vet[i] = SENTINELLA;
		i++;
	}
	return;
}


/* Funzione di inserimento brano generale, chiede all'utente di inserire i dati del nuovo brano, e i dati
 * dell'artista che canta il brano, controlla se un brano con stesso titolo e artista è già presente
 * o meno nel database, successivamente, chiede all'utente di inserire l'album di appartenenza, controllando
 * se esiste già un album con stesso nome e stesso cantante, nel caso non esiste inserisce il nuovo album, infine
 * chiede all'utente di inserire il genere. Effettua inoltre l'accoppiamento delle varie chiavi.
*/

void ProceduraInserimentoDaBrano(Database* musica){

	Brano nuovobrano;
	Artista nuovoartista;
	Album nuovoalbum;
	int esistenzabrano, esistenzartista;



	ChiediInserimentoNomeBrano(nuovobrano.nome);
	ChiediInserimentoNomeArteArtista(nuovoartista.NomeArte); //???? non è del brano

	esistenzabrano=CercaEsistenzaNomeBrano(musica->brano, nuovobrano.nome);
	esistenzartista=CercaEsistenzaNomeArtista(musica->artista, nuovoartista.NomeArte);

	if(esistenzabrano!=SENTINELLA && esistenzartista!=SENTINELLA)
		printf("\nBrano già presente!\n");
	else
	{
		if (esistenzartista!=SENTINELLA)
		{
			printf("\nCompleta inserimento dati brano\n");
			nuovobrano.durata=ChiediInserimentoDurataBrano();
			nuovobrano.anno=ChiediInserimentoAnnoBrano();
			InserireBrano(musica, &nuovobrano);
			InserireBranoArtista(musica, CalcolaMaxBrano(musica->brano), musica->artista[esistenzartista].idArtista);
		}
		else
		{
			printf("\nCompleta inserimento dati brano\n");
			nuovobrano.durata=ChiediInserimentoDurataBrano();
			nuovobrano.anno=ChiediInserimentoAnnoBrano();
			InserireBrano(musica, &nuovobrano);

			printf("\nCompleta inserimento dati artista\n");
			ChiediInserimentoNomeArtista(nuovoartista.nome);
			ChiediInserimentoCognomeArtista(nuovoartista.cognome);
			ChiediInserimentoLinkArtista(nuovoartista.linkBio);
			InserireArtista(musica, &nuovoartista);
			InserireBranoArtista(musica, CalcolaMaxBrano(musica->brano), CalcolaMaxArtista(musica->artista));
		}

		printf("\nInserire album d'appartenenza per: %s\n\n", nuovobrano.nome);
		ChiediInserimentoTitoloAlbum(nuovoalbum.titolo);

		int esistenzalbum=CercaEsistenzaTitoloAlbum(musica->album, nuovoalbum.titolo);

		if(esistenzalbum!=SENTINELLA)
		{
			InserireBranoAlbum(musica, CalcolaMaxBrano(musica->brano), musica->album[esistenzalbum].idAlbum);
		}

		else
		{
			nuovoalbum.anno=ChiediInserimentoAnnoAlbum();
			InserireAlbum(musica, &nuovoalbum);
			InserireBranoAlbum(musica, CalcolaMaxBrano(musica->brano), CalcolaMaxAlbum(musica->album));
		}

//possiamo ciclare per permettere l'inserimento di più di un genere per brano
		printf("\nInserire genere per: %s\n\n", nuovobrano.nome);
		char genereinput[STRING_MAX];
		int ris;
		do{
			scanf("%s", genereinput);
			fflush(stdin);
			ris=CercaEsistenzaGenere(musica->genere, genereinput);
			if(ris==SENTINELLA)
			{
				printf("\nInserire genere valido\n");
			}
		}while(ris==SENTINELLA);

			InserireBranoGenere(musica, CalcolaMaxBrano(musica->brano), ris);

	}

}


/* Chiede all'admin di inserire un nuovo genere */
Genere ChiediInserimentoGenere(){

	Genere nuovo;

	printf("\nInserire Nome Genere: \n");
	scanf("%s", nuovo.nome);
	fflush(stdin);

	return nuovo;

}


//Inserisce un nuovo brano (controlli già effettuati) nel database
void InserireBrano(Database* musica, Brano* nuovo){

	int i, inserito;
	i=0;
	inserito=0;

	do{
		if(musica->brano[i].idBrano==SENTINELLA && inserito == 0)
		{
			musica->brano[i].idBrano=1+CalcolaMaxBrano(musica->brano);
			strcpy(musica->brano[i].nome, nuovo->nome);
			musica->brano[i].durata=nuovo->durata;
			musica->brano[i].anno=nuovo->anno;
			musica->brano[i].ascolti=nuovo->ascolti;
			inserito=1;
		}
		i=i+1;
	}while(inserito!=1);

}


//Inserisce un nuovo album nel vettore album del database
void InserireAlbum(Database* musica, Album* nuovo){

	int i, inserito;
	i=0;
	inserito=0;

	do{
		if(musica->album[i].idAlbum==SENTINELLA && inserito==0)
		{
			musica->album[i].idAlbum=1+CalcolaMaxAlbum(musica->album);
			strcpy(musica->album[i].titolo, nuovo->titolo);
			musica->album[i].anno=nuovo->anno;
			inserito=1;
		}
		i=i+1;
	}while(inserito!=1);

}


//Inserisce un nuovo artista nel vettore artista del database
void InserireArtista(Database* musica, Artista* nuovo){

	int i, inserito;
	i=0;
	inserito=0;

	do{
		if(musica->artista[i].idArtista==SENTINELLA && inserito==0)
		{
			musica->artista[i].idArtista=1+CalcolaMaxArtista(musica->artista);
			strcpy(musica->artista[i].nome, nuovo->nome);
			strcpy(musica->artista[i].cognome, nuovo->cognome);
			strcpy(musica->artista[i].NomeArte, nuovo->NomeArte);
			strcpy(musica->artista[i].linkBio, nuovo->linkBio);
			inserito=1;
		}
		i=i+1;
	}while(inserito!=1);

}



/* Cerca la presenza del brano all'interno del database confrontandolo
 * con quello ricevuto in input, in caso negativo restituisce SENTINELLA, in caso
 * positivo restituisce la posizione del brano cercato all'interno del vettore brano */
int CercaEsistenzaNomeBrano(Brano* elenco, char* nuovo){

	int esito=SENTINELLA;
	int i=0;

	do{
		if(strcmp(elenco[i].nome, nuovo)==0)
			esito=i;
		i=i+1;
	}while(elenco[i].idBrano!=SENTINELLA && esito==SENTINELLA);

	return esito;

}


/* Cerca la presenza dell'artista all'interno del database confrontandolo
 * con quello ricevuto in input, in caso negativo restituisce SENTINELLA, in caso
 * positivo restituisce la posizione dell'artista cercato all'interno del vettore artista */

int CercaEsistenzaNomeArtista(Artista* elenco, char* nuovo){

	int esito=SENTINELLA;
	int i=0;

	do{
		if(strcmp(elenco[i].NomeArte, nuovo)==0)
			esito=i;
		i=i+1;
	}while(elenco[i].idArtista!=SENTINELLA && esito==SENTINELLA);

	return esito;

}


/* Cerca la presenza dell'album all'interno del database confrontandolo
 * con quello ricevuto in input, in caso negativo restituisce SENTINELLA, in caso
 * positivo restituisce la posizione dell'album cercato all'interno del vettore album */
int CercaEsistenzaTitoloAlbum(Album* elenco, char* nuovo){

	int esito=SENTINELLA;
	int i=0;

	do{
		if((strcmp(elenco[i].titolo, nuovo)==0))
			esito=i;
		i=i+1;
	}while(elenco[i].idAlbum!=SENTINELLA && esito==SENTINELLA);

	return esito;

}


/* Cerca la presenza del genere all'interno del database confrontandolo
 * con quello ricevuto in input, in caso negativo restituisce SENTINELLA, in caso
 * positivo restituisce la posizione del genere cercato all'interno del vettore genere */
int CercaEsistenzaGenere(Genere* elenco, char* genereinput){

	int esito=SENTINELLA;
	int i=0;

	do{
		if((strcmp(elenco[i].nome, genereinput)==0))
			esito=i;
		i=i+1;
	}while(elenco[i].idGenere!=SENTINELLA && esito==SENTINELLA);

	return esito;

}



//Calcola e restituisce il più grande fra gli id del vettore brano presente nel database
int CalcolaMaxBrano(Brano* elenco){

	int max=SENTINELLA;
	int i=0;

	max=elenco[i].idBrano;
	do{
		if(elenco[i].idBrano>max)
			max=elenco[i].idBrano;
		i=i+1;
	}while(elenco[i].idBrano!=SENTINELLA);

	return max;

}


//Calcola il più grande fra gli id del vettore album del database
int CalcolaMaxAlbum(Album* elenco){

	int max=SENTINELLA;
	int i=0;

	max=elenco[i].idAlbum;
	do{
		if(elenco[i].idAlbum>max)
			max=elenco[i].idAlbum;
		i=i+1;
	}while(elenco[i].idAlbum!=SENTINELLA);

	return max;

}


//Calcola il più grande fra gli id del vettore artista del database
int CalcolaMaxArtista(Artista* elenco){

	int max=SENTINELLA;
	int i=0;

	max=elenco[i].idArtista;
	do{
		if(elenco[i].idArtista>max)
			max=elenco[i].idArtista;
		i=i+1;
	}while(elenco[i].idArtista!=SENTINELLA);

	return max;

}


//Cerca il più grande fra gli id del vettore genere del database
int CalcolaMaxGenere(Genere* elenco){

	int max=SENTINELLA;
	int i=0;

	max=elenco[i].idGenere;
	do{
		if(elenco[i].idGenere>max)
			max=elenco[i].idGenere;
		i=i+1;
	}while(elenco[i].idGenere!=SENTINELLA);

	return max;

}


/* Funzione che inserisce nel vettore Brano-Artista le due chiavi ricevute in input */
void InserireBranoArtista(Database* musica, int chiavebrano, int chiaveartista){

	int i=0;

	while(musica->branoArtista[i].idBrano!=SENTINELLA){
		i=i+1;
	}
	musica->branoArtista[i].idBrano=chiavebrano;
	musica->branoArtista[i].idArtista=chiaveartista;

}


/* Funzione che inserisce nel vettore Brano-Album le due chiavi ricevute in input */
void InserireBranoAlbum(Database* musica, int chiavebrano, int chiavealbum){

	int i=0;

	while(musica->branoAlbum[i].idBrano!=SENTINELLA){
		i=i+1;
	}
	musica->branoAlbum[i].idBrano=chiavebrano;
	musica->branoAlbum[i].idAlbum=chiavealbum;


}


/* Funzione che inserisce nel vettore Brano-Genere le due chiavi ricevute in input */
void InserireBranoGenere(Database* musica, int chiavebrano, int chiavegenere){

	int i=0;

	while(musica->branoGenere[i].idBrano!=SENTINELLA){
		i=i+1;
	}
	musica->branoGenere[i].idBrano=chiavebrano;
	musica->branoGenere[i].idGenere=chiavegenere;

}



/* Funzione che controlla che l'anno inserito rispetti il vincolo > 1000, restituisce
 * il valore 1 se non è rispettata la condizione, 0 nel caso opposto */
int ControlloValiditaAnno(int anno){

	int esito;

	if(anno<1000)
		esito=1;
		else esito=0;

	return esito;
}


/* Funzione che controlla che la durata inserita rispetti il vincolo > 0, restituisce
 * il valore 1 se non è rispettata la condizione, 0 nel caso opposto */
int ControlloValiditaDurata(int durata){

	int esito;

	if(durata<0)
		esito=1;
		else esito=0;

	return esito;

}


/* Funzione di inserimento album generale, chiede all'utente di inserire i dati del nuovo album,
 * controlla se un album con stesso titolo è già presente o meno nel database. Nel caso
 * non è presente nel database, inserisce il nuovo album nel vettore album */

void ProceduraInserimentoAlbum(Database* musica){

	Album nuovoalbum;

	ChiediInserimentoTitoloAlbum(nuovoalbum.titolo);
	int esistenzalbum=CercaEsistenzaTitoloAlbum(musica->album, nuovoalbum.titolo);

	if(esistenzalbum!=SENTINELLA)
		printf("\nAlbum gia' presente! Non è possibile avere album omonimi\n");
	else
	{
			printf("\nCompleta inserimento album\n");
			nuovoalbum.anno=ChiediInserimentoAnnoAlbum();
			InserireAlbum(musica, &nuovoalbum);
	}

}


/* Funzione di inserimento album generale, chiede all'utente di inserire i dati del nuovo artista,
 * controlla se un artista con stesso titolo è già presente o meno nel database. Nel caso
 * non è presente nel database, inserisce il nuovo artista nel vettore artista */
void ProceduraInserimentoArtista(Database* musica){

	Artista nuovoartista;
	int esistenzartista;

	ChiediInserimentoNomeArteArtista(nuovoartista.NomeArte);

	esistenzartista=CercaEsistenzaNomeArtista(musica->artista, nuovoartista.NomeArte);

	if(esistenzartista!=SENTINELLA)
		printf("\nArtista già presente!\n");
	else
	{
			ChiediInserimentoNomeArtista(nuovoartista.nome);
			ChiediInserimentoCognomeArtista(nuovoartista.cognome);
			ChiediInserimentoLinkArtista(nuovoartista.linkBio);
			InserireArtista(musica, &nuovoartista);
	}

}


void ChiediInserimentoNomeBrano(char* nuovo){

	printf("\nInserire nome brano: \n");
	scanf("%s", nuovo);


}


int ChiediInserimentoDurataBrano(){

	int durata;

	do{
		printf("\nInserire durata del brano del brano (in secondi): \n");
		scanf("%d", &durata);
		fflush(stdin);
		if(ControlloValiditaDurata(durata)==1)
			printf("\nDurata non valida\n");
	}while(ControlloValiditaDurata(durata)==1);

	return durata;

}


int ChiediInserimentoAnnoBrano(){

	int anno;

	do{
		printf("\nInserire anno di pubblicazione del brano: \n");
		scanf("%d", &anno);
		fflush(stdin);
		if(ControlloValiditaAnno(anno)==1)
			printf("Anno non valido\n");
	}while(ControlloValiditaAnno(anno)==1);

	return anno;

}


void ChiediInserimentoNomeArteArtista(char* nuovo){

	printf("\nInserire nome d'arte: \n");
	scanf("%s", nuovo);

}


void ChiediInserimentoNomeArtista(char* nuovo){

	printf("\nInserire nome artista: \n");
	scanf("%s", nuovo);

}


void ChiediInserimentoCognomeArtista(char* nuovo){

	printf("\nInserire cognome artista: \n");
	scanf("%s", nuovo);

}


void ChiediInserimentoLinkArtista(char* nuovo){

	printf("\nInserire link biografia artista: \n");
	scanf("%s", nuovo);

}


void ChiediInserimentoTitoloAlbum(char* nuovo){

	printf("\nInserire titolo album: \n");
	scanf("%s", nuovo);

}

int ChiediInserimentoAnnoAlbum(){

	int anno;

	do{
		printf("\nInserire anno di pubblicazione dell'album: \n");
		scanf("%d", &anno);
		fflush(stdin);
		if(ControlloValiditaAnno(anno)==1)
			printf("Anno non valido\n");
	}while(ControlloValiditaAnno(anno)==1);

	return anno;

}

void AggiungereGenere(Database *BaseDati){
	Genere NuovoGenere;
	int esito = 0;

	LeggereGenereDaTastiera(&NuovoGenere);
	esito = RicercaGeneriSimili(BaseDati, NuovoGenere);
	if(esito == 0){
		InserireGenere(BaseDati, NuovoGenere);
		ScrivereUltimoEsito(BaseDati, OP_RIUSCITA);
		printf("Inserimento effettuato!");
	}else{
		ScrivereUltimoEsito(BaseDati, INS_FALLITO);
		printf("Inserimento annullato!");
	}
	return;
}


void LeggereGenereDaTastiera(Genere* NuovoGenere){
	char nomeGenere[STRING_MAX];

	do{
		printf("Inserisci il nome del genere musicale (almeno 1 carattere)> ");
		scanf("%s", nomeGenere);
	}while(strlen(nomeGenere)<GEN_MIN);
	ScrivereNomeGenere(NuovoGenere, nomeGenere);

	return;
}



int RicercaGeneriSimili(Database* BaseDati, Genere NuovoGenere){
	int esito = 0;
	int i = 0;
	char nomeGenere[STRING_MAX];
	char nomeGenereIesimo[STRING_MAX];
	Genere vettoreGenere[ELEM_MAX];

	LeggereVettoreGenere(vettoreGenere, BaseDati);
	while((LeggereIdGenere(LeggereGenere(vettoreGenere,i)) != SENTINELLA) && (esito == 0)){
		LeggereNomeGenere(NuovoGenere,nomeGenere);
		LeggereNomeGenere(LeggereGenere(vettoreGenere, i),nomeGenereIesimo);
		if(strcmp(nomeGenere,nomeGenereIesimo) == 0){
			printf("Esiste già un genere con lo stesso nome! ");
			esito = 1;
		}
		i++;
	}

	return esito;
}

void InserireGenere(Database *BaseDati, Genere NuovoGenere){
	int i = 0;
	Genere vettoreGenere[ELEM_MAX];

	LeggereVettoreGenere(vettoreGenere, BaseDati);
	while(LeggereIdGenere(LeggereGenere(vettoreGenere,i)) != SENTINELLA){
		i++;
	}

//	if(i==0) i++; //per evitare problemi al primo inserimento (possibile bug)

	ScrivereIdGenere(&NuovoGenere, LeggereIdGenere(LeggereGenere(vettoreGenere,i-1)) + 1);
	ScrivereGenere(vettoreGenere, i, NuovoGenere);
	ScrivereVettoreGenere(vettoreGenere, BaseDati);

	return;
}

void LeggereVettoreUtente(Utente *vettoreUtente,Database* BaseDati){
	int i = 0;
	while(i<ELEM_MAX){
		vettoreUtente[i] = BaseDati->utente[i];
		i++;
	}
	return;
}

void ScrivereVettoreUtente(Utente *vettoreUtente, Database* BaseDati){
	int i = 0;
	while(i<ELEM_MAX){
		BaseDati->utente[i] = vettoreUtente[i];
		i++;
	}
	return;
}

void LeggereVettoreGenere(Genere *vettoreGenere,Database* BaseDati){
	int i = 0;
	while(i<ELEM_MAX){
		vettoreGenere[i] = BaseDati->genere[i];
		i++;
	}
	return;
}

void ScrivereVettoreGenere(Genere *vettoreGenere,Database* BaseDati){
	int i = 0;
	while(i<ELEM_MAX){
		 BaseDati->genere[i] = vettoreGenere[i];
		i++;
	}
	return;
}









Utente LeggereUtente(Utente *vettoreUtente,int i){
	Utente UtScelto;
	UtScelto = vettoreUtente[i];
	return UtScelto;
}

void ScrivereUtente(Utente *vettoreUtente,int i, Utente UtScelto){
	vettoreUtente[i] = UtScelto;
	return;
}

void LeggereNomeUtente(Utente UtScelto, char* nomeUtente){
	strcpy(nomeUtente, UtScelto.nomeUtente);
	return;
}

void ScrivereNomeUtente(Utente* UtScelto,char* nomeUtente){
	strcpy(UtScelto->nomeUtente, nomeUtente);
	return;
}

int LeggereIdUtente(Utente UtScelto){
	return UtScelto.idUtente;
}

void ScrivereIdUtente(Utente* UtScelto,int idUtente){
	UtScelto->idUtente = idUtente;
	return;
}

void LeggerePassword(Utente UtScelto, char* password){
	strcpy(password, UtScelto.password);
	return;
}

void ScriverePassword(Utente* UtScelto, char* password){
	strcpy(UtScelto->password, password);
	return;
}

int LeggereAdmin(Utente UtScelto){
	return UtScelto.admin;
}

void ScrivereAdmin(Utente* UtScelto,int admin){
	UtScelto->admin = admin;
	return;
}







Genere LeggereGenere(Genere* vettoreGenere, int i){
	Genere GenScelto;
	GenScelto = vettoreGenere[i];
	return  GenScelto;
}

void ScrivereGenere(Genere* vettoreGenere,int i,Genere GenScelto){
	vettoreGenere[i] = GenScelto;
	return;
}

int LeggereIdGenere(Genere GenScelto){
	return GenScelto.idGenere;
}

void ScrivereIdGenere(Genere* GenScelto,int idGenere){
	GenScelto->idGenere = idGenere;
	return;
}

void LeggereNomeGenere(Genere GenScelto, char* nomeGenere){
	strcpy(nomeGenere, GenScelto.nome);
	return;
}

void ScrivereNomeGenere(Genere* GenScelto,char* nomeGenere){
	strcpy(GenScelto->nome, nomeGenere);
	return;
}

int LeggereUltimoEsito(Database* BaseDati){
	return BaseDati->ultimoEsito;
}

void ScrivereUltimoEsito(Database* BaseDati, int ultimoEsito){
	BaseDati->ultimoEsito = ultimoEsito;
	return;
}

int LeggereUtenteCorrente(Database* BaseDati){
	return BaseDati->utenteCorrente;
}

void ScrivereUtenteCorrente(Database* BaseDati, int idUtenteCorrente){
	BaseDati->utenteCorrente = idUtenteCorrente;
	return;
}





void AggiungerePlaylist(Database *BaseDati){
	Playlist NuovoPlaylist;
	int esito = 0;

	LeggerePlaylistDaTastiera(&NuovoPlaylist);
	esito = RicercaPlaylistSimili(BaseDati, NuovoPlaylist);
	if(esito == 0){
		InserirePlaylist(BaseDati, NuovoPlaylist);
		ScrivereUltimoEsito(BaseDati, OP_RIUSCITA);
		printf("Inserimento effettuato!");
	}else{
		ScrivereUltimoEsito(BaseDati, INS_FALLITO);
		printf("Inserimento annullato!");
	}
	return;
}


void LeggerePlaylistDaTastiera(Playlist* NuovoPlaylist){
	char nomePlaylist[STRING_MAX];
	char descrizione[STRING_MAX];
	int pubblica;

	do{
		printf("Inserisci il nome del Playlist musicale (almeno 1 carattere)> ");
		scanf("%s", nomePlaylist);
	}while(strlen(nomePlaylist)<GEN_MIN);
	do{
		printf("Inserisci descrizione della Playlist musicale (almeno 1 carattere)> ");
		scanf("%s", descrizione);
	}while(strlen(descrizione)<GEN_MIN);
	do{
		printf("Visibilità playlist? 1 pubblica, 0 privata> ");
		scanf("%d", &pubblica);
	}while((pubblica!=1) && (pubblica!=0));

	ScrivereNomePlaylist(NuovoPlaylist, nomePlaylist);
	ScrivereDescrizionePlaylist(NuovoPlaylist, descrizione);
	NuovoPlaylist->pubblica = pubblica;

	return;
}

int RicercaPlaylistSimili(Database* BaseDati, Playlist NuovoPlaylist){
	int esito = 0;
	int i = 0;
	char nomePlaylist[STRING_MAX];
	char nomePlaylistIesimo[STRING_MAX];
	Playlist vettorePlaylist[ELEM_MAX];

	LeggereVettorePlaylist(vettorePlaylist, BaseDati);
	while((LeggereIdPlaylist(LeggerePlaylist(vettorePlaylist,i)) != SENTINELLA) && (esito == 0)){
		LeggereNomePlaylist(NuovoPlaylist,nomePlaylist);
		LeggereNomePlaylist(LeggerePlaylist(vettorePlaylist, i),nomePlaylistIesimo);
		if((strcmp(nomePlaylist,nomePlaylistIesimo) == 0) && (LeggereUtenteCorrente(BaseDati)==LeggereIdUtentePlaylist(LeggerePlaylist(vettorePlaylist, i)))){
			printf("Esiste già una tua Playlist con lo stesso nome! ");
			esito = 1;
		}
		i++;
	}

	return esito;
}




void LeggereVettorePlaylist(Playlist *vettorePlaylist,Database* BaseDati){
	int i = 0;
	while(i<ELEM_MAX){
		vettorePlaylist[i] = BaseDati->playlist[i];
		i++;
	}
	return;
}

void ScrivereVettorePlaylist(Playlist *vettorePlaylist,Database* BaseDati){
	int i = 0;
	while(i<ELEM_MAX){
		BaseDati->playlist[i] = vettorePlaylist[i];
		i++;
	}
	return;
}

void LeggereVettoreBranoPlaylist(PlaylistBrano *vettorePlaylistBrano, Database* BaseDati){
	int i = 0;
	while(i<ELEM_MAX){
		vettorePlaylistBrano[i] = BaseDati->playlistBrano[i];
		i++;
	}
	return;
}

void ScrivereVettoreBranoPlaylist(PlaylistBrano *vettorePlaylistBrano, Database* BaseDati){
	int i = 0;
	while(i<ELEM_MAX){
		BaseDati->playlistBrano[i] = vettorePlaylistBrano[i];
		i++;
	}
	return;
}

void LeggereVettoreBrano(Brano *vettoreBrano, Database* BaseDati){
	int i = 0;
	while(i<ELEM_MAX){
		vettoreBrano[i] = BaseDati->brano[i];
		i++;
	}
	return;
}

void ScrivereVettoreBrano(Brano *vettoreBrano, Database* BaseDati){
	int i = 0;
	while(i<ELEM_MAX){
		BaseDati->brano[i] = vettoreBrano[i];
		i++;
	}
	return;
}

void LeggereVettoreArtista(Artista *vettoreArtista, Database* BaseDati){
	int i = 0;
	while(i<ELEM_MAX){
		vettoreArtista[i] = BaseDati->artista[i];
		i++;
	}
	return;
}

void ScrivereVettoreArtista(Artista *vettoreArtista, Database* BaseDati){
	int i = 0;
	while(i<ELEM_MAX){
		BaseDati->artista[i] = vettoreArtista[i];
		i++;
	}
	return;
}

void LeggereVettoreAlbum(Album *vettoreAlbum, Database* BaseDati){
	int i = 0;
	while(i<ELEM_MAX){
		vettoreAlbum[i] = BaseDati->album[i];
		i++;
	}
	return;
}

void ScrivereVettoreAlbum(Album *vettoreAlbum, Database* BaseDati){
	int i = 0;
	while(i<ELEM_MAX){
		BaseDati->album[i] = vettoreAlbum[i];
		i++;
	}
	return;
}

void LeggereVettoreBranoAlbum(BranoAlbum *vettoreBranoAlbum, Database* BaseDati){
	int i = 0;
	while(i<ELEM_MAX){
		vettoreBranoAlbum[i] = BaseDati->branoAlbum[i];
		i++;
	}
	return;
}

void ScrivereVettoreBranoAlbum(BranoAlbum *vettoreBranoAlbum, Database* BaseDati){
	int i = 0;
	while(i<ELEM_MAX){
		BaseDati->branoAlbum[i] = vettoreBranoAlbum[i];
		i++;
	}
	return;
}

void LeggereVettoreBranoArtista(BranoArtista *vettoreBranoArtista, Database* BaseDati){
	int i = 0;
	while(i<ELEM_MAX){
		vettoreBranoArtista[i] = BaseDati->branoArtista[i];
		i++;
	}
	return;
}

void ScrivereVettoreBranoArtista(BranoArtista *vettoreBranoArtista, Database* BaseDati){
	int i = 0;
	while(i<ELEM_MAX){
		BaseDati->branoArtista[i] = vettoreBranoArtista[i];
		i++;
	}
	return;
}




Playlist LeggerePlaylist(Playlist* vettorePlaylist, int i){
	Playlist PlaylistScelto;
	PlaylistScelto = vettorePlaylist[i];
	return  PlaylistScelto;
}

void ScriverePlaylist(Playlist* vettorePlaylist,int i,Playlist PlaylistScelto){
	vettorePlaylist[i] = PlaylistScelto;
	return;
}

int LeggereIdPlaylist(Playlist PlaylistScelto){
	return PlaylistScelto.idPlaylist;
}

int LeggereIdUtentePlaylist(Playlist PlaylistScelto){
	return PlaylistScelto.idUtente;
}

void ScrivereIdPlaylist(Playlist* PlaylistScelto,int idPlaylist){
	PlaylistScelto->idPlaylist = idPlaylist;
	return;
}

void LeggereNomePlaylist(Playlist PlaylistScelto, char* nomePlaylist){
	strcpy(nomePlaylist, PlaylistScelto.nome);
	return;
}

void ScrivereNomePlaylist(Playlist* PlaylistScelto,char* nomePlaylist){
	strcpy(PlaylistScelto->nome, nomePlaylist);
	return;
}

void ScrivereIdUtentePlaylist(Playlist* PlaylistScelto, int idUtenteCorrente){
	PlaylistScelto->idUtente = idUtenteCorrente;
	return;
}

void ScrivereDescrizionePlaylist(Playlist *PlaylistScelto, char* descrizionePlaylist){
	strcpy(PlaylistScelto->nome, descrizionePlaylist);
	return;
}

void LeggereDescrizionePlaylist(Playlist PlaylistScelto, char* descrizionePlaylist){
	strcpy(descrizionePlaylist, PlaylistScelto.nome);
	return;
}

int LeggereVisibilitaPlaylist(Playlist PlaylistScelto){
	return PlaylistScelto.pubblica;
}

void ScrivereVisibilitaPlaylist(Playlist* PlaylistScelto, int n){
	PlaylistScelto->pubblica = n;
	return;
}



Brano LeggereBrano(Brano* vettoreBrano, int i){
	Brano br;
	br = vettoreBrano[i];
	return br;
}

int LeggereIdBrano(Brano br){
	return br.idBrano;
}

void ScrivereIdBrano(Brano* br, int id){
	br->idBrano = id;
	return;
}

void LeggereNomeBrano(Brano br, char *parola){
	strcpy(parola, br.nome);
	return;
}
void ScrivereNomeBrano(Brano* br, char *parola){
	strcpy(br->nome, parola);
	return;
}

int LeggereDurataBrano(Brano br){
	return br.durata;
}

void ScrivereDurataBrano(Brano* br, int durata){
	br->durata = durata;
	return;
}

int LeggereAnnoBrano(Brano br){
	return br.anno;
}

void ScrivereAnnoBrano(Brano* br, int anno){
	br->anno = anno;
	return;
}

int LeggereAscoltiBrano(Brano br){
	return br.ascolti;
}

void ScrivereAscoltiBrano(Brano* br, int ascolti){
	br->ascolti = ascolti;
	return;
}

Album LeggereAlbum(Album* vettoreAlbum, int i){
	Album al;
	al = vettoreAlbum[i];
	return al;
}

int LeggereIdAlbum(Album al){
	return al.idAlbum;
}

void ScrivereIdAlbum(Album* al, int id){
	al->idAlbum = id;
	return;
}

void LeggereTitoloAlbum(Album al, char *parola){
	strcpy(parola, al.titolo);
	return;
}

void ScrivereTitoloAlbum(Album* al, char *parola){
	strcpy(al->titolo, parola);
	return;
}

int LeggereAnnoAlbum(Album al){
	return al.anno;
}

void ScrivereAnnoAlbum(Album* al, int anno){
	al->anno = anno;
	return;
}

Artista LeggereArtista(Artista* vettoreArtista, int i){
	Artista ar;
	ar = vettoreArtista[i];
	return ar;
}

int LeggereIdArtista(Artista ar){
	return ar.idArtista;
}
void ScrivereIdArtista(Artista* ar, int id){
	ar->idArtista = id;
	return;
}
void LeggereNomeArtista(Artista ar, char *parola){
	strcpy(parola, ar.nome);
	return;
}
void ScrivereNomeArtista(Artista* ar, char *parola){
	strcpy(ar->nome, parola);
	return;
}
void LeggereCognomeArtista(Artista ar, char *parola){
	strcpy(parola, ar.cognome);
	return;
}
void ScrivereCognomeArtista(Artista* ar, char *parola){
	strcpy(ar->cognome, parola);
	return;
}
void LeggereNomeArteArtista(Artista ar, char *parola){
	strcpy(parola, ar.NomeArte);
	return;
}
void ScrivereNomeArteArtista(Artista* ar, char *parola){
	strcpy(ar->NomeArte, parola);
	return;
}

BranoAlbum LeggereBranoAlbum(BranoAlbum* vettoreBranoAlbum, int i){
	BranoAlbum ba;
	ba = vettoreBranoAlbum[i];
	return ba;
}
int LeggereIdBranoBranoAlbum(BranoAlbum ba){
	return ba.idBrano;
}
void ScrivereIdBranoBranoAlbum(BranoAlbum* ba, int id){
	ba->idBrano = id;
	return;
}
int LeggereIdAlbumBranoAlbum(BranoAlbum ba){
	return ba.idAlbum;
}
void ScrivereIdAlbumBranoAlbum(BranoAlbum* ba, int id){
	ba->idAlbum = id;
	return;
}

BranoArtista LeggereBranoArtista(BranoArtista* vettoreBranoArtista, int i){
	BranoArtista ba;
	ba = vettoreBranoArtista[i];
	return ba;
}
int LeggereIdBranoBranoArtista(BranoArtista ba){
	return ba.idBrano;
}
void ScrivereIdBranoBranoArtista(BranoArtista* ba, int id){
	ba->idBrano = id;
	return;
}
int LeggereIdArtistaBranoArtista(BranoArtista ba){
	return ba.idArtista;
}
void ScrivereIdArtistaBranoArtista(BranoArtista* ba, int id){
	ba->idArtista = id;
	return;
}

PlaylistBrano LeggerePlaylistBrano(PlaylistBrano* vettorePlaylistBrano, int i){
	PlaylistBrano pl;
	pl = vettorePlaylistBrano[i];
	return pl;
}
int LeggereIdBranoPlaylistBrano(PlaylistBrano pl){
	return pl.idBrano;
}
void ScrivereIdBranoPlaylistBrano(PlaylistBrano* pl,int id){
	pl->idBrano = id;
	return;
}
int LeggereIdPlaylistPlaylistBrano(PlaylistBrano pl){
	return pl.idPlaylist;
}
void ScrivereIdPlaylistPlaylistBrano(PlaylistBrano* pl,int id){
	pl->idPlaylist = id;
	return;
}

BranoGenere LeggereBranoGenere(BranoGenere* vettoreBranoGenere, int i){
	BranoGenere gen;
	gen = vettoreBranoGenere[i];
	return gen;
}
int LeggereIdBranoBranoGenere(BranoGenere gen){
	return gen.idBrano;
}
void ScrivereIdBranoBranoGenere(BranoGenere* gen,int id){
	gen->idGenere = id;
	return;
}
int LeggereIdGenereBranoGenere(BranoGenere gen){
	return gen.idGenere;
}
void ScrivereIdGenereBranoGenere(BranoGenere* gen,int id){
	gen->idGenere = id;
}








void ModificareBrano(int id, int campo, Database *musica){
	char parola[STRING_MAX];
	int nuovadurata;
	int nuovoanno;
	Brano br;			//copia del brano da modificare

	br = RicercareBranoId(musica->brano, id);
	if(br.idBrano == SENTINELLA){
		printf("\nBrano non trovato. Id inserito non valido.\n");
	}else{

		if(campo == 1){
			do{
				ChiediInserimentoNomeBrano(parola);
			}while(strlen(parola) < GEN_MIN);
			strcpy(br.nome, parola);	//inserisco il nuovo nome nella struttura
			//cerco la posizione del brano e lo sostituisco con quello aggornato
			TrovaSostituisciBrano(musica, br);

		}else if(campo == 2){
			nuovadurata = ChiediInserimentoDurataBrano();
			br.durata = nuovadurata;
			//cerco la posizione del brano e lo sostituisco con quello aggornato
			TrovaSostituisciBrano(musica, br);

		}else if(campo==3){
			nuovoanno = ChiediInserimentoAnnoBrano();
			br.anno = nuovoanno;
			//cerco la posizione del brano e lo sostituisco con quello aggornato
			TrovaSostituisciBrano(musica, br);
		}
	}
	return;
}



void ModificareArtista(int id,int campo,Database *musica ){
	char parola[STRING_MAX];
	Artista ar;			//copia dell'artista da modificare

	ar = RicercareArtistaId(musica->artista, id);
	if(ar.idArtista == SENTINELLA){
		printf("\nArtista non trovato. Id inserito non valido.\n");
	}else{

		if(campo == 1){
			do{
				ChiediInserimentoNomeArtista(parola);
			}while(strlen(parola) < GEN_MIN);
			strcpy(ar.nome, parola);	//inserisco il nuovo nome nella struttura
			//cerco la posizione e lo sostituisco con quello aggornato
			TrovaSostituisciArtista(musica, ar);

		}else if(campo == 2){
			do{
				ChiediInserimentoCognomeArtista(parola);
			}while(strlen(parola) < GEN_MIN);
			strcpy(ar.cognome, parola);	//inserisco il nuovo cognome nella struttura
			//cerco la posizione dell'artista e lo sostituisco con quello aggornato
			TrovaSostituisciArtista(musica, ar);

		}else if(campo == 3){
			do{
				ChiediInserimentoNomeArteArtista(parola);
			}while(strlen(parola) < GEN_MIN);
			strcpy(ar.NomeArte, parola);	//inserisco il nuovo nome nella struttura
			//cerco la posizione e lo sostituisco con quello aggornato
			TrovaSostituisciArtista(musica, ar);
		}
	}
	return;
}



void ModificareAlbum (int id,int campo,Database *musica){
	char parola[STRING_MAX];
	int nuovoanno;
	Album al;			//copia dell'album da modificare

	al = RicercareAlbumId(musica->album, id);
	if(al.idAlbum == SENTINELLA){
		printf("\nAlbum non trovato. Id inserito non valido.\n");
	}else{

		if(campo == 1){
			do{
				ChiediInserimentoTitoloAlbum(parola);
			}while(strlen(parola) < GEN_MIN);
			strcpy(al.titolo, parola);	//inserisco il nuovo titolo nella struttura
			//cerco la posizione e lo sostituisco con quello aggornato
			TrovaSostituisciAlbum(musica, al);

		}else if(campo == 2){
			nuovoanno = ChiediInserimentoAnnoAlbum();
			al.anno = nuovoanno;
			//cerco la posizione del brano e lo sostituisco con quello aggornato
			TrovaSostituisciAlbum(musica, al);
		}
	}
	return;
}

void CancellareGenere(Database* BaseDati,int idGenereDaCancellare){
	int i = 0;
	int j;
	int posizioneCollegamento;
	int esito;
	while((LeggereIdGenere(LeggereGenere(BaseDati->genere,i)) != idGenereDaCancellare) && (i<ELEM_MAX)){
		i++;
	}
	if(i == ELEM_MAX){
		printf("Genere selezionato non esistente\n");
	}else{
		//cancello il genere dal database
		SpostareSinistraVettoreGenere(BaseDati->genere, i);
		//cancello tutti i brani con quel genere e le associazioni brano-genere
		j = 0;
		esito = 0;
		while((j<ELEM_MAX) && (esito==0)){
			posizioneCollegamento = RicercaPosizioneBranoGenereIdGenere(idGenereDaCancellare, BaseDati->branoGenere);
			if(posizioneCollegamento != SENTINELLA){
				CancellareBrano(BaseDati, LeggereIdBranoBranoGenere(BaseDati->branoGenere[posizioneCollegamento]));
				SpostareSinistraVettoreBranoGenere(BaseDati->branoGenere, posizioneCollegamento);
			}else{
				printf("Genere non collegato a nessun brano\n");
				esito = 1;
			}
			j++;
		}
	}

	return;
}

void SpostareSinistraVettoreGenere(Genere* vet,int i){
	while(i < ELEM_MAX - 1){
		vet[i] = vet[i+1];
		i++;
	}
	return;
}
void SpostareSinistraVettoreBranoGenere(BranoGenere* vet, int i){
	while(i < ELEM_MAX - 1){
		vet[i] = vet[i+1];
		i++;
	}
	return;
}

void CancellareBrano(Database* BaseDati,int idBranoDaCancellare){
	int i;
	int j;
	int posizioneCollegamento;
	int esito;
	i = 0;
	while((LeggereIdBrano(LeggereBrano(BaseDati->brano,i)) != idBranoDaCancellare) && (i < ELEM_MAX)){
		i++;
	}
	if(i==ELEM_MAX){
		printf("Brano selezionato non esistente\n");
	}else{
		//cancello il brano
		SpostareSinistraVettoreBrano(BaseDati->brano, i);
		//cancello le associazioni brano-artista
		j = 0;
		esito = 0;
		while((j<ELEM_MAX) && (esito==0)){
			posizioneCollegamento = RicercaPosizioneBranoArtistaIdBrano(idBranoDaCancellare, BaseDati->branoArtista);
			if(posizioneCollegamento != SENTINELLA){
				SpostareSinistraVettoreBranoArtista(BaseDati->branoArtista, posizioneCollegamento);
			}else{
				printf("Brano non collegato a nessun artista\n");
				esito = 1;
			}
			j++;
		}
		//cancello le associazioni brano-album
		j = 0;
		esito = 0;
		while((j<ELEM_MAX) && (esito==0)){
			 posizioneCollegamento = RicercaPosizioneBranoAlbumIdBrano(idBranoDaCancellare,BaseDati->branoAlbum);
			 if(posizioneCollegamento != SENTINELLA){
				 SpostareSinistraVettoreBranoAlbum(BaseDati->branoAlbum,posizioneCollegamento);
			 }else{
				 printf("Brano non collegato a nessun album\n");
				 esito = 1;
			 }
			 j++;
		}
		//cancello le associazioni brano-playlist
		j = 0;
		esito = 0;
		while((j<ELEM_MAX) && (esito==0)){
			 posizioneCollegamento = RicercaPosizioneBranoPlaylistIdBrano(idBranoDaCancellare,BaseDati->playlistBrano);
			 if(posizioneCollegamento != SENTINELLA){
				 SpostareSinistraVettoreBranoPlaylist(BaseDati->playlistBrano,posizioneCollegamento);
			 }else{
				 printf("Brano non collegato a nessuna playlist\n");
				 esito = 1;
			 }
			 j++;
		}
	}

	return;
}

void SpostareSinistraVettoreBrano(Brano* vet, int i){
	while(i < ELEM_MAX - 1){
		vet[i] = vet[i+1];
		i++;
	}
	return;
}
void SpostareSinistraVettoreBranoArtista(BranoArtista* vet, int i){
	while(i < ELEM_MAX - 1){
		vet[i] = vet[i+1];
		i++;
	}
	return;
}
void SpostareSinistraVettoreBranoAlbum(BranoAlbum* vet, int i){
	while(i < ELEM_MAX - 1){
		vet[i] = vet[i+1];
		i++;
	}
	return;
}

void CancellareAlbum(Database* BaseDati,int idAlbumDaCancellare){
	int i = 0;
	int j;
	int esito;
	int posizioneCollegamento;
	while((LeggereIdAlbum(LeggereAlbum(BaseDati->album,i)) != idAlbumDaCancellare) && (i < ELEM_MAX)){
		i++;
	}
	if(i==ELEM_MAX){
		printf("Album selezionato non esistente\n");
	}else{
		//cancello album
		SpostareSinistraVettoreAlbum(BaseDati->album, i);
		//cancello le associazioni brano-album
		j = 0;
		esito = 0;
		while((j<ELEM_MAX) && (esito==0)){
			posizioneCollegamento = RicercaPosizioneBranoAlbumIdAlbum(idAlbumDaCancellare, BaseDati->branoAlbum);
			if(posizioneCollegamento != SENTINELLA){
				SpostareSinistraVettoreBranoAlbum(BaseDati->branoAlbum, posizioneCollegamento);
			}else{
				printf("Album non collegato a nessun brano\n");
				esito = 1;
			}
			j++;
		}
	}
	return;
}

void CancellareArtista(Database* BaseDati,int idArtistaDaCancellare){
	int i = 0;
	int j;
	int esito;
	int posizioneCollegamento;
	while((LeggereIdArtista(LeggereArtista(BaseDati->artista,i)) != idArtistaDaCancellare) && (i < ELEM_MAX)){
		i++;
	}
	if(i==ELEM_MAX){
		printf("Artista selezionato non esistente\n");
	}else{
		//cancello l'artista
		SpostareSinistraVettoreArtista(BaseDati->artista, i);
		//cancello le associazioni brano-artista
		j = 0;
		esito = 0;
		while((j<ELEM_MAX) && (esito==0)){
			posizioneCollegamento = RicercaPosizioneBranoArtistaIdArtista(idArtistaDaCancellare, BaseDati->branoArtista);
			if(posizioneCollegamento != SENTINELLA){
				SpostareSinistraVettoreBranoArtista(BaseDati->branoArtista, posizioneCollegamento);
				//sto cancellando dal sistema i brani senza artista
				if(ContareCollegamentiBranoArtistaIdBrano(LeggereIdBranoBranoArtista(BaseDati->branoArtista[posizioneCollegamento]), BaseDati->branoArtista) == 0){
					CancellareBrano(BaseDati, LeggereIdBranoBranoArtista(BaseDati->branoArtista[posizioneCollegamento]) );
				}
			}else{
				printf("Artista non collegato a nessun brano\n");
				esito = 1;
			}
			j++;
		}
	}
	return;
}

void SpostareSinistraVettoreArtista(Artista* vet, int i){
	while(i < ELEM_MAX - 1){
		vet[i] = vet[i+1];
		i++;
	}
	return;
}
void SpostareSinistraVettoreAlbum(Album* vet, int i){
	while(i < ELEM_MAX - 1){
		vet[i] = vet[i+1];
		i++;
	}
	return;
}
