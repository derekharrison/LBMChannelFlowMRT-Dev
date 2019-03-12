/*
 * export_functions.c
 *
 *  Created on: 26 mei 2017
 *      Author: dharrison
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../inc/parameters.h"


void print_3D_doubles(FILE* pfile, int Nx, int Ny, int Nz, double*** f)
{
    int i, j, n;

    for(n = 0; n < Nz; ++n)
    {
        for(j = Ny - 1;j >= 0 ; --j)
        {
            for(i = 0;i < Nx; ++i)
                fprintf(pfile,"%f    ", f[i][j][n]);
            fprintf(pfile,"\n");
        }
    }

}


void read_3D_doubles(FILE* pfile, int Nx, int Ny, int Nz, double*** f)
{
    int i, j, n;

    for(n = 0; n < Nz; ++n)
    {
        for(j = Ny - 1;j >= 0 ; --j)
        {
            for(i = 0;i < Nx; ++i)
                fscanf(pfile,"%lf    ", &f[i][j][n]);
            fscanf(pfile,"\n");
        }
    }

}


void print_2D_doubles(FILE* pfile, int Nx, int Ny, double** f)
{
    int i, j;

    for(j = Ny - 1;j >= 0 ; --j)
    {
        for(i = 0;i < Nx; ++i)
            fprintf(pfile,"%f    ", f[i][j]);
        fprintf(pfile,"\n");
    }

}


void read_2D_doubles(FILE* pfile, int Nx, int Ny, double** f)
{
    int i, j;

    for(j = Ny - 1;j >= 0 ; --j)
    {
        for(i = 0;i < Nx; ++i)
            fscanf(pfile,"%lf    ", &f[i][j]);
        fscanf(pfile,"\n");
    }

}


void print_2D_int(FILE* pfile, int Nx, int Ny, int** f)
{
    int i, j;

    for(j = Ny - 1;j >= 0 ; --j)
    {
        for(i = 0;i < Nx; ++i)
            fprintf(pfile,"%i    ", f[i][j]);
        fprintf(pfile,"\n");
    }

}


void print_2D_map_of_3D_doubles(FILE* pfile, int Nx, int Ny, int z_index, double*** f)
{
    int i, j;

    for(j = Ny - 1;j >= 0 ; --j)
    {
        for(i = 0;i < Nx; ++i)
            fprintf(pfile,"%f    ", f[i][j][z_index]);
        fprintf(pfile,"\n");
    }

}


void max_velocity_and_vorticity()
{
    max_velocity = 0.0;
    max_vorticity = 0.0;

    double dummy_val_vel = 0.0;
    double dummy_val_vort = 0.0;

    for(i = 0; i < Nx; ++i)
        for(j = 0; j < Ny; ++j)
        {
            dummy_val_vel  = Ux[i][j] * Ux[i][j] + Uy[i][j] * Uy[i][j];
            dummy_val_vort = vort_field[i][j] * vort_field[i][j];

            if(dummy_val_vel > max_velocity)
            {
                max_velocity = dummy_val_vel;
            }

            if(dummy_val_vort > max_vorticity)
            {
                max_vorticity = dummy_val_vort;
            }
        }

    max_velocity  = sqrt(max_velocity);
    max_vorticity = sqrt(max_vorticity);

}


void force_calculations(FILE* pfile) //Needs further development. Force calculated incorrect
{
    int i, j;

    int solid_counter    = 0;
    double Fx_upper      = 0.0;
    double Fx_lower      = 0.0;
    double fluid_force_x = 0.0;
    double avg_density   = 0.0;
    double avg_density_in= 0.0;
    double avg_vel_x     = 0.0;
    double avg_vel_x_in  = 0.0;
    double avg_pressure_inlet  = 0.0;
    double avg_pressure_outlet = 0.0;

    double force_solid_x_real;

    int low_x;
    int high_x;


    /*calculating Reynolds based on inlet v*/
    if(wet_node)
    {
        for(j = 1; j < Ny - 1; ++j)
        {
            avg_vel_x_in   += rho[0][j] * Ux[0][j] * dx;
            avg_density_in += rho[0][j] * dx;
        }

        avg_vel_x_in   += rho[0][0] * Ux[0][0] * 0.5 * dx;
        avg_density_in += rho[0][0] * 0.5 * dx;

        avg_vel_x_in   += rho[0][Ny-1] * Ux[0][Ny-1] * 0.5 * dx;
        avg_density_in += rho[0][Ny-1] * 0.5 * dx;

        avg_density_in = avg_density_in / ((Ny - 2) * dx + dx);
        avg_vel_x_in = avg_vel_x_in / (avg_density_in * ((Ny - 2) * dx + dx));
    }
    else
    {
        for(j = 0; j < Ny; ++j)
        {
            avg_vel_x_in   += rho[0][j] * Ux[0][j] * dx;
            avg_density_in += rho[0][j] * dx;
        }

        avg_density_in = avg_density_in / (Ny * dx);
        avg_vel_x_in = avg_vel_x_in / (avg_density_in * (Ny * dx));
    }

    /*Calculating limits for density calculations*/ //calculating limits this way adversely affects Reynolds number
    if(obstacle_present)
    {
        low_x  = 0; //(int) (x_coordinate_circle - 2 * circle_radius);
        high_x = Nx;//(int) (x_coordinate_circle + 2 * circle_radius);
    }
    else
    {
        low_x  = 0;
        high_x = Nx;
    }


    /*Channel wall force calculations*/
    for(i = 0; i < Nx; ++i)
    {
        Fx_upper += ((fprop[i][Ny-1][8] * ck[8][0] + fprop[i][Ny-1][7] * ck[7][0]) -
                    (fold_step[i][Ny-1][5] * ck[5][0] + fold_step[i][Ny-1][6] * ck[6][0]));
        Fx_lower += ((fprop[i][0][5] * ck[5][0] + fprop[i][0][6] * ck[6][0]) -
                    (fold_step[i][0][8] * ck[8][0] + fold_step[i][0][7] * ck[7][0]));
    }


    /*Fluid and solid boundary force calculations*/
    for(i = low_x; i < high_x; ++i)
        for(j = 0; j < Ny; ++j)
        {
            if(solid_flags[i][j] == 0)
            {
                avg_density         += rho[i][j];
                avg_vel_x            += rho[i][j] * Ux[i][j] * dx;
                solid_counter++;
            }
        }


    /*Calculating force on fluid*/
    for(i = 0; i < Nx; ++i)
        for(j = 0; j < Ny; ++j)
        {
            if(solid_flags[i][j] == 0)
            {
                fluid_force_x       += F;
            }
        }

    avg_density = avg_density / (solid_counter);
    avg_vel_x   = avg_vel_x / (solid_counter * avg_density * dx);


    /*Calculating pressure averages and max velocity*/
    for(j = 0; j < Ny; ++j)
    {
        avg_pressure_inlet                     += rho[0][j];
        avg_pressure_outlet                    += rho[Nx-1][j];
    }

    avg_pressure_inlet  = cs * cs * avg_pressure_inlet / (Ny);
    avg_pressure_outlet = cs * cs * avg_pressure_outlet / (Ny);


    /*Calculating density unit conversion*/
    Crho = rho_avg_real / avg_density;


    /*Calculating real data*/
    for(i = 0; i < Nx; ++i)
        for(j = 0; j < Ny; ++j)
        {
            if(solid_flags[i][j] == 0)
            {
                rho_real[i][j] = rho[i][j] * Crho;
                Ux_real[i][j]  = Ux[i][j] * Cu;
                Uy_real[i][j]  = Uy[i][j] * Cu;
            }
        }

    force_solid_x_real = *Force_solid_x * Crho * Cl * Cl * Cl / (Ct * Ct);


    /*Exporting results*/
    fprintf(pfile,"Cl: %f\n", Cl);
    fprintf(pfile,"Cu: %f\n", Cu);
    fprintf(pfile,"Crho: %f\n", Crho);
    fprintf(pfile,"Ct: %f\n", Ct);
    fprintf(pfile,"solid counter: %i\n", solid_counter);
    fprintf(pfile,"average density: %f\n", avg_density);
    fprintf(pfile,"average velocity x: %f\n", avg_vel_x);
    fprintf(pfile,"average density based on inlet: %f\n", avg_density_in);
    fprintf(pfile,"average velocity x based on inlet: %f\n", avg_vel_x_in);
    fprintf(pfile,"Force in x direction along upper wall: %f\n", Fx_upper);
    fprintf(pfile,"Force in x direction along lower wall: %f\n", Fx_lower);
    fprintf(pfile,"Total force in x direction acting on fluid: %f\n", fluid_force_x);
    fprintf(pfile,"Total pressure force in x direction acting on fluid: %f\n", (avg_pressure_inlet - avg_pressure_outlet) * Ny * dx);
    fprintf(pfile,"Total pressure force in x direction acting on fluid, wetnode: %f\n", (avg_pressure_inlet - avg_pressure_outlet) * (Ny - 1) * dx);
    fprintf(pfile,"Total pressure force in x direction acting on fluid inlet anti bb: %f\n", (rhoi - rhoo) * Ny * dx * cs * cs);
    fprintf(pfile,"ratio pressure force to shear force at walls: %f\n", -(avg_pressure_inlet - avg_pressure_outlet) * Ny * dx / (Fx_upper + Fx_lower));
    fprintf(pfile,"ratio pressure force to shear force at walls, inlet anti bb: %f\n", -(rhoi - rhoo) * Ny * dx * cs * cs / (Fx_upper + Fx_lower));
    fprintf(pfile,"ratio pressure force to shear force at walls and solid: %f\n", -(avg_pressure_inlet - avg_pressure_outlet) * Ny * dx / (Fx_upper + Fx_lower + *Force_solid_x));
    fprintf(pfile,"ratio pressure force to shear force at walls and solid, inlet anti bb: %f\n", -(rhoi - rhoo) * Ny * dx * cs * cs / (Fx_upper + Fx_lower + *Force_solid_x));
    fprintf(pfile,"ratio pressure force to shear force at walls and solid, wetnode: %f\n", -(avg_pressure_inlet - avg_pressure_outlet) * (Ny - 1) * dx / (Fx_upper + Fx_lower + *Force_solid_x));

    if(obstacle_present)
    {
        fprintf(pfile,"\n");
        fprintf(pfile,"Reynolds solid body based on inlet: %f\n", avg_vel_x_in * 2 * circle_radius / vkin);
        fprintf(pfile,"Drag force coefficient Cd based on inlet: %f\n", *Force_solid_x / (0.5 * avg_vel_x_in * avg_vel_x_in  * avg_density_in * 2 * circle_radius));
        fprintf(pfile,"Reynolds solid body: %f\n", avg_vel_x * 2 * circle_radius / vkin);
        fprintf(pfile,"Drag force coefficient Cd real: %f\n", force_solid_x_real / (0.5 * Cu * avg_vel_x * Cu * avg_vel_x  * rho_avg_real * 2 * Cl * circle_radius));
        fprintf(pfile,"Drag force coefficient Cd: %f\n", *Force_solid_x / (0.5 * avg_vel_x * avg_vel_x  * avg_density * 2 * circle_radius));
        fprintf(pfile,"Drag force coefficient Cd based on net fluid force: %f\n", (fluid_force_x + (Fx_upper + Fx_lower)) / (0.5 * avg_vel_x * avg_vel_x  * avg_density * 2 * circle_radius));
        fprintf(pfile,"Drag force coefficient Cd based on net pressure force: %f\n", ((avg_pressure_inlet - avg_pressure_outlet) * Ny * dx + (Fx_upper + Fx_lower)) / (0.5 * avg_vel_x * avg_vel_x  * avg_density * 2 * circle_radius));
        fprintf(pfile,"Drag force coefficient Cd based on net pressure force, anti bb: %f\n", ((rhoi - rhoo) * Ny * dx * cs * cs + (Fx_upper + Fx_lower)) / (0.5 * avg_vel_x * avg_vel_x  * avg_density * 2 * circle_radius));
        fprintf(pfile,"Total force acting on solid in x direction: %f\n", *Force_solid_x);
        fprintf(pfile,"Total force acting on solid in y direction: %f\n", *Force_solid_y);
        fprintf(pfile,"Stokes force acting on solid x direction: %f\n", 6 * avg_density * vkin * M_PI * circle_radius * avg_vel_x);
        fprintf(pfile,"Oseen force acting on solid x direction: %f\n", (6 * avg_density * vkin * M_PI * circle_radius * avg_vel_x * (1.0 + 3.0 * vkin * circle_radius * avg_vel_x / 8.0)));
        fprintf(pfile,"Total force acting on solid and walls in x direction: %f\n", *Force_solid_x + Fx_lower + Fx_upper);
        fprintf(pfile,"Total force on solid in x direction, stokes normalized: %f\n", *Force_solid_x / (6 * avg_density * vkin * M_PI * circle_radius * avg_vel_x * (1.0 + 3.0 * vkin * circle_radius * avg_vel_x / 8.0)));
        fprintf(pfile,"Total fluid force in x direction, stokes normalized: %f\n", *Force_solid_x / (6 * avg_density * vkin * M_PI * circle_radius * avg_vel_x * (1.0 + 3.0 * vkin * circle_radius * avg_vel_x / 8.0)));

        fprintf(pfile, "\n");

        for(i = 0; i < n_particles; ++i)
            fprintf(pfile,"Force acting on obstacle %i in x direction: %f\n", i, Force_solid_x_obj[i]);

        for(i = 0; i < n_particles; ++i)
            fprintf(pfile,"Force acting on obstacle %i in y direction: %f\n", i, Force_solid_y_obj[i]);
    }

}

