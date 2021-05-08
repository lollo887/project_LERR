#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
Class SerieDomande {
  private:   
    Domanda lista_domande[16];  // una in più per il salta domanda
    int domanda_corrente ;
    bool salta_domanda=false;
  public: 
    SerieDomande ();
    void carica_domande (); // Legge da file tutte le 50 domande e ne inserisce 16, scelte in modo casuale, in lista_domande
    void aggiungi_domanda (); // scrive su file delle domande una domanda con le relative risposte e risposta corretta da usare nelle partite successive
	Domanda getDomandaCorrente();     
    bool incrementa_domanda();  // valorizza domanda_corrente con la posizione della domanda successiva (domandacorrente++), se arriva all'ultima avvisare che la partita è finita. 
     void visualizza_domanda();
    void setSaltaDomanda (); 
    bool getSaltaDomanda ();
    void visualizza_domande(Domanda d1[], int num_domande);  // Serve ? 
}  
SerieDomande :: SerieDomande(){
	carica_domande();
	domanda_corrente = 0;
}
void SerieDomande :: carica_domande(){
	Domanda dom[50];
	ifstream in; 
	in.open("domande.txt");
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
				dom.setCorretta(c);
				getline(in,s1);
		}
	}
	in.close();
	int casuale;
	bool gia_inserito[50];
	for (int i=0; i<50; i++) gia_inserito[i] = false;
	for(int i=0; i<16; i++){
		casuale = rand()%50;
		if (!gia_inserito[casuale]){
			gia_inserito[casuale] = true;
				d[i].Domanda(dom[casuale].getDomanda());
				for ( int j=0; j<4; j++){
			
			d[i].setDomanda(dom[casuale].getRisposta(j))
		}
		d[i].setCorretta(dom[casuale].getCorretta());
	}
	else i--;
}
}
void SerieDomande:: aggiungi_domanda(){
	ofstream out;
	out.open("domande.txt", ios::app);
	system("clear");
	string s1;
	int c;
	cout<<"inserisci il testo della  domanda";
	cin.clear(); cin.ignore(1);
	getline(cin,s1);
}
void SerieDomande :: visualizza_domanda(Domanda d1[], int i){
	string s1;
	for for (int j=0; j<i;j++){
		cout<<d1[j].getDomanda()<<endl;
	}
	cout<<"-----------------------------------------"<<endl;
	cin.clear(); cin.ignore();
	getline(cin,s1);
}
SerieDomande :: get_domanda_corrente(){
  return lista_domande[domanda_corrente];
}
 bool SerieDomande::incrementa_domanda(){
 	domanda_corrente++;
 	
 }
 void SerieDomande:: setSaltaDomanda(){
 	salta_domanda = true;
 }
 bool SerieDomande :: getSaltaDomanda(){
 	return salta_domanda;
 }
SerieDomande :: visualizza_domanda(){
  cout<<lista_domande[domanda_corrente].getTestoDomanda()<<endl;<<endl;
  cout<<lista_domande[domanda_corrente].getRisposta(0);<<endl;
  cout<<lista_domande[domanda_corrente].getRisposta(1);<<endl;
  cout<<lista_domande[domanda_corrente].getRisposta(2);<<endl;
  cout<<lista_domande[domanda_corrente].getRisposta(3);<<endl;<<endl;    
}

SerieDomande :: incrementa_domanda(){
    if(domanda_corrente < 16){
        domanda_corrente++;
        return true;
    }
    else{
        return false;
    }
}
main(){  // Esempio di main per provare la classe
  SerieDomande dom;
  dom.carica_domande();
}
