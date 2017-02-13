#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Dessin.hpp"
#define PI 3.14159265
using namespace std ; 

Dessin :: Dessin () {}
void Dessin :: FaireEchelle (sf::RenderWindow *fen , int xdeb , int ydeb , int xfin , int yfin, sf::Color c)  {
  double x0 , xtotal,y0,ytotal ; 
  int espace = 20 ; 
  int nombredeX  = xdeb -xfin; 
  bool absysse=true ; 
  if((nombredeX < 240)&&(nombredeX>-240)){
    absysse=false ;
  } 
  if(absysse) {
    if (xdeb < xfin ){ 
      x0 = xdeb ; 
      xtotal = xfin ; 
      y0 = ydeb ;
      ytotal = yfin ; 
    }
    else {
      x0 = xfin ; 
      xtotal =xdeb ;
      y0 = yfin;
      ytotal = ydeb ; 
    }

    double a  = (ytotal - y0) /(xtotal - x0);
    double b = ytotal - (a * xtotal ) ; 
    int lon = xtotal - x0 ;
    sf::VertexArray ligneUn (sf::Lines , 2 ) ;
    ligneUn[0] = sf::Vector2f (x0,y0-espace) ;
    ligneUn[0].color = c ;
    ligneUn[1] = sf::Vector2f (xtotal,ytotal-espace) ;
    ligneUn[1].color = c ; 
    sf::VertexArray ligneUn2 (sf::Lines , 2 ) ;
    ligneUn2[0] = sf::Vector2f (x0,y0-espace-1) ;
    ligneUn2[0].color = c ;
    ligneUn2[1] = sf::Vector2f (xtotal,ytotal-espace-1) ;
    ligneUn2[1].color = c ; 
    sf::VertexArray ligneDeux (sf::Lines,2) ; 
    ligneDeux[0] = sf::Vector2f (x0,y0+espace);
    ligneDeux[0].color = c ; 
    ligneDeux[1] = sf::Vector2f (xtotal,ytotal+espace) ;
    ligneDeux[1].color = c ;
    sf::VertexArray ligneDeux2 (sf::Lines,2) ; 
    ligneDeux2[0] = sf::Vector2f (x0,y0+espace+1);
    ligneDeux2[0].color = c ; 
    ligneDeux2[1] = sf::Vector2f (xtotal,ytotal+espace+1) ;
    ligneDeux2[1].color = c ;
    (*fen).draw(ligneUn) ;
    (*fen).draw(ligneDeux) ;
    (*fen).draw(ligneUn2) ;
    (*fen).draw(ligneDeux2) ; 

    if (lon <40 ) {
      int xmillieu = (xtotal+ x0)/2 ;
      int ymillieu = (ytotal+y0)/2 ;
      sf::VertexArray ligneTrois (sf::Lines,2 );
      ligneTrois[0] = sf::Vector2f(xmillieu,ymillieu-espace) ;
      ligneTrois[0].color = c ; 
      ligneTrois[1] = sf::Vector2f(xmillieu,ymillieu+espace) ; 
      ligneTrois[1].color = c ; 
      (*fen).draw(ligneTrois) ;  
      sf::VertexArray ligneTrois2 (sf::Lines,2 );
      ligneTrois2[0] = sf::Vector2f(xmillieu,ymillieu-espace+1) ;
      ligneTrois2[0].color = c ; 
      ligneTrois2[1] = sf::Vector2f(xmillieu,ymillieu+espace+1) ; 
      ligneTrois2[1].color = c ; 
      (*fen).draw(ligneTrois2) ; 
    }
    else {
      for (int i= x0+40 ; i <xtotal-40; i = i+40 ){
	int y = a*i + b ;
	sf::VertexArray ligne (sf::Lines,2 );
	ligne[0] = sf::Vector2f(i,y-espace) ;
	ligne[0].color = c ; 
	ligne[1] = sf::Vector2f (i,y+espace) ; 
	ligne[1].color = c ;
	sf::VertexArray ligne2 (sf::Lines,2 );
	ligne2[0] = sf::Vector2f(i,y-espace+1) ;
	ligne2[0].color = c ; 
	ligne2[1] = sf::Vector2f (i,y+espace+1) ; 
	ligne2[1].color = c ;
	(*fen).draw(ligne) ;
	(*fen).draw(ligne2) ;
      }
    }
  }


  else {
        if (ydeb < yfin ){ 
      x0 = xdeb ; 
      xtotal = xfin ; 
      y0 = ydeb ;
      ytotal = yfin ; 
    }
    else {
      x0 = xfin ; 
      xtotal =xdeb ;
      y0 = yfin;
      ytotal = ydeb ; 
    }

    double a  = (xtotal - x0) /(ytotal - y0);
    double b = xtotal - (a * ytotal ) ; 
    int lon = ytotal - y0 ;
    sf::VertexArray ligneUn (sf::Lines , 2 ) ;
    ligneUn[0] = sf::Vector2f (x0-espace,y0) ;
    ligneUn[0].color = c ;
    ligneUn[1] = sf::Vector2f (xtotal-espace,ytotal) ;
    ligneUn[1].color = c ; 
    sf::VertexArray ligneUn2 (sf::Lines , 2 ) ;
    ligneUn2[0] = sf::Vector2f (x0-espace-1,y0) ;
    ligneUn2[0].color = c ;
    ligneUn2[1] = sf::Vector2f (xtotal-espace-1,ytotal) ;
    ligneUn2[1].color = c ; 
    sf::VertexArray ligneDeux (sf::Lines,2) ; 
    ligneDeux[0] = sf::Vector2f (x0+espace,y0);
    ligneDeux[0].color = c ; 
    ligneDeux[1] = sf::Vector2f (xtotal+espace,ytotal) ;
    ligneDeux[1].color = c ;
    sf::VertexArray ligneDeux2 (sf::Lines,2) ; 
    ligneDeux2[0] = sf::Vector2f (x0+espace+1,y0);
    ligneDeux2[0].color = c ; 
    ligneDeux2[1] = sf::Vector2f (xtotal+espace+1,ytotal) ;
    ligneDeux2[1].color = c ;
    (*fen).draw(ligneUn) ;
    (*fen).draw(ligneDeux) ;
    (*fen).draw(ligneUn2) ;
    (*fen).draw(ligneDeux2) ; 

    if (lon <40 ) {
      int xmillieu = (xtotal+ x0)/2 ;
      int ymillieu = (ytotal+y0)/2 ;
      sf::VertexArray ligneTrois (sf::Lines,2 );
      ligneTrois[0] = sf::Vector2f(xmillieu-espace,ymillieu) ;
      ligneTrois[0].color = c ; 
      ligneTrois[1] = sf::Vector2f(xmillieu+espace,ymillieu) ; 
      ligneTrois[1].color = c ; 
      (*fen).draw(ligneTrois) ;  
      sf::VertexArray ligneTrois2 (sf::Lines,2 );
      ligneTrois2[0] = sf::Vector2f(xmillieu-espace+1,ymillieu) ;
      ligneTrois2[0].color = c ; 
      ligneTrois2[1] = sf::Vector2f(xmillieu+espace+1,ymillieu) ; 
      ligneTrois2[1].color = c ; 
      (*fen).draw(ligneTrois2) ; 
    }
    else {
      for (int i= y0+30 ; i <ytotal-10; i = i+30 ){
	int y = a*i + b ;
	sf::VertexArray ligne (sf::Lines,2 );
	ligne[0] = sf::Vector2f(y-espace,i) ;
	ligne[0].color = c ; 
	ligne[1] = sf::Vector2f (y+espace,i) ; 
	ligne[1].color = c ;
	sf::VertexArray ligne2 (sf::Lines,2 );
	ligne2[0] = sf::Vector2f(y-espace+1,i) ;
	ligne2[0].color = c ; 
	ligne2[1] = sf::Vector2f (y+espace+1,i) ; 
	ligne2[1].color = c ;
	(*fen).draw(ligne) ;
	(*fen).draw(ligne2) ;
	}
    }
  }
}

