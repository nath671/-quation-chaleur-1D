#ifndef Domaine1D_h
#define Domaine1D_h
#include <iostream>

using namespace std;

// ========================= CLASSE DOMAINE 1D ===============================================
class Domaine1D
{
private:
    double x_min, x_max;
    int N_x;   // nombre total de carreaux qui discrétisent le domaine
    double dx; // pas ou taille d'un petit carreau [ dx = (x_max - x_min) / N_x ]

public:
    // constructeurs
    Domaine1D(double, double, double, double);
    Domaine1D();

    // geteurs et seteurs
    int get_Nx() { return N_x; };
    double get_xmin() { return x_min; };
    double get_xmax() { return x_max; };
    double get_dx() { return dx; };
};
#endif