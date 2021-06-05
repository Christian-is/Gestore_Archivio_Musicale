/*
 * interfaccia.c
 *
 *  Created on: May 27, 2020
 *      Author: Gruppo 2
 */
#include "interfaccia.h"
#include "utente.h"
#include "ricerca.h"
#include "playlist.h"
#include "stampabasedati.h"


void Ricercare(Database *musica){
	int scelta;

	do{
	printf("Cosa vuoi cercare? 1 brani, 2 album, 3 artista, 4 playlist, 5 utente> ");
	scanf("%d", &scelta);
	}while((scelta != 1) && (scelta != 2) && (scelta != 3) && (scelta != 4) && (scelta != 5));

	if(scelta == 1){
		RicercareBrano(musica);
	}else if(scelta == 2){
		RicercareAlbum(musica);
	}else if(scelta == 3){
		RicercareArtista(musica);
	}else if(scelta == 4){
		RicercarePlaylist(musica);
	}else if(scelta == 5){
		RicercareUtente(musica);
	}
	return;
}

void Inserire(Database *musica){
	int scelta;
	Utente elencoUtenti[ELEM_MAX];

	LeggereVettoreUtente(elencoUtenti, musica);
	if(LeggereAdmin(RicercareUtenteId(elencoUtenti,LeggereUtenteCorrente(musica))) == 0 ){ //controlla se l'utente è un admin
		printf("Non hai i privilegi di admin necessari a compiere questa azione.\n");
	}else{
		do{
			printf("Cosa vuoi inserire? 1 brani, 2 album, 3 artista, 4 genere, 5 utente, 0 per uscire> ");
			scanf("%d", &scelta);
		}while((scelta != 0) && (scelta != 1) && (scelta != 2) && (scelta != 3) && (scelta != 4) && (scelta != 5));

		while(scelta!=0){
			if(scelta == 1){
				ProceduraInserimentoDaBrano(musica);
				}else if(scelta == 2){
					ProceduraInserimentoAlbum(musica);
				}else if(scelta == 3){
					ProceduraInserimentoArtista(musica);
				}else if(scelta == 4){
					AggiungereGenere(musica);
				}else if(scelta==5){
					AggiungereUtente(musica);
			}
			do{
				printf("Inserire altro? 1 brani, 2 album, 3 artista, 4 genere, 5 utente, 0 per uscire> ");
				scanf("%d", &scelta);
			}while((scelta != 0) && (scelta != 1) && (scelta != 2) && (scelta != 3) && (scelta != 4) && (scelta != 5));

		}
	}
	return;
}

