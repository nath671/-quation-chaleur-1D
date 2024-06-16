#include <iostream>
#include "EquationChaleur1D.h"

using namespace std;

// ========================= METHODES DE LA CLASSE EQUATION DE LA CHALEUR 1D =======================================

EquationChaleur1D::EquationChaleur1D(double a, double b, double d, double e)
{
    T_init = a;
    T_bords = b;
    N_t = d;
    dt = e;
}
EquationChaleur1D::EquationChaleur1D()
{
    T_init = 0;
    T_bords = 0;
    N_t = 0;
    dt = 0;
}

double **EquationChaleur1D::resoudre(double **Temperature, Domaine1D d, Piece p,
                                     double K, double C, double rho)
{
    // n est l'indice correspondant au temps
    // j est l'indice correspondant à y
    // i est l'indice correspondant à x

    // création du tableau
    for (int n = 0; n <= N_t; n++)
    {
        Temperature[n] = new double[d.get_Nx()];
    }

    // Température initiale dans la piece (à t = 0) (i.e à n = 0)
    for (int i = 1; i < d.get_Nx(); i++) // remplissage du tableau "temps initial" avec les valeurs de la température initiale
    {
        Temperature[0][i] = T_init;
    }

    // conditions aux bords
    for (int n = 0; n <= N_t; n++) // remplissage du tableau pour tout temps seulement avec les températures aux bords
    {                              // Ces valeurs ne seront pas modifiées par la suite
        Temperature[n][0] = T_bords;
        Temperature[n][d.get_Nx()] = T_bords;
    }

    // remplissage du reste des tableaux
    for (int n = 1; n <= N_t; n++)
    {
        for (int i = 1; i < d.get_Nx(); i++)
        {
            Temperature[n][i] = Temperature[n - 1][i] +
                                p.get_tab_K()[i] * dt * (Temperature[n - 1][i + 1] - 2 * Temperature[n - 1][i] + Temperature[n - 1][i - 1]) /
                                    (d.get_dx() * d.get_dx() * p.get_tab_rho()[i] * p.get_tab_C()[i]);
        }
    }
    return Temperature;
}