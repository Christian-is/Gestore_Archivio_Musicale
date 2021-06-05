/*
 ===========================================================================================================================
 Name        : main progetto: Gestore Archivio Musicale TTICSS
 Author      : Gruppo 2
 	 	 	 	 Giacovazzo Christian
 	 	 	 	 Simone Capone
 	 	 	 	 Simone De Girolamo
 	 	 	 	 Ivan Digioia
 	 	 	 	 Thomas Carella
 	 	 	 	 Tommaso La Cava

 Description : gestore musicale che permette di ricercare, inserire, modificare e cancellare brani, autori, album e playlist
 ===========================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestione.h"
#include "stampabasedati.h"
#include "utente.h"
#include "ricerca.h"
#include "interfaccia.h"



int main(){
	Database musica;
	int scelta;
	int eliminato = 0; //booleano che indica se l'utente corrente si è cancellato dal sistema (1) o meno (0)

	InizializzareDatabaseVuoto(&musica);
	CaricareFile(&musica);
	Registrazione(&musica);


	do{
		printf("\n\nDigita 1 per ricerca elementi, 2 per aggiunta elementi, 3 per modifica tue playlist, 4 modifica database, 5 per backup database, 6 per caricare in memoria il backup del database, 7 per stampa del database, 8 per cancellare strutture dal database, 9 per eliminare il tuo utente, 0 per uscire> ");
		scanf("%d", &scelta);
	}while((scelta != 0) && (scelta != 1) && (scelta != 2) && (scelta != 3) && (scelta != 4) && (scelta != 5) && (scelta != 6) && (scelta != 7) && (scelta != 8) && (scelta != 9));


	while(scelta != 0){
		if(scelta == 1){
			Ricercare(&musica);
		}else if(scelta == 2){
			//solo admin
			Inserire(&musica);
		}else if(scelta == 3){
			ModificarePlaylistUtente(&musica);
		}else if(scelta == 4){
			//solo admin
			Modificare(&musica);
		}else if(scelta == 5){
			//solo admin
			if((LeggereAdmin(RicercareUtenteId(musica.utente, LeggereUtenteCorrente(&musica))) == 1)){
				BackupFile(musica);
			}else{
				printf("Non hai i privilegi di admin necessari a compiere questa azione.\n");
			}
		}else if(scelta == 6){
			//solo admin
			if((LeggereAdmin(RicercareUtenteId(musica.utente, LeggereUtenteCorrente(&musica))) == 1)){
				RipristinareFile(&musica);
			}else{
				printf("Non hai i privilegi di admin necessari a compiere questa azione.\n");
			}
		}else if(scelta == 7){
			ScegliereStampa(&musica);
		}else if(scelta == 8){
			Cancellare(&musica);
		}else if(scelta == 9){
			CancellareUtente(&musica,LeggereUtenteCorrente(&musica));
			eliminato = 1;
			scelta = 0;
		}

		if(eliminato == 0){
		do{
			printf("Digita 1 per ricerca elementi, 2 per aggiunta elementi, 3 per modifica tue playlist, 4 modifica database, 5 per backup database, 6 per caricare in memoria il backup del database, 7 per stampa del database, 8 per cancellare strutture dal database, 9 per eliminare il tuo utente, 0 per uscire> ");
			scanf("%d", &scelta);
		}while((scelta != 0) && (scelta != 1) && (scelta != 2) && (scelta != 3) && (scelta != 4) && (scelta != 5) && (scelta != 6) && (scelta != 7) && (scelta != 8));
		}

	}

	do{
		printf("\nSalvare modifiche effettuate al database corrente? 1 si, 0 no> ");
		scanf("%d", &scelta);
	}while((scelta != 1) && (scelta != 0));
	if(scelta == 1){
		SalvareSuFile(musica);
	}

	system("pause");
	return 0;
}


