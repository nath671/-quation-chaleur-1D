
EDP_1D.txt: main.exe
				./main.exe

main.exe: main.cpp EquationChaleur1D.o Piece.o Mur.o Domaine1D.o Domaine1D.h EquationChaleur1D.h Piece.h
				g++ EquationChaleur1D.o Piece.o Mur.o Domaine1D.o main.cpp -o main.exe

EquationChaleur1D.o: EquationChaleur1D.cpp EquationChaleur1D.h Domaine1D.h Piece.h
				g++ -c EquationChaleur1D.cpp

Piece.o: Piece.cpp Piece.h Domaine1D.h Mur.h
				g++ -c Piece.cpp

Mur.o: Mur.h Mur.cpp
				g++ -c Mur.cpp

Domaine1D.o: Domaine1D.h Domaine1D.cpp
				g++ -c Domaine1D.cpp