/*
 * collision_operators.c
 *
 *  Created on: 21 jun. 2017
 *      Author: dharrison
 */

#include "parameters.h"


void MRT_operator()
{
	int i, j;

	for(i = 0; i < Nx; ++i)
		for(j = 0; j < Ny; ++j)
		{
			if(solid_flags[i][j] == 0)
			{
				/*mapping from population to momentum space*/
				moment_vec[0]    = M[0][0] * fk[i][j][0]    + M[0][1] * fprop[i][j][1] + M[0][2] * fprop[i][j][2] +
								   M[0][3] * fprop[i][j][3] + M[0][4] * fprop[i][j][4] + M[0][5] * fprop[i][j][5] +
								   M[0][6] * fprop[i][j][6] + M[0][7] * fprop[i][j][7] + M[0][8] * fprop[i][j][8];

				moment_vec[1]    = M[1][0] * fk[i][j][0]    + M[1][1] * fprop[i][j][1] + M[1][2] * fprop[i][j][2] +
								   M[1][3] * fprop[i][j][3] + M[1][4] * fprop[i][j][4] + M[1][5] * fprop[i][j][5] +
								   M[1][6] * fprop[i][j][6] + M[1][7] * fprop[i][j][7] + M[1][8] * fprop[i][j][8];

				moment_vec[2]    = M[2][0] * fk[i][j][0]    + M[2][1] * fprop[i][j][1] + M[2][2] * fprop[i][j][2] +
								   M[2][3] * fprop[i][j][3] + M[2][4] * fprop[i][j][4] + M[2][5] * fprop[i][j][5] +
								   M[2][6] * fprop[i][j][6] + M[2][7] * fprop[i][j][7] + M[2][8] * fprop[i][j][8];

				moment_vec[3]    = M[3][0] * fk[i][j][0]    + M[3][1] * fprop[i][j][1] + M[3][2] * fprop[i][j][2] +
								   M[3][3] * fprop[i][j][3] + M[3][4] * fprop[i][j][4] + M[3][5] * fprop[i][j][5] +
								   M[3][6] * fprop[i][j][6] + M[3][7] * fprop[i][j][7] + M[3][8] * fprop[i][j][8];

				moment_vec[4]    = M[4][0] * fk[i][j][0]    + M[4][1] * fprop[i][j][1] + M[4][2] * fprop[i][j][2] +
								   M[4][3] * fprop[i][j][3] + M[4][4] * fprop[i][j][4] + M[4][5] * fprop[i][j][5] +
								   M[4][6] * fprop[i][j][6] + M[4][7] * fprop[i][j][7] + M[4][8] * fprop[i][j][8];

				moment_vec[5]    = M[5][0] * fk[i][j][0]    + M[5][1] * fprop[i][j][1] + M[5][2] * fprop[i][j][2] +
								   M[5][3] * fprop[i][j][3] + M[5][4] * fprop[i][j][4] + M[5][5] * fprop[i][j][5] +
								   M[5][6] * fprop[i][j][6] + M[5][7] * fprop[i][j][7] + M[5][8] * fprop[i][j][8];

				moment_vec[6]    = M[6][0] * fk[i][j][0]    + M[6][1] * fprop[i][j][1] + M[6][2] * fprop[i][j][2] +
								   M[6][3] * fprop[i][j][3] + M[6][4] * fprop[i][j][4] + M[6][5] * fprop[i][j][5] +
								   M[6][6] * fprop[i][j][6] + M[6][7] * fprop[i][j][7] + M[6][8] * fprop[i][j][8];

				moment_vec[7]    = M[7][0] * fk[i][j][0]    + M[7][1] * fprop[i][j][1] + M[7][2] * fprop[i][j][2] +
								   M[7][3] * fprop[i][j][3] + M[7][4] * fprop[i][j][4] + M[7][5] * fprop[i][j][5] +
								   M[7][6] * fprop[i][j][6] + M[7][7] * fprop[i][j][7] + M[7][8] * fprop[i][j][8];

				moment_vec[8]    = M[8][0] * fk[i][j][0]    + M[8][1] * fprop[i][j][1] + M[8][2] * fprop[i][j][2] +
								   M[8][3] * fprop[i][j][3] + M[8][4] * fprop[i][j][4] + M[8][5] * fprop[i][j][5] +
								   M[8][6] * fprop[i][j][6] + M[8][7] * fprop[i][j][7] + M[8][8] * fprop[i][j][8];


				/*mapping from equilibrium population to equilibrium momentum space*/
				moment_vec_eq[0] = M[0][0] * feq[i][j][0] + M[0][1] * feq[i][j][1] + M[0][2] * feq[i][j][2] +
								   M[0][3] * feq[i][j][3] + M[0][4] * feq[i][j][4] + M[0][5] * feq[i][j][5] +
								   M[0][6] * feq[i][j][6] + M[0][7] * feq[i][j][7] + M[0][8] * feq[i][j][8];

				moment_vec_eq[1] = M[1][0] * feq[i][j][0] + M[1][1] * feq[i][j][1] + M[1][2] * feq[i][j][2] +
								   M[1][3] * feq[i][j][3] + M[1][4] * feq[i][j][4] + M[1][5] * feq[i][j][5] +
								   M[1][6] * feq[i][j][6] + M[1][7] * feq[i][j][7] + M[1][8] * feq[i][j][8];

				moment_vec_eq[2] = M[2][0] * feq[i][j][0] + M[2][1] * feq[i][j][1] + M[2][2] * feq[i][j][2] +
								   M[2][3] * feq[i][j][3] + M[2][4] * feq[i][j][4] + M[2][5] * feq[i][j][5] +
								   M[2][6] * feq[i][j][6] + M[2][7] * feq[i][j][7] + M[2][8] * feq[i][j][8];

				moment_vec_eq[3] = M[3][0] * feq[i][j][0] + M[3][1] * feq[i][j][1] + M[3][2] * feq[i][j][2] +
								   M[3][3] * feq[i][j][3] + M[3][4] * feq[i][j][4] + M[3][5] * feq[i][j][5] +
								   M[3][6] * feq[i][j][6] + M[3][7] * feq[i][j][7] + M[3][8] * feq[i][j][8];

				moment_vec_eq[4] = M[4][0] * feq[i][j][0] + M[4][1] * feq[i][j][1] + M[4][2] * feq[i][j][2] +
								   M[4][3] * feq[i][j][3] + M[4][4] * feq[i][j][4] + M[4][5] * feq[i][j][5] +
								   M[4][6] * feq[i][j][6] + M[4][7] * feq[i][j][7] + M[4][8] * feq[i][j][8];

				moment_vec_eq[5] = M[5][0] * feq[i][j][0] + M[5][1] * feq[i][j][1] + M[5][2] * feq[i][j][2] +
								   M[5][3] * feq[i][j][3] + M[5][4] * feq[i][j][4] + M[5][5] * feq[i][j][5] +
								   M[5][6] * feq[i][j][6] + M[5][7] * feq[i][j][7] + M[5][8] * feq[i][j][8];

				moment_vec_eq[6] = M[6][0] * feq[i][j][0] + M[6][1] * feq[i][j][1] + M[6][2] * feq[i][j][2] +
								   M[6][3] * feq[i][j][3] + M[6][4] * feq[i][j][4] + M[6][5] * feq[i][j][5] +
								   M[6][6] * feq[i][j][6] + M[6][7] * feq[i][j][7] + M[6][8] * feq[i][j][8];

				moment_vec_eq[7] = M[7][0] * feq[i][j][0] + M[7][1] * feq[i][j][1] + M[7][2] * feq[i][j][2] +
								   M[7][3] * feq[i][j][3] + M[7][4] * feq[i][j][4] + M[7][5] * feq[i][j][5] +
								   M[7][6] * feq[i][j][6] + M[7][7] * feq[i][j][7] + M[7][8] * feq[i][j][8];

				moment_vec_eq[8] = M[8][0] * feq[i][j][0] + M[8][1] * feq[i][j][1] + M[8][2] * feq[i][j][2] +
								   M[8][3] * feq[i][j][3] + M[8][4] * feq[i][j][4] + M[8][5] * feq[i][j][5] +
								   M[8][6] * feq[i][j][6] + M[8][7] * feq[i][j][7] + M[8][8] * feq[i][j][8];


				/*Colliding vector in moment space*/
				moment_vec_col[0] = moment_vec[0] - (moment_vec[0] - moment_vec_eq[0]) * omega_vec[0] * dt;
				moment_vec_col[1] = moment_vec[1] - (moment_vec[1] - moment_vec_eq[1]) * omega_vec[1] * dt;
				moment_vec_col[2] = moment_vec[2] - (moment_vec[2] - moment_vec_eq[2]) * omega_vec[2] * dt;
				moment_vec_col[3] = moment_vec[3] - (moment_vec[3] - moment_vec_eq[3]) * omega_vec[3] * dt;
				moment_vec_col[4] = moment_vec[4] - (moment_vec[4] - moment_vec_eq[4]) * omega_vec[4] * dt;
				moment_vec_col[5] = moment_vec[5] - (moment_vec[5] - moment_vec_eq[5]) * omega_vec[5] * dt;
				moment_vec_col[6] = moment_vec[6] - (moment_vec[6] - moment_vec_eq[6]) * omega_vec[6] * dt;
				moment_vec_col[7] = moment_vec[7] - (moment_vec[7] - moment_vec_eq[7]) * omega_vec[7] * dt;
				moment_vec_col[8] = moment_vec[8] - (moment_vec[8] - moment_vec_eq[8]) * omega_vec[8] * dt;


				/*Calculating matrix multiplication of M_inv with momentum vector*/
				fk_vec[0] = M_inv[0][0] * moment_vec_col[0] + M_inv[0][1] * moment_vec_col[1] + M_inv[0][2] * moment_vec_col[2] +
							M_inv[0][3] * moment_vec_col[3] + M_inv[0][4] * moment_vec_col[4] +	M_inv[0][5] * moment_vec_col[5] +
							M_inv[0][6] * moment_vec_col[6] + M_inv[0][7] * moment_vec_col[7] +	M_inv[0][8] * moment_vec_col[8];

				fk_vec[1] = M_inv[1][0] * moment_vec_col[0] + M_inv[1][1] * moment_vec_col[1] +	M_inv[1][2] * moment_vec_col[2] +
							M_inv[1][3] * moment_vec_col[3] + M_inv[1][4] * moment_vec_col[4] +	M_inv[1][5] * moment_vec_col[5] +
							M_inv[1][6] * moment_vec_col[6] + M_inv[1][7] * moment_vec_col[7] +	M_inv[1][8] * moment_vec_col[8];

				fk_vec[2] = M_inv[2][0] * moment_vec_col[0] + M_inv[2][1] * moment_vec_col[1] +	M_inv[2][2] * moment_vec_col[2] +
							M_inv[2][3] * moment_vec_col[3] + M_inv[2][4] * moment_vec_col[4] +	M_inv[2][5] * moment_vec_col[5] +
							M_inv[2][6] * moment_vec_col[6] + M_inv[2][7] * moment_vec_col[7] +	M_inv[2][8] * moment_vec_col[8];

				fk_vec[3] = M_inv[3][0] * moment_vec_col[0] + M_inv[3][1] * moment_vec_col[1] +	M_inv[3][2] * moment_vec_col[2] +
							M_inv[3][3] * moment_vec_col[3] + M_inv[3][4] * moment_vec_col[4] +	M_inv[3][5] * moment_vec_col[5] +
							M_inv[3][6] * moment_vec_col[6] + M_inv[3][7] * moment_vec_col[7] +	M_inv[3][8] * moment_vec_col[8];

				fk_vec[4] = M_inv[4][0] * moment_vec_col[0] + M_inv[4][1] * moment_vec_col[1] +	M_inv[4][2] * moment_vec_col[2] +
							M_inv[4][3] * moment_vec_col[3] + M_inv[4][4] * moment_vec_col[4] +	M_inv[4][5] * moment_vec_col[5] +
							M_inv[4][6] * moment_vec_col[6] + M_inv[4][7] * moment_vec_col[7] +	M_inv[4][8] * moment_vec_col[8];

				fk_vec[5] = M_inv[5][0] * moment_vec_col[0] + M_inv[5][1] * moment_vec_col[1] +	M_inv[5][2] * moment_vec_col[2] +
							M_inv[5][3] * moment_vec_col[3] + M_inv[5][4] * moment_vec_col[4] +	M_inv[5][5] * moment_vec_col[5] +
							M_inv[5][6] * moment_vec_col[6] + M_inv[5][7] * moment_vec_col[7] +	M_inv[5][8] * moment_vec_col[8];

				fk_vec[6] = M_inv[6][0] * moment_vec_col[0] + M_inv[6][1] * moment_vec_col[1] +	M_inv[6][2] * moment_vec_col[2] +
							M_inv[6][3] * moment_vec_col[3] + M_inv[6][4] * moment_vec_col[4] +	M_inv[6][5] * moment_vec_col[5] +
							M_inv[6][6] * moment_vec_col[6] + M_inv[6][7] * moment_vec_col[7] +	M_inv[6][8] * moment_vec_col[8];

				fk_vec[7] = M_inv[7][0] * moment_vec_col[0] + M_inv[7][1] * moment_vec_col[1] +	M_inv[7][2] * moment_vec_col[2] +
							M_inv[7][3] * moment_vec_col[3] + M_inv[7][4] * moment_vec_col[4] +	M_inv[7][5] * moment_vec_col[5] +
							M_inv[7][6] * moment_vec_col[6] + M_inv[7][7] * moment_vec_col[7] +	M_inv[7][8] * moment_vec_col[8];

				fk_vec[8] = M_inv[8][0] * moment_vec_col[0] + M_inv[8][1] * moment_vec_col[1] +	M_inv[8][2] * moment_vec_col[2] +
							M_inv[8][3] * moment_vec_col[3] + M_inv[8][4] * moment_vec_col[4] +	M_inv[8][5] * moment_vec_col[5] +
							M_inv[8][6] * moment_vec_col[6] + M_inv[8][7] * moment_vec_col[7] +	M_inv[8][8] * moment_vec_col[8];


				/*Mapping from momentum to population space*/
				fk[i][j][0] = fk_vec[0];
				fk[i][j][1] = fk_vec[1];
				fk[i][j][2] = fk_vec[2];
				fk[i][j][3] = fk_vec[3];
				fk[i][j][4] = fk_vec[4];
				fk[i][j][5] = fk_vec[5];
				fk[i][j][6] = fk_vec[6];
				fk[i][j][7] = fk_vec[7];
				fk[i][j][8] = fk_vec[8];
			}
		}

}


