/*
 * functions.h
 *
 *  Created on: 19 mei 2017
 *      Author: dharrison
 */

#ifndef MEMORY_FUNCTIONS_H_
#define MEMORY_FUNCTIONS_H_


#include "types.h"


void parameter_declaration();
void initialization();

double*** Memory_alloc_3D(int Nx, int Ny, int Nz);
double** Memory_alloc_2D(int Nx, int Ny);
double* Memory_alloc_1D(int Nx);

void Memory_dealloc_3D(int Nx, int Ny, double*** f);
void Memory_dealloc_2D(int Nx, double** f);
void Memory_dealloc_1D(double* f);

int** Memory_alloc_2D_int(int Nx, int Ny);
void Memory_dealloc_2D_int(int Nx, int** f);

b_location* Memory_alloc_1D_struct_array(int N_boudaries);
void Memory_dealloc_1D_struct_array(b_location* f);

N_boundary_nodes* Memory_alloc_struct();
void Memory_dealloc_struct(N_boundary_nodes* f);

B_locations_objs* Mem_alloc_boundary_location_struct_mult_obj(int Np, int Nbt, int Nbinit);
void Realloc_boundary_location_struct(B_locations_objs *boundary_locs, int partnumber, int b_type, int number_of_boundaries);
void Dealloc_boundary_location_struct_mult_obj(B_locations_objs *boundary_locs, int Np, int Nbt);


#endif /* MEMORY_FUNCTIONS_H_ */
