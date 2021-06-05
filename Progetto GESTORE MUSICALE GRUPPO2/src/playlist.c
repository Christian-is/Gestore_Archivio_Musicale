/*
 * playlist.c
 *
 *  Created on: May 31, 2020
 *      Author: Gruppo 2
 */
#include "playlist.h"

void InserirePlaylist(Database *BaseDati, Playlist NuovoPlaylist){
	int i = 0;
	Playlist vettorePlaylist[ELEM_MAX];

	LeggereVettorePlaylist(vettorePlaylist, BaseDati);
	while(LeggereIdPlaylist(LeggerePlaylist(vettorePlaylist,i)) != SENTINELLA){
		i++;
	}

//	if(i==0) i++; //per evitare problemi al primo inserimento (possibile bug)
	ScrivereIdUtentePlaylist(&NuovoPlaylist, LeggereUtenteCorrente(BaseDati));
	ScrivereIdPlaylist(&NuovoPlaylist, LeggereIdPlaylist(LeggerePlaylist(vettorePlaylist,i-1)) + 1);
	ScriverePlaylist(vettorePlaylist, i, NuovoPlaylist);
	ScrivereVettorePlaylist(vettorePlaylist, BaseDati);

	return;
}

/* Funzione che inserisce nel vettore Playlist-Brano le due chiavi ricevute in input */
void InserirePlaylistBrano(Database* musica, int chiavebrano, int chiaveplaylist){

	int i=0;

	while(musica->playlistBrano[i].idBrano!=SENTINELLA){
		i=i+1;
	}
	musica->playlistBrano[i].idBrano=chiavebrano;
	musica->playlistBrano[i].idPlaylist=chiaveplaylist;
}


void ModificarePlaylist(int id,int campo, Database *musica){
	char parola[STRING_MAX];;
	Playlist pl;

	pl = RicercarePlaylistId(musica->playlist, id);
	if(pl.idPlaylist == SENTINELLA){
		printf("\nPlaylist non trovata. Id inserito non valido.\n");
	}else{

		if(campo == 1){
			do{
				printf("Inserisci nome playlist> ");
				scanf("%s", parola);
			}while(strlen(parola) < LUNG_MIN);
			strcpy(pl.nome, parola);
			TrovaSostituisciPlaylist(musica, pl);

		}else if(campo == 2){
			do{
				printf("Inserisci descrizione playlist> ");
				scanf("%s", parola);
			}while(strlen(parola) < LUNG_MIN);
			strcpy(pl.descrizione, parola);
			TrovaSostituisciPlaylist(musica, pl);

		}else if(campo == 3){
			do{
				printf("Cambiare visibilità playlist? 1 pubblica, 0 privata> ");
				scanf("%d", &pl.pubblica);
			}while((pl.pubblica != 1) && (pl.pubblica != 0));
			TrovaSostituisciPlaylist(musica, pl);
		}
	}
	return;
}

void CancellarePlaylist(Database *BaseDati, int idPlaylistDaCancellare){
	int i;
	int posizioneCollegamento=0;

	//cerco la playlist da eliminare
	i = 0;
	while((LeggereIdPlaylist(LeggerePlaylist(BaseDati->playlist,i)) != idPlaylistDaCancellare)&&(i < ELEM_MAX)){
		i++;
	}
	if(i == ELEM_MAX){
		printf("Playlist selezionata non esistente\n");
	}else{
		SpostareSinistraVettorePlaylist(BaseDati->playlist, i); //cancello playlist
		//cancello i brani collegati alla playlist
		while(posizioneCollegamento != SENTINELLA){
			posizioneCollegamento = RicercaPosizioneBranoPlaylistIdPlaylist(idPlaylistDaCancellare, BaseDati->playlistBrano);
			if((posizioneCollegamento <= ELEM_MAX) && (posizioneCollegamento!= SENTINELLA)){
				SpostareSinistraVettoreBranoPlaylist(BaseDati->playlistBrano, posizioneCollegamento);
			}else{
				printf("Playlist non collegata a nessun brano\n");
			}
		}
	}
	return;
}

void CancellareBranoDaPlaylist(Database *BaseDati, int idBranoDaCancellare, int idPlaylistDaAggiornare){
	int posizioneCollegamento;
	posizioneCollegamento = RicercaPosizioneBranoPlaylistIdBrano(idBranoDaCancellare, BaseDati->playlistBrano);
	if(posizioneCollegamento != SENTINELLA){
		SpostareSinistraVettoreBranoPlaylist(BaseDati->playlistBrano, posizioneCollegamento);
	}else{
		printf("Brano non collegato alla playlist\n");
	}
	return;
}

void SpostareSinistraVettorePlaylist(Playlist* vet, int i){
	while(i < ELEM_MAX - 1){
		vet[i] = vet[i+1];
		i++;
	}
	return;
}

void SpostareSinistraVettoreBranoPlaylist(PlaylistBrano* vet, int i){
	while(i < ELEM_MAX - 1){
		vet[i] = vet[i+1];
		i++;
	}
	return;
}