void MRT_operator_stable()
{
	/*The calculations performed in this function have been verified, hence the reason it is stated to be stable.
	 *Note: the current implementation of the MRT collision operator, "MRT_operator", has also been verified.
	 *Also, this implementation is less efficient due to use of nested loops.*/

	int i, j, m, k;

	for(i = 0; i < Nx; ++i)
		for(j = 0; j < Ny; ++j)
		{
			if(solid_flags[i][j] == 0)
			{
				/*Mapping to moment space*/
				for(m = 0; m < 9; ++m)
				{
					moment_vec[m]    = M[m][0] * fk[i][j][0]    + M[m][1] * fprop[i][j][1] + M[m][2] * fprop[i][j][2] +
									   M[m][3] * fprop[i][j][3] + M[m][4] * fprop[i][j][4] + M[m][5] * fprop[i][j][5] +
									   M[m][6] * fprop[i][j][6] + M[m][7] * fprop[i][j][7] + M[m][8] * fprop[i][j][8];

					moment_vec_eq[m] = M[m][0] * feq[i][j][0] + M[m][1] * feq[i][j][1] + M[m][2] * feq[i][j][2] +
							           M[m][3] * feq[i][j][3] + M[m][4] * feq[i][j][4] + M[m][5] * feq[i][j][5] +
									   M[m][6] * feq[i][j][6] + M[m][7] * feq[i][j][7] + M[m][8] * feq[i][j][8];

					fk_vec[m]        = 0.0;
				}


				/*Mapping to population space*/
				for(m = 0; m < 9; ++m)
					for(k = 0; k < 9; ++k)
					{
						fk_vec[m] += M_inv[m][k] * (moment_vec[k] - moment_vec_eq[k]) * omega_vec[k] * dt;
					}

				fk[i][j][0] = fk[i][j][0]    - fk_vec[0];
				fk[i][j][1] = fprop[i][j][1] - fk_vec[1];
				fk[i][j][2] = fprop[i][j][2] - fk_vec[2];
				fk[i][j][3] = fprop[i][j][3] - fk_vec[3];
				fk[i][j][4] = fprop[i][j][4] - fk_vec[4];
				fk[i][j][5] = fprop[i][j][5] - fk_vec[5];
				fk[i][j][6] = fprop[i][j][6] - fk_vec[6];
				fk[i][j][7] = fprop[i][j][7] - fk_vec[7];
				fk[i][j][8] = fprop[i][j][8] - fk_vec[8];
			}
		}

}


