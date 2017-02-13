#ifndef JEU_HPP
#define JEU_HPP

#include "Plateau.hpp"
#include "Joueur.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class Jeu : public Plateau
{
public:
  Jeu(int taille, const int nbr_pion, const int joueur,int dimx,int dimy); // creer un jeu
  virtual ~Jeu();
  void Couleur() ;
  int De(const int min, const int max);
  bool gagnant(int nj);
  void avance(Joueur& j, int nump, int av, int jeu, int *nbDebut, int *nbFin , int *nbfinal);
  virtual void deplacementGraphique (int numeroCase, int * x, int *y)=0;
  virtual void rempliSym()=0;
  virtual void dessinerDecor()=0;
  virtual void  creationDessin(int choix ,  int debut , int fin, sf::Color c , sf::Color c2)=0;
  void setSprite(sf::Sprite *sprite, int dx,int dy);
  void avancePasAPas(int type,int deb , int fin , int joueur , int pion);
  void update ();

protected:
  const int nbr_pion;  //nombre de pion pour chaque joueur
  const int nbr_sym;   //nombre de type de case different
  const int nbr_joueur; //nombre de joueur
  vector <Joueur> player;
  sf::Color tableauCouleur[10] ;
  sf::RenderWindow window ;
  sf::Sprite backgroundSprite ;
  sf::Texture backgroundTexture;
  int xdim  ;
  int ydim  ;
private:
};

#endif // JEU_HPP