void compare_analytical_solution_poiseulle(FILE* pfile, int Nx, int Ny, double** Ux)
{
    avg_vel = 0.0;
    maxv     = 0.0;
    double avg_pressure_inlet  = 0.0;
    double avg_pressure_outlet = 0.0;
    double avg_vel_x_in        = 0.0;
    double avg_density_in      = 0.0;

    double analytical_solution_non_dim[Ny];
    double analytical_solution[Ny];
    double analytical_solution_wetnode[Ny];
    double analytical_solution_wetnode_non_dim[Ny];
    double analytical_solution_pressure_driven[Ny];


    /*calculating Reynolds based on inlet v*/
    for(j = 1; j < Ny - 1; ++j)
    {
        avg_vel_x_in   += rho[0][j] * Ux[0][j] * dx;
        avg_density_in += rho[0][j] * dx;
    }

    avg_vel_x_in   += rho[0][0] * Ux[0][0] * 0.5 * dx;
    avg_density_in += rho[0][0] * 0.5 * dx;

    avg_vel_x_in   += rho[0][Ny-1] * Ux[0][Ny-1] * 0.5 * dx;
    avg_density_in += rho[0][Ny-1] * 0.5 * dx;


    avg_density_in = avg_density_in / ((Ny - 2) * dx + dx);
    avg_vel_x_in = avg_vel_x_in / (avg_density_in * ((Ny - 2) * dx + dx));


    /*Calculating averages and max velocity*/
    for(j = 0; j < Ny; ++j)
    {
        avg_pressure_inlet                     += rho[0][j];
        avg_pressure_outlet                    += rho[Nx-1][j];
        avg_vel                                += Ux[Nx/2][j]*dx;

        if(Ux[Nx/2][j] > maxv)
        {
            maxv = Ux[Nx/2][j];
        }
    }

    avg_vel             = avg_vel / (Ny * dx);
    avg_pressure_inlet  = cs * cs * avg_pressure_inlet / (Ny);
    avg_pressure_outlet = cs * cs * avg_pressure_outlet / (Ny);


    /*Calculating analytical solutions*/
    for(j = 0; j < Ny; ++j)
    {
        analytical_solution_non_dim[j]         = 4 * (Ly[j] / (Ny * dx) - Ly[j] * Ly[j] / (Ny * dx * Ny * dx));
        analytical_solution[j]                 = (0.5 / vkin) * F * (Ny * dx * Ly[j] - Ly[j] * Ly[j]);
        analytical_solution_wetnode[j]         = (0.5 / vkin) * F * ((Ny - 1) * dx * Ly_wet_node[j] - Ly_wet_node[j] * Ly_wet_node[j]) + 0.5 * F;
        analytical_solution_wetnode_non_dim[j] = 4 * (Ly_wet_node[j] / ((Ny - 1) * dx) - Ly_wet_node[j] * Ly_wet_node[j] / ((Ny - 1) * dx * (Ny - 1) * dx)); //Note this implementation is incorrect for second order force model

        if(prescribed_inlet_vel_bb)
        {
            analytical_solution_pressure_driven[j] = (0.5 / vkin) * ((avg_pressure_inlet - avg_pressure_outlet) / ((Nx - 1) * dx)) * (Ny * dx * Ly[j] - Ly[j] * Ly[j]);
        }
        else if(inlet_anti_bb)
        {
            analytical_solution_pressure_driven[j] = (0.5 / vkin) * ((rhoi - rhoo) * cs * cs / (Nx * dx)) * (Ny * dx * Ly[j] - Ly[j] * Ly[j]);
        }
        else
        {
            analytical_solution_pressure_driven[j] = inlet_velocity[j];
        }
    }

    fprintf(pfile,"\nratio average poiseulle flow to max flow, wetnode: %f\n", avg_vel_x_in / maxv);
    fprintf(pfile,"\nratio average poiseulle flow to max flow: %f\n", avg_vel / maxv);

    fprintf(pfile,"\n\n    Ly        ");
    fprintf(pfile,"analytical    ");
    fprintf(pfile,"ana wetnode    ");
    fprintf(pfile,"analytical pressure    ");
    fprintf(pfile,"numerical    ");
    fprintf(pfile,"y/(Ny*dx)    ");
    fprintf(pfile,"ana nondim    ");
    fprintf(pfile,"num nondim    ");
    fprintf(pfile,"wet ana ndim    ");
    fprintf(pfile,"error\n");

    for(j = Ny - 1;j >= 0 ; --j)
    {
        fprintf(pfile,"Y: %f    ", Ly[j]);
        fprintf(pfile,"%f    ", analytical_solution[j]);
        fprintf(pfile,"%f    ", analytical_solution_wetnode[j]);
        fprintf(pfile,"%f    ", analytical_solution_pressure_driven[j]);
        fprintf(pfile,"%.8f    ", Ux[Nx/2][j]);
        fprintf(pfile,"%f    ", Ly[j] / (Ny * dx));
        fprintf(pfile,"%f    ", analytical_solution_non_dim[j]);
        fprintf(pfile,"%f    ", Ux[Nx/2][j]/(maxv));
        fprintf(pfile,"%f    ", analytical_solution_wetnode_non_dim[j]);
        fprintf(pfile,"%f\n", 100 * (1.0 - Ux[Nx/2][j] / analytical_solution[j]));
    }

}


