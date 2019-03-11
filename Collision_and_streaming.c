/*
 * Collision_and_streaming.c
 *
 *  Created on: 19 mei 2017
 *      Author: dharrison
 */


#include "parameters.h"
#include "collision_operators.h"
#include <math.h>
#include <stdlib.h>


void Calculate_equilibrium()
{
	int i, j;

	for(i = 0; i < Nx; ++i)
		for(j = 0; j < Ny; ++j)
		{
			if(solid_flags[i][j] == 0)
			{
				feq[i][j][0] = w[0] * rho[i][j] * (1.0 + (ck[0][0] * Ux[i][j] + ck[0][1] * Uy[i][j]) * 3.0 + 0.5 * (ck[0][0] * Ux[i][j] + ck[0][1] * Uy[i][j]) * (ck[0][0] * Ux[i][j] + ck[0][1] * Uy[i][j]) * 9.0 - 0.5 * (Ux[i][j] * Ux[i][j] + Uy[i][j] * Uy[i][j]) * 3.0);
				feq[i][j][1] = w[1] * rho[i][j] * (1.0 + (ck[1][0] * Ux[i][j] + ck[1][1] * Uy[i][j]) * 3.0 + 0.5 * (ck[1][0] * Ux[i][j] + ck[1][1] * Uy[i][j]) * (ck[1][0] * Ux[i][j] + ck[1][1] * Uy[i][j]) * 9.0 - 0.5 * (Ux[i][j] * Ux[i][j] + Uy[i][j] * Uy[i][j]) * 3.0);
				feq[i][j][2] = w[2] * rho[i][j] * (1.0 + (ck[2][0] * Ux[i][j] + ck[2][1] * Uy[i][j]) * 3.0 + 0.5 * (ck[2][0] * Ux[i][j] + ck[2][1] * Uy[i][j]) * (ck[2][0] * Ux[i][j] + ck[2][1] * Uy[i][j]) * 9.0 - 0.5 * (Ux[i][j] * Ux[i][j] + Uy[i][j] * Uy[i][j]) * 3.0);
				feq[i][j][3] = w[3] * rho[i][j] * (1.0 + (ck[3][0] * Ux[i][j] + ck[3][1] * Uy[i][j]) * 3.0 + 0.5 * (ck[3][0] * Ux[i][j] + ck[3][1] * Uy[i][j]) * (ck[3][0] * Ux[i][j] + ck[3][1] * Uy[i][j]) * 9.0 - 0.5 * (Ux[i][j] * Ux[i][j] + Uy[i][j] * Uy[i][j]) * 3.0);
				feq[i][j][4] = w[4] * rho[i][j] * (1.0 + (ck[4][0] * Ux[i][j] + ck[4][1] * Uy[i][j]) * 3.0 + 0.5 * (ck[4][0] * Ux[i][j] + ck[4][1] * Uy[i][j]) * (ck[4][0] * Ux[i][j] + ck[4][1] * Uy[i][j]) * 9.0 - 0.5 * (Ux[i][j] * Ux[i][j] + Uy[i][j] * Uy[i][j]) * 3.0);
				feq[i][j][5] = w[5] * rho[i][j] * (1.0 + (ck[5][0] * Ux[i][j] + ck[5][1] * Uy[i][j]) * 3.0 + 0.5 * (ck[5][0] * Ux[i][j] + ck[5][1] * Uy[i][j]) * (ck[5][0] * Ux[i][j] + ck[5][1] * Uy[i][j]) * 9.0 - 0.5 * (Ux[i][j] * Ux[i][j] + Uy[i][j] * Uy[i][j]) * 3.0);
				feq[i][j][6] = w[6] * rho[i][j] * (1.0 + (ck[6][0] * Ux[i][j] + ck[6][1] * Uy[i][j]) * 3.0 + 0.5 * (ck[6][0] * Ux[i][j] + ck[6][1] * Uy[i][j]) * (ck[6][0] * Ux[i][j] + ck[6][1] * Uy[i][j]) * 9.0 - 0.5 * (Ux[i][j] * Ux[i][j] + Uy[i][j] * Uy[i][j]) * 3.0);
				feq[i][j][7] = w[7] * rho[i][j] * (1.0 + (ck[7][0] * Ux[i][j] + ck[7][1] * Uy[i][j]) * 3.0 + 0.5 * (ck[7][0] * Ux[i][j] + ck[7][1] * Uy[i][j]) * (ck[7][0] * Ux[i][j] + ck[7][1] * Uy[i][j]) * 9.0 - 0.5 * (Ux[i][j] * Ux[i][j] + Uy[i][j] * Uy[i][j]) * 3.0);
				feq[i][j][8] = w[8] * rho[i][j] * (1.0 + (ck[8][0] * Ux[i][j] + ck[8][1] * Uy[i][j]) * 3.0 + 0.5 * (ck[8][0] * Ux[i][j] + ck[8][1] * Uy[i][j]) * (ck[8][0] * Ux[i][j] + ck[8][1] * Uy[i][j]) * 9.0 - 0.5 * (Ux[i][j] * Ux[i][j] + Uy[i][j] * Uy[i][j]) * 3.0);
			}
		}

}


void Calculate_collision()
{
	int i, j;

	int use_MRT	   = (MRT_TRT_BGK_switch == 2);
	int use_TRT    = (MRT_TRT_BGK_switch == 1);
	int use_BGK    = (MRT_TRT_BGK_switch != 1 && MRT_TRT_BGK_switch != 2);
	int use_forces = (F > 0);


	/*Collision*/
	if(use_MRT)
	{
		MRT_operator();
	}
	else if(use_TRT)
	{
		TRT_operator();
	}
	else if(use_BGK)
	{
		BGK_operator();
	}


	/*Addition of forces and storing distributions of current timestep*/
	for(i = 0; i < Nx; ++i)
		for(j = 0; j < Ny; ++j)
		{
			if(solid_flags[i][j] == 0)
			{
				if(use_forces)
				{
					/*Adding forces. Note that force calculations for wetnode and TRT are not correct*/
					fk[i][j][0] += 1.0 * (1.0 - 0.5 * omega * 1.0) * w[0] * ((3.0 * (ck[0][0] - Ux[i][j]) + 9.0 * (ck[0][0] * Ux[i][j] + ck[0][1] * Uy[i][j]) * ck[0][0]) * F);
					fk[i][j][1] += 1.0 * (1.0 - 0.5 * omega * 1.0) * w[1] * ((3.0 * (ck[1][0] - Ux[i][j]) + 9.0 * (ck[1][0] * Ux[i][j] + ck[1][1] * Uy[i][j]) * ck[1][0]) * F);
					fk[i][j][2] += 1.0 * (1.0 - 0.5 * omega * 1.0) * w[2] * ((3.0 * (ck[2][0] - Ux[i][j]) + 9.0 * (ck[2][0] * Ux[i][j] + ck[2][1] * Uy[i][j]) * ck[2][0]) * F);
					fk[i][j][3] += 1.0 * (1.0 - 0.5 * omega * 1.0) * w[3] * ((3.0 * (ck[3][0] - Ux[i][j]) + 9.0 * (ck[3][0] * Ux[i][j] + ck[3][1] * Uy[i][j]) * ck[3][0]) * F);
					fk[i][j][4] += 1.0 * (1.0 - 0.5 * omega * 1.0) * w[4] * ((3.0 * (ck[4][0] - Ux[i][j]) + 9.0 * (ck[4][0] * Ux[i][j] + ck[4][1] * Uy[i][j]) * ck[4][0]) * F);
					fk[i][j][5] += 1.0 * (1.0 - 0.5 * omega * 1.0) * w[5] * ((3.0 * (ck[5][0] - Ux[i][j]) + 9.0 * (ck[5][0] * Ux[i][j] + ck[5][1] * Uy[i][j]) * ck[5][0]) * F);
					fk[i][j][6] += 1.0 * (1.0 - 0.5 * omega * 1.0) * w[6] * ((3.0 * (ck[6][0] - Ux[i][j]) + 9.0 * (ck[6][0] * Ux[i][j] + ck[6][1] * Uy[i][j]) * ck[6][0]) * F);
					fk[i][j][7] += 1.0 * (1.0 - 0.5 * omega * 1.0) * w[7] * ((3.0 * (ck[7][0] - Ux[i][j]) + 9.0 * (ck[7][0] * Ux[i][j] + ck[7][1] * Uy[i][j]) * ck[7][0]) * F);
					fk[i][j][8] += 1.0 * (1.0 - 0.5 * omega * 1.0) * w[8] * ((3.0 * (ck[8][0] - Ux[i][j]) + 9.0 * (ck[8][0] * Ux[i][j] + ck[8][1] * Uy[i][j]) * ck[8][0]) * F);
				}

				/*Storing distributions for force calculations*/
				fold_step[i][j][1] = fk[i][j][1];
				fold_step[i][j][2] = fk[i][j][2];
				fold_step[i][j][3] = fk[i][j][3];
				fold_step[i][j][4] = fk[i][j][4];
				fold_step[i][j][5] = fk[i][j][5];
				fold_step[i][j][6] = fk[i][j][6];
				fold_step[i][j][7] = fk[i][j][7];
				fold_step[i][j][8] = fk[i][j][8];
			}
		}

}


