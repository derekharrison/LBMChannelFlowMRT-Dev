/*
 * parameter_declaration.c
 *
 *  Note: all parameters are global
 *
 *  Created on: 19 mei 2017
 *      Author: dharrison
 */


#include <math.h>
#include "../inc/parameters.h"


void parameter_declaration()
{
    /*Grid and lattice parameters*/
    Nx                 = 1290;
    Ny                 = 1410;
    ti                 = 0.0;
    timesteps          = 60000;
    time_interval_vids = 100;
    time_interval_data = 1000;
    min_timestep       = 0;


    /*Restart simulation by setting restart_sim to 1. Simulations can be restarted with data from previous simulation*/
    restart_sim = 0;


    /*Lattice physical parameters*/
    dt   = 1.0;
    dx   = 1.0;
    rhoo = 1.0;
    rhoi = 1.0;
    F    = 0.0;


    /*Setting initial lattice velocities*/
    Uxi = 0.0;
    Uyi = 0.0;


    /*Defined physical parameters*/
    rho_avg_real = 1.0;
    width_real   = 0.41;
    vkin_real    = 0.001;


    /*Periodic boundaries switch. 1 for periodic boundaries and else for specified inlet velocity and outlet pressure.
     *If periodic boundaries are used the pressure_periodic_switch can be used to specify if pressure driven periodic
     *flow is to be used. If pressure_periodic_switch = 1, flow is pressure driven. Otherwise the flow is force driven.*/
    periodic_boundaries_switch = 0;
    pressure_periodic_switch   = 0;


    /*For free slip at channel wall set free_slip to 1. Else no slip boundary conditions are used if wet_node = 0.*/
    free_slip = 0;


    /*Use wet node. 1 for wetnode and 0 for BB*/
    wet_node = 0;


    /*Moving channel walls, BB*/
    upper_wall_moving = 0;
    u_wall            = 0.0;
    lower_wall_moving = 0;
    l_wall            = 0.0;


    /*Setting inlet and outlet non periodic boundaries. These are only used if no periodic boundaries are used, i.e.:
     * if periodic_boundaries_switch = 0.*/
    inlet_anti_bb           = 0;
    inlet_wetnode            = 1;
    prescribed_inlet_vel_bb = 0;

    outlet_anti_bb          = 1;


    /*If inlet wetnode, max inlet velocity for inlet parabolic profile can be specified with u_inlet_max*/
    u_inlet_max = 0.26;


    /*Collision operator switch. 2 for MRT, 1 for TRT and else for BGK. Note, TRT seems unstable when wetnode boundaries are used.*/
    MRT_TRT_BGK_switch = 1;


    /*Mapping MRT switch. 1 for Hermite approach, 0 for Gram-Schmidt*/
    mapping_set_up_switch = 0;


    /*Relaxation parameters BGK and TRT*/
    tau             = 0.6; //sqrt(13.0 / 64) + 5.0 / 8;
    magic_parameter = 3.0 / 16;


    /*Relaxation parameters MRT Gram-Schmidt*/
    tau_v = 0.6;
    tau_e = 0.6;


    /*Free parameters MRT Gram-Schmidt*/
    tau_eps = 1.0 / 1.14;
    tau_q   = 1.0 / 1.92;


    /*Solid obstacle present*/
    obstacle_present = 1;


    /*Switch for force calculations on all particles, or individual particles. 1 for individual force, else for collective force*/
    solid_boundary_stream_switch = 1;


    /*number of obstacles present. The code crashes if n_particles is not equal to actual number of particles, even if standard force cal
     *is used. Need to prevent this behaviour.*/
    n_particles = 5;


    /*Setting debug flags. Flags check conservation of stability and conservation of mass and momentum*/
    check_mass_momentum = 0;
    nonneg_stab_check   = 0;


    /*For large domain sizes, limit the time dependent data to be stored for visualization. Set store_limited_time_dep_data = 0
     *To prevent limit of domain sample for visualization*/
    store_limited_time_dep_data = 1;

    Nx_low  = (int) (13.5 * 30 - 50);
    Nx_high = (int) (13.5 * 30 + 450);
    Ny_low  = (int) (0.5 * Ny - 125);
    Ny_high = (int) (0.5 * Ny + 125);


    /*File names for data export*/
    data_final_timestep = "./SimData/data_final_timestep.txt";
    data_time_dependent = "./SimData/data_time_dependent";
    parameters          = "./SimData/parameters.txt";
    force_vec_results   = "./SimData/force_vec_results";
    data_store          = "./SimData/data_store_for_sim_cont.txt";
}
