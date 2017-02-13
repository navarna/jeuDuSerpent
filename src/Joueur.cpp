#include <SFML/Graphics.hpp>
#include "Joueur.hpp"
Joueur::Joueur(){}

//ajoute un pion au joueur
void Joueur::ajoute_pion(){
    pion.push_back(0);
}
//ajoute n pion au plateau
void Joueur::ajoute_pion(int n){
    for(int i=0; i<n; i++){
        ajoute_pion();
    }
}

Joueur::~Joueur()
{
    //dtor
}

int Joueur::getPosition(int n){
return pion[n];
}

int Joueur::setPosition(int nump,int n){
pion[nump]=n;
}

void Joueur::setId(int t){
id=t;
}

int Joueur::getId(){
return id;
}

void Joueur::affi(){
for(int i=0;i<pion.size();i++)
     cout << "le pion "<< i+1 << " est a la position " << pion[i]+1<<endl;
}

int Joueur :: getXpion (int n ) {
  return xPion[n];
} 

int Joueur :: getYpion (int n ) {
  return yPion[n];
} 

void Joueur :: setPositionGraphique(int n , int x , int y ) {
  xPion[n] = x;
  yPion[n] = y ;
}

sf::Sprite Joueur :: getPionGraphique (int n ) {
  return pionGraphique[n] ; 
}

void Joueur ::setPionGraphique (int n , sf::Sprite *sp ) {
  this->pionGraphique[n] = *sp ; 
}

void Joueur :: initialisation (string ImagePion , sf::Color c , int nombrePion , int x , int y){
  if(!textureDesPions.loadFromFile(ImagePion) ) {
    cerr << "erreur chargement de l'image "<< ImagePion << endl ;
    exit(0) ;
  }
  while(nombrePion >0 ) {
    sf::Sprite nouveau ;
    nouveau.setColor(c) ;
    this->pionGraphique.push_back(nouveau) ;
    this->xPion.push_back(x) ;
    this->yPion.push_back(y) ;
    nombrePion -- ; 
  }

  


}

void Joueur :: dessinerPion (sf::RenderWindow *fen, int xdim , int ydim ) {
  for (int i = 0 ; i < xPion.size() ; i ++ ) {
  sf ::Sprite sprite =getPionGraphique(i) ;  
  sprite.setTexture(textureDesPions);
  int dx = getXpion(i);
  int dy = getYpion(i); 
  sf::FloatRect rect = sprite.getGlobalBounds();
  float xpos = (xdim - rect.width)  - dx;
  float ypos = (ydim - rect.height) - dy;
  sprite.setPosition(xpos, ypos);
  (*fen).draw(sprite);
  }
}