void periodic_boundaries()
{
	int j;

	for(j = 0; j < Ny; ++j)
	{
		fk_virt_left[j][0] = fk[Nx-1][j][0];
		fk_virt_left[j][1] = fk[Nx-1][j][1];
		fk_virt_left[j][2] = fk[Nx-1][j][2];
		fk_virt_left[j][3] = fk[Nx-1][j][3];
		fk_virt_left[j][4] = fk[Nx-1][j][4];
		fk_virt_left[j][5] = fk[Nx-1][j][5];
		fk_virt_left[j][6] = fk[Nx-1][j][6];
		fk_virt_left[j][7] = fk[Nx-1][j][7];
		fk_virt_left[j][8] = fk[Nx-1][j][8];

		fk_virt_right[j][0] = fk[0][j][0];
		fk_virt_right[j][1] = fk[0][j][1];
		fk_virt_right[j][2] = fk[0][j][2];
		fk_virt_right[j][3] = fk[0][j][3];
		fk_virt_right[j][4] = fk[0][j][4];
		fk_virt_right[j][5] = fk[0][j][5];
		fk_virt_right[j][6] = fk[0][j][6];
		fk_virt_right[j][7] = fk[0][j][7];
		fk_virt_right[j][8] = fk[0][j][8];
	}

}


void periodic_pressure_boundaries()
{
	int j;

	for(j = 0; j < Ny; ++j)
	{
		fk_virt_left[j][0] = feq[Nx-1][j][0] * rhoi / rho[Nx-1][j] + fk[Nx-1][j][0] - feq[Nx-1][j][0];
		fk_virt_left[j][1] = feq[Nx-1][j][1] * rhoi / rho[Nx-1][j] + fk[Nx-1][j][1] - feq[Nx-1][j][1];
		fk_virt_left[j][2] = feq[Nx-1][j][2] * rhoi / rho[Nx-1][j] + fk[Nx-1][j][2] - feq[Nx-1][j][2];
		fk_virt_left[j][3] = feq[Nx-1][j][3] * rhoi / rho[Nx-1][j] + fk[Nx-1][j][3] - feq[Nx-1][j][3];
		fk_virt_left[j][4] = feq[Nx-1][j][4] * rhoi / rho[Nx-1][j] + fk[Nx-1][j][4] - feq[Nx-1][j][4];
		fk_virt_left[j][5] = feq[Nx-1][j][5] * rhoi / rho[Nx-1][j] + fk[Nx-1][j][5] - feq[Nx-1][j][5];
		fk_virt_left[j][6] = feq[Nx-1][j][6] * rhoi / rho[Nx-1][j] + fk[Nx-1][j][6] - feq[Nx-1][j][6];
		fk_virt_left[j][7] = feq[Nx-1][j][7] * rhoi / rho[Nx-1][j] + fk[Nx-1][j][7] - feq[Nx-1][j][7];
		fk_virt_left[j][8] = feq[Nx-1][j][8] * rhoi / rho[Nx-1][j] + fk[Nx-1][j][8] - feq[Nx-1][j][8];

		fk_virt_right[j][0] = feq[0][j][0] * rhoo / rho[0][j] + fk[0][j][0] - feq[0][j][0];
		fk_virt_right[j][1] = feq[0][j][1] * rhoo / rho[0][j] + fk[0][j][1] - feq[0][j][1];
		fk_virt_right[j][2] = feq[0][j][2] * rhoo / rho[0][j] + fk[0][j][2] - feq[0][j][2];
		fk_virt_right[j][3] = feq[0][j][3] * rhoo / rho[0][j] + fk[0][j][3] - feq[0][j][3];
		fk_virt_right[j][4] = feq[0][j][4] * rhoo / rho[0][j] + fk[0][j][4] - feq[0][j][4];
		fk_virt_right[j][5] = feq[0][j][5] * rhoo / rho[0][j] + fk[0][j][5] - feq[0][j][5];
		fk_virt_right[j][6] = feq[0][j][6] * rhoo / rho[0][j] + fk[0][j][6] - feq[0][j][6];
		fk_virt_right[j][7] = feq[0][j][7] * rhoo / rho[0][j] + fk[0][j][7] - feq[0][j][7];
		fk_virt_right[j][8] = feq[0][j][8] * rhoo / rho[0][j] + fk[0][j][8] - feq[0][j][8];
	}

}


void streaming_boundaries_wet_node_prescribed_inlet_vel()
{
	int j;

	double rho_inlet[Ny];
	double Nt_inlet[Ny];


	/*inlet_velocity time dependence*/
	/*
	for(j = 0; j < Ny; ++j)
	{
		inlet_velocity[j] = u_inlet_max * 4 * (Ly_wet_node[j] / ((Ny - 1) * dx) - Ly_wet_node[j] * Ly_wet_node[j] / ((Ny - 1) * dx * (Ny - 1) * dx)) * sin(timestep * M_PI * Ct/ (8.0));
	}
	*/

	/*Calculating wall density for wet node approach*/
	for(j = 0; j < Ny; ++j)
	{
		rho_inlet[j] = (fprop[0][j][0] + fprop[0][j][2] + fprop[0][j][4] + 2 * (fprop[0][j][3] + fprop[0][j][6] + fprop[0][j][7])) / (1 - inlet_velocity[j] / c);
	}


	/*Calculating inlet equilibrium distributions*/
	for(j = 0; j < Ny; ++j)
	{
		feq[0][j][0] = w[0] * rho_inlet[j] * (1.0 + (ck[0][0] * inlet_velocity[j]) * 3.0 + 0.5 * (ck[0][0] * inlet_velocity[j]) * (ck[0][0] * inlet_velocity[j]) * 9.0 - 0.5 * (inlet_velocity[j] * inlet_velocity[j]) * 3.0);
		feq[0][j][1] = w[1] * rho_inlet[j] * (1.0 + (ck[1][0] * inlet_velocity[j]) * 3.0 + 0.5 * (ck[1][0] * inlet_velocity[j]) * (ck[1][0] * inlet_velocity[j]) * 9.0 - 0.5 * (inlet_velocity[j] * inlet_velocity[j]) * 3.0);
		feq[0][j][2] = w[2] * rho_inlet[j] * (1.0 + (ck[2][0] * inlet_velocity[j]) * 3.0 + 0.5 * (ck[2][0] * inlet_velocity[j]) * (ck[2][0] * inlet_velocity[j]) * 9.0 - 0.5 * (inlet_velocity[j] * inlet_velocity[j]) * 3.0);
		feq[0][j][3] = w[3] * rho_inlet[j] * (1.0 + (ck[3][0] * inlet_velocity[j]) * 3.0 + 0.5 * (ck[3][0] * inlet_velocity[j]) * (ck[3][0] * inlet_velocity[j]) * 9.0 - 0.5 * (inlet_velocity[j] * inlet_velocity[j]) * 3.0);
		feq[0][j][4] = w[4] * rho_inlet[j] * (1.0 + (ck[4][0] * inlet_velocity[j]) * 3.0 + 0.5 * (ck[4][0] * inlet_velocity[j]) * (ck[4][0] * inlet_velocity[j]) * 9.0 - 0.5 * (inlet_velocity[j] * inlet_velocity[j]) * 3.0);
		feq[0][j][5] = w[5] * rho_inlet[j] * (1.0 + (ck[5][0] * inlet_velocity[j]) * 3.0 + 0.5 * (ck[5][0] * inlet_velocity[j]) * (ck[5][0] * inlet_velocity[j]) * 9.0 - 0.5 * (inlet_velocity[j] * inlet_velocity[j]) * 3.0);
		feq[0][j][6] = w[6] * rho_inlet[j] * (1.0 + (ck[6][0] * inlet_velocity[j]) * 3.0 + 0.5 * (ck[6][0] * inlet_velocity[j]) * (ck[6][0] * inlet_velocity[j]) * 9.0 - 0.5 * (inlet_velocity[j] * inlet_velocity[j]) * 3.0);
		feq[0][j][7] = w[7] * rho_inlet[j] * (1.0 + (ck[7][0] * inlet_velocity[j]) * 3.0 + 0.5 * (ck[7][0] * inlet_velocity[j]) * (ck[7][0] * inlet_velocity[j]) * 9.0 - 0.5 * (inlet_velocity[j] * inlet_velocity[j]) * 3.0);
		feq[0][j][8] = w[8] * rho_inlet[j] * (1.0 + (ck[8][0] * inlet_velocity[j]) * 3.0 + 0.5 * (ck[8][0] * inlet_velocity[j]) * (ck[8][0] * inlet_velocity[j]) * 9.0 - 0.5 * (inlet_velocity[j] * inlet_velocity[j]) * 3.0);
	}


	/*Correcting for wetnode*/
	for(j = 0; j < Ny; ++j)
	{
		Nt_inlet[j]  = (rho_inlet[j] * inlet_velocity[j] - c * (fprop[0][j][1] - fprop[0][j][3] + feq[0][j][5] - feq[0][j][7] + feq[0][j][8] - feq[0][j][6])) / (c * (1 + 2 / sqrt(2)));
	}


	/*Inlet boundary*/
	for(j = 0; j < Ny; ++j)
	{
		fprop[0][j][1] = fprop[0][j][3] + feq[0][j][1] - feq[0][j][3] + Nt_inlet[j];
		fprop[0][j][5] = fprop[0][j][7] + feq[0][j][5] - feq[0][j][7] + Nt_inlet[j] / sqrt(2);
		fprop[0][j][8] = fprop[0][j][6] + feq[0][j][8] - feq[0][j][6] + Nt_inlet[j] / sqrt(2);
	}

}


