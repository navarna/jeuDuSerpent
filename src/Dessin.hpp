#ifndef DESSIN
#define DESSIN
#include <SFML/Graphics.hpp>

class Dessin {
public:
  Dessin() ;
  void FaireEchelle (sf::RenderWindow *fen , int xdeb , int ydeb , int xfin , int yfin, sf::Color c);
  void FaireSerpent (sf::RenderWindow *fen , int xdeb , int ydeb , int xfin , int yfin , sf::Color c ,sf::Color c2);
   void FaireDessin (sf::RenderWindow * fen , int x , int y , int chiffre,sf::Color c );
};

#endif 
