#ifndef DOMANDA_H
#define DOMANDA_H

#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

class Domanda{
  private: 
    string testo_domanda;
    string risposte[4];
    int risposta_corretta;
     
  public:  
    Domanda();  
    string getTestoDomanda();
    void setDomanda(string s);
    string getRisposta(int num_risposta);
    void setRisposta(string s, int num_risposta);    
    void setRispostaCorretta(int r);
    int getRispostaCorretta();
};

#endif