void streaming_boundaries_wet_node_prescribed_outlet_vel()
{
	int j;

	double rho_outlet[Ny];
	double Nt_outlet[Ny];


	/*Calculating wall density for wet node approach*/
	for(j = 0; j < Ny; ++j)
	{
		rho_outlet[j] = fprop[Nx-1][j][0] + fprop[Nx-1][j][2] + fprop[Nx-1][j][4] + 2 * (fprop[Nx-1][j][1] + fprop[Nx-1][j][5] + fprop[Nx-1][j][8]);
	}


	/*Calculating inlet equilibrium distributions*/
	for(j = 0; j < Ny; ++j)
	{
		feq[0][j][0] = w[0] * rho_outlet[j] * (1.0 + (ck[0][0] * inlet_velocity[j]) * 3.0 + 0.5 * (ck[0][0] * inlet_velocity[j]) * (ck[0][0] * inlet_velocity[j]) * 9.0 - 0.5 * (inlet_velocity[j] * inlet_velocity[j]) * 3.0);
		feq[0][j][1] = w[1] * rho_outlet[j] * (1.0 + (ck[1][0] * inlet_velocity[j]) * 3.0 + 0.5 * (ck[1][0] * inlet_velocity[j]) * (ck[1][0] * inlet_velocity[j]) * 9.0 - 0.5 * (inlet_velocity[j] * inlet_velocity[j]) * 3.0);
		feq[0][j][2] = w[2] * rho_outlet[j] * (1.0 + (ck[2][0] * inlet_velocity[j]) * 3.0 + 0.5 * (ck[2][0] * inlet_velocity[j]) * (ck[2][0] * inlet_velocity[j]) * 9.0 - 0.5 * (inlet_velocity[j] * inlet_velocity[j]) * 3.0);
		feq[0][j][3] = w[3] * rho_outlet[j] * (1.0 + (ck[3][0] * inlet_velocity[j]) * 3.0 + 0.5 * (ck[3][0] * inlet_velocity[j]) * (ck[3][0] * inlet_velocity[j]) * 9.0 - 0.5 * (inlet_velocity[j] * inlet_velocity[j]) * 3.0);
		feq[0][j][4] = w[4] * rho_outlet[j] * (1.0 + (ck[4][0] * inlet_velocity[j]) * 3.0 + 0.5 * (ck[4][0] * inlet_velocity[j]) * (ck[4][0] * inlet_velocity[j]) * 9.0 - 0.5 * (inlet_velocity[j] * inlet_velocity[j]) * 3.0);
		feq[0][j][5] = w[5] * rho_outlet[j] * (1.0 + (ck[5][0] * inlet_velocity[j]) * 3.0 + 0.5 * (ck[5][0] * inlet_velocity[j]) * (ck[5][0] * inlet_velocity[j]) * 9.0 - 0.5 * (inlet_velocity[j] * inlet_velocity[j]) * 3.0);
		feq[0][j][6] = w[6] * rho_outlet[j] * (1.0 + (ck[6][0] * inlet_velocity[j]) * 3.0 + 0.5 * (ck[6][0] * inlet_velocity[j]) * (ck[6][0] * inlet_velocity[j]) * 9.0 - 0.5 * (inlet_velocity[j] * inlet_velocity[j]) * 3.0);
		feq[0][j][7] = w[7] * rho_outlet[j] * (1.0 + (ck[7][0] * inlet_velocity[j]) * 3.0 + 0.5 * (ck[7][0] * inlet_velocity[j]) * (ck[7][0] * inlet_velocity[j]) * 9.0 - 0.5 * (inlet_velocity[j] * inlet_velocity[j]) * 3.0);
		feq[0][j][8] = w[8] * rho_outlet[j] * (1.0 + (ck[8][0] * inlet_velocity[j]) * 3.0 + 0.5 * (ck[8][0] * inlet_velocity[j]) * (ck[8][0] * inlet_velocity[j]) * 9.0 - 0.5 * (inlet_velocity[j] * inlet_velocity[j]) * 3.0);
	}


	/*Correcting for wetnode*/
	for(j = 0; j < Ny; ++j)
	{
		Nt_outlet[j] = 0.5 / c * rho_outlet[j] * l_wall - 0.5 * (fprop[Nx-1][j][1] - fprop[Nx-1][j][3]) - 0.5 * (feq[Nx-1][j][5] - feq[Nx-1][j][7] + feq[Nx-1][j][8] - feq[Nx-1][j][6]);
	}


	/*Outlet boundary*/
	for(j = 0; j < Ny; ++j)
	{
		fprop[Nx-1][j][2] = fprop[Nx-1][j][4] + feq[Nx-1][j][2] - feq[Nx-1][j][4];
		fprop[Nx-1][j][5] = fprop[Nx-1][j][7] + feq[Nx-1][j][5] - feq[Nx-1][j][7] + Nt_outlet[j];
		fprop[Nx-1][j][6] = fprop[Nx-1][j][8] + feq[Nx-1][j][6] - feq[Nx-1][j][8] - Nt_outlet[j];
	}

}