void compare_analytical_solution_couette(FILE* pfile, int Nx, int Ny, double** Ux)
{
    int j, n, trunc_series;

    double t;
    double phi[Ny], eta[Ny];

    trunc_series = 100;
    t              = vkin * timesteps * dt / (Ny * dx * Ny * dx);

    /*Dimensionless distance*/
    for(j = 0; j < Ny; ++j)
    {
        eta[j] = Ly[j] / (Ny * dx);
        phi[j] = (1 - eta[j]);
    }

    /*Dimensionless velocity*/
    for(j = 0; j < Ny; ++j)
        for(n = 1; n < trunc_series; ++n)
        {
            phi[j] -= (2 / (n * M_PI) * exp(-n * n * M_PI * M_PI * t)) * sin(n * M_PI * eta[j]);
        }

    fprintf(pfile,"y/(Ny*dx)    ");
    fprintf(pfile,"ana nondim    ");
    fprintf(pfile,"num nondim    ");
    fprintf(pfile,"error percent\n");

    for(j = Ny - 1;j >= 0 ; --j)
    {
        fprintf(pfile,"%f    ", Ly[j] / (Ny * dx));
        fprintf(pfile,"%f    ", phi[j]);
        fprintf(pfile,"%f    ", Ux[Nx/2][j] / l_wall);
        fprintf(pfile,"%f\n", 100 * (1 - (Ux[Nx/2][j] / l_wall) / phi[j]));
    }

}
