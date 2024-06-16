#include <iostream>
#include <fstream>
#include <iomanip>
#include "Domaine1D.h"
#include "Piece.h"
#include "EquationChaleur1D.h"

using namespace std;
// ========================= FONCTION MAIN =========================== // 
int main()
{
    ofstream fichier("EDP_1D.txt"); // ouverture du ficher texte dans lequel les résultats seront envoyés

    // ------- Définition des constantes pour les différents matériaux ------- //
    // pour l'air
    double C_air = 1005;    // J.K⁻¹.kg⁻¹ capcaité thermique massique
    double K_air = 0.0234;  // W.m⁻¹.K⁻¹  conduction thermique
    double rho_air = 1.204; // kg/m³ (à 20°C) densité massique
    // pour le fer
    double C_fer = 444;    // J.K⁻¹.kg⁻¹
    double K_fer = 80;     // W.m⁻¹.K⁻¹
    double rho_fer = 7860; // kg/m³ (à 20°C)
    // pour l'argent
    double C_argent = 236;     // J.K⁻¹.kg⁻¹
    double K_argent = 418;     // W.m⁻¹.K⁻¹
    double rho_argent = 10500; // kg/m³ (à 20°C)
    // pour le bois de pin
    double C_bois_pin = 1500;  // J.K⁻¹.kg⁻¹
    double K_bois_pin = 0.15;  // W.m⁻¹.K⁻¹
    double rho_bois_pin = 500; // kg/m³ (à 20°C)
    // ---------------------------------------------------------------------- //

    double x_min = 0; // en metres
    double x_max = 1;
    double dx = 0.01;
    int N_x = (x_max - x_min) / dx; // nombre de carreaux de discrétisation selon Ox
    double x;

    double T_init = 20; // en °C
    double T_bords = 0.0;

    double t_final = 4000; // en secondes
    double dt = 2;
    int N_t = t_final / dt;
    double t;

    Domaine1D domaine(x_min, x_max, N_x, dx);                 // création du domaine
    EquationChaleur1D EDP(T_init, T_bords, N_t, dt);          // création de l'EDP
    Mur mur1(K_bois_pin, rho_bois_pin, C_bois_pin, 0.2, 0.3); // creation d'un mur

    // création des tableaux
    double *C = new double[domaine.get_Nx()];
    double *K = new double[domaine.get_Nx()];
    double *rho = new double[domaine.get_Nx()];
    Mur *murs = new Mur[(int)mur1.get_nb_murs()];
    double **Temperature = new double *[N_t + 1];

    murs[0] = mur1;

    Piece piece(C, K, rho, murs, domaine);
    piece.Amenagement(C_air, K_air, rho_air, domaine);

    EDP.resoudre(Temperature, domaine, piece, K_air, C_air, rho_air); // resolution de l'EDP

    // affichage des resultats dans le fichier texte
    for (int n = 0; n <= N_t; n++)
    {
        for (int i = 0; i <= N_x; i++)
        {
            x = x_min + i * dx;
            t = n * dt;

            fichier << t << "  " << x << "  " << Temperature[n][i] << endl;
        }
        fichier << endl;
    }

    system("gnuplot EDP_1D.gnu"); // execute gnuplot -> creer resultat1D.png

    // delete les tableaux
    for (int n = 0; n <= N_t; n++)
    {
        delete[] Temperature[n];
    }
    delete[] Temperature;
    fichier.close();

    return 0;
}