void streaming_internal_nodes()
{
	int i, j;

	int use_periodic_boundaries     = (periodic_boundaries_switch == 1);
	int use_pressure_periodic_b     = (pressure_periodic_switch == 1);
	int use_prescribed_boundaries   = (!periodic_boundaries_switch);


	/*Calculating outlet velocity for prescribed outlet pressure condition. Anti-bounce back*/
	for(j = 0; j < Ny; ++j)
	{
		outlet_velocity_x[j] = Ux[Nx-1][j] + 0.5 * (Ux[Nx-1][j] - Ux[Nx-2][j]);
		outlet_velocity_y[j] = Uy[Nx-1][j] + 0.5 * (Uy[Nx-1][j] - Uy[Nx-2][j]);
	}


	if(use_periodic_boundaries)
	{
		if(use_pressure_periodic_b)
		{
			periodic_pressure_boundaries();
		}
		else
		{
			periodic_boundaries();
		}
	}


	for(i = 1; i < Nx - 1; ++i)
		for(j = 1; j < Ny - 1; ++j)
		{
			if(solid_flags[i][j] == 0)
			{
				fprop[i][j][1] = fk[i-1][j][1];
				fprop[i][j][2] = fk[i][j-1][2];
				fprop[i][j][3] = fk[i+1][j][3];
				fprop[i][j][4] = fk[i][j+1][4];
				fprop[i][j][5] = fk[i-1][j-1][5];
				fprop[i][j][6] = fk[i+1][j-1][6];
				fprop[i][j][7] = fk[i+1][j+1][7];
				fprop[i][j][8] = fk[i-1][j+1][8];
			}
		}


	for(i = 0; i < Nx - 1; ++i)
	{
		fprop[i][0][4]      = fk[i][1][4];
		fprop[i][Ny-1][2]   = fk[i][Ny-2][2];
		fprop[i][0][3]      = fk[i+1][0][3];
		fprop[i][Ny-1][3]   = fk[i+1][Ny-1][3];
		fprop[i][Ny-1][6]   = fk[i+1][Ny-2][6];
		fprop[i][0][7]      = fk[i+1][1][7];
		fprop[i+1][0][1]    = fk[i][0][1];
		fprop[i+1][Ny-1][1] = fk[i][Ny-1][1];
		fprop[i+1][Ny-1][5] = fk[i][Ny-2][5];
		fprop[i+1][0][8]    = fk[i][1][8];
	}

	fprop[Nx-1][Ny-1][2] = fk[Nx-1][Ny-2][2];
	fprop[Nx-1][0][4]    = fk[Nx-1][1][4];


	for(j = 0; j < Ny - 1; ++j)
	{
		fprop[Nx-1][j][1]   = fk[Nx-2][j][1];
		fprop[0][j+1][2]    = fk[0][j][2];
		fprop[Nx-1][j+1][2] = fk[Nx-1][j][2];
		fprop[0][j][3]      = fk[1][j][3];
		fprop[0][j][4]      = fk[0][j+1][4];
		fprop[Nx-1][j][4]   = fk[Nx-1][j+1][4];
		fprop[Nx-1][j+1][5] = fk[Nx-2][j][5];
		fprop[0][j+1][6]    = fk[1][j][6];
		fprop[0][j][7]      = fk[1][j+1][7];
		fprop[Nx-1][j][8]   = fk[Nx-2][j+1][8];

		if(use_periodic_boundaries)
		{
			fprop[0][j][1]      = fk_virt_left[j][1];
			fprop[0][j+1][5]    = fk_virt_left[j][5];
			fprop[0][j][8]      = fk_virt_left[j+1][8];

			fprop[Nx-1][j][3]   = fk_virt_right[j][3];
			fprop[Nx-1][j+1][6] = fk_virt_right[j][6];
			fprop[Nx-1][j][7]   = fk_virt_right[j+1][7];
		}
	}

	fprop[Nx-1][Ny-1][1] = fk[Nx-2][Ny-1][1];
	fprop[0][Ny-1][3]    = fk[1][Ny-1][3];


	if(use_periodic_boundaries)
	{
		fprop[0][Ny-1][1]    = fk_virt_left[Ny-1][1];
		fprop[Nx-1][Ny-1][3] = fk_virt_right[Ny-1][3];
	}


	/*If periodic boundaries are not used and instead prescribed execute code below. Note, these calculations may need to be includes
	 * in the corner boundary nodes. Although preliminary investigations have not indicated this to be necessary*/
	if(use_prescribed_boundaries)
	{
		for(j = 1; j < Ny - 1; ++j)
		{
			/*For precribed inlet velocity*/
			if(prescribed_inlet_vel_bb)
			{
				fprop[0][j][1] = fk[0][j][3] - 2 * w[3] * rhoi * (ck[3][0] * inlet_velocity[j] * 3.0);
				fprop[0][j][5] = fk[0][j][7] - 2 * w[7] * rhoi * (ck[7][0] * inlet_velocity[j] * 3.0);
				fprop[0][j][8] = fk[0][j][6] - 2 * w[6] * rhoi * (ck[6][0] * inlet_velocity[j] * 3.0);
			}


			/*For prescribed inlet pressure*/
			if(inlet_anti_bb)
			{
				fprop[0][j][1]   = -fk[0][j][3] + 2 * w[3] * rhoi * (1.0 + 0.5 * (ck[3][0] * inlet_velocity[j]) * (ck[3][0] * inlet_velocity[j]) * 9.0 - 0.5 * (inlet_velocity[j] * inlet_velocity[j]) * 3.0);
				fprop[0][j][5]   = -fk[0][j][7] + 2 * w[7] * rhoi * (1.0 + 0.5 * (ck[7][0] * inlet_velocity[j]) * (ck[7][0] * inlet_velocity[j]) * 9.0 - 0.5 * (inlet_velocity[j] * inlet_velocity[j]) * 3.0);
				fprop[0][j][8]   = -fk[0][j][6] + 2 * w[6] * rhoi * (1.0 + 0.5 * (ck[6][0] * inlet_velocity[j]) * (ck[6][0] * inlet_velocity[j]) * 9.0 - 0.5 * (inlet_velocity[j] * inlet_velocity[j]) * 3.0);
			}


			/*For prescribed outlet pressure*/
			if(outlet_anti_bb)
			{
				fprop[Nx-1][j][3]   = -fk[Nx-1][j][1] + 2 * w[1] * rhoo * (1.0 + 0.5 * (ck[1][0] * outlet_velocity_x[j] + ck[1][1] * outlet_velocity_y[j]) * (ck[1][0] * outlet_velocity_x[j] + ck[1][1] * outlet_velocity_y[j]) * 9.0 - 0.5 * (outlet_velocity_x[j] * outlet_velocity_x[j] + outlet_velocity_y[j] * outlet_velocity_y[j]) * 3.0);
				fprop[Nx-1][j][6]   = -fk[Nx-1][j][8] + 2 * w[8] * rhoo * (1.0 + 0.5 * (ck[8][0] * outlet_velocity_x[j] + ck[8][1] * outlet_velocity_y[j]) * (ck[8][0] * outlet_velocity_x[j] + ck[8][1] * outlet_velocity_y[j]) * 9.0 - 0.5 * (outlet_velocity_x[j] * outlet_velocity_x[j] + outlet_velocity_y[j] * outlet_velocity_y[j]) * 3.0);
				fprop[Nx-1][j][7]   = -fk[Nx-1][j][5] + 2 * w[5] * rhoo * (1.0 + 0.5 * (ck[5][0] * outlet_velocity_x[j] + ck[5][1] * outlet_velocity_y[j]) * (ck[5][0] * outlet_velocity_x[j] + ck[5][1] * outlet_velocity_y[j]) * 9.0 - 0.5 * (outlet_velocity_x[j] * outlet_velocity_x[j] + outlet_velocity_y[j] * outlet_velocity_y[j]) * 3.0);
			}
		}

		/*For inlet velocity wetnode*/
		if(inlet_wetnode)
		{
			streaming_boundaries_wet_node_prescribed_inlet_vel();
		}
	}

}


