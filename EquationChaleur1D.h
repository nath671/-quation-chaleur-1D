#ifndef EquationChaleur1D_h
#define EquationChaleur1D_h
#include <iostream>
#include "Domaine1D.h"
#include "Piece.h"

using namespace std;

// ========================= CLASSE EQUATION DE LA CHALEUR 1D =======================================
class EquationChaleur1D
{
private:
    double T_init, T_bords;
    int N_t;   // Nt = t_final / dt""""
    double dt; // pas de temps

public:
    // constructeurs
    EquationChaleur1D(double, double, double, double);
    EquationChaleur1D();

    // autres méthodes
    double **resoudre(double **, Domaine1D, Piece, double, double, double);
};
#endif