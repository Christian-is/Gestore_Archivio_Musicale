/*
 * utente.c
 *
 *  Created on: May 26, 2020
 *      Author: Gruppo 2
 */
#include "utente.h"

//funzioni
void AggiungereUtente(Database* BaseDati){
	Utente NuovoUtente;
	int esito = 0;

	LeggereUtenteDaTastiera(&NuovoUtente);
	esito = RicercaUtentiSimili(BaseDati, NuovoUtente);
	if(esito == 0){
		InserireUtente(BaseDati, NuovoUtente);
		ScrivereUltimoEsito(BaseDati, OP_RIUSCITA);
		printf("Inserimento effettuato!");
	}else{
		ScrivereUltimoEsito(BaseDati, INS_FALLITO);
		printf("Inserimento annullato!");
	}
	return;
}

void LeggereUtenteDaTastiera(Utente* NuovoUtente){
	char nomeUtente[STRING_MAX];
	char password[STRING_MAX];
	int admin;

	do{
		printf("Inserisci il nome dell'utente (almeno 6 caratteri)> ");
		scanf("%s", nomeUtente);
	}while(strlen(nomeUtente)<LUNG_MIN);

	do{
		printf("Inserisci ora una password (almeno 6 caratteri)> ");
		scanf("%s", password);
	}while(strlen(password)<LUNG_MIN);

	printf("Questo utente deve essere amministratore? 1 si, 0 no> ");
	scanf("%d", &admin);
	while((admin != 1) && (admin != 0)){
		printf("Inserire valore valido!\n");
		printf("Questo utente deve essere amministratore? 1 si, 0 no> ");
		scanf("%d", &admin);
	}

	ScrivereNomeUtente(NuovoUtente, nomeUtente);
	ScriverePassword(NuovoUtente, password);
	ScrivereAdmin(NuovoUtente, admin);
	return;
}

int RicercaUtentiSimili(Database *BaseDati, Utente NuovoUtente){
	int esito = 0;
	int i = 0;
	char nomeUtente[STRING_MAX];
	char nomeUtenteIesimo[STRING_MAX];
	Utente vettoreUtente[ELEM_MAX];

	LeggereVettoreUtente(vettoreUtente, BaseDati);
	while((LeggereIdUtente(LeggereUtente(vettoreUtente,i)) != SENTINELLA) && (esito == 0)){
		LeggereNomeUtente(NuovoUtente,nomeUtente);
		LeggereNomeUtente(LeggereUtente(vettoreUtente, i),nomeUtenteIesimo);
		if(strcmp(nomeUtente,nomeUtenteIesimo) == 0){
			printf("Esiste già un utente con lo stesso nome! ");
			esito = 1;
		}
		i++;
	}

	return esito;
}

void InserireUtente(Database *BaseDati, Utente NuovoUtente){
	int i = 0;
	Utente vettoreUtente[ELEM_MAX];

	LeggereVettoreUtente(vettoreUtente, BaseDati);
	while(LeggereIdUtente(LeggereUtente(vettoreUtente,i)) != SENTINELLA){
		i++;
	}
	//if(i==0) i++; //per evitare problemi al primo inserimento (possibile bug)

	ScrivereIdUtente(&NuovoUtente, LeggereIdUtente(LeggereUtente(vettoreUtente,i-1)) + 1);
	ScrivereUtente(vettoreUtente, i, NuovoUtente);
	ScrivereVettoreUtente(vettoreUtente, BaseDati);

	return;
}

void ModificareUtente(int utenteCorrente,int campo, Database *musica){
	char parola[STRING_MAX];;
	Utente ut;

	ut = RicercareUtenteId(musica->utente, utenteCorrente);
	if(ut.idUtente == SENTINELLA){
		printf("\nUtente non trovato. Id inserito non valido.\n");
	}else{

		if(campo == 1){
			do{
				printf("Inserisci nome utente> ");
				scanf("%s", parola);
			}while(strlen(parola) < LUNG_MIN);
			strcpy(ut.nomeUtente, parola);
			TrovaSostituisciUtente(musica, ut);

		}else if(campo == 2){
			do{
				printf("Inserisci nuova password> ");
				scanf("%s", parola);
			}while(strlen(parola) < LUNG_MIN);
			strcpy(ut.password, parola);
			TrovaSostituisciUtente(musica, ut);

		}else if(campo == 3){
			do{
				printf("Cambiare privilegi amministrativi? 1 admin, 2 non admin> ");
				scanf("%d", &ut.admin);
			}while((ut.admin != 1) && (ut.admin != 0));
			TrovaSostituisciUtente(musica, ut);
		}
	}
	return;
}

void CancellareUtente(Database *BaseDati, int idUtenteDaCancellare){
	int i;
	int j;
	int vettoreIdPlaylist[ELEM_MAX];

	//cerco la posizione nel vettore degli utenti dell'utente da eliminare
	i = 0;
	while((LeggereIdUtente(LeggereUtente(BaseDati->utente,i)) != idUtenteDaCancellare) && (i < ELEM_MAX)){
		i = i+1;
	}

	if(i == ELEM_MAX){
		printf("Utente selezionato non esistente\n");//se finisco il vettore, l'utente non esiste
	}else{
		SpostareSinistraVettoreUtente(BaseDati->utente, i); //elimino l'utente

		InizializzareVettore(vettoreIdPlaylist);
		RicercarePlaylistIdUtente(idUtenteDaCancellare, BaseDati, vettoreIdPlaylist); //cerco le playlist dell'utente eliminato
		j = 0;
		while(vettoreIdPlaylist[j] != SENTINELLA){
			CancellarePlaylist(BaseDati, vettoreIdPlaylist[j]); //elimino le playlist dell'utente eliminato
			j++;
		}
	}

	return;
}

void SpostareSinistraVettoreUtente(Utente* vet,int i){
	while(i < ELEM_MAX - 1){
		vet[i] = vet[i+1];
		i++;
	}
	return;
}



void Registrazione(Database *musica){
	int scelta;

	do{
		printf("Digita 1 per login utente, 0 per creazione nuovo utente> ");
		scanf("%d", &scelta);
	}while((scelta != 1) && (scelta != 0));

	if(scelta == 0){
		//ripete l'aggiunta utente se l'inserimento fallisce
		do{
			AggiungereUtente(musica);
		}while(LeggereUltimoEsito(musica) == INS_FALLITO);
	}

	//ripete login utente se fallisco il login
	printf(" Effettua ora il Login:\n");
	do{
			LoginUtente(musica);
	}while(musica->utenteCorrente == SENTINELLA);

	return;
}

void LoginUtente(Database *musica){
	char nome[STRING_MAX];
	char password[STRING_MAX];
	int esito = 0;
	int i = 0;

	do{
		printf("Inserisci il nome dell'utente> ");
		scanf("%s", nome);
	}while(strlen(nome)<LUNG_MIN);
	do{
		printf("Inserisci la password> ");
		scanf("%s", password);
	}while(strlen(password)<LUNG_MIN);

	while((i<ELEM_MAX) && (esito==0)){
		if((strcmp(musica->utente[i].nomeUtente, nome)==0) && (strcmp(musica->utente[i].password, password)==0)){
			musica->utenteCorrente = musica->utente[i].idUtente;
			esito = 1;
			printf("Login effettuato correttamente.\n");
		}
		i++;
	}
	if(esito==0){
		printf("Login fallito. Reinserire dati.\n");
	}
	return;
}