void streaming_solid_boundaries()
{
	int i, j, n;

	double force_x = 0.0;
	double force_y = 0.0;

	int number_bs_type_1 = number_b_nodes->type_1;
	int number_bs_type_2 = number_b_nodes->type_2;
	int number_bs_type_3 = number_b_nodes->type_3;
	int number_bs_type_4 = number_b_nodes->type_4;
	int number_bs_type_5 = number_b_nodes->type_5;
	int number_bs_type_6 = number_b_nodes->type_6;
	int number_bs_type_7 = number_b_nodes->type_7;
	int number_bs_type_8 = number_b_nodes->type_8;
	int number_bs_type_9 = number_b_nodes->type_9;
	int number_bs_type_10 = number_b_nodes->type_10;
	int number_bs_type_11 = number_b_nodes->type_11;
	int number_bs_type_12 = number_b_nodes->type_12;


	/*Streaming type 1 nodes*/
	for(n = 0; n < number_bs_type_1; ++n)
	{
		i = b_locations_type_1[n].i_index;
		j = b_locations_type_1[n].j_index;
		fprop[i][j][6] = fk[i][j][8];
		force_x += ((fprop[i][j][6] * ck[6][0]) -
					(fold_step[i][j][8] * ck[8][0]));
		force_y += ((fprop[i][j][6] * ck[6][1]) -
					(fold_step[i][j][8] * ck[8][1]));
	}


	/*Streaming type 2 nodes*/
	for(n = 0; n < number_bs_type_2; ++n)
	{
		i = b_locations_type_2[n].i_index;
		j = b_locations_type_2[n].j_index;
		fprop[i][j][2] = fk[i][j][4];
		fprop[i][j][5] = fk[i][j][7];
		fprop[i][j][6] = fk[i][j][8];
		force_x += ((fprop[i][j][5] * ck[5][0] + fprop[i][j][6] * ck[6][0] + fprop[i][j][2] * ck[2][0]) -
					(fold_step[i][j][8] * ck[8][0] + fold_step[i][j][7] * ck[7][0] + fold_step[i][j][4] * ck[4][0]));
		force_y += ((fprop[i][j][5] * ck[5][1] + fprop[i][j][6] * ck[6][1] + fprop[i][j][2] * ck[2][1]) -
					(fold_step[i][j][8] * ck[8][1] + fold_step[i][j][7] * ck[7][1] + fold_step[i][j][4] * ck[4][1]));
	}


	/*Streaming type 3 nodes*/
	for(n = 0; n < number_bs_type_3; ++n)
	{
		i = b_locations_type_3[n].i_index;
		j = b_locations_type_3[n].j_index;
		fprop[i][j][5] = fk[i][j][7];
		force_x += ((fprop[i][j][5] * ck[5][0]) -
					(fold_step[i][j][7] * ck[7][0]));
		force_y += ((fprop[i][j][5] * ck[5][1]) -
					(fold_step[i][j][7] * ck[7][1]));
	}


	/*Streaming type 4 nodes*/
	for(n = 0; n < number_bs_type_4; ++n)
	{
		i = b_locations_type_4[n].i_index;
		j = b_locations_type_4[n].j_index;
		fprop[i][j][2] = fk[i][j][4];
		fprop[i][j][3] = fk[i][j][1];
		fprop[i][j][6] = fk[i][j][8];
		force_x += ((fprop[i][j][3] * ck[3][0] + fprop[i][j][6] * ck[6][0]) -
					(fold_step[i][j][8] * ck[8][0] + fold_step[i][j][1] * ck[1][0]));
		force_y += ((fprop[i][j][2] * ck[2][1] + fprop[i][j][3] * ck[3][1] + fprop[i][j][6] * ck[6][1]) -
					(fold_step[i][j][4] * ck[4][1] + fold_step[i][j][1] * ck[1][1] + fold_step[i][j][8] * ck[8][1]));
	}


	/*Streaming type 5 nodes*/
	for(n = 0; n < number_bs_type_5; ++n)
	{
		i = b_locations_type_5[n].i_index;
		j = b_locations_type_5[n].j_index;
		fprop[i][j][1] = fk[i][j][3];
		fprop[i][j][2] = fk[i][j][4];
		fprop[i][j][5] = fk[i][j][7];
		force_x += ((fprop[i][j][5] * ck[5][0] + fprop[i][j][1] * ck[1][0]) -
					(fold_step[i][j][3] * ck[3][0] + fold_step[i][j][7] * ck[7][0]));
		force_y += ((fprop[i][j][2] * ck[2][1] + fprop[i][j][1] * ck[1][1] + fprop[i][j][5] * ck[5][1]) -
					(fold_step[i][j][4] * ck[4][1] + fold_step[i][j][3] * ck[3][1] + fold_step[i][j][7] * ck[7][1]));
	}


	/*Streaming type 6 nodes*/
	for(n = 0; n < number_bs_type_6; ++n)
	{
		i = b_locations_type_6[n].i_index;
		j = b_locations_type_6[n].j_index;
		fprop[i][j][3] = fk[i][j][1];
		fprop[i][j][6] = fk[i][j][8];
		fprop[i][j][7] = fk[i][j][5];
		force_x += ((fprop[i][j][6] * ck[6][0] + fprop[i][j][7] * ck[7][0] + fprop[i][j][3] * ck[3][0]) -
					(fold_step[i][j][5] * ck[5][0] + fold_step[i][j][8] * ck[8][0] + fold_step[i][j][1] * ck[1][0]));
		force_y += ((fprop[i][j][6] * ck[6][1] + fprop[i][j][7] * ck[7][1] + fprop[i][j][3] * ck[3][1]) -
				   (fold_step[i][j][5] * ck[5][1] + fold_step[i][j][8] * ck[8][1] + fold_step[i][j][1] * ck[1][1]));
	}


	/*Streaming type 7 nodes*/
	for(n = 0; n < number_bs_type_7; ++n)
	{
		i = b_locations_type_7[n].i_index;
		j = b_locations_type_7[n].j_index;
		fprop[i][j][1] = fk[i][j][3];
		fprop[i][j][5] = fk[i][j][7];
		fprop[i][j][8] = fk[i][j][6];
		force_x += ((fprop[i][j][1] * ck[1][0] + fprop[i][j][5] * ck[5][0] + fprop[i][j][8] * ck[8][0]) -
					(fold_step[i][j][3] * ck[3][0] + fold_step[i][j][7] * ck[7][0] + fold_step[i][j][6] * ck[6][0]));
		force_y += ((fprop[i][j][1] * ck[1][1] + fprop[i][j][5] * ck[5][1] + fprop[i][j][8] * ck[8][1]) -
				   (fold_step[i][j][3] * ck[3][1] + fold_step[i][j][7] * ck[7][1] + fold_step[i][j][6] * ck[6][1]));
	}


	/*Streaming type 8 nodes*/
	for(n = 0; n < number_bs_type_8; ++n)
	{
		i = b_locations_type_8[n].i_index;
		j = b_locations_type_8[n].j_index;
		fprop[i][j][3] = fk[i][j][1];
		fprop[i][j][4] = fk[i][j][2];
		fprop[i][j][7] = fk[i][j][5];
		force_x += ((fprop[i][j][3] * ck[3][0] + fprop[i][j][7] * ck[7][0]) -
					(fold_step[i][j][1] * ck[1][0] + fold_step[i][j][5] * ck[5][0]));
		force_y += ((fprop[i][j][3] * ck[3][1] + fprop[i][j][7] * ck[7][1] + fprop[i][j][4] * ck[4][1]) -
				   (fold_step[i][j][1] * ck[1][1] + fold_step[i][j][5] * ck[5][1] + fold_step[i][j][2] * ck[2][1]));
	}


	/*Streaming type 9 nodes*/
	for(n = 0; n < number_bs_type_9; ++n)
	{
		i = b_locations_type_9[n].i_index;
		j = b_locations_type_9[n].j_index;
		fprop[i][j][1] = fk[i][j][3];
		fprop[i][j][4] = fk[i][j][2];
		fprop[i][j][8] = fk[i][j][6];
		force_x += ((fprop[i][j][1] * ck[1][0] + fprop[i][j][8] * ck[8][0]) -
					(fold_step[i][j][3] * ck[3][0] + fold_step[i][j][6] * ck[6][0]));
		force_y += ((fprop[i][j][1] * ck[1][1] + fprop[i][j][4] * ck[4][1] + fprop[i][j][8] * ck[8][1]) -
				   (fold_step[i][j][3] * ck[3][1] + fold_step[i][j][2] * ck[2][1] + fold_step[i][j][6] * ck[6][1]));
	}


	/*Streaming type 10 nodes*/
	for(n = 0; n < number_bs_type_10; ++n)
	{
		i = b_locations_type_10[n].i_index;
		j = b_locations_type_10[n].j_index;
		fprop[i][j][7] = fk[i][j][5];
		force_x += ((fprop[i][j][7] * ck[7][0]) -
					(fold_step[i][j][5] * ck[5][0]));
		force_y += ((fprop[i][j][7] * ck[7][1]) -
				   (fold_step[i][j][5] * ck[5][1]));
	}


	/*Streaming type 11 nodes*/
	for(n = 0; n < number_bs_type_11; ++n)
	{
		i = b_locations_type_11[n].i_index;
		j = b_locations_type_11[n].j_index;
		fprop[i][j][4] = fk[i][j][2];
		fprop[i][j][7] = fk[i][j][5];
		fprop[i][j][8] = fk[i][j][6];
		force_x += ((fprop[i][j][8] * ck[8][0] + fprop[i][j][7] * ck[7][0]) -
					(fold_step[i][j][5] * ck[5][0] + fold_step[i][j][6] * ck[6][0]));
		force_y += ((fprop[i][j][8] * ck[8][1] + fprop[i][j][7] * ck[7][1] + fprop[i][j][4] * ck[4][1]) -
					(fold_step[i][j][5] * ck[5][1] + fold_step[i][j][6] * ck[6][1]  + fold_step[i][j][2] * ck[2][1]));
	}


	/*Streaming type 12 nodes*/
	for(n = 0; n < number_bs_type_12; ++n)
	{
		i = b_locations_type_12[n].i_index;
		j = b_locations_type_12[n].j_index;
		fprop[i][j][8] = fk[i][j][6];
		force_x += ((fprop[i][j][8] * ck[8][0]) -
					(fold_step[i][j][6] * ck[6][0]));
		force_y += ((fprop[i][j][8] * ck[8][1]) -
					(fold_step[i][j][6] * ck[6][1]));
	}

	Force_solid_x[0] = force_x;
	Force_solid_y[0] = force_y;
	force_vec_x[timestep] = force_x;

}


