/*
 * Mass_conservation_and_momentum.c
 *
 *  Created on: 19 mei 2017
 *      Author: dharrison
 */


#include <stdlib.h>
#include "../inc/parameters.h"


void mass_momentum_conservation()
{
    int i, j;

    for(i = 0; i < Nx; ++i)
        for(j = 0; j < Ny; ++j)
        {
            mass_cons_check[i][j] = 0.0;
            momentumx_cons[i][j] = 1.0;
            momentumy_cons[i][j] = 1.0;

            mass_cons_check[i][j] += fk[i][j][0] - feq[i][j][0];
            mass_cons_check[i][j] += fk[i][j][1] - feq[i][j][1];
            mass_cons_check[i][j] += fk[i][j][2] - feq[i][j][2];
            mass_cons_check[i][j] += fk[i][j][3] - feq[i][j][3];
            mass_cons_check[i][j] += fk[i][j][4] - feq[i][j][4];
            mass_cons_check[i][j] += fk[i][j][5] - feq[i][j][5];
            mass_cons_check[i][j] += fk[i][j][6] - feq[i][j][6];
            mass_cons_check[i][j] += fk[i][j][7] - feq[i][j][7];
            mass_cons_check[i][j] += fk[i][j][8] - feq[i][j][8];

            momentumx_cons[i][j] += (fk[i][j][0] - feq[i][j][0]) * ck[0][0];
            momentumx_cons[i][j] += (fk[i][j][1] - feq[i][j][1]) * ck[1][0];
            momentumx_cons[i][j] += (fk[i][j][2] - feq[i][j][2]) * ck[2][0];
            momentumx_cons[i][j] += (fk[i][j][3] - feq[i][j][3]) * ck[3][0];
            momentumx_cons[i][j] += (fk[i][j][4] - feq[i][j][4]) * ck[4][0];
            momentumx_cons[i][j] += (fk[i][j][5] - feq[i][j][5]) * ck[5][0];
            momentumx_cons[i][j] += (fk[i][j][6] - feq[i][j][6]) * ck[6][0];
            momentumx_cons[i][j] += (fk[i][j][7] - feq[i][j][7]) * ck[7][0];
            momentumx_cons[i][j] += (fk[i][j][8] - feq[i][j][8]) * ck[8][0];

            momentumy_cons[i][j] += (fk[i][j][0] - feq[i][j][0]) * ck[0][1];
            momentumy_cons[i][j] += (fk[i][j][1] - feq[i][j][1]) * ck[1][1];
            momentumy_cons[i][j] += (fk[i][j][2] - feq[i][j][2]) * ck[2][1];
            momentumy_cons[i][j] += (fk[i][j][3] - feq[i][j][3]) * ck[3][1];
            momentumy_cons[i][j] += (fk[i][j][4] - feq[i][j][4]) * ck[4][1];
            momentumy_cons[i][j] += (fk[i][j][5] - feq[i][j][5]) * ck[5][1];
            momentumy_cons[i][j] += (fk[i][j][6] - feq[i][j][6]) * ck[6][1];
            momentumy_cons[i][j] += (fk[i][j][7] - feq[i][j][7]) * ck[7][1];
            momentumy_cons[i][j] += (fk[i][j][8] - feq[i][j][8]) * ck[8][1];
        }

}


void set_stability_flags()
{
    int i, j, k;

    double non_neg_check;

    for(i = 0; i < Nx; ++i)
        for(j = 0; j < Ny; ++j)
        {
            for(k = 0; k < 9; ++k)
            {
                non_neg_check = feq[i][j][k];
                if(non_neg_check < 0)
                    feqfl[i][j] = 1.0;
            }
        }

}


void stability_probe()
{
    int k;

    double non_neg_check;

    for(k = 0; k < 9; ++k)
    {
        non_neg_check = feq[Nx/4][Ny/4][k];
        if(non_neg_check < 0)
        {
            feqfl[Nx/4][Ny/4] = 1.0;
            exit(3);
        }

        non_neg_check = feq[Nx/2][Ny/4][k];
        if(non_neg_check < 0)
        {
            feqfl[Nx/4][Ny/4] = 1.0;
            exit(3);
        }

        non_neg_check = feq[3*Nx/4][Ny/4][k];
        if(non_neg_check < 0)
        {
            feqfl[Nx/4][Ny/4] = 1.0;
            exit(3);
        }

        non_neg_check = feq[Nx/2][Ny/2][k];
        if(non_neg_check < 0)
        {
            feqfl[Nx/4][Ny/4] = 1.0;
            exit(3);
        }

        non_neg_check = feq[Nx/4][3*Ny/4][k];
        if(non_neg_check < 0)
        {
            feqfl[Nx/4][Ny/4] = 1.0;
            exit(3);
        }

        non_neg_check = feq[3*Nx/4][3*Ny/4][k];
        if(non_neg_check < 0)
        {
            feqfl[Nx/4][Ny/4] = 1.0;
            exit(3);
        }
    }

}
