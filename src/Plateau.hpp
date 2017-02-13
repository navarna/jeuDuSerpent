#ifndef PLATEAU_H
#define PLATEAU_H
#include "Case.hpp"

#include <vector>
#include <iostream>
using namespace std;

class Plateau
{
public:
  Plateau(int taille);
  virtual ~Plateau();
  void affiche();
  
protected:
  vector <Case> plat;
  int taille;  //nombre de case du plateau

private:
};

#endif // PLATEAU_H