void streaming_solid_boundaries_ind_parts()
{
	int i, j, n, partnumber;


	for(partnumber = 0; partnumber < n_particles; ++partnumber)
	{
		double force_x = 0.0;
		double force_y = 0.0;


		int number_bs_type_1 = boundary_locations->part_number[partnumber].boundary_type[0].number_of_boundaries;
		int number_bs_type_2 = boundary_locations->part_number[partnumber].boundary_type[1].number_of_boundaries;
		int number_bs_type_3 = boundary_locations->part_number[partnumber].boundary_type[2].number_of_boundaries;
		int number_bs_type_4 = boundary_locations->part_number[partnumber].boundary_type[3].number_of_boundaries;
		int number_bs_type_5 = boundary_locations->part_number[partnumber].boundary_type[4].number_of_boundaries;
		int number_bs_type_6 = boundary_locations->part_number[partnumber].boundary_type[5].number_of_boundaries;
		int number_bs_type_7 = boundary_locations->part_number[partnumber].boundary_type[6].number_of_boundaries;
		int number_bs_type_8 = boundary_locations->part_number[partnumber].boundary_type[7].number_of_boundaries;
		int number_bs_type_9 = boundary_locations->part_number[partnumber].boundary_type[8].number_of_boundaries;
		int number_bs_type_10 = boundary_locations->part_number[partnumber].boundary_type[9].number_of_boundaries;
		int number_bs_type_11 = boundary_locations->part_number[partnumber].boundary_type[10].number_of_boundaries;
		int number_bs_type_12 = boundary_locations->part_number[partnumber].boundary_type[11].number_of_boundaries;


		/*Streaming type 1 nodes*/
		for(n = 0; n < number_bs_type_1; ++n)
		{
			i = boundary_locations->part_number[partnumber].boundary_type[0].boundary_number[n].i_index;
			j = boundary_locations->part_number[partnumber].boundary_type[0].boundary_number[n].j_index;
			fprop[i][j][6] = fk[i][j][8];
			force_x += ((fprop[i][j][6] * ck[6][0]) -
						(fold_step[i][j][8] * ck[8][0]));
			force_y += ((fprop[i][j][6] * ck[6][1]) -
						(fold_step[i][j][8] * ck[8][1]));
		}


		/*Streaming type 2 nodes*/
		for(n = 0; n < number_bs_type_2; ++n)
		{
			i = boundary_locations->part_number[partnumber].boundary_type[1].boundary_number[n].i_index;
			j = boundary_locations->part_number[partnumber].boundary_type[1].boundary_number[n].j_index;
			fprop[i][j][2] = fk[i][j][4];
			fprop[i][j][5] = fk[i][j][7];
			fprop[i][j][6] = fk[i][j][8];
			force_x += ((fprop[i][j][5] * ck[5][0] + fprop[i][j][6] * ck[6][0] + fprop[i][j][2] * ck[2][0]) -
						(fold_step[i][j][8] * ck[8][0] + fold_step[i][j][7] * ck[7][0] + fold_step[i][j][4] * ck[4][0]));
			force_y += ((fprop[i][j][5] * ck[5][1] + fprop[i][j][6] * ck[6][1] + fprop[i][j][2] * ck[2][1]) -
						(fold_step[i][j][8] * ck[8][1] + fold_step[i][j][7] * ck[7][1] + fold_step[i][j][4] * ck[4][1]));
		}


		/*Streaming type 3 nodes*/
		for(n = 0; n < number_bs_type_3; ++n)
		{
			i = boundary_locations->part_number[partnumber].boundary_type[2].boundary_number[n].i_index;
			j = boundary_locations->part_number[partnumber].boundary_type[2].boundary_number[n].j_index;
			fprop[i][j][5] = fk[i][j][7];
			force_x += ((fprop[i][j][5] * ck[5][0]) -
						(fold_step[i][j][7] * ck[7][0]));
			force_y += ((fprop[i][j][5] * ck[5][1]) -
						(fold_step[i][j][7] * ck[7][1]));
		}


		/*Streaming type 4 nodes*/
		for(n = 0; n < number_bs_type_4; ++n)
		{
			i = boundary_locations->part_number[partnumber].boundary_type[3].boundary_number[n].i_index;
			j = boundary_locations->part_number[partnumber].boundary_type[3].boundary_number[n].j_index;
			fprop[i][j][2] = fk[i][j][4];
			fprop[i][j][3] = fk[i][j][1];
			fprop[i][j][6] = fk[i][j][8];
			force_x += ((fprop[i][j][3] * ck[3][0] + fprop[i][j][6] * ck[6][0]) -
						(fold_step[i][j][8] * ck[8][0] + fold_step[i][j][1] * ck[1][0]));
			force_y += ((fprop[i][j][2] * ck[2][1] + fprop[i][j][3] * ck[3][1] + fprop[i][j][6] * ck[6][1]) -
						(fold_step[i][j][4] * ck[4][1] + fold_step[i][j][1] * ck[1][1] + fold_step[i][j][8] * ck[8][1]));
		}


		/*Streaming type 5 nodes*/
		for(n = 0; n < number_bs_type_5; ++n)
		{
			i = boundary_locations->part_number[partnumber].boundary_type[4].boundary_number[n].i_index;
			j = boundary_locations->part_number[partnumber].boundary_type[4].boundary_number[n].j_index;
			fprop[i][j][1] = fk[i][j][3];
			fprop[i][j][2] = fk[i][j][4];
			fprop[i][j][5] = fk[i][j][7];
			force_x += ((fprop[i][j][5] * ck[5][0] + fprop[i][j][1] * ck[1][0]) -
						(fold_step[i][j][3] * ck[3][0] + fold_step[i][j][7] * ck[7][0]));
			force_y += ((fprop[i][j][2] * ck[2][1] + fprop[i][j][1] * ck[1][1] + fprop[i][j][5] * ck[5][1]) -
						(fold_step[i][j][4] * ck[4][1] + fold_step[i][j][3] * ck[3][1] + fold_step[i][j][7] * ck[7][1]));
		}


		/*Streaming type 6 nodes*/
		for(n = 0; n < number_bs_type_6; ++n)
		{
			i = boundary_locations->part_number[partnumber].boundary_type[5].boundary_number[n].i_index;
			j = boundary_locations->part_number[partnumber].boundary_type[5].boundary_number[n].j_index;
			fprop[i][j][3] = fk[i][j][1];
			fprop[i][j][6] = fk[i][j][8];
			fprop[i][j][7] = fk[i][j][5];
			force_x += ((fprop[i][j][6] * ck[6][0] + fprop[i][j][7] * ck[7][0] + fprop[i][j][3] * ck[3][0]) -
						(fold_step[i][j][5] * ck[5][0] + fold_step[i][j][8] * ck[8][0] + fold_step[i][j][1] * ck[1][0]));
			force_y += ((fprop[i][j][6] * ck[6][1] + fprop[i][j][7] * ck[7][1] + fprop[i][j][3] * ck[3][1]) -
					   (fold_step[i][j][5] * ck[5][1] + fold_step[i][j][8] * ck[8][1] + fold_step[i][j][1] * ck[1][1]));
		}


		/*Streaming type 7 nodes*/
		for(n = 0; n < number_bs_type_7; ++n)
		{
			i = boundary_locations->part_number[partnumber].boundary_type[6].boundary_number[n].i_index;
			j = boundary_locations->part_number[partnumber].boundary_type[6].boundary_number[n].j_index;
			fprop[i][j][1] = fk[i][j][3];
			fprop[i][j][5] = fk[i][j][7];
			fprop[i][j][8] = fk[i][j][6];
			force_x += ((fprop[i][j][1] * ck[1][0] + fprop[i][j][5] * ck[5][0] + fprop[i][j][8] * ck[8][0]) -
						(fold_step[i][j][3] * ck[3][0] + fold_step[i][j][7] * ck[7][0] + fold_step[i][j][6] * ck[6][0]));
			force_y += ((fprop[i][j][1] * ck[1][1] + fprop[i][j][5] * ck[5][1] + fprop[i][j][8] * ck[8][1]) -
					   (fold_step[i][j][3] * ck[3][1] + fold_step[i][j][7] * ck[7][1] + fold_step[i][j][6] * ck[6][1]));
		}


		/*Streaming type 8 nodes*/
		for(n = 0; n < number_bs_type_8; ++n)
		{
			i = boundary_locations->part_number[partnumber].boundary_type[7].boundary_number[n].i_index;
			j = boundary_locations->part_number[partnumber].boundary_type[7].boundary_number[n].j_index;
			fprop[i][j][3] = fk[i][j][1];
			fprop[i][j][4] = fk[i][j][2];
			fprop[i][j][7] = fk[i][j][5];
			force_x += ((fprop[i][j][3] * ck[3][0] + fprop[i][j][7] * ck[7][0]) -
						(fold_step[i][j][1] * ck[1][0] + fold_step[i][j][5] * ck[5][0]));
			force_y += ((fprop[i][j][3] * ck[3][1] + fprop[i][j][7] * ck[7][1] + fprop[i][j][4] * ck[4][1]) -
					   (fold_step[i][j][1] * ck[1][1] + fold_step[i][j][5] * ck[5][1] + fold_step[i][j][2] * ck[2][1]));
		}


		/*Streaming type 9 nodes*/
		for(n = 0; n < number_bs_type_9; ++n)
		{
			i = boundary_locations->part_number[partnumber].boundary_type[8].boundary_number[n].i_index;
			j = boundary_locations->part_number[partnumber].boundary_type[8].boundary_number[n].j_index;
			fprop[i][j][1] = fk[i][j][3];
			fprop[i][j][4] = fk[i][j][2];
			fprop[i][j][8] = fk[i][j][6];
			force_x += ((fprop[i][j][1] * ck[1][0] + fprop[i][j][8] * ck[8][0]) -
						(fold_step[i][j][3] * ck[3][0] + fold_step[i][j][6] * ck[6][0]));
			force_y += ((fprop[i][j][1] * ck[1][1] + fprop[i][j][4] * ck[4][1] + fprop[i][j][8] * ck[8][1]) -
					   (fold_step[i][j][3] * ck[3][1] + fold_step[i][j][2] * ck[2][1] + fold_step[i][j][6] * ck[6][1]));
		}


		/*Streaming type 10 nodes*/
		for(n = 0; n < number_bs_type_10; ++n)
		{
			i = boundary_locations->part_number[partnumber].boundary_type[9].boundary_number[n].i_index;
			j = boundary_locations->part_number[partnumber].boundary_type[9].boundary_number[n].j_index;
			fprop[i][j][7] = fk[i][j][5];
			force_x += ((fprop[i][j][7] * ck[7][0]) -
						(fold_step[i][j][5] * ck[5][0]));
			force_y += ((fprop[i][j][7] * ck[7][1]) -
					   (fold_step[i][j][5] * ck[5][1]));
		}


		/*Streaming type 11 nodes*/
		for(n = 0; n < number_bs_type_11; ++n)
		{
			i = boundary_locations->part_number[partnumber].boundary_type[10].boundary_number[n].i_index;
			j = boundary_locations->part_number[partnumber].boundary_type[10].boundary_number[n].j_index;
			fprop[i][j][4] = fk[i][j][2];
			fprop[i][j][7] = fk[i][j][5];
			fprop[i][j][8] = fk[i][j][6];
			force_x += ((fprop[i][j][8] * ck[8][0] + fprop[i][j][7] * ck[7][0]) -
						(fold_step[i][j][5] * ck[5][0] + fold_step[i][j][6] * ck[6][0]));
			force_y += ((fprop[i][j][8] * ck[8][1] + fprop[i][j][7] * ck[7][1] + fprop[i][j][4] * ck[4][1]) -
						(fold_step[i][j][5] * ck[5][1] + fold_step[i][j][6] * ck[6][1]  + fold_step[i][j][2] * ck[2][1]));
		}


		/*Streaming type 12 nodes*/
		for(n = 0; n < number_bs_type_12; ++n)
		{
			i = boundary_locations->part_number[partnumber].boundary_type[11].boundary_number[n].i_index;
			j = boundary_locations->part_number[partnumber].boundary_type[11].boundary_number[n].j_index;
			fprop[i][j][8] = fk[i][j][6];
			force_x += ((fprop[i][j][8] * ck[8][0]) -
						(fold_step[i][j][6] * ck[6][0]));
			force_y += ((fprop[i][j][8] * ck[8][1]) -
						(fold_step[i][j][6] * ck[6][1]));
		}

		Force_solid_x_obj[partnumber] = force_x;
		Force_solid_y_obj[partnumber] = force_y;
		force_vec_x_obj[partnumber][timestep] = force_x;
	}

}


