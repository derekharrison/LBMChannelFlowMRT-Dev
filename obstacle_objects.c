/*
 * obstacle_objects.c
 *
 *  Created on: 24 mei 2017
 *      Author: dharrison
 */


#include <stdio.h>
#include <stdlib.h>
#include "parameters.h"
#include "boundary_nodes.h"


void rectangle(double x_coordinate, double y_coordinate, double width, double height)
{
	int i, j;
	int nx_low, nx_high, ny_low, ny_high;

	nx_low  = (int) (x_coordinate / dx + 0.5);
	nx_high = (int) ((x_coordinate + width) / dx - 0.5);

	ny_low  = (int) (y_coordinate / dx + 0.5);
	ny_high = (int) ((y_coordinate + height) / dx - 0.5);


	if(x_coordinate < 0 || (x_coordinate + width) > (Nx * dx) || y_coordinate < 0 || (y_coordinate + height) > (Ny * dx))
	{
		printf("x coordinate of rectangle must be greater than %f\n", 0.0);
		printf("y coordinate of rectangle must be greater than %f\n", 0.0);
		printf("x coordinate + width of rectangle must be less than %f\n", Nx * dx);
		printf("y coordinate + height of rectangle must be less than %f\n", Ny * dx);
		exit(1);
	}


	for(i = nx_low; i <= nx_high; ++i)
		for(j = ny_low; j <= ny_high; ++j)
		{
			stream_flags[i][j] = 0;
			solid_flags[i][j] = 1;
		}

}


void circle(double x_coordinate, double y_coordinate, double radius)
{
	int i, j;
	int nx_low, nx_high, ny_low, ny_high;
	double R_square, r_square;

	r_square = radius * radius;

	nx_low  = (int) ((x_coordinate - radius) / dx + 0.5);
	nx_high = (int) ((x_coordinate + radius) / dx - 0.5);

	ny_low  = (int) ((y_coordinate - radius) / dx + 0.5);
	ny_high = (int) ((y_coordinate + radius) / dx - 0.5);


	if((x_coordinate - radius) < 0 || (x_coordinate + radius) > (Nx * dx) || (y_coordinate - radius) < 0 || (y_coordinate + radius) > (Ny * dx))
	{
		printf("x coordinate - radius of circle must be greater than %f\n", 0.0);
		printf("y coordinate - radius of circle must be greater than %f\n", 0.0);
		printf("x coordinate + radius of circle must be less than %f\n", Nx * dx);
		printf("y coordinate + radius of circle must be less than %f\n", Ny * dx);
		exit(2);
	}


	for(i = nx_low; i <= nx_high; ++i)
		for(j = ny_low; j <= ny_high; ++j)
		{
			R_square = (X_coordinates[i][j] - x_coordinate) * (X_coordinates[i][j] - x_coordinate) +
					   (Y_coordinates[i][j] - y_coordinate) * (Y_coordinates[i][j] - y_coordinate);

			if(R_square < r_square)
			{
				stream_flags[i][j] = 0;
				solid_flags[i][j] = 1;
			}
		}


	/*Determining locations of boundary nodes for individual objects*/
	calculate_boundary_nodes_ind_part(nx_low - 2, nx_high + 2, ny_low - 2, ny_high + 2, particle_number);


	/*Increment particle count*/
	particle_number += 1;

}
