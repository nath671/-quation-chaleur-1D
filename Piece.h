#ifndef Piece_h
#define Piece_h
#include <iostream>
#include "Mur.h"
#include "Domaine1D.h"

using namespace std;

// ========================= CLASSE PIECE =======================================
class Piece
{
private:
    double *tab_K;
    double *tab_rho;
    double *tab_C;
    Mur *murs;
    Domaine1D d;

public:
    Piece(double *, double *, double *, Mur *, Domaine1D);
    Piece();

    double *get_tab_C() { return tab_C; };
    double *get_tab_K() { return tab_K; };
    double *get_tab_rho() { return tab_rho; };

    double *Amenagement(double, double, double, Domaine1D);
};
#endif