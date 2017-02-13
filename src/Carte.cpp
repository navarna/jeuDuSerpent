#include "Carte.hpp"
#include "Dessin.hpp"
#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

Carte::Carte(int nbr_joueur, int nbr_pion): Jeu(64, nbr_pion, nbr_joueur,1005,734){
   for(int i=0; i<nbr_joueur; i++){

   for(int j=0; j<nbr_joueur; j++){
    nbr_carte[j]=8;
   }
    main[i][0]=0;
    main[i][1]=0;
    main[i][2]=1;
    main[i][3]=1;
    main[i][4]=2;
    main[i][5]=2;
    main[i][6]=3;
    main[i][7]=3;
   }


}

void Carte::rempliSym(){
    int de;
    int trefle=0, coeur=0, carro=0, pic=0;
    bool rem=false;

    for(int j=0; j<64; j+=8){
        for(int i=0; i<8; i++){
            while(!rem){
                unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
                default_random_engine generateur (seed*(i+j+100));
                uniform_int_distribution<int> distribution(0,3);
                de=distribution(generateur);
                switch(de){
                case 0:
                    if(trefle<2){
                            plat[i+j].setSymbole(de);
                            trefle++;
                            rem=true;
                    }
                    break;
                case 1:
                    if(coeur<2){
                            plat[i+j].setSymbole(de);
                            coeur++;
                            rem=true;
                    }
                    break;
                case 2:
                    if(carro<2){
                            plat[i+j].setSymbole(de);
                            carro++;
                            rem=true;
                    }
                    break;
                case 3:
                    if(pic<2){
                            plat[i+j].setSymbole(de);
                            pic++;
                            rem=true;
                    }
                    break;
                default:
                    break;
            }

        }
         rem=false;
        }
        trefle=0;
        coeur=0;
        carro=0;
        pic=0;
    }
}

string Carte::Deck(int de){
    switch(de){
        case 0:
            return "rond";
            break;
        case 1:
            return "triangle";
            break;
        case 2:
            return "losange";
            break;
        case 3:
            return "hexa";
            break;
        default:
            return "";
            break;
        }
}

int Carte::prochainSym(int n_case, int sym){
    for(int i=n_case+1; i<=n_case+8; i++){
        if(plat[i].getSymbole()==sym){
            return i;
        }
    }
    return 0;
}

void Carte::affiche_main(int joueur){
    cout <<"Vous avez";
    for(int i=0; i<8; i++){
        cout<<" "<<Deck(main[joueur][i]);
    }
    cout<<" dans votre main"<<endl;
}

int Carte::choisi_carte(int nj){
    string nump="";
    int sym;
    bool b=false, test=false;
    cout <<"Quelle carte voulez vous choisir?"<<endl;
    while(!test){
        while(!b){
            cin>>nump;
            if(nump.compare("rond")==0){
                sym=0;
                nbr_carte[nj]--;
                b=true;
            }
            else if(nump.compare("triangle")==0){
                sym=1;
                nbr_carte[nj]--;
                b=true;
            }
            else if(nump.compare("losange")==0){
                sym=2;
                nbr_carte[nj]--;
                b=true;
            }
            else if(nump.compare("hexa")==0){
                sym=3;
                nbr_carte[nj]--;
                b=true;
            }
            else{
                cout<<"cette couleur n'existe pas"<<endl;
            }
        }
        for(int i=0; i<8; i++){
            if(main[nj][i]==sym){
                main[nj][i]=-1;
                return sym;
            }
        }
        nbr_carte[nj]++;
        cout<<"Vous n'avez pas de cette couleur dans la main"<<endl;
        b=false;
    }
}

