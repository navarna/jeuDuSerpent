#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
class Joueur
{
public:
  Joueur();
  virtual ~Joueur();
  void ajoute_pion();      //ajoute un seul pion
  void ajoute_pion(int n); //ajoute plusieurs pions au joueur
  int getPosition(int n);
  int setPosition(int nump,int n);
  void setId(int t);
  int getId();
  void affi();
  int getXpion (int n ) ;
  int getYpion (int n ) ;
  void setPositionGraphique (int n , int x , int y) ;
  sf::Sprite getPionGraphique(int n ) ;
  void setPionGraphique(int n ,sf::Sprite* sp); 
  void initialisation (string imagePion , sf::Color c , int nombrePion, int x , int y ) ;
  void dessinerPion (sf::RenderWindow *fen, int xdim , int ydim );
protected:
  vector<int> pion;       // tableau contenant les pions du joueur
  vector<int>  xPion ;
  vector <int> yPion ; 
  vector <sf::Sprite> pionGraphique;
  sf::Texture textureDesPions ; 
  sf::Color c ;
  static int compteur;
  int id;                    //numero du joueur
private:
};

#endif // JOUEUR_H