void Modificare(Database *musica){ //può essere resa più generale tramite sottofunzioni (come in Ricercare)
	int scelta;
	int campo;
	int idBranoDaAggiornare;
	int idAlbumDaAggiornare;
	int idArtistaDaAggiornare;
	Utente elencoUtenti[ELEM_MAX];

	LeggereVettoreUtente(elencoUtenti, musica);
	do{
		printf("Digita 1 per modificare un brano, 2 per modificare un album, 3 per modificare un artista, 4 per modificare il tuo utente, 0 per uscire> ");
		scanf("%d",&scelta);
	}while((scelta != 1) && (scelta != 2) && (scelta != 3) &&(scelta == 4) && (scelta != 0));

	while(scelta!=0){
		if(scelta == 1){
			if(LeggereAdmin(RicercareUtenteId(elencoUtenti,musica->utenteCorrente)) == 0 ){
				printf("Non hai i privilegi di admin necessari a compiere questa azone.\n");
			}else{
				printf("Scegli il brano da modificare:\n");
				Ricercare(musica);
				printf("Inserisci l'id del brano da modificare> ");
				scanf("%d",&idBranoDaAggiornare);
				do{
				printf("Indicare quale campo del brano vuoi modificare. 1 titolo, 2 durata, 3 anno> ");
				scanf("%d",&campo);
				}while((campo != 1) && (campo != 2) && (campo != 3));
				ModificareBrano(idBranoDaAggiornare, campo, musica);
			}

		}else if(scelta == 2){
			if(LeggereAdmin(RicercareUtenteId(elencoUtenti,musica->utenteCorrente)) == 0 ){
				printf("Non hai i privilegi di admin necessari a compiere questa azone.\n");
			}else{
				printf("Scegli l'album da modificare:\n");
				Ricercare(musica);
				printf("Inserisci l'id dell'album da modificare> ");
				scanf("%d",&idAlbumDaAggiornare);
				do{
					printf("Indicare quale campo dell'album vuoi modificare. 1 titolo, 2 anno> ");
					scanf("%d",&campo);
				}while((campo != 1) && (campo != 2));
				ModificareAlbum(idAlbumDaAggiornare, campo, musica);
			}

		}else if(scelta == 3){
			if(LeggereAdmin(RicercareUtenteId(elencoUtenti,musica->utenteCorrente)) == 0 ){
				printf("Non hai i privilegi di admin necessari a compiere questa azone.\n");
			}else{
				printf("Scegli l'artista da modificare:\n");
				Ricercare(musica);
				printf("Inserisci l'id dell'artista da modificare> ");
				scanf("%d",&idArtistaDaAggiornare);
				do{
				printf("Indicare quale campo dell'artista vuoi modificare. 1 nome, 2 cognome, 3 nome d'arte> ");
				scanf("%d",&campo);
				}while((campo != 1) && (campo != 2) && (campo != 3));
				ModificareArtista(idArtistaDaAggiornare, campo, musica);
			}

		}else if(scelta == 4){
			do{
				printf("Indicare il campo del proprio utente che si vuole modificare. 1 nome, 2 password, 3 privilegi admin> ");
				scanf("%d",&campo);
			}while((campo != 1) && (campo != 2) && (campo != 3));
			ModificareUtente(LeggereUtenteCorrente(musica), campo, musica);
		}

		do{
			printf("Digita 1 per modificare un brano, 2 per modificare un album, 3 per modificare un artista, 4 per modificare il tuo utente, 0 per uscire> ");
			scanf("%d",&scelta);
		}while((scelta != 1) && (scelta != 2) && (scelta != 3) &&(scelta == 4) && (scelta != 0));

	}

	return;
}


