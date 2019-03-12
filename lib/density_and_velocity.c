/*
 * density_and_velocity.c
 *
 *  Created on: 19 mei 2017
 *      Author: dharrison
 */


#include "../inc/parameters.h"


void calculating_rho()
{
    int i, j;

    double sum;

    for(i = 0; i < Nx; ++i)
        for(j = 0; j < Ny; ++j)
        {
            if(solid_flags[i][j] == 0)
            {
                sum = 0.0;

                sum += fk[i][j][0];
                sum += fprop[i][j][1];
                sum += fprop[i][j][2];
                sum += fprop[i][j][3];
                sum += fprop[i][j][4];
                sum += fprop[i][j][5];
                sum += fprop[i][j][6];
                sum += fprop[i][j][7];
                sum += fprop[i][j][8];

                rho[i][j] = sum;
                rho_rec[i][j] = 1.0 / sum;
            }
        }

}


void calculating_Ux()
{
    int i, j;

    double sum;

    for(i = 0; i < Nx; ++i)
        for(j = 0; j < Ny; ++j)
        {
            if(solid_flags[i][j] == 0)
            {
                sum = 0.0;

                sum += fk[i][j][0] * ck[0][0];
                sum += fprop[i][j][1] * ck[1][0];
                sum += fprop[i][j][2] * ck[2][0];
                sum += fprop[i][j][3] * ck[3][0];
                sum += fprop[i][j][4] * ck[4][0];
                sum += fprop[i][j][5] * ck[5][0];
                sum += fprop[i][j][6] * ck[6][0];
                sum += fprop[i][j][7] * ck[7][0];
                sum += fprop[i][j][8] * ck[8][0];

                Ux[i][j] = (sum + 0.5 * F) * rho_rec[i][j];
            }
        }

}


void calculating_Uy()
{
    int i, j;

    double sum;

    for(i = 0; i < Nx; ++i)
        for(j = 0; j < Ny; ++j)
        {
            if(solid_flags[i][j] == 0)
            {
                sum = 0.0;

                sum += fk[i][j][0] * ck[0][1];
                sum += fprop[i][j][1] * ck[1][1];
                sum += fprop[i][j][2] * ck[2][1];
                sum += fprop[i][j][3] * ck[3][1];
                sum += fprop[i][j][4] * ck[4][1];
                sum += fprop[i][j][5] * ck[5][1];
                sum += fprop[i][j][6] * ck[6][1];
                sum += fprop[i][j][7] * ck[7][1];
                sum += fprop[i][j][8] * ck[8][1];

                Uy[i][j] = sum * rho_rec[i][j];
            }
        }

}


void vorticity()
{
    int i, j;

    for(i = 1; i < Nx - 1; ++i)
        for(j = 1; j < Ny - 1; ++j)
        {
            if(solid_flags[i][j] == 0)
            {
                vort_field[i][j] = 0.5 * (Uy[i+1][j] - Uy[i-1][j] - Ux[i][j+1] + Ux[i][j-1]) * dx_rec;
            }
        }

}
