#ifndef Mur_h
#define Mur_h

#include <iostream>

using namespace std;

// ========================= CLASSE MUR ===============================================
class Mur
{
private:
    double K_mur, rho_mur, C_mur;
    double xmin, xmax;
    static int nb_murs;

public:
    Mur(double, double, double, double, double);
    Mur();
    Mur(Mur &); // constructeur de copie
    ~Mur();     // destructeur

    double get_C() { return C_mur; };
    double get_rho() { return rho_mur; };
    double get_K() { return K_mur; };

    double get_xmin() { return xmin; };
    double get_xmax() { return xmax; };

    double get_nb_murs() { return nb_murs; };
};
#endif