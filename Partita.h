#ifndef PARTITA_H_
#define PARTITA_H_

#include <cstdlib>
#include <iostream>
#include "listadomande.h"

using namespace std;

class Partita {
  private: 
    SerieDomande domande;
    string lista_premi_euro[16];
    int premio_corrente;
    bool aiuto_casa;    
    bool aiuto_dimezza_risposte;    
    bool aiuto_salta_domanda;    
  public: 
    Partita ();  // valorizza anche la lista dei premi
    void avvio_partita();       // Avvia la partita
    void aiuto_da_casa();
    void dimezza_risposte();
    void visualizza_montepremi(); // visualizza la lista di premi nell'attributo lista_premi_euro evidenziando il premio_corrente
    void salvaPartita(); // Nel caso di risposta affermativa, il gioco deve chiedere il nome al giocatore per poi 
                         // scrivere, su un file di testo, una riga contenente il nome, il montepremi raggiunto, 
                         // il numero di aiuti utilizzati. Il gioco,successivamente, deve tornare al menu dove, scegliendo 
                         // come opzione Record, e possibile visualizzare il file appena modicato.    
};

#endif