void ModificarePlaylistUtente(Database *musica){
	int scelta;
	int campo;
	int idBranoDaInserire;
	int vettoreId[ELEM_MAX]; //da inizializzare a -1. Conterrà degli id corrispondenti a strutture da stampare a video
	int idPlaylistDaAggiornare;
	int idBranoDaCancellare;

	InizializzareVettore(vettoreId);
	printf("Le tue playlist sono le seguenti> ");
	RicercarePlaylistIdUtente(LeggereUtenteCorrente(musica), musica, vettoreId); //cerca nel database l'utente corrente e salva nel vettoreId gli idPlaylist a lui associate
	StampareRisultatiPlaylist(musica, vettoreId);

	do{
		printf("Digita 1 per inserire un brano in una playlist, 2 per modificare le informazioni riguardo le tue playlist, 3 per inserire una nuova playlist, 4 per cancellare una playlist,  5 per rimuovere un brano da playlist, 0 per uscire ");
		scanf("%d",&scelta);
	}while((scelta != 1) && (scelta != 2) && (scelta != 3) && (scelta != 4) && (scelta != 5) && (scelta != 0));

	while(scelta!=0){
		if(scelta==1){
			printf("Cerca l'elemento da inserire nella playlist:\n");
			Ricercare(musica);
			printf("Digitare l'id del brano che si vuole inserire in una playlist> ");
			scanf("%d",&idBranoDaInserire);
			do{
				printf("Digitare l'id della palylist dove si vuole aggiungere il brano> ");
				scanf("%d",&idPlaylistDaAggiornare);
				//bisogna controllare che sia una playlist dell'utente e solo dopo far partire la funzione InserirePlaylistBrano
				if(ControllarePossessoPlaylist(musica->playlist, LeggereUtenteCorrente(musica), idPlaylistDaAggiornare) == 0){
					printf("Non puoi modificare questa playlist poichè non è la tua!\n");
				}
			}while(ControllarePossessoPlaylist(musica->playlist, LeggereUtenteCorrente(musica), idPlaylistDaAggiornare) == 0);
			InserirePlaylistBrano(musica, idBranoDaInserire, idPlaylistDaAggiornare); //aggiorna la tabella BranoPlaylist con questa nuova coppia di valori

		}else if(scelta==2){
			do{
				printf("Digitare l'id della palylist da modificare> ");
				scanf("%d",&idPlaylistDaAggiornare);
				//bisogna controllare che sia una playlist dell'utente e solo dopo far partire la funzione di modifica
				if(ControllarePossessoPlaylist(musica->playlist, LeggereUtenteCorrente(musica), idPlaylistDaAggiornare) == 0){
					printf("Non puoi modificare questa playlist poichè non è la tua!\n");
				}
			}while(ControllarePossessoPlaylist(musica->playlist, LeggereUtenteCorrente(musica), idPlaylistDaAggiornare) == 0);
			do{
				printf("Indicare il campo della playlist da modificare: 1 nome, 2 descrizione, 3 visibilità> ");
				scanf("%d", &campo);
			}while((campo != 1) && (campo != 2) && (campo != 3));
			ModificarePlaylist(idPlaylistDaAggiornare, campo, musica);

		}else if(scelta==3){
			AggiungerePlaylist(musica);

		}else if(scelta==4){
			printf("Inserire l'id della playlist da cancellare> ");
			scanf("%d",&idPlaylistDaAggiornare);
			//bisogna controllare che sia una playlist dell'utente e solo dopo far partire la funzione CancellaPlaylist
			if(ControllarePossessoPlaylist(musica->playlist,LeggereUtenteCorrente(musica), idPlaylistDaAggiornare) == 1){
				CancellarePlaylist(musica,idPlaylistDaAggiornare);
			}else{
				printf("Non puoi cancellare questa playlist poichè non è la tua!\n");
			}
		}else if(scelta==5){
			printf("Inserire idBrano da rimuovere dalla playlist> ");
			scanf("%d",&idBranoDaCancellare);
			printf("“Inserire idPlaylist da cui  rimuoverlo> ");
			scanf("%d",&idPlaylistDaAggiornare);
			//bisogna controllare che sia una playlist dell'utente e solo dopo far partire la funzione CancellaPlaylist
			if(ControllarePossessoPlaylist(musica->playlist,LeggereUtenteCorrente(musica), idPlaylistDaAggiornare) == 1){
				CancellareBranoDaPlaylist(musica,idBranoDaCancellare, idPlaylistDaAggiornare);
			}else{
				printf("Non puoi modificare questa playlist poichè non è la tua!\n");
			}
		}

		do{
			printf("Digita 1 per inserire un brano in una playlist, 2 per modificare le informazioni riguardo le tue playlist, 3 per inserire una nuova playlist, 4 per cancellare una playlist, 5 per rimuovere un brano da playlist, 0 per uscire ");
			scanf("%d",&scelta);
		}while((scelta != 1) && (scelta != 2) && (scelta != 3) && (scelta != 4) && (scelta != 5) && (scelta != 0));

	}


	return;
}



