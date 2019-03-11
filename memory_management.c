/*
 * memory_management.c
 *
 *  Created on: 19 mei 2017
 *      Author: dharrison
 */


#include "memory_functions.h"
#include "parameters.h"


void memory_allocate()
{
	fk                = Memory_alloc_3D(Nx, Ny, 9);
	feq               = Memory_alloc_3D(Nx, Ny, 9);
	fprop             = Memory_alloc_3D(Nx, Ny, 9);
	fold_step		  = Memory_alloc_3D(Nx, Ny, 9);
	feqfl             = Memory_alloc_2D(Nx, Ny);
	mass_cons_check   = Memory_alloc_2D(Nx, Ny);
	momentumy_cons    = Memory_alloc_2D(Nx, Ny);
	momentumx_cons    = Memory_alloc_2D(Nx, Ny);
	rho               = Memory_alloc_2D(Nx, Ny);
	rho_rec           = Memory_alloc_2D(Nx, Ny);
	Ux                = Memory_alloc_2D(Nx, Ny);
	Uy                = Memory_alloc_2D(Nx, Ny);
	Ux_real           = Memory_alloc_2D(Nx, Ny);
	Uy_real           = Memory_alloc_2D(Nx, Ny);
	rho_real          = Memory_alloc_2D(Nx, Ny);
	X_coordinates     = Memory_alloc_2D(Nx, Ny);
	Y_coordinates     = Memory_alloc_2D(Nx, Ny);
	vort_field        = Memory_alloc_2D(Nx, Ny);
	M			      = Memory_alloc_2D(9, 9);
	M_inv             = Memory_alloc_2D(9, 9);
	M_adj             = Memory_alloc_2D(9, 9);
	stream_flags      = Memory_alloc_2D_int(Nx, Ny);
	solid_flags       = Memory_alloc_2D_int(Nx, Ny);
	ck                = Memory_alloc_2D(9, 2);
	w                 = Memory_alloc_1D(9);
	omega_vec         = Memory_alloc_1D(9);
	moment_vec        = Memory_alloc_1D(9);
	moment_vec_col    = Memory_alloc_1D(9);
	moment_vec_eq     = Memory_alloc_1D(9);
	fk_vec            = Memory_alloc_1D(9);
	Ly                = Memory_alloc_1D(Ny);
	Ly_wet_node       = Memory_alloc_1D(Ny);
	inlet_velocity    = Memory_alloc_1D(Ny);
	outlet_velocity_x = Memory_alloc_1D(Ny);
	outlet_velocity_y = Memory_alloc_1D(Ny);
    number_b_nodes    = Memory_alloc_struct();
	fk_virt_left      = Memory_alloc_2D(Ny, 9);
	fk_virt_right     = Memory_alloc_2D(Ny, 9);
	force_vec_x       = Memory_alloc_1D(timesteps);
	Force_solid_x     = Memory_alloc_1D(1);
	Force_solid_y     = Memory_alloc_1D(1);
	Force_solid_x_obj = Memory_alloc_1D(n_particles);
	Force_solid_y_obj = Memory_alloc_1D(n_particles);
	force_vec_x_obj   = Memory_alloc_2D(n_particles, timesteps);

	b_locations_type_1  = Memory_alloc_1D_struct_array((Nx / 2) * Ny);
	b_locations_type_2  = Memory_alloc_1D_struct_array((Nx / 2) * Ny);
	b_locations_type_3  = Memory_alloc_1D_struct_array((Nx / 2) * Ny);
	b_locations_type_4  = Memory_alloc_1D_struct_array((Nx / 2) * Ny);
	b_locations_type_5  = Memory_alloc_1D_struct_array((Nx / 2) * Ny);
	b_locations_type_6  = Memory_alloc_1D_struct_array((Nx / 2) * Ny);
	b_locations_type_7  = Memory_alloc_1D_struct_array((Nx / 2) * Ny);
	b_locations_type_8  = Memory_alloc_1D_struct_array((Nx / 2) * Ny);
	b_locations_type_9  = Memory_alloc_1D_struct_array((Nx / 2) * Ny);
	b_locations_type_10 = Memory_alloc_1D_struct_array((Nx / 2) * Ny);
	b_locations_type_11 = Memory_alloc_1D_struct_array((Nx / 2) * Ny);
	b_locations_type_12 = Memory_alloc_1D_struct_array((Nx / 2) * Ny);

	boundary_locations  = Mem_alloc_boundary_location_struct_mult_obj(n_particles, 12, (Nx / 2) * Ny);

}


