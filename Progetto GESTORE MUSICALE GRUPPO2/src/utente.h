/*
 * utente.h
 *
 *  Created on: May 26, 2020
 *      Author: Gruppo 2
 *
 *  Modulo che si occupa della gestione degli utenti
 */

#ifndef UTENTE_H_
#define UTENTE_H_

#include "gestione.h"
#include "ricerca.h"
#include "playlist.h"

//funzioni principali
void AggiungereUtente(Database* BaseDati); //funzione che avvia la procedura di inserimento di un nuovo utente nel database. Stampa a video se tale procedura va a buon fine o meno
void LeggereUtenteDaTastiera(Utente* NuovoUtente); //acquisisce le informazoni dell'utente da tastiera
int RicercaUtentiSimili(Database* BaseDati, Utente NuovoUtente); //funzione che controlla se il nome di un utente che si vuole inserire nel database è già presente. Restituisce 1 se è già presente, 0 altrimenti
void InserireUtente(Database *BaseDati, Utente NuovoUtente); //inserisce una struttura di tipo Utente nel database
void ModificareUtente(int utenteCorrente, int campo, Database *musica); //funzione che modifica il campo di un utente nel database. Riceve in input l'id dell'utente, l'identificativo numerico del campo e il database
void CancellareUtente(Database *BaseDati, int idUtenteDaCancellare); //funzione che elimina dal database un utente e tutte le playlist a lui associate
void SpostareSinistraVettoreUtente(Utente* vet,int i); //sposta a sinistra il vettore in input a partire dalla posizione i

void Registrazione(Database *musica); //permette di fare il login dopo l'eventuale aggiunta di un nuovo utente
void LoginUtente(Database *musica); //procedura di accesso al sistema da parte di un utente


#endif /* UTENTE_H_ */
