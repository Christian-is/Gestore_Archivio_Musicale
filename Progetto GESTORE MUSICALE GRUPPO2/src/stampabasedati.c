/*
 * stampa.c
 *
 *  Created on: 19 mag 2020
 *      Author: Gruppo 2
 */

#include "stampabasedati.h"

//Funzione che stampa l'intero database
void StampaDatabase(Database* musica){

	StampaTabellaBrano(musica);
	StampaTabellaArtisti(musica);
	StampaTabellaBranoArtista(musica);
	StampaTabellaAlbum(musica);
	StampaTabellaBranoAlbum(musica);
	StampaTabellaGenere(musica);
	StampaTabellaBranoGenere(musica);
	StampaTabellaPlaylist(musica);
	StampaTabellaPlaylistBrano(musica);
	StampaTabellaUtente(musica);
	StampaUtenteCorrente(musica);
	StampaUltimoEsito(musica);


}

// Funzione che stampa tutti i dati presenti nella tabella Brano
void StampaTabellaBrano(Database* musica){

	int i;
	i=0;
	printf("ELENCO BRANI:\n\n");
	while(musica->brano[i].idBrano!=SENTINELLA){
		printf("Brano in posizione %d\n", i);
		printf("id-Brano: %d\n", musica->brano[i].idBrano);
		printf("Nome brano: %s\n", musica->brano[i].nome);
		printf("Durata brano: %d\n", musica->brano[i].durata);
		printf("Anno: %d\n", musica->brano[i].anno);
//		printf("Ascolti: %d\n", musica->brano[i].ascolti);
		i=i+1;
		printf("\n");
	}

}

// Funzione che stampa tutti i dati presenti nella tabella Artisti
void StampaTabellaArtisti(Database* musica){

	int i;
	i=0;
	printf("\nELENCO ARTISTI:\n\n");
	while(musica->artista[i].idArtista!=SENTINELLA){
		printf("Artista in posizione %d\n", i);
		printf("id-Artista: %d\n", musica->artista[i].idArtista);
		printf("Nome artista: %s\n", musica->artista[i].nome);
		printf("Cognome artista: %s\n", musica->artista[i].cognome);
		printf("Nome d'arte: %s\n", musica->artista[i].NomeArte);
		printf("link-Bio: %s\n", musica->artista[i].linkBio);
		i=i+1;
		printf("\n");
	}

}

// Funzione che stampa tutti i dati presenti nella tabella Brano-Artisti
void StampaTabellaBranoArtista(Database* musica){

	int i;
	i=0;
	printf("\nCOPPIE Brano-Artista:\n\n");
	while(musica->branoArtista[i].idArtista!=SENTINELLA || musica->branoArtista[i].idBrano!=SENTINELLA){
		printf("Posizione %d\n", i);
		printf("id-Brano: %d\n", musica->branoArtista[i].idBrano);
		printf("id-Artista: %d\n", musica->branoArtista[i].idArtista);
		i=i+1;
		printf("\n");
	}

}

// Funzione che stampa tutti i dati presenti nella tabella Album
void StampaTabellaAlbum(Database* musica){

	int i;
	i=0;
	printf("ELENCO ALBUM:\n\n");
	while(musica->album[i].idAlbum!=SENTINELLA){
		printf("Album in posizione %d\n", i);
		printf("id-Album: %d\n", musica->album[i].idAlbum);
		printf("Titolo: %s\n", musica->album[i].titolo);
		printf("Anno: %d\n", musica->album[i].anno);
		i=i+1;
		printf("\n");
	}

}

// Funzione che stampa tutti i dati presenti nella tabella Brano-Album
void StampaTabellaBranoAlbum(Database* musica){

	int i;
	i=0;
	printf("TABELLA Brano-Album:\n\n");
	while(musica->branoAlbum[i].idAlbum!=SENTINELLA || musica->branoAlbum[i].idBrano!=SENTINELLA){
		printf("Coppia Brano-Album in posizione %d\n", i);
		printf("id-Brano: %d\n", musica->branoAlbum[i].idBrano);
		printf("id-Album: %d\n", musica->branoAlbum[i].idAlbum);
		i=i+1;
		printf("\n");
	}

}


