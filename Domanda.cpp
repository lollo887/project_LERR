#include<iostream>
#include<cstdlib>
#include<string>
#include "Domanda.h"

using namespace std;

Domanda :: Domanda(){
	risposte[0] = "1" ;
	risposte[1] = "2" ;
	risposte[2] = "3" ;
	risposte[3] = "4" ;
}

string Domanda :: getTestoDomanda(){	
	return testo_domanda;
}

void Domanda :: setDomanda(string s){
	testo_domanda = s;
}

string Domanda :: getRisposta(int num_risposta){
	return risposte[num_risposta];
}

void Domanda :: setRisposta(string s, int num_risposta){
	risposte[num_risposta] = s;	
}

void Domanda :: setRispostaCorretta(int r){	
  risposta_corretta = r;
}

int Domanda :: getRispostaCorretta(){
	return risposta_corretta;
}
