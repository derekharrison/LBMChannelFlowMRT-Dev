/*
 * parameters.h
 *
 *  Created on: 19 mei 2017
 *      Author: dharrison
 */


#ifndef PARAMETERS_H_
#define PARAMETERS_H_


#include <stdio.h>
#include <time.h>
#include "types.h"


/*Variable declaration*/
extern int                 i, j, k, timestep;
extern double             vkin, tau, dx, dx_rec, dt, tfinal, ti, rhoo, rhoi, F, maxv;
extern double               Uxi, Uyi;
extern double             avg_vel, max_velocity, max_vorticity;
extern double             ***fk, ***feq, ***fprop, ***fold_step, **rho, **rho_rec, **feqfl, **mass_cons_check, **Ux, **Uy, *w, **vort_field, c, cs;
extern double             **X_coordinates, **Y_coordinates;
extern int              **stream_flags, **solid_flags;
extern double             **momentumy_cons, **momentumx_cons, *Ly, *Ly_wet_node;
extern double             **fk_virt_left, **fk_virt_right;
extern int                 Nx, Ny, timesteps, time_interval_vids, time_interval_data;
extern int                 check_mass_momentum, nonneg_stab_check, free_slip;
extern FILE             *pfile, *datafile, *param_file, *force_res, *data_store_for_restart;
extern double             **ck;
extern N_boundary_nodes    *number_b_nodes;
extern b_location        *b_locations_type_1, *b_locations_type_2, *b_locations_type_3, *b_locations_type_4, *b_locations_type_5, *b_locations_type_6;
extern b_location        *b_locations_type_7, *b_locations_type_8, *b_locations_type_9, *b_locations_type_10, *b_locations_type_11, *b_locations_type_12;
extern B_location_parts *b_location_parts;
extern B_locations_objs *boundary_locations;

extern double             *force_vec_x;
extern double            *Force_solid_x;
extern double            *Force_solid_y;
extern double             **force_vec_x_obj;
extern double            *Force_solid_x_obj;
extern double            *Force_solid_y_obj;

extern int                upper_wall_moving, lower_wall_moving;
extern double             u_wall, l_wall;

extern int                 obstacle_present;
extern double             x_coordinate_circle, y_coordinate_circle, circle_radius;

extern double             Cl, Ct, Crho, Cu, Cvkin;
extern double            **Ux_real, **Uy_real, **rho_real;
extern double            dx_real, width_real, length_real, dt_real;
extern double           rho_avg_real, vkin_real;

extern int                MRT_TRT_BGK_switch, periodic_boundaries_switch, pressure_periodic_switch;
extern double            magic_parameter, omega, omega_min;
extern double             *inlet_velocity,  *outlet_velocity_x, *outlet_velocity_y, u_inlet_max;
extern int                inlet_anti_bb, outlet_anti_bb, prescribed_inlet_vel_bb, inlet_wetnode;
extern int                wet_node;

extern int              mapping_set_up_switch;
extern double             determinant_M, **M, **M_inv, **M_adj, *omega_vec, *moment_vec, *moment_vec_col, *moment_vec_eq, *fk_vec;
extern double             omega_e, omega_eps, omega_q, omega_v;
extern double             omega_v_hermite, omega_z, omega_ga, omega_gb;
extern double              tau_e, tau_v, tau_eps, tau_q;
extern double             v_shear, v_bulk;

extern int                store_limited_time_dep_data, Nx_low, Nx_high, Ny_low, Ny_high, min_timestep, restart_sim;

extern int                 n_particles, particle_number, partice_iter, solid_boundary_stream_switch;

extern char             *data_final_timestep, *data_time_dependent, *parameters, *force_vec_results, *data_store;

extern clock_t             begin, end;
extern double             time_spent;


#endif /* PARAMETERS_H_ */