// Funzione che stampa tutti i dati presenti nella tabella Genere
void StampaTabellaGenere(Database* musica){

	int i;
	i=0;
	printf("TABELLA GENERE:\n\n");
	while(musica->genere[i].idGenere!=SENTINELLA){
		printf("Genere in posizione %d\n", i);
		printf("id-Genere: %d\n", musica->genere[i].idGenere);
		printf("Nome genere: %s\n", musica->genere[i].nome);
		i=i+1;
		printf("\n");
	}

}

// Funzione che stampa tutti i dati presenti nella tabella Brano-Genere
void StampaTabellaBranoGenere(Database* musica){

	int i;
	i=0;
	printf("TABELLA Brano-Genere:\n\n");
	while(musica->branoGenere[i].idGenere!=SENTINELLA || musica->branoGenere[i].idBrano!=SENTINELLA){
		printf("Coppia Brano-Genere in posizione %d\n", i);
		printf("id-Brano: %d\n", musica->branoGenere[i].idBrano);
		printf("id-Genere: %d\n", musica->branoGenere[i].idGenere);
		i=i+1;
		printf("\n");
	}

}

// Funzione che stampa tutti i dati presenti nella tabella Playlist
void StampaTabellaPlaylist(Database* musica){
	Utente elencoUtenti[ELEM_MAX];
	int i;

	LeggereVettoreUtente(elencoUtenti, musica);
	i=0;
	printf("TABELLA PLAY-LIST:\n\n");
	while(musica->playlist[i].idPlaylist!=SENTINELLA){
		//solo admin e playlist pubbliche
		if((musica->playlist[i].pubblica == 1) ||
		(LeggereAdmin(RicercareUtenteId(elencoUtenti,LeggereUtenteCorrente(musica))) == 1)){
				printf("Playlist in posizione %d\n", i);
				printf("id-Playlist: %d\n", musica->playlist[i].idPlaylist);
				printf("id-Utente: %d\n", musica->playlist[i].idUtente);
				printf("Nome playlist: %s\n", musica->playlist[i].nome);
				printf("Descrizione: %s\n", musica->playlist[i].descrizione);
				printf("Pubblica: %d\n", musica->playlist[i].pubblica);
		}
		i=i+1;
		printf("\n");
	}


}

// Funzione che stampa tutti i dati presenti nella tabella Playlist-Brano
void StampaTabellaPlaylistBrano(Database* musica){

	int i;
	i=0;
	printf("COPPIE Playlist-Brano:\n\n");
	while(musica->playlistBrano[i].idBrano!=SENTINELLA || musica->playlistBrano[i].idPlaylist!=SENTINELLA){
		printf("Coppia playlist - Brano in posizione %d\n", i);
		printf("id-Playlist: %d\n", musica->playlistBrano[i].idPlaylist);
		printf("id-Brano: %d\n", musica->playlistBrano[i].idBrano);
		i=i+1;
		printf("\n");
	}

}

// Funzione che stampa tutti i dati presenti nella tabella Utente
void StampaTabellaUtente(Database* musica){
	Utente elencoUtenti[ELEM_MAX];
	int i;

	LeggereVettoreUtente(elencoUtenti, musica);
	i=0;
	printf("TABELLA UTENTE:\n\n");
	while(musica->utente[i].idUtente!=SENTINELLA){
		printf("Utente in posizione %d\n", i);
		printf("id-Utente: %d\n", musica->utente[i].idUtente);
		printf("Nome utente: %s\n", musica->utente[i].nomeUtente);
		//solo admin e utente corrispondente possono vedere la password
		if((musica->utente[i].idUtente == LeggereUtenteCorrente(musica)) ||
		(LeggereAdmin(RicercareUtenteId(elencoUtenti,LeggereUtenteCorrente(musica))) == 1)){
			printf("Password: %s\n", musica->utente[i].password);
		}
		printf("Admin: %d\n", musica->utente[i].admin);
		i=i+1;
		printf("\n");
	}
}

