#include "Numeri.hpp"

Numeri::Numeri(int nbr_joueur): Jeu(40,6,nbr_joueur,1061,687)
{
    //ctor
}

Numeri::~Numeri()
{
    //dtor
}

void Numeri::rempliSym(){
    for(int i=0;i<40;i++)
        plat[i].setSymbole(0);
    plat[1].setSymbole(-3);
    plat[2].setSymbole(-3);
    plat[3].setSymbole(-3);
    plat[4].setSymbole(-2);
    plat[5].setSymbole(-2);
    plat[6].setSymbole(-1);
    plat[7].setSymbole(-1);
    plat[10].setSymbole(1);
    plat[13].setSymbole(2);
    plat[15].setSymbole(3);
    plat[17].setSymbole(4);
    plat[19].setSymbole(5);
    plat[20].setSymbole(6);
    plat[23].setSymbole(7);
    plat[26].setSymbole(8);
    plat[28].setSymbole(9);
    plat[29].setSymbole(10);
    plat[31].setSymbole(11);
    plat[32].setSymbole(12);
    plat[34].setSymbole(13);
    plat[35].setSymbole(15);
    plat[37].setSymbole(20);
    plat[38].setSymbole(25);
    plat[39].setSymbole(30);
}

int Numeri::gagnant(){
    int tab[nbr_joueur];
    int max=0;
    for(int i=0;i<nbr_joueur;i++)
        tab[i]=0;
    for(int j=0;j<nbr_joueur;j++){
        for (int p=0;p<nbr_pion;p++){
            tab[j]+=(p+1)*plat[player[j].getPosition(p)].getSymbole();
        }
        if(tab[j]>max) max=j;
    }
    return max;
}

bool Numeri::finJeu(){
    int f=0;
    for(int j=0;j<nbr_joueur;j++){
        for(int i=0;i<nbr_pion;i++){
            switch(player[j].getPosition(i)){
                case 39:
                    f++;
                    break;
                case 38:
                    f++;
                    break;
                case 37:
                    f++;
                    break;
            }
        }
    }
    return (f==3);
}


bool Numeri::testAligne(int nj){
    for(int i=0;i<nbr_pion-1;i++){
        for(int j=i+1;j<nbr_pion;j++){
            if(player[nj].getPosition(i)==player[nj].getPosition(j)+1 || player[nj].getPosition(i)==player[nj].getPosition(j)-1){
                for(int k=0;k<nbr_pion;k++){
                    if(k!=i && k!=j){
                        if(player[nj].getPosition(k)==player[nj].getPosition(i)+1 || player[nj].getPosition(k)==player[nj].getPosition(i)-1 || player[nj].getPosition(k)==player[nj].getPosition(j)+1 || player[nj].getPosition(k)==player[nj].getPosition(j)-1){
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

int* Numeri::choisi_pion(int numj, int de){
    //int id=player[numj].getId();
    int nbp;
    int * pp=(int*)malloc(sizeof(int)*3);
    bool b=false;
    //if(id==1){         // Si joueur humain
        string nump1[3];
        vector<int> nump;
        while(!b){
            cout << "Combien de pions voulez-vous jouer ?" << endl;
            cin >> nbp;
            cout << "Entrez les numéros des pions souhaités : " << endl;
            for(int w=0;w<nbp;w++){
            cout << "Pion " << w+1 << " : ";
            cin >> pp[w];
            }
            if(nbp==1){
            pp[1]=0;
            pp[2]=0;
            }
            if(nbp==2){
            pp[2]=0;
            }
            b=pion_legal(numj,pp,de);
        }
    //}
    /*else if(id==0){   // Si joueur robot
        while(!b){
            nump=De(1,nbr_pion);
            b=pion_legal(numj,nump);
        }
        cout << "Le joueur " << numj+1 << " a choisi le pion numéro " << nump << endl;
    }*/
    return pp;
}

bool Numeri::pion_legal(int numj,int* nump,int de){ // verifie si le pion nump du joueur numj peut etre joué
    int somme=0;
    for(int i=0;i<(sizeof(nump)/sizeof(int))+1;i++){
    if(nump[i] < 0 || nump[i] > 6){
        cout << "Le pion " << nump[i] << " n'existe pas !" << endl;
        return false;
    }
    else if(player[numj].getPosition(nump[i]-1)==39){
        cout << "Le pion " << nump[i] << " est déjà arrivé !" << endl;
        return false;
    }
    somme+=nump[i];
    }
    if(de!=somme){
        cout << "Le compte des pions n'est pas bons !" << somme << endl;
        return false;
    }
    return true;
}

bool Numeri::estOccupe(int n){
    for(int j=0;j<nbr_joueur;j++){
        for(int i=0;i<nbr_pion;i++){
            if(player[j].getPosition(i)==n)
                return true;
        }
    }
    return false;
}

int Numeri::avancep(int numj,int nump){
    int i=1;
    while(estOccupe(player[numj].getPosition(nump)+i)){
        i++;
    }
    return i;
}


void Numeri::partie(){
    int de=0;
    int i=0;
    rempliSym();

    affiche();
    update();
    bool g=false;
    int * a=(int*)malloc(3*sizeof(int));
    while(!g){
     cout << "Joueur "<<i+1<<" à vous de jouer"<<endl;
        de=De(1,6);
        cout << "Joueur " << i+1 << " a lancé "<< de <<endl;
        a=choisi_pion(i,de);
        for(int h=0;h<3;h++){
        int av=avancep(i,a[h]);
	int nbdeb=0 , nbfin=0 , nbfinal=0;
	avance(player[i],a[h]-1,av,0,&nbdeb,&nbfin,&nbfinal);
	
	avancePasAPas(0,nbdeb,player[i].getPosition(a[h])+1,i,a[h]);
        }
        player[i].affi();
        if(testAligne(i))
            i--;
        g=finJeu();
        i=((++i)%nbr_joueur);
}
        int winner=gagnant();
        cout << "Le joueur " << winner+1 << "a gagné !" << endl;
     //sf::sleep(sf::milliseconds(3000));
}

void Numeri::deplacementGraphique (int numeroCase, int * x, int *y){
  int resultatX = 1006 ;
  int resultatY = 56 ; 
  int nbY = (numeroCase-1) / 5 ;
  int nbX = (numeroCase -1 ) %8 ;
  resultatY += nbY * 143;
  resultatX -= nbX * 92 ; 
  (*x) = resultatX ;
  (*y) = resultatY ; 
  cout << "deplacementgraph" << numeroCase <<" " <<  *x  << " " << *y << endl ; 
}
void Numeri::dessinerDecor(){}
void  Numeri::creationDessin(int choix ,  int debut , int fin, sf::Color c , sf::Color c2){}
