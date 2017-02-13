#include <SFML/Graphics.hpp>
#include "Affichage.hpp"
#include "Dessin.hpp"

Affichage::Affichage()
  : window(sf::VideoMode(xdim, ydim), "Affichage experiment",sf::Style::Close) {
  // Load images in textures and create sprite
  // background sprite
  if (!backgroundTexture.loadFromFile("Images/plateau2.png")) {
    cerr << "Error loading Images/Plateau2.gif" << endl;
    exit(0);
  }
  backgroundSprite.setTexture(backgroundTexture);
  // Pion sprite
  if (!pionTexture.loadFromFile("Images/BishopYellow.png")) {
    cerr << "Error loading Images/bishopYellow.png" << endl;
    exit(0);
  }
}


void Affichage :: deplacementGraphique ( int numeroCase, int * x, int *y) {
    int resultatX = 804 ;
    int resultatY = 39 ; 
    int nbY = (numeroCase-1) / 8 ;
    int nbX = (numeroCase -1 ) %8 ;
    resultatY += nbY * 79;
    resultatX -= nbX * 64 ; 
    (*x) = resultatX ;
    (*y) = resultatY ;  
}

void Affichage :: avancePasAPas( int deb , int fin , int *x , int *y) {
  for (int i = deb+1 ; i<= fin ;  i++) {
    sf::sleep(sf::milliseconds(700));
    deplacementGraphique(i,x,y) ; 
    render() ;
  }
}


void Affichage :: creationDessin(int choix ,  int debut , int fin, sf::Color c , sf::Color c2){
  int xdebut, ydebut , xfin,  yfin  ;
  deplacementGraphique(debut,&xdebut ,&ydebut ) ;
  deplacementGraphique(fin , &xfin,&yfin) ;
  Dessin d  ; 
  if(choix) {
    d.FaireEchelle(&window , 836-xdebut , 634-ydebut , 836-xfin , 634-yfin , c) ; 
  }
  else {
    d.FaireSerpent(&window , 836-xdebut , 634-ydebut , 836-xfin , 634-yfin , c,c2)  ;
  }
} 

void Affichage :: couleurSprite (sf::Sprite* sprite , int rouge , int vert , int bleu ) {
  sf::Color a (rouge,vert,bleu) ; 
  (*sprite).setColor(a) ;
  
}

void Affichage::setSprite(sf::Sprite *sprite, int dx,int dy){
    // Dimensions of the sprite
    sf::FloatRect rect = sprite->getGlobalBounds();
    // Position of upper-left corner of the sprite
    float xpos = (xdim - rect.width)  - dx;
    float ypos = (ydim - rect.height) - dy;
    // Set position of the sprite
    sprite->setPosition(xpos, ypos);
    // Draw the sprite at the given position
    window.draw(*sprite);
}

// Update view
void Affichage::render() {
  // Background color
  window.clear(sf::Color::White);
  setSprite(&backgroundSprite,0,0);
  setSprite(&pionSprite,xPion,yPion);
  // Make update visible
  window.display();
}

