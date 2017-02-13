#include "Serpent.hpp"
#include "Dessin.hpp"

#include <SFML/Graphics.hpp>
Serpent::Serpent(int nbr_joueur, int nbr_pion)
  :Jeu(64, nbr_pion, nbr_joueur,836,634){
  char c=0;
  bool b=false;
  for(int i=0;i<nbr_joueur;i++){
    cout << "Le joueur " << i+1 << " est-il un robot ? (o/n)" << endl;
    cin >> c;
    if (c=='o') {
      player[i].setId(0);
    }
    else if (c=='n') {
      player[i].setId(1);
    }
    else i--;
  }

}
Serpent::~Serpent()
{
    //dtor
}

void Serpent::rempliSym(){
    int c=0;
    int min_c,max_c,min_s,max_s,sym;
    min_c=3;
    max_c=53;
    for(int i=1;i<9;i++){
    if(i>4){
    min_c=17;
    max_c=62;
    }
    unsigned seed=0;
    do{
    seed = std::chrono::system_clock::now().time_since_epoch().count();
        default_random_engine generateur (i*seed);
        uniform_int_distribution<int> distribution_case(min_c,max_c);
        c=distribution_case(generateur);
    if(i<5){
    min_s=9;
    max_s=plat.size()-c-2;
    }
    else {
    min_s=9;
    max_s=c-2;
    }
    }

     while(plat[c].getSymbole()!=0);
        default_random_engine generateur2 (i*seed*100);
        uniform_int_distribution<int> distribution_sym(min_s,max_s);
        if(i<5) sym=distribution_sym(generateur2);
        else sym=-distribution_sym(generateur2);
        plat[c].setSymbole(sym);
    }
}

bool Serpent::pion_legal(int numj,int nump){ // verifie si le pion nump du joueur numj peut etre joué
    if(nump < 1 || nump > nbr_pion){
        cout << "Le pion " << nump << " n'existe pas !" << endl;
        return false;
    }
    else if(player[numj].getPosition(nump-1)==63){
        cout << "Le pion " << nump << " est déjà arrivé !" << endl;
        return false;
    }
    return true;
}

int Serpent::choisi_pion(int numj){ // s'occupe du choix du pion
    int id=player[numj].getId();
    int nump=0;
    bool b=false;
    if(id==1){         // Si joueur humain
        string nump1="";
        while(!b){
            cout << "Entrez le numéro du pion souhaité : " << endl;
            cin >> nump1;
            nump=atoi(nump1.c_str());
            b=pion_legal(numj,nump);
        }
    }
    else if(id==0){   // Si joueur robot
        while(!b){
            nump=De(1,nbr_pion);
            b=pion_legal(numj,nump);
        }
        cout << "Le joueur " << numj+1 << " a choisi le pion numéro " << nump << endl;
    }
    return nump-1;
}

bool Serpent::question(){
    int a, b, op, reponse;
    std::string nump1;
    unsigned int seed;

    for(int i=1; i<3; i++){
        seed = std::chrono::system_clock::now().time_since_epoch().count();
        default_random_engine generateur (seed*i);
        uniform_int_distribution<int> distribution(1, 20);
        switch(i){
        case 1:
            a=distribution(generateur);
            break;
        case 2:
            b=distribution(generateur);
            break;
        default:
            break;
        }
    }
        default_random_engine generateur (seed*4);
        uniform_int_distribution<int> distribution_sym(1, 3);
        op=distribution_sym(generateur);
        if(op==1){
            cout<<a<<"+"<<b<<"= ?"<<endl;
        }
        else if(op==2){
            cout<<a<<"-"<<b<<"= ?"<<endl;
        }
        else{
            cout<<a<<"*"<<b<<"= ?"<<endl;
        }
        std::cin>>nump1;
        reponse=atoi(nump1.c_str());
        if(op==1){
            if(reponse==a+b)
                return true;
        }
        else if(op==2){
            if(reponse==a-b)
                return true;
        }
        else{
            if(reponse==a*b)
                return true;;
        }
        return false;
}

void Serpent::partie(int n){
    int de=0;
    int i=0;
    rempliSym();
    affiche();
    update() ;
    bool g=false;
    bool joue=true;
    while(!g){
     cout << "Joueur "<<i+1<<" à vous de jouer"<<endl;
    if(n==1)
        if (player[i].getId()==1)
            joue=question(); //on pose la question au joueur humain seulement
    if (joue){
        de=De(1,6);
        if (nbr_pion==1){
	  int nbdeb=0 , nbfin=0 , nbfinal=0 ;
	  avance(player[i],0,de,1,&nbdeb,&nbfin,&nbfinal);
	  avancePasAPas(1,nbdeb,nbfin,i,0);
	    avancePasAPas(0,nbdeb,nbfinal,i,0);
	}
        else {
            int a=choisi_pion(i);
	    int nbdeb=0 , nbfin=0 , nbfinal=0 ;
	    avance(player[i],a,de,1, &nbdeb,&nbfin,&nbfinal);
	    avancePasAPas(1,nbdeb,nbfin,i,a);
	    avancePasAPas(0,nbdeb,nbfinal,i,a);
        }
        cout << "Joueur " << i+1 << " a lancé "<< de <<endl;
        player[i].affi();
        g=gagnant(i);
    }
    else
        cout<<"Vous n'avez pas bien repondu a la question..."<<endl;
    i=((++i)%nbr_joueur);
    //sleep(1);
    }
     sf::sleep(sf::milliseconds(3000));
}


void Serpent :: dessinerDecor() {
  int count  = 0;
  for(int i = 0 ; i < taille ; i++) {
    int caseI = plat[i].getSymbole()  ;
    if (caseI != 0 ) {
      if(caseI<0){
	int deb = i+1 +caseI ;
	creationDessin(0,deb,i+1,tableauCouleur[count],tableauCouleur[count] );
      }
      else {
	int fin = i+1 + caseI ;
	creationDessin(1,i+1,fin,tableauCouleur[count],tableauCouleur[count]);
      }
      count ++ ;
    }
  }
}

void Serpent :: creationDessin(int choix ,  int debut , int fin, sf::Color c , sf::Color c2){
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


void Serpent :: deplacementGraphique ( int numeroCase, int * x, int *y) {
    int resultatX = 804 ;
    int resultatY = 39 ;
    int nbY = (numeroCase-1) / 8 ;
    int nbX = (numeroCase -1 ) %8 ;
    resultatY += nbY * 79;
    resultatX -= nbX * 64 ;
    (*x) = resultatX ;
    (*y) = resultatY ;
}

