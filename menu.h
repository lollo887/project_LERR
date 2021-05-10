#ifndef MENU_H_
#define MENU_H_

#include<iostream>
#include<cstdlib>
using namespace std;

class Menu {
  private: 
    SerieDomande ld;
    Partita p;
  public: 
   Menu();
   visualizza_menu();   
   visualizza_record ();   // Legge dal file risultatipartite.txt (instream) la lista dei risultati delle partite giocate e le visualizza
   visualizza_crediti();   // Visualizza i nomi dei progettisti. Una volta mostrati i crediti, bisogna premere Invio per tornare al menu principale.   
};

#endif