void streaming_boundaries_no_slip()
{
	int i;

	int upper_wall_not_moving = !upper_wall_moving;
	int lower_wall_not_moving = !lower_wall_moving;


	/*Calculating outlet velocity for perscribed outlet pressure condition. Anti-bounceback*/
	for(j = 0; j < Ny; ++j)
	{
		outlet_velocity_x[j] = Ux[Nx-1][j] + 0.5 * (Ux[Nx-1][j] - Ux[Nx-2][j]);
		outlet_velocity_y[j] = Uy[Nx-1][j] + 0.5 * (Uy[Nx-1][j] - Uy[Nx-2][j]);
	}


	/*Upper Boundary, no slip boundary condition*/
	if(upper_wall_moving)
	{
		for(i = 1; i < Nx - 1; ++i)
		{
			if((solid_flags[i][Ny-1] == 0) && (solid_flags[i+1][Ny-1] == 1))
			{
				fprop[i][Ny-1][3] = fk[i][Ny-1][1];
				fprop[i][Ny-1][4] = fk[i][Ny-1][2] - 2 * w[2] * rho[i][Ny-1] * (ck[2][0] * u_wall * 3.0);
				fprop[i][Ny-1][7] = fk[i][Ny-1][5] - 2 * w[5] * rho[i][Ny-1] * (ck[5][0] * u_wall * 3.0);
			}
			else if((solid_flags[i][Ny-1] == 0) && (solid_flags[i-1][Ny-1] == 1))
			{
				fprop[i][Ny-1][1] = fk[i][Ny-1][3];
				fprop[i][Ny-1][4] = fk[i][Ny-1][2] - 2 * w[2] * rho[i][Ny-1] * (ck[2][0] * u_wall * 3.0);
				fprop[i][Ny-1][8] = fk[i][Ny-1][6] - 2 * w[6] * rho[i][Ny-1] * (ck[6][0] * u_wall * 3.0);
			}
			else if((solid_flags[i][Ny-1] == 0) && (solid_flags[i-1][Ny-1] == 0) && (solid_flags[i+1][Ny-1] == 0))
			{
				fprop[i][Ny-1][4] = fk[i][Ny-1][2] - 2 * w[2] * rho[i][Ny-1] * (ck[2][0] * u_wall * 3.0);
				fprop[i][Ny-1][7] = fk[i][Ny-1][5] - 2 * w[5] * rho[i][Ny-1] * (ck[5][0] * u_wall * 3.0);
				fprop[i][Ny-1][8] = fk[i][Ny-1][6] - 2 * w[6] * rho[i][Ny-1] * (ck[6][0] * u_wall * 3.0);
			}
		}
	}
	else if(upper_wall_not_moving)
	{
		for(i = 1; i < Nx - 1; ++i)
		{
			if((solid_flags[i][Ny-1] == 0) && (solid_flags[i+1][Ny-1] == 1))
			{
				fprop[i][Ny-1][3] = fk[i][Ny-1][1];
				fprop[i][Ny-1][4] = fk[i][Ny-1][2];
				fprop[i][Ny-1][7] = fk[i][Ny-1][5];
			}
			else if((solid_flags[i][Ny-1] == 0) && (solid_flags[i-1][Ny-1] == 1))
			{
				fprop[i][Ny-1][1] = fk[i][Ny-1][3];
				fprop[i][Ny-1][4] = fk[i][Ny-1][2];
				fprop[i][Ny-1][8] = fk[i][Ny-1][6];
			}
			else if((solid_flags[i][Ny-1] == 0) && (solid_flags[i-1][Ny-1] == 0) && (solid_flags[i+1][Ny-1] == 0))
			{
				fprop[i][Ny-1][4] = fk[i][Ny-1][2];
				fprop[i][Ny-1][7] = fk[i][Ny-1][5];
				fprop[i][Ny-1][8] = fk[i][Ny-1][6];
			}
		}
	}

	if(upper_wall_moving)
	{
		fprop[0][Ny-1][4] = fk[0][Ny-1][2] - 2 * w[2] * rho[0][Ny-1] * (ck[2][0] * u_wall * 3.0);
		fprop[0][Ny-1][7] = fk[0][Ny-1][5] - 2 * w[5] * rho[0][Ny-1] * (ck[5][0] * u_wall * 3.0);
		fprop[0][Ny-1][8] = fk[0][Ny-1][6] - 2 * w[6] * rho[0][Ny-1] * (ck[6][0] * u_wall * 3.0);

		fprop[Nx-1][Ny-1][4] = fk[Nx-1][Ny-1][2] - 2 * w[2] * rho[Nx-1][Ny-1] * (ck[2][0] * u_wall * 3.0);
		fprop[Nx-1][Ny-1][7] = fk[Nx-1][Ny-1][5] - 2 * w[5] * rho[Nx-1][Ny-1] * (ck[5][0] * u_wall * 3.0);
		fprop[Nx-1][Ny-1][8] = fk[Nx-1][Ny-1][6] - 2 * w[6] * rho[Nx-1][Ny-1] * (ck[6][0] * u_wall * 3.0);
	}
	else if(upper_wall_not_moving)
	{
		fprop[0][Ny-1][4] = fk[0][Ny-1][2];
		fprop[0][Ny-1][7] = fk[0][Ny-1][5];
		fprop[0][Ny-1][8] = fk[0][Ny-1][6];

		fprop[Nx-1][Ny-1][4] = fk[Nx-1][Ny-1][2];
		fprop[Nx-1][Ny-1][7] = fk[Nx-1][Ny-1][5];
		fprop[Nx-1][Ny-1][8] = fk[Nx-1][Ny-1][6];
	}


	/*Lower Boundary, no slip boundary condition*/
	if(lower_wall_moving)
	{
		for(i = 1; i < Nx - 1; ++i)
		{
			if((solid_flags[i][0] == 0) && (solid_flags[i+1][0] == 1))
			{
				fprop[i][0][2] = fk[i][0][4] - 2 * w[4] * rho[i][0] * (ck[4][0] * l_wall * 3.0);
				fprop[i][0][3] = fk[i][0][1];
				fprop[i][0][6] = fk[i][0][8] - 2 * w[8] * rho[i][0] * (ck[8][0] * l_wall * 3.0);
			}
			else if((solid_flags[i][0] == 0) && (solid_flags[i-1][0] == 1))
			{
				fprop[i][0][1] = fk[i][0][3];
				fprop[i][0][2] = fk[i][0][4] - 2 * w[4] * rho[i][0] * (ck[4][0] * l_wall * 3.0);
				fprop[i][0][5] = fk[i][0][7] - 2 * w[7] * rho[i][0] * (ck[7][0] * l_wall * 3.0);
			}
			else if((solid_flags[i][0] == 0) && (solid_flags[i-1][0] == 0) && (solid_flags[i+1][0] == 0))
			{
				fprop[i][0][2] = fk[i][0][4] - 2 * w[4] * rho[i][0] * (ck[4][0] * l_wall * 3.0);
				fprop[i][0][5] = fk[i][0][7] - 2 * w[7] * rho[i][0] * (ck[7][0] * l_wall * 3.0);
				fprop[i][0][6] = fk[i][0][8] - 2 * w[8] * rho[i][0] * (ck[8][0] * l_wall * 3.0);
			}
		}
	}
	else if(lower_wall_not_moving)
	{
		for(i = 1; i < Nx - 1; ++i)
		{
			if((solid_flags[i][0] == 0) && (solid_flags[i+1][0] == 1))
			{
				fprop[i][0][2] = fk[i][0][4];
				fprop[i][0][3] = fk[i][0][1];
				fprop[i][0][6] = fk[i][0][8];
			}
			else if((solid_flags[i][0] == 0) && (solid_flags[i-1][0] == 1))
			{
				fprop[i][0][1] = fk[i][0][3];
				fprop[i][0][2] = fk[i][0][4];
				fprop[i][0][5] = fk[i][0][7];
			}
			else if((solid_flags[i][0] == 0) && (solid_flags[i-1][0] == 0) && (solid_flags[i+1][0] == 0))
			{
				fprop[i][0][2] = fk[i][0][4];
				fprop[i][0][5] = fk[i][0][7];
				fprop[i][0][6] = fk[i][0][8];
			}
		}
	}

	if(lower_wall_moving)
	{
		fprop[0][0][2] = fk[0][0][4] - 2 * w[4] * rho[0][0] * (ck[4][0] * l_wall * 3.0);
		fprop[0][0][5] = fk[0][0][7] - 2 * w[7] * rho[0][0] * (ck[7][0] * l_wall * 3.0);
		fprop[0][0][6] = fk[0][0][8] - 2 * w[8] * rho[0][0] * (ck[8][0] * l_wall * 3.0);

		fprop[Nx-1][0][2] = fk[Nx-1][0][4] - 2 * w[4] * rho[Nx-1][0] * (ck[4][0] * l_wall * 3.0);
		fprop[Nx-1][0][5] = fk[Nx-1][0][7] - 2 * w[7] * rho[Nx-1][0] * (ck[7][0] * l_wall * 3.0);
		fprop[Nx-1][0][6] = fk[Nx-1][0][8] - 2 * w[8] * rho[Nx-1][0] * (ck[8][0] * l_wall * 3.0);
	}
	else if(lower_wall_not_moving)
	{
		fprop[0][0][2] = fk[0][0][4];
		fprop[0][0][5] = fk[0][0][7];
		fprop[0][0][6] = fk[0][0][8];

		fprop[Nx-1][0][2] = fk[Nx-1][0][4];
		fprop[Nx-1][0][5] = fk[Nx-1][0][7];
		fprop[Nx-1][0][6] = fk[Nx-1][0][8];
	}

}


