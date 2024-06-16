#include <iostream>
#include "Domaine1D.h"

using namespace std;

// ========================= METHODES DE LA CLASSE DOMAINE 1D ===============================================
Domaine1D::Domaine1D(double a, double b, double c, double d)
{
    x_min = a;
    x_max = b;
    N_x = c;
    dx = d;
}
Domaine1D::Domaine1D()
{
    x_min = 0;
    x_max = 0;
    N_x = 0;
    dx = 0;
}