void Cancellare(Database *musica){ //dentro i vari Cancella, se non trovo l'utente stampo a video un errore
	int scelta;
	int idBranoDaCancellare;
	int idAlbumDaCancellare;
	int idArtistaDaCancellare;
	int idGenereDaCancellare;
	int idUtenteDaCancellare;
	Utente elencoUtenti[ELEM_MAX];

	LeggereVettoreUtente(elencoUtenti, musica);
	if(LeggereAdmin(RicercareUtenteId(elencoUtenti,musica->utenteCorrente)) == 0 ){ //controlla se l'utente è un admin
		printf("Non hai i privilegi di admin necessari a compiere questa azione.");
	}else{

		do{
			printf("Digita 1 per cancellare un brano, 2 per cancellare un album, 3 per cancellare un artista, 4 per cancellare un genere, 5 per cancellare un utente, 0 per uscire ");
			scanf("%d",&scelta);
		}while((scelta != 1) && (scelta != 2) && (scelta != 3) && (scelta != 4) && (scelta != 5) && (scelta != 0));

		while(scelta!=0){
			if(scelta==1){
				printf("Scegli il brano da cancellare:");
				StampaTabellaBrano(musica);
				printf("Inserisci l'id del brano da cancellare:");
				scanf("%d",&idBranoDaCancellare);
				CancellareBrano(musica, idBranoDaCancellare); //cancella anche tutti i collegamenti BranoArtista e BranoAlbum
			}else if(scelta==2){
				printf("Scegli l'album da cancellare:");
				StampaTabellaAlbum(musica);
				printf("Inserisci l'id dell'album da cancellare:");
				scanf("%d",&idAlbumDaCancellare);
				CancellareAlbum(musica, idAlbumDaCancellare); //cancella anche tutti i collegamenti BranoAlbum
			}else if(scelta==3){
				printf("Scegli l'artista da cancellare:");
				StampaTabellaArtisti(musica);
				printf("Inserisci l'id dell'artista da cancellare:");
				scanf("%d",&idArtistaDaCancellare);
				CancellareArtista(musica,idArtistaDaCancellare); //cancella anche tutti i collegamenti BranoArtista e tutti i brani di quell'artista (solo se ha un unico artista)
			}else if(scelta==4){
				printf("Scegli il genere da cancellare:");
				StampaTabellaGenere(musica); //stampa a video tutti i generi nel database
				printf("Inserisci l'id del genere da cancellare:");
				scanf("%d",&idGenereDaCancellare);
				CancellareGenere(musica,idGenereDaCancellare); //cancella anche tutti i collegamenti BranoGenere e tutti i brani con quel genere
			}else if(scelta==5){
				printf("Scegli l'utente da cancellare:");
				StampaTabellaUtente(musica); //stampa a video tutti gli utenti nel database
				printf("Inserisci l'id dell'utente da cancellare:");
				scanf("%d",&idUtenteDaCancellare);
				CancellareUtente(musica,idUtenteDaCancellare); //cancella anche tutte le playlist dell'utente
			}

			do{
				printf("Digita 1 per cancellare un brano, 2 per cancellare un album, 3 per cancellare un artista, 4 per cancellare un genere, 5 per cancellare un utente, 0 per uscire ");
				scanf("%d",&scelta);
			}while((scelta != 1) && (scelta != 2) && (scelta != 3) && (scelta != 4) && (scelta != 5) && (scelta != 0));
		}

	}
	return;
}

void ScegliereStampa(Database *musica){
	int scelta;
	Utente elencoUtenti[ELEM_MAX];

	LeggereVettoreUtente(elencoUtenti, musica);
	do{
		printf("Selezionare stampa desiderata:\n 1 Database completo (solo admin), 2 brani, 3 album, 4 artisti, 5 generi, 6 playlist, 7 utenti> ");
		scanf("%d", &scelta);
	}while((scelta != 1) && (scelta != 2) && (scelta != 3) && (scelta != 4) && (scelta != 5) && (scelta != 6) && (scelta != 7));

	if(scelta==1){
		//solo admin
		if(LeggereAdmin(RicercareUtenteId(elencoUtenti,LeggereUtenteCorrente(musica))) == 0 ){ //controlla se l'utente è un admin
			printf("Non hai i privilegi di admin necessari a compiere questa azione.\n");
		}else{
			StampaDatabase(musica);
		}
	}else if(scelta==2){
		StampaTabellaBrano(musica);
	}else if(scelta==3){
		StampaTabellaAlbum(musica);
	}else if(scelta==4){
		StampaTabellaArtisti(musica);
	}else if(scelta==5){
		StampaTabellaGenere(musica);
	}else if(scelta==6){
		//solo le pubbliche (admin le vede tutte)
		StampaTabellaPlaylist(musica);
	}else if(scelta==7){
		//password visibili solo all'admin e utente corrispondente
		StampaTabellaUtente(musica);
	}
	return;
}

