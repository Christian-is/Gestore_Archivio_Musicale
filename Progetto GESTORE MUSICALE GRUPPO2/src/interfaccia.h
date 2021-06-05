/*
 * interfaccia.h
 *
 *  Created on: May 27, 2020
 *      Author: Gruppo 2
 *
 *  Modulo che si occupa della gestione dei menù di scelta delle azioni da compiere
 */

#ifndef INTERFACCIA_H_
#define INTERFACCIA_H_
#include <stdio.h>
#include <stdlib.h>
#include "gestione.h"

void Ricercare(Database *musica); //in base al criterio "ricercato" (chiesto all'interno della funzione), apre diverse sottofunzioni di ricerca e stampa a video le ricerche effettuate
void Inserire(Database *musica); //all'interno della funzione viene richiesto cosa inserire e apre altre sottofunzioni di conseguenza (solo admin)
void ModificarePlaylistUtente(Database *musica); //modifica delle playlist dell'utente corrente; all'interno della funzione viene richiesto cosa modificare e apre altre sottofunzioni di conseguenza
void Modificare(Database *musica); //Modifica i campi delle tabelle del database (non gli id). Divisa in più sottofunzioni (solo admin)
void Cancellare(Database *musica); //Cancella intere strutture dal database. Divisa in più sottofunzioni (solo admin)
void ScegliereStampa(Database *musica); //permette di sceglire quale parte del database stampare a video

#endif /* INTERFACCIA_H_ */
