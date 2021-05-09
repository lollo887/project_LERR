#ifndef LISTADOMANDE_H
#define LISTADOMANDE_H

#include<iostream>
#include<cstdlib>
#include<string>
#include "Domanda.h"

using namespace std;

class SerieDomande {
	private:   	
		Domanda lista_domande[16];  // una in più per il salta domanda
    	int domanda_corrente ;
    	bool salta_domanda;
    	int num_domande;
	public: 
    	SerieDomande ();
    	void carica_domande (); // Legge da file tutte le 50 domande e ne inserisce 16, scelte in modo casuale, in lista_domande
    	void aggiungi_domanda (); // scrive su file delle domande una domanda con le relative risposte e risposta corretta da usare nelle partite successive
		Domanda getDomandaCorrente();  
		int get_domanda_corrente();   
    	bool incrementa_domanda();  // valorizza domanda_corrente con la posizione della domanda successiva (domandacorrente++), se arriva all'ultima avvisare che la partita è finita. 
		void visualizza_domanda();
    	void setSaltaDomanda (); 
    	bool getSaltaDomanda ();
    	void incrementa_num_domande();
    	int get_num_domande();
};

#endif