void MRT_operator_test()
{
	/*This is a test implementation of the MRT collision operator for development purposes*/

	int i, j, m, k;

	for(i = 0; i < Nx; ++i)
		for(j = 0; j < Ny; ++j)
		{
			if(solid_flags[i][j] == 0)
			{
				/*Mapping to moment space*/
				for(m = 0; m < 9; ++m)
				{
					moment_vec[m]    = M[m][0] * fk[i][j][0]    + M[m][1] * fprop[i][j][1] + M[m][2] * fprop[i][j][2] +
									   M[m][3] * fprop[i][j][3] + M[m][4] * fprop[i][j][4] + M[m][5] * fprop[i][j][5] +
									   M[m][6] * fprop[i][j][6] + M[m][7] * fprop[i][j][7] + M[m][8] * fprop[i][j][8];

					moment_vec_eq[m] = M[m][0] * feq[i][j][0] + M[m][1] * feq[i][j][1] + M[m][2] * feq[i][j][2] +
							           M[m][3] * feq[i][j][3] + M[m][4] * feq[i][j][4] + M[m][5] * feq[i][j][5] +
									   M[m][6] * feq[i][j][6] + M[m][7] * feq[i][j][7] + M[m][8] * feq[i][j][8];

					fk_vec[m]        = 0.0;
				}


				/*Collision in moment space*/
				for(m = 0; m < 9; ++m)
				{
					moment_vec_col[m] = moment_vec[m] - (moment_vec[m] - moment_vec_eq[m]) * omega_vec[m] * dt;
				}


				/*Mapping to population space*/
				for(m = 0; m < 9; ++m)
					for(k = 0; k < 9; ++k)
					{
						fk_vec[m] += M_inv[m][k] * moment_vec_col[k];
					}

				fk[i][j][0] = fk_vec[0];
				fk[i][j][1] = fk_vec[1];
				fk[i][j][2] = fk_vec[2];
				fk[i][j][3] = fk_vec[3];
				fk[i][j][4] = fk_vec[4];
				fk[i][j][5] = fk_vec[5];
				fk[i][j][6] = fk_vec[6];
				fk[i][j][7] = fk_vec[7];
				fk[i][j][8] = fk_vec[8];
			}
		}

}


