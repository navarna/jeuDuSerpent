#ifndef AFFICHAGE
#define AFFICHAGE
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std ; 

class Affichage{
public:  
  Affichage() ;
  virtual ~Affichage() ;
private :
  void couleurSprite(sf::Sprite * sprite ,sf::Color c) ;
  void deplacementGraphique ( int numeroCase, int * x , int *y );
  void avancePasAPas(int deb , int fin ) ; 
  void update();		        // Update positions of particules
  void render();		        // Draw sprites at updated positions
  void setSprite(sf::Sprite *, int dx, int dy);
  void creationDessin (int choix ,  int debut , int fin, sf::Color c , sf::Color c2) ;
  const int xdim = 836 ;
  const int ydim = 634 ;
  const
  sf::RenderWindow window ;
  sf::Texture backgroundTexture; 	// Texture for the background
  sf::Sprite backgroundSprite;  
};

#endif