// Stampa utente corrente
void StampaUtenteCorrente(Database* musica){

	printf("Utente corrente: %d\n", musica->utenteCorrente);

}

// Stampa ultimo esito
void StampaUltimoEsito(Database* musica){

	printf("Ultimo esito: %d\n", musica->ultimoEsito);

}









//funzioni che ricevono un vettore di id e stampano le strutture corrispondenti
void StampareRisultatiPlaylist(Database *BaseDati, int *vettoreId){
	int i;
	int k;
	Playlist vettorePlaylist[STRING_MAX];
	char nomePlaylist[STRING_MAX];
	char descrizionePlaylist[STRING_MAX];

	LeggereVettorePlaylist(vettorePlaylist, BaseDati);
	i = 0;
	while(vettoreId[i] != SENTINELLA){
		k = 0;
		while(vettorePlaylist[k].idPlaylist != SENTINELLA){
			if(LeggereIdPlaylist(vettorePlaylist[k]) == vettoreId[i]){
				LeggereNomePlaylist(vettorePlaylist[k],nomePlaylist);
				LeggereDescrizionePlaylist(vettorePlaylist[k],descrizionePlaylist);
				printf("\n");
				printf("id-Playlist: %d\n", LeggereIdPlaylist(vettorePlaylist[k]));
				printf("id-Utente: %d\n", LeggereIdUtentePlaylist(vettorePlaylist[k]));
				printf("Nome playlist: %s\n", nomePlaylist);
				printf("Descrizione: %s\n", descrizionePlaylist);
				printf("Pubblica: %d\n", LeggereVisibilitaPlaylist(vettorePlaylist[k]));
			}
			k++;
		}
		i++;
	}
	return;
}

void StampareRisultatiUtente(Database *BaseDati, int *vettoreId){
	int i;
	int k;
	Utente vettoreUtente[STRING_MAX];
	char nome[STRING_MAX];
	char password[STRING_MAX];

	LeggereVettoreUtente(vettoreUtente, BaseDati);
	i = 0;
	while(vettoreId[i] != SENTINELLA){
		k = 0;
		while(vettoreUtente[k].idUtente != SENTINELLA){
			if(LeggereIdUtente(vettoreUtente[k]) == vettoreId[i]){
				LeggereNomeUtente(vettoreUtente[k],nome);
				LeggerePassword(vettoreUtente[k], password);
				printf("\n");
				printf("id-Utente: %d\n", LeggereIdUtente(vettoreUtente[k]));
				printf("Nome utente: %s\n", nome);
				//solo admin e utente corrispondente possono vedere la password
				if((BaseDati->utente[k].idUtente == LeggereUtenteCorrente(BaseDati)) ||
				(LeggereAdmin(RicercareUtenteId(vettoreUtente,LeggereUtenteCorrente(BaseDati))) == 1)){
					printf("Password: %s\n", password);
				}
				printf("Admin: %d\n", LeggereAdmin(vettoreUtente[k]));
			}
			k++;
		}
		i++;
	}
	return;
}

void StampareRisultatiBrano(Database *BaseDati, int *vettoreId){
	int i;
	int k;

	i = 0;
	while(vettoreId[i] != SENTINELLA){
		k = 0;
		while(BaseDati->brano[k].idBrano != SENTINELLA){
			if(BaseDati->brano[k].idBrano  == vettoreId[i]){

				printf("\n");
				printf("id-Brano: %d\n", BaseDati->brano[k].idBrano);
				printf("Nome brano: %s\n", BaseDati->brano[k].nome);
				printf("Durata brano: %d\n",BaseDati->brano[k].durata);
				printf("Anno: %d\n",BaseDati->brano[k].anno);
			}
			k++;
		}
		i++;
	}
	return;
}

