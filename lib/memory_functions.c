/*
 * memory_functions.c
 *
 *  Created on: 19 mei 2017
 *      Author: dharrison
 */


#include <stdlib.h>
#include "../inc/types.h"


double ** mat2D(int n) {

    double ** mat = malloc(sizeof(double *) * n);

    for(int i = 0; i < n; ++i)
        mat[i] = malloc(sizeof(double) * n);

    return mat;
}

void free_mat2D(double ** mat, int n) {

    for(int i = 0; i < n; ++i)
        free(mat[i]);

    free(mat);
}

double*** Memory_alloc_3D(int Nx, int Ny, int Nz)
{
    int i, j;

    double ***f = (double ***) malloc(sizeof(double *) * Nx);

    for(i = 0; i < Nx; ++i)
    {
        *(f + i) = (double **) malloc(sizeof(double *) * Ny);
        for(j = 0; j < Ny; ++j)
            *(*(f + i) + j) = (double *) malloc(sizeof(double) * Nz);
    }

    return f;
}




void Memory_dealloc_3D(int Nx, int Ny, double*** f)
{
    int i, j;

    for(i = 0; i < Nx; ++i)
    {
        for(j = 0; j < Ny; ++j)
            free(*(*(f + i) + j));
    }

    for(i = 0; i < Nx; ++i)
    {
        free(*(f + i));
    }

    free(f);
}


double** Memory_alloc_2D(int Nx, int Ny)
{
    int i;

    double **f = (double **) malloc(sizeof(double *) * Nx);

    for(i = 0; i < Nx; ++i)
        *(f + i) = (double *) malloc(sizeof(double) * Ny);

    return f;
}


void Memory_dealloc_2D(int Nx, double** f)
{
    int i;

    for(i = 0; i < Nx; ++i)
        free(*(f + i));

    free(f);
}


int** Memory_alloc_2D_int(int Nx, int Ny)
{
    int i;

    int **f = (int **) malloc(sizeof(int *) * Nx);

    for(i = 0; i < Nx; ++i)
        *(f + i) = (int *) malloc(sizeof(int) * Ny);

    return f;
}


void Memory_dealloc_2D_int(int Nx, int** f)
{
    int i;

    for(i = 0; i < Nx; ++i)
        free(*(f + i));

    free(f);
}


b_location* Memory_alloc_1D_struct_array(int N_boundaries)
{
    b_location *f = (b_location *) malloc(sizeof(b_location) * N_boundaries);

    return f;
}


void Memory_dealloc_1D_struct_array(b_location* f)
{
    free(f);
}


N_boundary_nodes* Memory_alloc_struct()
{
    N_boundary_nodes *f = (N_boundary_nodes *) malloc(sizeof(N_boundary_nodes));

    return f;
}


void Memory_dealloc_struct(N_boundary_nodes* f)
{
    free(f);
}


B_location_parts*** array_of_boundary_loc_struct(int number_particles, int boundary_type)
{
    int i, j;

    B_location_parts ***f = (B_location_parts ***) malloc(sizeof(B_location_parts **) * number_particles);

    for(i = 0; i < number_particles; ++i)
        f[i] = (B_location_parts **) malloc(sizeof(B_location_parts *));

    for(i = 0; i < number_particles; ++i)
        for(j = 0; j < boundary_type; ++j)
            f[i][j] = (B_location_parts *) malloc(sizeof(B_location_parts *));

    return f;
}


B_locations_objs* Mem_alloc_boundary_location_struct_mult_obj(int Np, int Nbt, int Nbinit)
{
    int number_of_particles = Np;
    int number_of_boundary_types = Nbt;
    int number_of_boundaries_init = Nbinit;

    int i, j;

    B_locations_objs *boundary_locs;


    boundary_locs = (B_locations_objs *) malloc(sizeof(B_locations_objs));


    boundary_locs->part_number = (boundary_type *) malloc(sizeof(boundary_type) * number_of_particles);


    for(i = 0; i < number_of_particles;++i)
    {
        boundary_locs->part_number[i].boundary_type = (boundary_number *) malloc(sizeof(boundary_number) * number_of_boundary_types);
    }


    for(i = 0; i < number_of_particles;++i)
        for(j = 0; j < number_of_boundary_types; ++j)
        {
            boundary_locs->part_number[i].boundary_type[j].boundary_number = (B_location_parts_mult_obj *) malloc(sizeof(B_location_parts_mult_obj) * number_of_boundaries_init);
        }

    return boundary_locs;

}


void Realloc_boundary_location_struct(B_locations_objs *boundary_locs, int partnumber, int b_type, int number_of_boundaries)
{
    boundary_locs->part_number[partnumber].boundary_type[b_type].boundary_number =
            (B_location_parts_mult_obj *) realloc(boundary_locs->part_number[partnumber].boundary_type[b_type].boundary_number,
                                                  sizeof(B_location_parts_mult_obj) * number_of_boundaries);

}


void Dealloc_boundary_location_struct_mult_obj(B_locations_objs *boundary_locs, int Np, int Nbt)
{
    int number_of_particles = Np;
    int number_of_boundary_types = Nbt;

    int i, j;


    for(i = 0; i < number_of_particles;++i)
        for(j = 0; j < number_of_boundary_types; ++j)
        {
            free(boundary_locs->part_number[i].boundary_type[j].boundary_number);
        }


    for(i = 0; i < number_of_particles;++i)
    {
        free(boundary_locs->part_number[i].boundary_type);
    }

    free(boundary_locs->part_number);


    free(boundary_locs);

}


double* Memory_alloc_1D(int Nx)
{
    double *f = (double *) malloc(sizeof(double) * Nx);

    return f;
}


void Memory_dealloc_1D(double* f)
{
    free(f);
}