void TRT_operator()
{
	int i, j;

	for(i = 0; i < Nx; ++i)
		for(j = 0; j < Ny; ++j)
		{
			if(solid_flags[i][j] == 0)
			{
				fk[i][j][0] = fk[i][j][0]    - omega * dt * (fk[i][j][0] - feq[i][j][0]);
				fk[i][j][1] = fprop[i][j][1] - omega * dt * (0.5 * (fprop[i][j][1] + fprop[i][j][3]) - 0.5 * (feq[i][j][1] + feq[i][j][3])) - omega_min * dt * (0.5 * (fprop[i][j][1] - fprop[i][j][3]) - 0.5 * (feq[i][j][1] - feq[i][j][3]));
				fk[i][j][2] = fprop[i][j][2] - omega * dt * (0.5 * (fprop[i][j][2] + fprop[i][j][4]) - 0.5 * (feq[i][j][2] + feq[i][j][4])) - omega_min * dt * (0.5 * (fprop[i][j][2] - fprop[i][j][4]) - 0.5 * (feq[i][j][2] - feq[i][j][4]));
				fk[i][j][3] = fprop[i][j][3] - omega * dt * (0.5 * (fprop[i][j][3] + fprop[i][j][1]) - 0.5 * (feq[i][j][3] + feq[i][j][1])) - omega_min * dt * (0.5 * (fprop[i][j][3] - fprop[i][j][1]) - 0.5 * (feq[i][j][3] - feq[i][j][1]));
				fk[i][j][4] = fprop[i][j][4] - omega * dt * (0.5 * (fprop[i][j][4] + fprop[i][j][2]) - 0.5 * (feq[i][j][4] + feq[i][j][2])) - omega_min * dt * (0.5 * (fprop[i][j][4] - fprop[i][j][2]) - 0.5 * (feq[i][j][4] - feq[i][j][2]));
				fk[i][j][5] = fprop[i][j][5] - omega * dt * (0.5 * (fprop[i][j][5] + fprop[i][j][7]) - 0.5 * (feq[i][j][5] + feq[i][j][7])) - omega_min * dt * (0.5 * (fprop[i][j][5] - fprop[i][j][7]) - 0.5 * (feq[i][j][5] - feq[i][j][7]));
				fk[i][j][6] = fprop[i][j][6] - omega * dt * (0.5 * (fprop[i][j][6] + fprop[i][j][8]) - 0.5 * (feq[i][j][6] + feq[i][j][8])) - omega_min * dt * (0.5 * (fprop[i][j][6] - fprop[i][j][8]) - 0.5 * (feq[i][j][6] - feq[i][j][8]));
				fk[i][j][7] = fprop[i][j][7] - omega * dt * (0.5 * (fprop[i][j][7] + fprop[i][j][5]) - 0.5 * (feq[i][j][7] + feq[i][j][5])) - omega_min * dt * (0.5 * (fprop[i][j][7] - fprop[i][j][5]) - 0.5 * (feq[i][j][7] - feq[i][j][5]));
				fk[i][j][8] = fprop[i][j][8] - omega * dt * (0.5 * (fprop[i][j][8] + fprop[i][j][6]) - 0.5 * (feq[i][j][8] + feq[i][j][6])) - omega_min * dt * (0.5 * (fprop[i][j][8] - fprop[i][j][6]) - 0.5 * (feq[i][j][8] - feq[i][j][6]));
			}
		}

}


void BGK_operator()
{
	int i, j;

	double omega_diff = 1 - omega;

	for(i = 0; i < Nx; ++i)
		for(j = 0; j < Ny; ++j)
		{
			if(solid_flags[i][j] == 0)
			{
				fk[i][j][0] = omega_diff * fk[i][j][0]    + omega * feq[i][j][0];
				fk[i][j][1] = omega_diff * fprop[i][j][1] + omega * feq[i][j][1];
				fk[i][j][2] = omega_diff * fprop[i][j][2] + omega * feq[i][j][2];
				fk[i][j][3] = omega_diff * fprop[i][j][3] + omega * feq[i][j][3];
				fk[i][j][4] = omega_diff * fprop[i][j][4] + omega * feq[i][j][4];
				fk[i][j][5] = omega_diff * fprop[i][j][5] + omega * feq[i][j][5];
				fk[i][j][6] = omega_diff * fprop[i][j][6] + omega * feq[i][j][6];
				fk[i][j][7] = omega_diff * fprop[i][j][7] + omega * feq[i][j][7];
				fk[i][j][8] = omega_diff * fprop[i][j][8] + omega * feq[i][j][8];
			}
		}

}
