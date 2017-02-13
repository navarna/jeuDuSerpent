#ifndef SERPENT_H
#define SERPENT_H
#include "Jeu.hpp"
#include "Joueur.hpp"
#include <SFML/Graphics.hpp>
#include <random>
#include <chrono>
#include <unistd.h>
using namespace std;

class Serpent : public Jeu
{
public:
  Serpent(int nbr_joueur,int nbr_pion);
  virtual ~Serpent();
  virtual void rempliSym();
  void partie(int n);
  bool pion_legal(int numj,int nump);
  int choisi_pion(int numj);
  bool question();
  virtual void dessinerDecor();
  virtual void  creationDessin(int choix ,  int debut , int fin, sf::Color c , sf::Color c2);
  virtual void deplacementGraphique (int numeroCase, int * x, int *y);
protected:

private:
};

#endif // SERPENT_H
