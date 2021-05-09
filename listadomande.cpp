#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include <fstream>
#include "listadomande.h"

using namespace std;

SerieDomande :: SerieDomande(){
	carica_domande();
	domanda_corrente = 0;
	num_domande = 15;
}

void SerieDomande :: carica_domande(){
	srand (time(NULL));
	Domanda dom[50];
	ifstream in; 
	in.open("Domande_complete.txt");
	string s1;
	int c;
	for( int i=0; i<50; i++){
		if(getline(in,s1)){ 
			dom[i].setDomanda(s1);
			for (int j=0; j<4; j++){
				getline(in,s1);
				dom[i].setRisposta(s1,j);
			}
			in>>c;
			dom[i].setRispostaCorretta(c);
			getline(in,s1);
		}
	}
	in.close();
	int casuale;
	bool gia_inserito[50];
	for (int i=0; i<50; i++) 
		gia_inserito[i] = false;
	for(int i=0; i<16; i++){
		casuale = rand()%50;
		if (!gia_inserito[casuale]){
			gia_inserito[casuale] = true;
			lista_domande[i].setDomanda(dom[casuale].getTestoDomanda());
			for (int j=0; j<4; j++){
				lista_domande[i].setRisposta(dom[casuale].getRisposta(j),j);
			}
			lista_domande[i].setRispostaCorretta(dom[casuale].getRispostaCorretta());
		}
		else i--;
	}
}

void SerieDomande:: aggiungi_domanda(){
	ofstream out;
	out.open("domande.txt", ios::app);
	system("CLS");
	string s1;
	int c;
	cout<<"Inserisci il testo della  domanda"<<endl;
	cin.clear(); 
	cin.ignore(1);
	getline(cin,s1);
	
	//da completare
	cout<<"Da completare"<<endl;
	
}

Domanda SerieDomande :: getDomandaCorrente(){
	return lista_domande[domanda_corrente];
}

int SerieDomande :: get_domanda_corrente(){
	return domanda_corrente;
}

bool SerieDomande :: incrementa_domanda(){
    if(domanda_corrente < num_domande-1){
        domanda_corrente++;
        return true;
    }
    else{
        return false;
    }
}

void SerieDomande :: visualizza_domanda(){
	cout<<lista_domande[domanda_corrente].getTestoDomanda()<<endl;
	for (int j=0;j<4;j++){
		cout<<lista_domande[domanda_corrente].getRisposta(j)<<endl;
	}
	cout<<endl;
}

void SerieDomande:: setSaltaDomanda(){
 	salta_domanda = true;
}

bool SerieDomande :: getSaltaDomanda(){
 	return salta_domanda;
}

void SerieDomande :: incrementa_num_domande(){
	num_domande++;
}

int SerieDomande :: get_num_domande(){
	return num_domande;
}
