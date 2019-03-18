/*
 * intialization.c
 *
 *  Created on: 19 mei 2017
 *      Author: dharrison
 */


#include <math.h>
#include "../inc/parameters.h"
#include "../inc/export.h"


void initialization()
{
    /*Initializing particle count*/
    particle_number = 0;


    /*Relaxation parameters BGK*/
    omega     = 1.0 / tau;
    omega_min = 1.0 / ((magic_parameter / (1.0 / (omega * dt) - 0.5) + 0.5) * dt);


    /*Relaxation parameters MRT Gram-Schmidt*/
    omega_e = 1.0 / tau_e;
    omega_v = 1.0 / tau_v;

    omega_eps = 1.0 / tau_eps;
    omega_q   = 1.0 / tau_q;


    /*Calculated parameters*/
    c  = dx / dt;
    cs = 1.0 / sqrt(3);

    tfinal = timesteps * dt + ti;
    vkin   = cs * cs * (1.0 / (omega * dt) - 0.5);
    dx_rec = 1.0 / dx;


    /*Calculating kinematic viscosity for MRT Gram-Schmidt*/
    v_shear = cs * cs * (1.0 / omega_v - 0.5);
    v_bulk  = cs * cs * (1.0 / omega_e - 0.5) - v_shear / 3.0;


    /*Calculated physical parameters*/
    dx_real = dx * width_real / (Ny * dx);
    dt_real = vkin * dx_real * dx_real / vkin_real;
    length_real = Nx * dx * width_real / (Ny * dx);


    /*Calculating unit conversions*/
    Cl    = width_real / (Ny * dx);
    Ct    = dt_real / dt;
    Cu    = Cl / Ct;
    Cvkin = Cl * Cl / Ct;


    /*Initialize weights*/
    w[0] = 4.0 / 9;
    w[1] = w[2] = w[3] = w[4] = 1.0 / 9;
    w[5] = w[6] = w[7] = w[8] = 1.0 / 36;


    /*Initialize streaming velocities*/
    ck[0][0] = 0.0; ck[0][1] = 0.0;
    ck[1][0] = c  ; ck[1][1] = 0.0;
    ck[2][0] = 0.0; ck[2][1] = c;
    ck[3][0] = -c ; ck[3][1] = 0.0;
    ck[4][0] = 0.0; ck[4][1] = -c;
    ck[5][0] = c  ; ck[5][1] = c;
    ck[6][0] = -c ; ck[6][1] = c;
    ck[7][0] = -c ; ck[7][1] = -c;
    ck[8][0] = c  ; ck[8][1] = -c;


    /*Initialize relaxation parameter vector for MRT collision operator.
     *Start by setting relaxation moments of even order to omega and odd order to omega_min (the relaxation
     *parameters used in TRT operator). Then optimize free parameters*/
    if(mapping_set_up_switch)
    {
        omega_vec[0] = 0;
        omega_vec[1] = omega_min;
        omega_vec[2] = omega_min;
        omega_vec[3] = omega;
        omega_vec[4] = omega;
        omega_vec[5] = omega;
        omega_vec[6] = omega_min;
        omega_vec[7] = omega_min;
        omega_vec[8] = omega;
    }
    else
    {
        omega_vec[0] = 0.0;
        omega_vec[1] = omega;//omega_e;
        omega_vec[2] = omega;//omega_eps;
        omega_vec[3] = 0.0;
        omega_vec[4] = omega_min;//omega_q;
        omega_vec[5] = 0.0;
        omega_vec[6] = omega_min;//omega_q;
        omega_vec[7] = omega;//omega_v;
        omega_vec[8] = omega;//omega_v;
    }


    /*Initialize coordinates along y for analytical comparison*/
    for(j = 0; j < Ny; ++j)
    {
        Ly[j] = j * dx + 0.5 * dx;
        Ly_wet_node[j] = j * dx;
    }


    /*Initializing inlet velocity for prescribed inlet velocity condition*/
    for(j = 0; j < Ny; ++j)
    {
        //inlet_velocity[j] = 0.25 * 4 * (Ly[j] / (Ny * dx) - Ly[j] * Ly[j] / (Ny * dx * Ny * dx));
        if(inlet_anti_bb)
        {
            inlet_velocity[j] = (0.5 / vkin) * ((rhoi - rhoo) / (Nx * dx)) * (Ny * dx * Ly[j] - Ly[j] * Ly[j]) / 3.0;
        }
        else if(inlet_wetnode && wet_node)
        {
            inlet_velocity[j] = u_inlet_max * 4 * (Ly_wet_node[j] / ((Ny - 1) * dx) - Ly_wet_node[j] * Ly_wet_node[j] / ((Ny - 1) * dx * (Ny - 1) * dx));
        }
        else if(inlet_wetnode && !wet_node)
        {
            inlet_velocity[j] = u_inlet_max * 4 * (Ly[j] / (Ny * dx) - Ly[j] * Ly[j] / (Ny * dx * Ny * dx));
        }
        else
        {
            inlet_velocity[j] = (0.5 / vkin) * ((rhoi - rhoo) / (Nx * dx)) * (Ny * dx * Ly[j] - Ly[j] * Ly[j]) / 3.0; //u_inlet_max * 4 * (Ly[j] / (Ny * dx) - Ly[j] * Ly[j] / (Ny * dx * Ny * dx));
        }
    }


    /*Initializing density and reciprocal of density*/
    if(periodic_boundaries_switch)
    {
        for(i = 0; i < Nx; ++i)
            for(j = 0; j < Ny; ++j)
            {
                rho[i][j] = (i + 1) * (rhoo - rhoi)/(Nx + 1) * 1.0 + rhoi;
                rho_rec[i][j] = 1.0 / rho[i][j];
            }
    }
    else
    {
        for(i = 0; i < Nx; ++i)
            for(j = 0; j < Ny; ++j)
            {
                rho[i][j] = (i) * (rhoo - rhoi)/(Nx - 1) * 1.0 + rhoi;
                rho_rec[i][j] = 1.0 / rho[i][j];
            }
    }


    /*Initializing stability check flags*/
    for(i = 0; i < Nx; ++i)
        for(j = 0; j < Ny; ++j)
            feqfl[i][j] = 0.0;


    /*Initializing mass conservation check flags*/
    for(i = 0; i < Nx; ++i)
        for(j = 0; j < Ny; ++j)
            mass_cons_check[i][j] = 0.0;


    /*Initializing stream flags*/
    for(i = 0; i < Nx; ++i)
        for(j = 0; j < Ny; ++j)
            stream_flags[i][j] = 1;


    /*Initializing solids flags*/
    for(i = 0; i < Nx; ++i)
        for(j = 0; j < Ny; ++j)
            solid_flags[i][j] = 0;


    /*Initialize x velocity component*/
    for(i = 0; i < Nx; ++i)
        for(j = 0; j < Ny; ++j)
            Ux[i][j] = Uxi;//(0.5 / vkin) * F * ((Ny - 1) * dx * Ly_wet_node[j] - Ly_wet_node[j] * Ly_wet_node[j]);//Uxi; //(0.5 / vkin) * F * (Ny * dx * Ly[j] - Ly[j] * Ly[j]);


    /*Initializing vorticity field flags*/
    for(i = 0; i < Nx; ++i)
        for(j = 0; j < Ny; ++j)
            vort_field[i][j] = 0.0;


    /*Initialize y velocity component*/
    for(i = 0; i < Nx; ++i)
        for(j = 0; j < Ny; ++j)
            Uy[i][j] = Uyi;


    /*Initializing velocity distributions*/
    for(i = 0; i < Nx; ++i)
        for(j = 0; j < Ny; ++j)
            for(k = 0; k < 9; ++k)
            {
                fk[i][j][k]    = w[k]*rho[i][j];
                feq[i][j][k]   = w[k]*rho[i][j];
                fprop[i][j][k] = w[k]*rho[i][j];
                fold_step[i][j][k] = w[k]*rho[i][j];
            }


    /*If simulations are restarted, overwrite data for Ux, Uy, rho, fk and fprop to continue simulation with data from previous run*/
    if(restart_sim)
    {
        read_data_for_restart(data_store_for_restart);
    }


    /*Initializing X and Y coordinate map*/
    for(i = 0; i < Nx; ++i)
        for(j = 0; j < Ny; ++j)
        {
            X_coordinates[i][j] = i * dx + 0.5;
            Y_coordinates[i][j] = j * dx + 0.5;
        }

}
