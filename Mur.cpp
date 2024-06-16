#include <iostream>
#include "Mur.h"

using namespace std;

// ========================= METHODES DE LA CLASSE MUR ===============================================
int Mur::nb_murs = 0;

Mur::Mur(Mur &m)
{
    K_mur = m.K_mur;
    rho_mur = m.rho_mur;
    C_mur = m.C_mur;
    xmin = m.xmin;
    xmax = m.xmax;
    nb_murs++;
}
Mur::Mur(double K, double rho, double C, double x_min, double x_max)
{
    K_mur = K;
    rho_mur = rho;
    C_mur = C;
    xmin = x_min;
    xmax = x_max;
    nb_murs++;
}
Mur::Mur()
{
    K_mur = 0;
    rho_mur = 0;
    C_mur = 0;
    xmin = 0;
    xmax = 0;
}
Mur::~Mur()
{
    nb_murs--;
}