void StampareRisultatiAlbum(Database *BaseDati, int *vettoreId){
	int i;
	int k;

	i = 0;
	while(vettoreId[i] != SENTINELLA){
		k = 0;
		while(BaseDati->album[k].idAlbum != SENTINELLA){
			if(BaseDati->album[k].idAlbum  == vettoreId[i]){

				printf("\n");
				printf("id-Album: %d\n", BaseDati->album[k].idAlbum);
				printf("Titolo: %s\n", BaseDati->album[k].titolo);
				printf("Anno: %d\n", BaseDati->album[k].anno);
			}
			k++;
		}
		i++;
	}
	return;
}

void StampareRisultatiArtista(Database *BaseDati, int *vettoreId){
	int i;
	int k;

	i = 0;
	while(vettoreId[i] != SENTINELLA){
		k = 0;
		while(BaseDati->artista[k].idArtista != SENTINELLA){
			if(BaseDati->artista[k].idArtista  == vettoreId[i]){

				printf("\n");
				printf("id-Artista: %d\n", BaseDati->artista[k].idArtista);
				printf("Nome artista: %s\n", BaseDati->artista[k].nome);
				printf("Cognome artista: %s\n", BaseDati->artista[k].cognome);
				printf("Nome d'arte: %s\n", BaseDati->artista[k].NomeArte);
				printf("link-Bio: %s\n", BaseDati->artista[k].linkBio);
			}
			k++;
		}
		i++;
	}
	return;
}


void StampareBraniDaAlbum(Database *BaseDati, int *vettoreId){
	int i;
	int k;
	int c = 0;
	int vettoreIdBrano[ELEM_MAX];

	InizializzareVettore(vettoreIdBrano);
	i = 0;
	while(vettoreId[i] != SENTINELLA){
		k = 0;
		while(BaseDati->branoAlbum[k].idAlbum != SENTINELLA){
			if(BaseDati->branoAlbum[k].idAlbum  == vettoreId[i]){
				vettoreIdBrano[c] = BaseDati->branoAlbum[k].idBrano;
				c++;
			}
			k++;
		}
		i++;
	}
	StampareRisultatiBrano(BaseDati, vettoreIdBrano);
	return;
}

void StampareBraniDaArtista(Database *BaseDati, int *vettoreId){
	int i;
	int k;
	int c = 0;
	int vettoreIdBrano[ELEM_MAX];

	InizializzareVettore(vettoreIdBrano);
	i = 0;
	while(vettoreId[i] != SENTINELLA){
		k = 0;
		while(BaseDati->branoArtista[k].idArtista != SENTINELLA){
			if(BaseDati->branoArtista[k].idArtista  == vettoreId[i]){
				vettoreIdBrano[c] = BaseDati->branoArtista[k].idBrano;
				c++;
			}
			k++;
		}
		i++;
	}
	StampareRisultatiBrano(BaseDati, vettoreIdBrano);
	return;
}

void StampareBraniDaPlaylist(Database *BaseDati, int *vettoreId){
	int i;
	int k;
	int c = 0;
	int vettoreIdBrano[ELEM_MAX];

	InizializzareVettore(vettoreIdBrano);
	i = 0;
	while(vettoreId[i] != SENTINELLA){
		k = 0;
		while(BaseDati->playlistBrano[k].idPlaylist != SENTINELLA){
			if(BaseDati->playlistBrano[k].idPlaylist  == vettoreId[i]){
				vettoreIdBrano[c] = BaseDati->playlistBrano[k].idBrano;
				c++;
			}
			k++;
		}
		i++;
	}
	StampareRisultatiBrano(BaseDati, vettoreIdBrano);
}
