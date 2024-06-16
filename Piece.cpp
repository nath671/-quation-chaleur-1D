#include <iostream>
#include "Piece.h"

using namespace std;

// ========================= METHODE DE CLASSE PIECE =======================================

Piece::Piece(double *C, double *K, double *rho, Mur *mur, Domaine1D domaine)
{
    tab_C = C;
    tab_K = K;
    tab_rho = rho;
    murs = mur;
    d = domaine;
}
Piece::Piece()
{
    tab_C = 0;
    tab_K = 0;
    tab_rho = 0;
    murs = 0;
}

// l'aménagement de la piece se fait via la définition des constantes K, rho, C pour chaque
// carrés de discrétisation de la piece
double *Piece::Amenagement(double C_air, double K_air, double rho_air, Domaine1D d)
{
    double x;
    bool mur_present = false;

    for (int i = 0; i <= d.get_Nx(); i++)
    {
        x = d.get_xmin() + i * d.get_dx();

        for (int k = 0; k < murs->get_nb_murs(); k++)
        {

            // est ce que on est dans un des k murs ?
            if (x >= murs[k].get_xmin() and x <= murs[k].get_xmax())
            {
                tab_C[i] = murs[k].get_C();
                tab_K[i] = murs[k].get_K();
                tab_rho[i] = murs[k].get_rho();

                mur_present = true;

                break;
            }
            else
            {

                mur_present = false;
            }
        }
        if (mur_present == false)
        {
            tab_C[i] = C_air;
            tab_K[i] = K_air;
            tab_rho[i] = rho_air;
        }
    }

    return tab_C, tab_K, tab_rho;
}