void streaming_boundaries_free_slip()
{
	int i;


	/*Upper Boundary, free slip boundary condition*/
	for(i = 1; i < Nx - 1; ++i)
	{
		if((solid_flags[i][Ny-1] == 0) && (solid_flags[i+1][Ny-1] == 1))
		{
			fprop[i][Ny-1][3] = fk[i][Ny-1][1];
			fprop[i][Ny-1][4] = fk[i][Ny-1][2];
			fprop[i][Ny-1][7] = fk[i][Ny-1][6];
		}
		else if((solid_flags[i][Ny-1] == 0) && (solid_flags[i-1][Ny-1] == 1))
		{
			fprop[i][Ny-1][1] = fk[i][Ny-1][3];
			fprop[i][Ny-1][4] = fk[i][Ny-1][2];
			fprop[i][Ny-1][8] = fk[i][Ny-1][5];
		}
		else if((solid_flags[i][Ny-1] == 0) && (solid_flags[i-1][Ny-1] == 0) && (solid_flags[i+1][Ny-1] == 0))
		{
			fprop[i][Ny-1][4] = fk[i][Ny-1][2];
			fprop[i][Ny-1][7] = fk[i][Ny-1][6];
			fprop[i][Ny-1][8] = fk[i][Ny-1][5];
		}
	}

	fprop[0][Ny-1][4] = fk[0][Ny-1][2];
	fprop[0][Ny-1][7] = fk[0][Ny-1][6];
	fprop[0][Ny-1][8] = fk[0][Ny-1][5];

	fprop[Nx-1][Ny-1][4] = fk[Nx-1][Ny-1][2];
	fprop[Nx-1][Ny-1][7] = fk[Nx-1][Ny-1][6];
	fprop[Nx-1][Ny-1][8] = fk[Nx-1][Ny-1][5];


	/*Lower Boundary, free slip boundary condition*/
	for(i = 1; i < Nx - 1; ++i)
	{
		if((solid_flags[i][0] == 0) && (solid_flags[i+1][0] == 1))
		{
			fprop[i][0][2] = fk[i][0][4];
			fprop[i][0][3] = fk[i][0][1];
			fprop[i][0][6] = fk[i][0][7];
		}
		else if((solid_flags[i][0] == 0) && (solid_flags[i-1][0] == 1))
		{
			fprop[i][0][1] = fk[i][0][3];
			fprop[i][0][2] = fk[i][0][4];
			fprop[i][0][5] = fk[i][0][8];
		}
		else if((solid_flags[i][0] == 0) && (solid_flags[i-1][0] == 0) && (solid_flags[i+1][0] == 0))
		{
			fprop[i][0][2] = fk[i][0][4];
			fprop[i][0][5] = fk[i][0][8];
			fprop[i][0][6] = fk[i][0][7];
		}
	}

	fprop[0][0][2] = fk[0][0][4];
	fprop[0][0][6] = fk[0][0][7];
	fprop[0][0][5] = fk[0][0][8];

	fprop[Nx-1][0][2] = fk[Nx-1][0][4];
	fprop[Nx-1][0][6] = fk[Nx-1][0][7];
	fprop[Nx-1][0][5] = fk[Nx-1][0][8];

}


void streaming_boundaries_no_slip_wet_node()
{
	/*Streaming boundaries. No slip nodition applied using non equilibrium bounce back method (wetnode).
	 *Note that boundaries do not take solids at wall into account. This function will need to be modified to
	 *take this into account.*/

	int i;

	int use_equilibrium_scheme    = 0;
	int use_nonequilibrium_scheme = (!use_equilibrium_scheme);

	double rho_upper[Nx];
	double rho_lower[Nx];
	double Nx_upper[Nx];
	double Nx_lower[Nx];


	/*Calculating wall density for wet node approach*/
	for(i = 0; i < Nx; ++i)
	{
		rho_upper[i] = fprop[i][Ny-1][0] + fprop[i][Ny-1][1] + fprop[i][Ny-1][3] + 2 * (fprop[i][Ny-1][2] + fprop[i][Ny-1][5] + fprop[i][Ny-1][6]);
		rho_lower[i] = fprop[i][0][0] + fprop[i][0][1] + fprop[i][0][3] + 2 * (fprop[i][0][4] + fprop[i][0][7] + fprop[i][0][8]);
	}


	/*Correcting for wetnode*/
	for(i = 0; i < Nx; ++i)
	{
		Nx_upper[i] = 0.5 / c * rho_upper[i] * u_wall - 0.5 * (fprop[i][Ny-1][1] - fprop[i][Ny-1][3]) - 0.5 * (feq[i][Ny-1][5] - feq[i][Ny-1][7] + feq[i][Ny-1][8] - feq[i][Ny-1][6]);
		Nx_lower[i] = 0.5 / c * rho_lower[i] * l_wall - 0.5 * (fprop[i][0][1] - fprop[i][0][3]) - 0.5 * (feq[i][0][5] - feq[i][0][7] + feq[i][0][8] - feq[i][0][6]);
	}


	if(use_nonequilibrium_scheme)
	{
		/*Upper boundary*/
		for(i = 0; i < Nx; ++i)
		{
			fprop[i][Ny-1][4] = fprop[i][Ny-1][2] + feq[i][Ny-1][4] - feq[i][Ny-1][2];
			fprop[i][Ny-1][7] = fprop[i][Ny-1][5] + feq[i][Ny-1][7] - feq[i][Ny-1][5] - Nx_upper[i];
			fprop[i][Ny-1][8] = fprop[i][Ny-1][6] + feq[i][Ny-1][8] - feq[i][Ny-1][6] + Nx_upper[i];
		}

		/*Lower Boundary, no slip boundary condition*/
		for(i = 0; i < Nx; ++i)
		{
			fprop[i][0][2] = fprop[i][0][4] + feq[i][0][2] - feq[i][0][4];
			fprop[i][0][5] = fprop[i][0][7] + feq[i][0][5] - feq[i][0][7] + Nx_lower[i];
			fprop[i][0][6] = fprop[i][0][8] + feq[i][0][6] - feq[i][0][8] - Nx_lower[i];
		}
	}
	else if(use_equilibrium_scheme)
	{
		/*Upper boundary*/
		for(i = 0; i < Nx; ++i)
		{
			fprop[i][Ny-1][4] = feq[i][Ny-1][2] * rho_upper[i] / rho[i][Ny-1];
			fprop[i][Ny-1][7] = feq[i][Ny-1][5] * rho_upper[i] / rho[i][Ny-1];
			fprop[i][Ny-1][8] = feq[i][Ny-1][6] * rho_upper[i] / rho[i][Ny-1];
		}

		/*Lower Boundary, no slip boundary condition*/
		for(i = 0; i < Nx; ++i)
		{
			fprop[i][0][4] = feq[i][0][2] * rho_lower[i] / rho[i][0];
			fprop[i][0][7] = feq[i][0][5] * rho_lower[i] / rho[i][0];
			fprop[i][0][8] = feq[i][0][6] * rho_lower[i] / rho[i][0];
		}
	}

}


void streaming_boundaries()
{
	if(free_slip)
	{
		streaming_boundaries_free_slip();
	}
	else if(wet_node)
	{
		streaming_boundaries_no_slip_wet_node();
	}
	else
	{
		streaming_boundaries_no_slip();
	}

	if(solid_boundary_stream_switch)
	{
		streaming_solid_boundaries_ind_parts();
	}
	else
	{
		streaming_solid_boundaries();
	}

}
