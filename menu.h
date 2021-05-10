#ifndef MENU_H_
#define MENU_H_

#include<iostream>
#include<cstdlib>
#include"Partita.h"

using namespace std;

class Menu {
  private: 
    SerieDomande ld;
    Partita p;
  public: 
   Menu();
   void visualizza_menu();   
   void visualizza_record ();   // Legge dal file risultatipartite.txt (instream) la lista dei risultati delle partite giocate e le visualizza
   void visualizza_crediti();   // Visualizza i nomi dei progettisti. Una volta mostrati i crediti, bisogna premere Invio per tornare al menu principale.   
};

#endif
