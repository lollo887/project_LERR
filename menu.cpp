#include<iostream>
#include<cstdlib>
#include<fstream>
#include"menu.h"
using namespace std;

Menu :: Menu() : ld(), p(){
  visualizza_menu();
}
 
void Menu :: visualizza_menu(){
  int opzione;
  do {
    system("clear");
    cout<<"*** CHI VUOL ESSERE MILIONARIO ***"<<endl<<endl; 
    cout<<"1) Inizia Gioco"<<endl; 
    cout<<"2) Aggiungi domanda"<<endl; 
    cout<<"3) Record"<<endl; 
    cout<<"4) Crediti"<<endl; 
    cout<<"5) Esci"<<endl<<endl;
    cout<<"Opzione scelta: "; 
    cin>>opzione;   
    switch(opzione){
      case 1:
        p.avvio_partita();
        break;
      case 2:
        ld.aggiungi_domanda();
        break;
      case 3:
      	visualizza_record();
      	break;
      case 4:
      	visualizza_crediti();
      	break;
      case 5:
        cout<<"E' stato un piacere giocare insieme a te, grazie e alla prossima..."<<endl;
        return;
      default:    
        cout<<"Scelta non valida, riprova."<<endl; //se il numero non è tra 1 e 5
    	break;
    }
  } while(true);
}
void Menu :: visualizza_record(){
	ifstream in;
	in.open("risultatipartite.txt");
	string s1;
	system("clear");
	while(getline(in,s1)){
		cout<<s1<<endl;
	}
	system("pause");
	getline(cin,s1);
}

void Menu :: visualizza_crediti(){
	ifstream in;
	in.open("crediti.txt");
	string s1;
	system("clear");
	while(getline(in,s1)){
		cout<<s1<<endl;
	}
	getline(cin,s1);
	//cout<<"premere INVIO per tornare al menu' iniziale";
	system("pause");
}







