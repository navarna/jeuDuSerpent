#ifndef NUMERI_HPP
#define NUMERI_HPP
#include "Jeu.hpp"
#include <unistd.h>
#include <vector>
using namespace std;


class Numeri : public Jeu
{
    public:
        Numeri(int nbr_joueur);
        virtual ~Numeri();
        void rempliSym();
        bool finJeu();
        int gagnant();
        bool testAligne(int nj);
        int* choisi_pion(int numj,int de);
        bool pion_legal(int numj,int nump[],int de);
        void partie();
        bool estOccupe(int n);
        int avancep(int numj,int nump);
        virtual void deplacementGraphique (int numeroCase, int * x, int *y);
        virtual void dessinerDecor();
        virtual void  creationDessin(int choix ,  int debut , int fin, sf::Color c , sf::Color c2);
    protected:
    private:
};

#endif // NUMERI_HPP