void Carte::recule_pion(int nj){
    int p=0;
    p=choisi_pion(nj);
    int res=0, diff=64;
    for(int i=0; i<nbr_pion; i++){
        if(i!=p){
            if(player[nj].getPosition(p)-player[nj].getPosition(i)<diff){
               diff= player[nj].getPosition(p)-player[nj].getPosition(i);
                res=player[nj].getPosition(i);
            }
        }
    }
    if(diff<0){
        player[nj].setPosition(p,0);
	avancePasAPas(0,0,0,nj,p);
    }
    else{
        player[nj].setPosition(p,res);
	avancePasAPas(0,0,res,nj,p) ;
    }
}


void Carte::partie(){

    int de=0;
    int b=0;
    char c;
    int i=0;
    int psym=0;
    rempliSym();
    affiche();
    update();
    bool g=false;
    while(!g){
        cout << "Joueur "<<i+1<<" à vous de jouer"<<endl;
        cout<<"Vous avez "<<nbr_carte[i]<<" cartes dans votre main"<<endl;
        affiche_main(i);
        if(nbr_carte[i]!=8){
                cout<<"Voulez vous faire reculer un pion pour piocher une carte? (o/n)"<<endl;
                while(c!='n'&&c!='o'){
                cin>>c;
                if(c=='n'){
                    b=choisi_carte(i);

                        int nbdeb=0 , nbfin=0 , nbfinal=0 ;
                        int a=choisi_pion(i);
                        psym=prochainSym(player[i].getPosition(a), b);
                       avance(player[i],a,psym-player[i].getPosition(a),0,&nbdeb,&nbfin,&nbfinal);
                        avancePasAPas(1,nbdeb ,nbfin,i,a);
                }
                else if(c=='o'){
                    recule_pion(i);
                    int de=De(0,3);
                    for(int k=0; k<8; k++){
                        if(main[i][k]==-1){
                            main[i][k]=de;
                            nbr_carte[i]++;
                            break;
                        }
                    }
                }
            }
        }
        else{
            b=choisi_carte(i);
            int nbdeb=0 , nbfin=0 , nbfinal=0 ;
            int a=choisi_pion(i);
            psym=prochainSym(player[i].getPosition(a), b);
            avance(player[i], a, psym-player[i].getPosition(a),0, &nbdeb, &nbfin, &nbfinal);
            avancePasAPas(1,nbdeb ,nbfin,i,a);
        }

        player[i].affi();
        g=gagnant(i);
        i=((++i)%nbr_joueur);
        }


    }




Carte::~Carte()
{
    //dtor
}

void Carte::deplacementGraphique (int numeroCase, int * x, int *y){
  int resultatX = 955 ;
  int resultatY = 40 ;
  int nbY = (numeroCase-1) / 8 ;
  int nbX = (numeroCase -1 ) %8 ;
  resultatY += nbY * 91;
  resultatX -= nbX * 86 ;
  (*x) = resultatX ;
  (*y) = resultatY ;
}
void Carte::dessinerDecor(){
  int taille = plat.size() ;
  Dessin d ;
  for(int i = 0 ; i < plat.size() ; i++) {
    int symb = plat[i].getSymbole() ;
    creationDessin(0,i+1,symb,tableauCouleur[9-symb],tableauCouleur[9-symb]);
  }
}

void  Carte::creationDessin(int choix ,  int debut , int chiffre, sf::Color c , sf::Color c2){
  int xdebut, ydebut ;
  deplacementGraphique(debut,&xdebut ,&ydebut ) ;
  Dessin d  ;
  d.FaireDessin(&window , 975-xdebut , 705-ydebut , chiffre, c) ;
}

bool Carte::pion_legal(int numj,int nump){ // verifie si le pion nump du joueur numj peut etre joué
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

int Carte::choisi_pion(int numj){ // s'occupe du choix du pion
    int nump=0;
    bool b=false;
        string nump1="";
        while(!b){
            cout << "Entrez le numéro du pion souhaité : " << endl;
            cin >> nump1;
            nump=atoi(nump1.c_str());
            b=pion_legal(numj,nump);
        }


    return nump-1;
}




