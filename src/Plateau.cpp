#include "Plateau.hpp"

using namespace std;
Plateau::Plateau(int taille): taille(taille)
{
  for(int i=0; i<taille; i++){
    plat.push_back(Case(i, 0));
  }
}

void Plateau::affiche(){
  cout<<" ------------------------------------"<<endl;
    for(int i=0; i<plat.size(); i++){
        cout<<"| "<<plat[i];
        if((i+1)%8==0){
            cout<<"|"<<endl;
        }
    }
    cout<<" ------------------------------------"<<endl;
    cout <<endl;
}

Plateau::~Plateau()
{
    //dtor
}

