#include <iostream>
#include "Plateau.hpp"
#include "Joueur.hpp"
#include "Jeu.hpp"
#include "Serpent.hpp"
#include "Carte.hpp"
#include "Numeri.hpp"

using namespace std;

int main()
{
    string joueur, type_jeu, pion;
    int j, t, p;
    bool arg=false;
    while(!arg){
        cout <<"Combien de joueurs vont participer à cette partie ? (10 joueurs max)"<<endl;
        cin>>joueur;
        j=atoi(joueur.c_str());
        if(j<1||j>10){
            cout<<"Le nombre de joueurs n'est pas correct"<<endl;
        }
        else{
            arg=true;
        }
    }
    arg=false;
    while(!arg){
        cout<<"Combien de pions par joueur voulez-vous ? (6 pion max)"<<endl;
        cin>>pion;
        p=atoi(pion.c_str());
        if(p<1 || p>6){
            cout << "Le nombre de pions n'est pas correct"<<endl;
        }
        else{
            arg=true;
        }
    }
    arg=false;
    while(!arg){
        cout<<"A quel type de jeux voulez-vous jouer?"<<endl;
        cout<<"Serpent Classique-------> 1"<<endl;
        cout<<"Serpent Avec question---> 2"<<endl;
        cout<<"Serpent avec des cartes-> 3"<<endl;
        cout<<"Numeri------------------> 4"<<endl;
        cin>>type_jeu;
        t=atoi(type_jeu.c_str());
        if(t!=1 && t!=2 && t!=3&&t!=4){
            cout<<"Entrez 1, 2, 3 ou 4"<<endl;
        }
        else{arg=true;}
    }
    if(t==1 || t==2){
        Serpent s(j, p);
        s.partie(t-1);
    }
    else if(t==3){
        Carte c(j, p);
        c.partie();
    }
    else if(t==4){
    	Numeri n(j);
    	n.partie();
    }
      return 0;
}
