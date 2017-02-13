
all: main clean

main:Case.o Plateau.o Joueur.o Jeu.o Dessin.o Serpent.o Carte.o Numeri.o main.o	
	 g++ Case.o Plateau.o Joueur.o Jeu.o Dessin.o Serpent.o Carte.o Numeri.o main.o -o main -lsfml-graphics -lsfml-window -lsfml-system 

Case.o : Case.hpp
	g++ -std=c++11 -c Case.cpp
Plateau.o: Case.hpp Plateau.hpp
	g++ -std=c++11 -c Plateau.cpp 
Joueur.o: Joueur.hpp
	g++ -std=c++11 -c Joueur.cpp 
Jeu.o:Jeu.hpp Joueur.hpp Plateau.hpp 
	 g++ -std=c++11 -c Jeu.cpp 
Dessin.o:Dessin.hpp
	g++ -std=c++11 -c Dessin.cpp 
Serpent.o: Dessin.hpp Jeu.hpp Joueur.hpp Serpent.hpp 
	g++ -std=c++11 -c Serpent.cpp 

Carte.o:Carte.hpp Jeu.hpp Joueur.cpp Dessin.hpp
	g++ -std=c++11 -c Carte.cpp 

Numeri.o:Numeri.hpp Jeu.hpp Joueur.cpp
	g++ -std=c++11 -c Numeri.cpp

main.o: Plateau.hpp Joueur.hpp Jeu.cpp Serpent.cpp Carte.hpp Numeri.hpp
	g++ -std=c++11 -c main.cpp 


clean:
	rm -rf *.o
