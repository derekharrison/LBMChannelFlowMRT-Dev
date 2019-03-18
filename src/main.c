/*
 * LBMChannelFlow-Dev
 *
 * LBM simulation of 2D flow through a channel with solid obstacles
 *
 *  Created on: 17 mei 2017
 *      Author: dharrison
 *
 *      5-6-2017, Modified code to add TRT functionality
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../inc/Collision_and_streaming.h"
#include "../inc/Stability_and_conservation_check.h"
#include "../inc/density_and_velocity.h"
#include "../inc/parameters.h"
#include "../inc/export.h"
#include "../inc/memory_management.h"
#include "../inc/Obstacles.h"
#include "../inc/boundary_nodes.h"
#include "../inc/memory_functions.h"
#include "../inc/moment_and_space_transformations.h"


int main(int argc, char* argv[])
{
    begin = clock();

    /*Declaring parameters*/
    parameter_declaration();


    /*Allocating memory*/
    memory_allocate();


    /*Initialization*/
    initialization();


    /*Placing obstacles*/
    if(obstacle_present)
    {
        Obstacles();
    }


    /*Calculating boundary nodes*/
    calculate_boundary_nodes();


    /*Setting up transformation matrices for MRT*/
    if(mapping_set_up_switch)
    {
        moment_transformation_set_up_hermite();
    }
    else
    {
        moment_transformation_set_up_gram_schmidt();
    }


    /*Performing LBM calculations*/
    for(timestep = 0; timestep < timesteps; ++timestep)
    {
        /*Calculating equilibrium*/
        Calculate_equilibrium();


        /*Collision step*/
        Calculate_collision();


        /*Streaming step central nodes*/
        streaming_internal_nodes();


        /*Streaming boundary nodes*/
        streaming_boundaries();


        /*Calculating rho field*/
        calculating_rho();


        /*Calculating Ux field*/
        calculating_Ux();


        /*Calculating Uy field*/
        calculating_Uy();


        /*Calculating vorticity field*/
        vorticity();


        /*Stability probe*/
        stability_probe();


        /*Check mass and momentum conservation*/
        if(check_mass_momentum)
        {
            mass_momentum_conservation();
        }


        /*Setting nonnegative equilibrium flags*/
        if(nonneg_stab_check)
        {
            set_stability_flags();
        }


        /*Exporting time dependent results at specified intervals*/
        if(store_limited_time_dep_data)
        {
            export_time_dep_data_limited(datafile, Nx_low, Nx_high, Ny_low, Ny_high);
        }
        else
        {
            export_time_dep_data(datafile);
        }

        /*Exporting data for simulation restart*/
        export_data_for_restart(data_store_for_restart);


        /*Temporary mechanism for tracking simulation progress*/
        progress_track_temp();

    }


    /*Exporting data at final timestep*/
    export_final_data(pfile);


    /*Exporting force results*/
    if(solid_boundary_stream_switch)
    {
        export_force_x_results_ind_part(force_res);
    }
    else
    {
        export_force_x_results(force_res);
    }


    /*Exporting parameters*/
    if(store_limited_time_dep_data)
    {
        export_parameters_limited(param_file);
    }
    else
    {
        export_parameters(param_file);
    }


    /*Deallocating memory*/
    memory_deallocate();


    end         = clock();
    time_spent     = (double)(end - begin) / CLOCKS_PER_SEC;


    printf("Run Time: %f\n"             , time_spent);
    printf("particle_number: %i\n"   , particle_number);
    printf("tfinal: %f\n"             , tfinal);
    printf("average velocity %f\n"     , avg_vel);
    printf("kinematic viscosity %f\n", vkin);
    printf("tau %f\n"                 , tau);
    printf("omega_min: %f\n"         , omega_min);

    if(MRT_TRT_BGK_switch == 2)
    {
        printf("kinematic shear viscosity MRT: %f\n" , v_shear);
        printf("kinematic bulk viscosity MRT: %f\n"  , v_bulk);
        printf("kinematic bulk viscosity real: %E\n" , Cvkin * v_bulk);
    }

    return 0;
}
