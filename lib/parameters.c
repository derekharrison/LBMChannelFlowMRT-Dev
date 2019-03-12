/*
 * parameters.c
 *
 *  Created on: 20 mei 2017
 *      Author: dharrison
 */


#include <stdio.h>
#include <time.h>
#include "../inc/types.h"


int              i, j, k, timestep;
double           vkin, tau, dx, dx_rec, dt, tfinal, ti, rhoo, rhoi, F, maxv;
double           Uxi, Uyi;
double           avg_vel, max_velocity, max_vorticity;
double           ***fk, ***feq, ***fprop, ***fold_step, **rho, **rho_rec, **feqfl, **mass_cons_check, **Ux, **Uy, *w, **vort_field, c, cs;
double              **X_coordinates, **Y_coordinates;
int              **stream_flags, **solid_flags;
double           **momentumy_cons, **momentumx_cons, *Ly, *Ly_wet_node;
double           **fk_virt_left, **fk_virt_right;
int              Nx, Ny, timesteps, time_interval_vids, time_interval_data;
int              check_mass_momentum, nonneg_stab_check, free_slip;
FILE             *pfile, *datafile, *param_file, *force_res, *data_store_for_restart;
N_boundary_nodes *number_b_nodes;
b_location          *b_locations_type_1, *b_locations_type_2, *b_locations_type_3, *b_locations_type_4, *b_locations_type_5, *b_locations_type_6;
b_location           *b_locations_type_7, *b_locations_type_8, *b_locations_type_9, *b_locations_type_10, *b_locations_type_11, *b_locations_type_12;
B_location_parts *b_location_parts;
B_locations_objs *boundary_locations;

double              *force_vec_x;
double             *Force_solid_x;
double             *Force_solid_y;
double              **force_vec_x_obj;
double             *Force_solid_x_obj;
double             *Force_solid_y_obj;
double           **ck;

int                 upper_wall_moving, lower_wall_moving;
double              u_wall, l_wall;

int              obstacle_present;
double           x_coordinate_circle, y_coordinate_circle, circle_radius;

double              Cl, Ct, Crho, Cu, Cvkin;
double              **Ux_real, **Uy_real, **rho_real;
double              dx_real, width_real, length_real, dt_real;
double           rho_avg_real, vkin_real;

int                 MRT_TRT_BGK_switch, periodic_boundaries_switch, pressure_periodic_switch;
double             magic_parameter, omega, omega_min;
double              *inlet_velocity, *outlet_velocity_x, *outlet_velocity_y, u_inlet_max;
int                 inlet_anti_bb, outlet_anti_bb, prescribed_inlet_vel_bb, inlet_wetnode;
int                 wet_node;

int              mapping_set_up_switch;
double              determinant_M, **M, **M_inv, **M_adj, *omega_vec, *moment_vec, *moment_vec_col, *moment_vec_eq, *fk_vec;
double              omega_e, omega_eps, omega_q, omega_v;
double              omega_v_hermite, omega_z, omega_ga, omega_gb;
double           tau_e, tau_v, tau_eps, tau_q;
double              v_shear, v_bulk;

int              store_limited_time_dep_data, Nx_low, Nx_high, Ny_low, Ny_high, min_timestep, restart_sim;

char              *data_final_timestep, *data_time_dependent, *parameters, *force_vec_results, *data_store;

int              n_particles, particle_number, partice_iter, solid_boundary_stream_switch;

clock_t          begin, end;
double           time_spent;