void memory_deallocate()
{
	Memory_dealloc_3D(Nx, Ny, fk);
	Memory_dealloc_3D(Nx, Ny, feq);
	Memory_dealloc_3D(Nx, Ny, fprop);
	Memory_dealloc_3D(Nx, Ny, fold_step);
	Memory_dealloc_2D(Nx, rho);
	Memory_dealloc_2D(Nx, feqfl);
	Memory_dealloc_2D(Nx, mass_cons_check);
	Memory_dealloc_2D(Nx, momentumy_cons);
	Memory_dealloc_2D(Nx, momentumx_cons);
	Memory_dealloc_2D(Nx, rho_rec);
	Memory_dealloc_2D(Nx, Ux);
	Memory_dealloc_2D(Nx, Uy);
	Memory_dealloc_2D(9, M);
	Memory_dealloc_2D(9, M_inv);
	Memory_dealloc_2D(9, M_adj);
	Memory_dealloc_2D(Nx, Ux_real);
	Memory_dealloc_2D(Nx, Uy_real);
	Memory_dealloc_2D(Nx, rho_real);
	Memory_dealloc_2D(Nx, X_coordinates);
	Memory_dealloc_2D(Nx, Y_coordinates);
	Memory_dealloc_2D_int(Nx, stream_flags);
	Memory_dealloc_2D_int(Nx, solid_flags);
	Memory_dealloc_2D(Nx, vort_field);
	Memory_dealloc_2D(9, ck);
	Memory_dealloc_2D(Ny, fk_virt_left);
	Memory_dealloc_2D(Ny, fk_virt_right);
	Memory_dealloc_struct(number_b_nodes);
	Memory_dealloc_1D(Ly);
	Memory_dealloc_1D(Ly_wet_node);
	Memory_dealloc_1D(inlet_velocity);
	Memory_dealloc_1D(outlet_velocity_x);
	Memory_dealloc_1D(outlet_velocity_y);
	Memory_dealloc_1D(w);
	Memory_dealloc_1D(omega_vec);
	Memory_dealloc_1D(moment_vec);
	Memory_dealloc_1D(moment_vec_col);
	Memory_dealloc_1D(moment_vec_eq);
	Memory_dealloc_1D(fk_vec);
	Memory_dealloc_1D(force_vec_x);
	Memory_dealloc_1D(Force_solid_x);
	Memory_dealloc_1D(Force_solid_y);
	Memory_dealloc_1D(Force_solid_x_obj);
	Memory_dealloc_1D(Force_solid_y_obj);
	Memory_dealloc_2D(n_particles, force_vec_x_obj);

	Memory_dealloc_1D_struct_array(b_locations_type_1);
	Memory_dealloc_1D_struct_array(b_locations_type_2);
	Memory_dealloc_1D_struct_array(b_locations_type_3);
	Memory_dealloc_1D_struct_array(b_locations_type_4);
	Memory_dealloc_1D_struct_array(b_locations_type_5);
	Memory_dealloc_1D_struct_array(b_locations_type_6);
	Memory_dealloc_1D_struct_array(b_locations_type_7);
	Memory_dealloc_1D_struct_array(b_locations_type_8);
	Memory_dealloc_1D_struct_array(b_locations_type_9);
	Memory_dealloc_1D_struct_array(b_locations_type_10);
	Memory_dealloc_1D_struct_array(b_locations_type_11);
	Memory_dealloc_1D_struct_array(b_locations_type_12);

	Dealloc_boundary_location_struct_mult_obj(boundary_locations, n_particles, 12);

}
