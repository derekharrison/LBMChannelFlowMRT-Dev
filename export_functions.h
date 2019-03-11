/*
 * export_functions.h
 *
 *  Created on: 26 mei 2017
 *      Author: dharrison
 */

#ifndef EXPORT_FUNCTIONS_H_
#define EXPORT_FUNCTIONS_H_

void print_3D_doubles(FILE* pfile, int Nx, int Ny, int Nz, double*** f);
void read_3D_doubles(FILE* pfile, int Nx, int Ny, int Nz, double*** f);
void print_2D_doubles(FILE* pfile, int Nx, int Ny, double** f);
void read_2D_doubles(FILE* pfile, int Nx, int Ny, double** f);
void print_2D_int(FILE* pfile, int Nx, int Ny, int** f);
void force_calculations(FILE* pfile);
void compare_analytical_solution_poiseulle(FILE* pfile, int Nx, int Ny, double** Ux);
void compare_analytical_solution_couette(FILE* pfile, int Nx, int Ny, double** Ux);
void max_velocity_and_vorticity();
void print_2D_map_of_3D_doubles(FILE* pfile, int Nx, int Ny, int z_index, double*** f);


#endif /* EXPORT_FUNCTIONS_H_ */
