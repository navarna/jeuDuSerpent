#ifndef CARTE_H
#define CARTE_H

#include "Jeu.hpp"
#include "Joueur.hpp"
#include <SFML/Graphics.hpp>
using namespace std;

class Carte : public Jeu
{
    public:
        Carte(int nbr_joueur, int nbr_pion);
        virtual ~Carte();
        virtual void rempliSym();
        string Deck(int de);
        int prochainSym(int n_case, int sym);
        void partie();
        bool pion_legal(int numj,int nump);
        int choisi_pion(int numj);
        void deplacementGraphique (int numeroCase, int * x, int *y);
        void dessinerDecor();
        void  creationDessin(int choix ,  int debut , int fin, sf::Color c , sf::Color c2);
        void affiche_main(int joueur);
        int choisi_carte(int nj);
        void recule_pion(int nj);
    protected:
        int main[10][8];
        int nbr_carte[10];
    private:
};

#endif // CARTE_H
