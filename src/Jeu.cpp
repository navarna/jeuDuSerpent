#include "Jeu.hpp"
#include "Dessin.hpp"
#include <iostream>
#include <chrono>
#include <SFML/Graphics.hpp>


Jeu::Jeu(int taille, int nbr_pion, int nbr_joueur, int dimx, int dimy): Plateau(taille), nbr_pion(nbr_pion), nbr_sym(nbr_sym), nbr_joueur(nbr_joueur),window(sf::VideoMode(dimx,dimy),"Serpent"){
  xdim = dimx ;
  ydim = dimy ;
  Couleur() ;
  int x , y ;
  if(xdim == 836 ) {
    if (!backgroundTexture.loadFromFile("Images/plateau2.png")) {
      cerr << "Error loading Images/Plateau2.gif" << endl;
      exit(0);
    }
    x = 804 ;
    y = 39 ;
  }
  else if (xdim == 1005) {
    if (!backgroundTexture.loadFromFile("./Images/plateau4.png")) {
      cerr << "Error loading Images/Plateau2.gif" << endl;
      exit(0);
    }
    x = 955;
    y = 40 ;
  }
  else {
    if (!backgroundTexture.loadFromFile("Images/plateau3.png")) {
      cerr << "Error loading Images/Plateau2.gif" << endl;
      exit(0);
    }
    x = 1006 ;
    y = 56 ;

  }
  backgroundSprite.setTexture(backgroundTexture);

  for(int i=0;i<nbr_joueur;i++)
    player.push_back(Joueur());
  for(int j=0;j<player.size();j++){
    player[j].ajoute_pion(nbr_pion);
      player[j].initialisation("./Images/KnightYellow.png",tableauCouleur[j]  , nbr_pion,x , y );
  }

  window.clear(sf::Color::White);
  window.display();

}

void Jeu ::Couleur () {
  sf::Color gris (132,132,132);
  sf::Color orange (150,80,0) ;
  tableauCouleur[0] =sf::Color::Blue;
  tableauCouleur[1] = sf::Color::Red;
  tableauCouleur[2] = sf::Color::Yellow;
  tableauCouleur[3] = sf::Color::Magenta  ;
  tableauCouleur[4] = sf::Color::Cyan ;
  tableauCouleur[5] = gris;
  tableauCouleur[6] = orange;
  tableauCouleur[7] = sf::Color::Green ;
  tableauCouleur[8] = sf::Color::White ;
  tableauCouleur[10] =  sf::Color::Black;
}

Jeu::~Jeu()
{
    //dtor
}

int Jeu::De(const int min,const int max){
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
default_random_engine generateur (seed);
uniform_int_distribution<int> distribution(min,max);
int n=distribution(generateur);
return n;
}

bool Jeu::gagnant(int nj){
    for(int i=0;i<nbr_pion;i++){
        if (player[nj].getPosition(i)<63)
            return false;
    }
    cout << "Le joueur " << nj+1 << " a gagné !!!!" << endl;
    return true;
}

void Jeu::avance(Joueur& j,int nump, int av, int jeu ,int *nbDebut, int *nbFin , int *nbFinal){
  *nbDebut = j.getPosition(nump) ;
    if(j.getPosition(nump)+av>plat.size()-1){
        j.setPosition(nump,plat.size()-1-(j.getPosition(nump)+av-(plat.size()-1)));
	*nbFin =  j.getPosition(nump) ;
    if(jeu==1)
        j.setPosition(nump,j.getPosition(nump)+plat[j.getPosition(nump)].getSymbole());
	*nbFinal =  j.getPosition(nump) ;
    }
    else {
       *nbDebut = j.getPosition(nump) ;
        j.setPosition(nump,j.getPosition(nump)+av);
	*nbFin = j.getPosition(nump) ;
     if(jeu==1)
        j.setPosition(nump,j.getPosition(nump)+plat[j.getPosition(nump)].getSymbole());
	*nbFinal = j.getPosition(nump) ;
    }
}




void Jeu::setSprite(sf::Sprite *sprite, int dx,int dy){
    sf::FloatRect rect = sprite->getGlobalBounds();
    float xpos = (xdim - rect.width)  - dx;
    float ypos = (ydim - rect.height) - dy;
    sprite->setPosition(xpos, ypos);
    window.draw(*sprite);
}


void Jeu :: avancePasAPas(int type, int deb , int fin, int joueur , int pion) {
   int x =0, y=0 ;
   if(type) {
     for (int i = deb+1 ; i<= fin+1 ;  i++) {
       sf::sleep(sf::milliseconds(700));
       deplacementGraphique(i,&x,&y) ;
       player[joueur].setPositionGraphique(pion , x,y) ;
       update();
     }
   }
   else {
     sf::sleep(sf::milliseconds(700));
     deplacementGraphique(fin+1,&x,&y) ;
     player[joueur].setPositionGraphique(pion , x,y) ;
     update();
   }
}

 void Jeu :: update() {
   window.clear(sf::Color::White);
    setSprite(&backgroundSprite,0,0);
    dessinerDecor() ;
   for (int i = 0 ; i < player.size() ; i++) {
     player[i].dessinerPion(&window,xdim,ydim) ;
     }
  window.display();
 }

