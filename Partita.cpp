#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Partita.h"

using namespace std;

Partita :: Partita (){ // valorizza anche la lista dei premi
    aiuto_casa = false;
    aiuto_dimezza_risposte = false;
    aiuto_salta_domanda = false;
    premio_corrente=-1;
    lista_premi_euro[0] = "15 - 1 MILLION";
    lista_premi_euro[1] = "14 - 300.000";
    lista_premi_euro[2] = "13 - 150.000";
    lista_premi_euro[3] = "12 - 70.000";
    lista_premi_euro[4] = "11 - 30.000";
    lista_premi_euro[5] = "10 - 20.000";
    lista_premi_euro[6] = "9 - 15.000";
    lista_premi_euro[7] = "8 - 10.000";
    lista_premi_euro[8] = "7 - 7.000";
    lista_premi_euro[9] = "6 - 5.000";
    lista_premi_euro[10] = "5 - 3.000";
    lista_premi_euro[11] = "4 - 2.000";
    lista_premi_euro[12] = "3 - 1.500";
    lista_premi_euro[13] = "2 - 1.000";
    lista_premi_euro[14] = "1 - 500";
}

void Partita :: avvio_partita (){
  int scelta=0;
  domande.carica_domande();
  bool visualizzaDomanda = true;
  do{
  	if(visualizzaDomanda == true){
  	  system("clear");
  	  domande.visualizza_domanda();
	}
	else{
	  visualizzaDomanda = true;
	}
    cout<<"Inserisci risposta. (Inserisci 5 se vuoi un aiuto.)"<<endl;
    cin>>scelta;   
    if(scelta>=1 && scelta<=4 ){  // Verifica la risposta
      if (scelta==domande.getDomandaCorrente().getRispostaCorretta()) {
        premio_corrente++; // -1 + 1 = 0 (listapremi[0])
        system("clear");
        visualizza_montepremi();
        if (domande.incrementa_domanda() == false){ //sono finite le domande
          cout<<endl;
          cout<<"\a\a\a";
		  cout<<"\e[102m";
		  cout<<"\e[30m";
		  cout<<"Cogratulations! You win"<<endl;
		  cout<<"\e[39m"<<endl;
		  cout<<"\e[49m"<<endl;
          salvaPartita(); 
          return; // Esce dal metodo
        } else{
          system("pause");
		}
      } else {
        cout<<"Risposta sbagliata."<<endl;
        salvaPartita();
        return; // Esce e torna al menu principale
      }
    } else if(scelta == 5) {  // Aiuto
      visualizzaDomanda = false;
      if(aiuto_dimezza_risposte==false || aiuto_casa==false || aiuto_salta_domanda==false) {
        string s1 = "Seleziona l'aiuto:";
        if(aiuto_casa == false) s1 += " 1) Aiuto da casa ";
        if(aiuto_dimezza_risposte == false) s1 += " 2) Dimezza risposta ";
        if(aiuto_salta_domanda == false) s1 += " 3) Salta domanda  ";
        cout<<s1<<endl;
      
        int aiuto=0;
        cin>>aiuto;
        do {
          if(aiuto == 1){
          	if (aiuto_casa == true){ 
        		cout<<"Aiuto gia' usato";
        	}
        	else{
            	aiuto_da_casa();
        	}
			break;   // esce dal do while
          } else if(aiuto == 2){
          	if (aiuto_dimezza_risposte == true){ 
        		cout<<"Aiuto gia' usato";
        	}
        	else{
            	dimezza_risposte();
        	}
            break;
          } else if(aiuto == 3){
          	if (aiuto_salta_domanda == true){ 
        		cout<<"Aiuto gia' usato";
        	}
        	else{
        		aiuto_salta_domanda = true;
        		domande.incrementa_num_domande();
				if (domande.incrementa_domanda() == false){
					cout<<"\a\a\a";
					cout<<"\e[102m";
					cout<<"\e[30m";
					cout<<"\e[5mCogratulations! You win"<<endl;
					cout<<"\e[39m"<<endl;
					cout<<"\e[49m"<<endl;
              		salvaPartita();
              		return; // Esce dal metodo e torna al menu principale
            	}
            	else{
				  visualizzaDomanda = true;
				  break;
				}
			}
          } else {
            cout<<"Selezione non valida. Riprova."<<endl;
          }      
        }while(true);
      } else {
        cout<<"Aiuti esauriti!"<<endl;        
      }
    } else if (scelta == 6){ // Temporaneo
      domande.aggiungi_domanda(); 
    } else {
      cout<<"Scelta non valida. Riprova."<<endl;
    }
  } while(true);  
}

void Partita :: aiuto_da_casa(){ // 3 volte su 4 (75% di probabilità che sia giusta)
	aiuto_casa = true; 
	int n = 0;
	do{
		n = rand()%4;
	}while(n == domande.getDomandaCorrente().getRispostaCorretta());
	if (rand()%4 == 1){
		cout<<"La risposta corretta e' la "<<n<<endl;
	}
	else{
		cout<<"La risposta corretta e' la "<<domande.getDomandaCorrente().getRispostaCorretta()<<endl;
	}
}

/*bool Partita :: salta_domanda(){
	return domande.incrementa_domanda();
} */ 
    
void Partita :: dimezza_risposte(){
    aiuto_dimezza_risposte = true;
	int n = 0;
	do{
		n = rand()%4;
	}while(n == domande.getDomandaCorrente().getRispostaCorretta());
    cout<<"La risposta corretta e' la "<<domande.getDomandaCorrente().getRispostaCorretta()<<" o la "<<n<<endl; 
}

void Partita :: visualizza_montepremi(){  // visualizza la lista di premi nell'attributo lista_premi_euro evidenziando il premio_corrente
    int n = domande.get_num_domande()-1;
    if (aiuto_salta_domanda == true)
      n--;
	for(int i=0; i<15; i++){
        if (n-i == premio_corrente) {
			//evidenziare la riga
			cout<<"\a";
			cout<<"\e[91m";
			cout<<"*** "<<lista_premi_euro[i]<<" ***";
			cout<<"\e[39m"<<endl;
		}
		else{
			cout<<lista_premi_euro[i]<<endl;
		}
	}
}

void Partita :: salvaPartita(){
	char scelta;
	cout<<"Vuoi salvare la partita? (y/n)"<<endl;
	do{
		cin>>scelta;
		if(scelta == 'y'){
			string nomeg;
			cout<<"Inserire nome giocatore: ";
			cin>>nomeg;
			int n = domande.get_num_domande()-1;
			if (aiuto_salta_domanda == true)
			  n--;
			nomeg += " montepremi: " + lista_premi_euro[n-premio_corrente];
			string aiuti = "";
			if( aiuto_dimezza_risposte == true){
				aiuti += "dimezza risposta";
			}
			if( aiuto_salta_domanda == true){
				if(aiuti != ""){
				  aiuti += ", " ;
				}
				aiuti += "salta domanda";
			}
			if( aiuto_casa == true){
				if(aiuti != ""){
				  aiuti += ", " ;
				}
				aiuti += "aiuto da casa";
			}
			if( aiuti == ""){
				nomeg += " aiuti utilizzati: nessuno";
			}
			else {
				nomeg += " aiuti utilizzati: " + aiuti;
			}
			ofstream out;
			out.open("risultatipartite.txt", ios::app);
			out<<nomeg<<endl;
			out.close();
		}
	}while(scelta != 'y' && scelta != 'n');
}