void Dessin :: FaireSerpent (sf::RenderWindow *fen , int xdeb , int ydeb , int xfin , int yfin , sf::Color c ,sf::Color c2)  {
  double x0 , xtotal,y0,ytotal ;
  int nombredeX  = xdeb -xfin; 
  bool absysse=true ;
  if((nombredeX < 190)&&(nombredeX>-190)){
    // cout << nombredeX <<endl ; 
    absysse=false ;
  } 
  if(absysse) {
    if (xdeb < xfin ){ 
      x0 = xdeb ; 
      xtotal = xfin ; 
      y0 = ydeb ;
      ytotal = yfin ; 
    }
    else {
      x0 = xfin ; 
      xtotal =xdeb ;
      y0 = yfin;
      ytotal = ydeb ; 
    }
  }
  else {
    if (ydeb < yfin ){ 
      x0 = ydeb ; 
      xtotal = yfin ; 
      y0 = xdeb ;
      ytotal = xfin ; 
    }
    else {
      x0 = yfin ; 
      xtotal =ydeb ;
      y0 = xfin;
      ytotal = xdeb ; 
    }
  }
  double a  = (ytotal - y0)/(xtotal - x0) ;
  double b = ytotal - (a * xtotal ) ; 
  int nbrPoints  =( xtotal - x0)*10 +11;  
  sf::VertexArray tab(sf::LinesStrip,nbrPoints)  ;
  sf::VertexArray tab2(sf::LinesStrip,nbrPoints) ; 
  /* sf::VertexArray tab3(sf::LinesStrip,nbrPoints) ; 
  sf::VertexArray tab4(sf::LinesStrip,nbrPoints) ; 
  sf::VertexArray tab5(sf::LinesStrip,nbrPoints) ; */
  if(absysse) {
  tab[0] = sf::Vector2f(x0,y0);
  tab[0].color = c ;
  tab2[0] = sf::Vector2f(x0,y0-1) ; 
  tab2[0].color = c;
  /*tab3[0] = sf::Vector2f(x0,y0-2) ;
  tab3[0].color = c ; 
  tab4[0] = sf::Vector2f(x0,y0+1) ; 
  tab4[0].color = c ;
  tab5[0] = sf::Vector2f(x0,y0+2) ; 
  tab5[0].color = c ;*/
  }
  else {
    tab[0] = sf::Vector2f(y0,x0);
    tab[0].color = c ;
    tab2[0] = sf::Vector2f(y0,x0-1) ; 
    tab2[0].color = c;
    /*tab3[0] = sf::Vector2f(y0,x0-2) ;
    tab3[0].color = c ; 
    tab4[0] = sf::Vector2f(y0,x0+1) ; 
    tab4[0].color = c ;
    tab5[0] = sf::Vector2f(y0,x0+2) ; 
    tab5[0].color = c ;*/
  }
  int count = 0 ; 
  int ychange ;
  for (int i = x0 ; i <= xtotal ; i++) {
    for(int j = 0 ; j < 10 ; j ++) {
      count++ ; 
      ychange= sin((i+0.01*j)/10) *30;
      int x , y ;
      if(absysse) {
	x = i ;
	y = a*i+b+ychange ;
      }
      else {
	x = a*i+b+ychange ;
	y = i  ;
      }
      tab[count] = sf::Vector2f(x,y) ;
      tab[count].color = c ;
      tab2[count] = sf::Vector2f(x,y-1) ;
      tab2[count].color = c2 ;
      /*tab3[count] = sf::Vector2f(x,y-2) ;
      tab3[count].color = c ;
      tab4[count] = sf::Vector2f(x,y+1) ;
      tab4[count].color = c2 ;
      tab5[count] = sf::Vector2f(x,y+2) ;
      tab5[count].color = c ;*/
    }
  }
  int x , y ; 
  if(absysse) {
    x = xtotal ;
    y = a*xtotal+b+ychange ;
  }
  else {
    y = x0 ;
    x = y0;
  }
  sf::Vector2f v =  sf::Vector2f(x,y) ;
  sf::VertexArray tete (sf::Triangles , 3) ;
  tete[0] = sf::Vector2f(v.x-6, v.y-6);
  tete[1] = sf::Vector2f (v.x+6 , v.y-6);
  tete[2] =sf::Vector2f(v.x+6 , v.y+6) ;
  tete[0].color = c ;
  tete[1].color = c ;
  tete[2].color = c2 ;
  (*fen).draw(tab);
  (*fen).draw(tab2);
  /*(*fen).draw(tab3);
  (*fen).draw(tab4);
  (*fen).draw(tab5);*/
  (*fen).draw(tete) ; 
}

void Dessin :: FaireDessin (sf::RenderWindow * fen , int x , int y , int choix,sf::Color c ) {
  
  if (choix ==  0) {
    sf::CircleShape symbole(20);
    symbole.setFillColor(c) ;
    symbole.setPosition(x,y) ;
    (*fen).draw(symbole);
  }
  else if (choix == 1 ) {
    sf::CircleShape symbole(20,3);
    symbole.setFillColor(c) ;
    symbole.setPosition(x,y) ;
    (*fen).draw(symbole);
  }
  else if (choix == 2 ) {
    sf::CircleShape symbole(20,4);
    symbole.setFillColor(c) ;
    symbole.setPosition(x,y) ;
    (*fen).draw(symbole);
  }
  else if (choix == 3 ) {
    sf::CircleShape symbole(20,8);
    symbole.setFillColor(c) ;
    symbole.setPosition(x,y) ;
    (*fen).draw(symbole);
  }
  else {
    cout << "erreur " << endl ;
    
  }
  
}
