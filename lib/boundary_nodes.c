/*
 * boundary_nodes.c
 *
 *  Created on: 25 mei 2017
 *      Author: dharrison
 */


#include <stdlib.h>
#include "../inc/parameters.h"
#include "../inc/memory_functions.h"


void calculate_boundary_nodes()
{
	int i, j;

	int type_1_counter = 0;
	int type_2_counter = 0;
	int type_3_counter = 0;
	int type_4_counter = 0;
	int type_5_counter = 0;
	int type_6_counter = 0;
	int type_7_counter = 0;
	int type_8_counter = 0;
	int type_9_counter = 0;
	int type_10_counter = 0;
	int type_11_counter = 0;
	int type_12_counter = 0;


	int bool_type_1 = 0;
	int bool_type_2 = 0;
	int bool_type_3 = 0;
	int bool_type_4 = 0;
	int bool_type_5 = 0;
	int bool_type_6 = 0;
	int bool_type_7 = 0;
	int bool_type_8 = 0;
	int bool_type_9 = 0;
	int bool_type_10 = 0;
	int bool_type_11 = 0;
	int bool_type_12 = 0;


	/*Checking internal nodes*/
	for(i = 1; i < Nx - 1; ++i)
		for(j = 1; j < Ny - 1; ++j)
		{
			if(solid_flags[i][j] == 0)
			{
				bool_type_1 = (solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							  (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0);

				if(bool_type_1)
				{
					b_locations_type_1[type_1_counter].i_index = i;
					b_locations_type_1[type_1_counter].j_index = j;
					b_locations_type_1[type_1_counter].type = 1;
					type_1_counter += 1;
				}


				bool_type_2 = ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 1) && (solid_flags[i-1][j-1] == 0)) ||

							  ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 1) && (solid_flags[i-1][j-1] == 1)) ||

							  ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 1) && (solid_flags[i-1][j-1] == 0)) ||

							  ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 1) && (solid_flags[i-1][j-1] == 1));

				if(bool_type_2)
				{
					b_locations_type_2[type_2_counter].i_index = i;
					b_locations_type_2[type_2_counter].j_index = j;
					b_locations_type_2[type_2_counter].type = 2;
					type_2_counter += 1;
				}


				bool_type_3 = (solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							  (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 1);

				if(bool_type_3)
				{
					b_locations_type_3[type_3_counter].i_index = i;
					b_locations_type_3[type_3_counter].j_index = j;
					b_locations_type_3[type_3_counter].type = 3;
					type_3_counter += 1;
				}


				bool_type_4 = ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 1) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 1) && (solid_flags[i-1][j-1] == 0)) ||

							  ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 1) &&
							   (solid_flags[i+1][j] == 1) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 1) && (solid_flags[i-1][j-1] == 1)) ||

							  ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 1) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 1) && (solid_flags[i-1][j-1] == 1)) ||

							  ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 1) &&
							   (solid_flags[i+1][j] == 1) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 1) && (solid_flags[i-1][j-1] == 0));

				if(bool_type_4)
				{
					b_locations_type_4[type_4_counter].i_index = i;
					b_locations_type_4[type_4_counter].j_index = j;
					b_locations_type_4[type_4_counter].type = 4;
					type_4_counter += 1;
				}


				bool_type_5 = ((solid_flags[i-1][j] == 1) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 1) && (solid_flags[i-1][j-1] == 1)) ||

							  ((solid_flags[i-1][j] == 1) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 1) && (solid_flags[i-1][j-1] == 1)) ||

							  ((solid_flags[i-1][j] == 1) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 1) && (solid_flags[i-1][j-1] == 1)) ||

							  ((solid_flags[i-1][j] == 1) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 1) && (solid_flags[i-1][j-1] == 1));

				if(bool_type_5)
				{
					b_locations_type_5[type_5_counter].i_index = i;
					b_locations_type_5[type_5_counter].j_index = j;
					b_locations_type_5[type_5_counter].type = 5;
					type_5_counter += 1;
				}


				bool_type_6 = ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 1) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0)) ||

							  ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 1) &&
							   (solid_flags[i+1][j] == 1) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0)) ||

							  ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 1) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0)) ||

							  ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 1) &&
							   (solid_flags[i+1][j] == 1) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0));

				if(bool_type_6)
				{
					b_locations_type_6[type_6_counter].i_index = i;
					b_locations_type_6[type_6_counter].j_index = j;
					b_locations_type_6[type_6_counter].type = 6;
					type_6_counter += 1;
				}


				bool_type_7 = ((solid_flags[i-1][j] == 1) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0)) ||

							  ((solid_flags[i-1][j] == 1) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 1)) ||

							  ((solid_flags[i-1][j] == 1) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 1)) ||

							  ((solid_flags[i-1][j] == 1) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0));

				if(bool_type_7)
				{
					b_locations_type_7[type_7_counter].i_index = i;
					b_locations_type_7[type_7_counter].j_index = j;
					b_locations_type_7[type_7_counter].type = 7;
					type_7_counter += 1;
				}


				bool_type_8 = ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 1) && (solid_flags[i+1][j+1] == 1) &&
							   (solid_flags[i+1][j] == 1) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0)) ||

							  ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 1) && (solid_flags[i+1][j+1] == 1) &&
							   (solid_flags[i+1][j] == 1) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0)) ||

							  ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 1) && (solid_flags[i+1][j+1] == 1) &&
							   (solid_flags[i+1][j] == 1) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0)) ||

							  ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 1) && (solid_flags[i+1][j+1] == 1) &&
							   (solid_flags[i+1][j] == 1) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0));

				if(bool_type_8)
				{
					b_locations_type_8[type_8_counter].i_index = i;
					b_locations_type_8[type_8_counter].j_index = j;
					b_locations_type_8[type_8_counter].type = 8;
					type_8_counter += 1;
				}


				bool_type_9 = ((solid_flags[i-1][j] == 1) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 1) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0)) ||

							  ((solid_flags[i-1][j] == 1) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 1) && (solid_flags[i+1][j+1] == 1) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 1)) ||

							  ((solid_flags[i-1][j] == 1) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 1) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 1)) ||

							  ((solid_flags[i-1][j] == 1) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 1) && (solid_flags[i+1][j+1] == 1) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0));

				if(bool_type_9)
				{
					b_locations_type_9[type_9_counter].i_index = i;
					b_locations_type_9[type_9_counter].j_index = j;
					b_locations_type_9[type_9_counter].type = 9;
					type_9_counter += 1;
				}


				bool_type_10 = (solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 1) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0);

				if(bool_type_10)
				{
					b_locations_type_10[type_10_counter].i_index = i;
					b_locations_type_10[type_10_counter].j_index = j;
					b_locations_type_10[type_10_counter].type = 10;
					type_10_counter += 1;
				}


				bool_type_11 = ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 1) && (solid_flags[i+1][j+1] == 0) &&
							    (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0)) ||

							   ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 1) && (solid_flags[i+1][j+1] == 1) &&
							    (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0)) ||

							   ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 1) && (solid_flags[i+1][j+1] == 0) &&
							    (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0)) ||

							   ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 1) && (solid_flags[i+1][j+1] == 1) &&
							    (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0));

				if(bool_type_11)
				{
					b_locations_type_11[type_11_counter].i_index = i;
					b_locations_type_11[type_11_counter].j_index = j;
					b_locations_type_11[type_11_counter].type = 11;
					type_11_counter += 1;
				}


				bool_type_12 = (solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0);

				if(bool_type_12)
				{
					b_locations_type_12[type_12_counter].i_index = i;
					b_locations_type_12[type_12_counter].j_index = j;
					b_locations_type_12[type_12_counter].type = 12;
					type_12_counter += 1;
				}
			}
		}


	number_b_nodes->type_1  = type_1_counter;
	number_b_nodes->type_2  = type_2_counter;
	number_b_nodes->type_3  = type_3_counter;
	number_b_nodes->type_4  = type_4_counter;
	number_b_nodes->type_5  = type_5_counter;
	number_b_nodes->type_6  = type_6_counter;
	number_b_nodes->type_7  = type_7_counter;
	number_b_nodes->type_8  = type_8_counter;
	number_b_nodes->type_9  = type_9_counter;
	number_b_nodes->type_10 = type_10_counter;
	number_b_nodes->type_11 = type_11_counter;
	number_b_nodes->type_12 = type_12_counter;

	printf("\n");
	printf("total number of boundaries type 1 is %i\n", type_1_counter);
	printf("total number of boundaries type 2 is %i\n", type_2_counter);
	printf("total number of boundaries type 3 is %i\n", type_3_counter);
	printf("total number of boundaries type 4 is %i\n", type_4_counter);
	printf("total number of boundaries type 5 is %i\n", type_5_counter);
	printf("total number of boundaries type 6 is %i\n", type_6_counter);
	printf("total number of boundaries type 7 is %i\n", type_7_counter);
	printf("total number of boundaries type 8 is %i\n", type_8_counter);
	printf("total number of boundaries type 9 is %i\n", type_9_counter);
	printf("total number of boundaries type 10 is %i\n", type_10_counter);
	printf("total number of boundaries type 11 is %i\n", type_11_counter);
	printf("total number of boundaries type 12 is %i\n", type_12_counter);


	b_locations_type_1  = (b_location *) realloc(b_locations_type_1, sizeof(b_location) * type_1_counter);
	b_locations_type_2  = (b_location *) realloc(b_locations_type_2, sizeof(b_location) * type_2_counter);
	b_locations_type_3  = (b_location *) realloc(b_locations_type_3, sizeof(b_location) * type_3_counter);
	b_locations_type_4  = (b_location *) realloc(b_locations_type_4, sizeof(b_location) * type_4_counter);
	b_locations_type_5  = (b_location *) realloc(b_locations_type_5, sizeof(b_location) * type_5_counter);
	b_locations_type_6  = (b_location *) realloc(b_locations_type_6, sizeof(b_location) * type_6_counter);
	b_locations_type_7  = (b_location *) realloc(b_locations_type_7, sizeof(b_location) * type_7_counter);
	b_locations_type_8  = (b_location *) realloc(b_locations_type_8, sizeof(b_location) * type_8_counter);
	b_locations_type_9  = (b_location *) realloc(b_locations_type_9, sizeof(b_location) * type_9_counter);
	b_locations_type_10 = (b_location *) realloc(b_locations_type_10, sizeof(b_location) * type_10_counter);
	b_locations_type_11 = (b_location *) realloc(b_locations_type_11, sizeof(b_location) * type_11_counter);
	b_locations_type_12 = (b_location *) realloc(b_locations_type_12, sizeof(b_location) * type_12_counter);

}


void calculate_boundary_nodes_ind_part(int nx_low, int nx_high, int ny_low, int ny_high, int partnumber)
{
	int i, j;

	int type_1_counter = 0;
	int type_2_counter = 0;
	int type_3_counter = 0;
	int type_4_counter = 0;
	int type_5_counter = 0;
	int type_6_counter = 0;
	int type_7_counter = 0;
	int type_8_counter = 0;
	int type_9_counter = 0;
	int type_10_counter = 0;
	int type_11_counter = 0;
	int type_12_counter = 0;


	int bool_type_1 = 0;
	int bool_type_2 = 0;
	int bool_type_3 = 0;
	int bool_type_4 = 0;
	int bool_type_5 = 0;
	int bool_type_6 = 0;
	int bool_type_7 = 0;
	int bool_type_8 = 0;
	int bool_type_9 = 0;
	int bool_type_10 = 0;
	int bool_type_11 = 0;
	int bool_type_12 = 0;


	/*Checking internal nodes*/
	for(i = nx_low; i < nx_high; ++i)
		for(j = ny_low; j < ny_high; ++j)
		{
			if(solid_flags[i][j] == 0)
			{
				bool_type_1 = (solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							  (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0);

				if(bool_type_1)
				{
					boundary_locations->part_number[partnumber].boundary_type[0].boundary_number[type_1_counter].i_index = i;
					boundary_locations->part_number[partnumber].boundary_type[0].boundary_number[type_1_counter].j_index = j;
					boundary_locations->part_number[partnumber].boundary_type[0].boundary_number[type_1_counter].type = 1;
					type_1_counter += 1;
				}


				bool_type_2 = ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 1) && (solid_flags[i-1][j-1] == 0)) ||

							  ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 1) && (solid_flags[i-1][j-1] == 1)) ||

							  ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 1) && (solid_flags[i-1][j-1] == 0)) ||

							  ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 1) && (solid_flags[i-1][j-1] == 1));

				if(bool_type_2)
				{
					boundary_locations->part_number[partnumber].boundary_type[1].boundary_number[type_2_counter].i_index = i;
					boundary_locations->part_number[partnumber].boundary_type[1].boundary_number[type_2_counter].j_index = j;
					boundary_locations->part_number[partnumber].boundary_type[1].boundary_number[type_2_counter].type = 2;
					type_2_counter += 1;
				}


				bool_type_3 = (solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							  (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 1);

				if(bool_type_3)
				{
					boundary_locations->part_number[partnumber].boundary_type[2].boundary_number[type_3_counter].i_index = i;
					boundary_locations->part_number[partnumber].boundary_type[2].boundary_number[type_3_counter].j_index = j;
					boundary_locations->part_number[partnumber].boundary_type[2].boundary_number[type_3_counter].type = 3;
					type_3_counter += 1;
				}


				bool_type_4 = ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 1) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 1) && (solid_flags[i-1][j-1] == 0)) ||

							  ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 1) &&
							   (solid_flags[i+1][j] == 1) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 1) && (solid_flags[i-1][j-1] == 1)) ||

							  ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 1) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 1) && (solid_flags[i-1][j-1] == 1)) ||

							  ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 1) &&
							   (solid_flags[i+1][j] == 1) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 1) && (solid_flags[i-1][j-1] == 0));

				if(bool_type_4)
				{
					boundary_locations->part_number[partnumber].boundary_type[3].boundary_number[type_4_counter].i_index = i;
					boundary_locations->part_number[partnumber].boundary_type[3].boundary_number[type_4_counter].j_index = j;
					boundary_locations->part_number[partnumber].boundary_type[3].boundary_number[type_4_counter].type = 4;
					type_4_counter += 1;
				}


				bool_type_5 = ((solid_flags[i-1][j] == 1) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 1) && (solid_flags[i-1][j-1] == 1)) ||

							  ((solid_flags[i-1][j] == 1) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 1) && (solid_flags[i-1][j-1] == 1)) ||

							  ((solid_flags[i-1][j] == 1) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 1) && (solid_flags[i-1][j-1] == 1)) ||

							  ((solid_flags[i-1][j] == 1) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 1) && (solid_flags[i-1][j-1] == 1));

				if(bool_type_5)
				{
					boundary_locations->part_number[partnumber].boundary_type[4].boundary_number[type_5_counter].i_index = i;
					boundary_locations->part_number[partnumber].boundary_type[4].boundary_number[type_5_counter].j_index = j;
					boundary_locations->part_number[partnumber].boundary_type[4].boundary_number[type_5_counter].type = 5;
					type_5_counter += 1;
				}


				bool_type_6 = ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 1) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0)) ||

							  ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 1) &&
							   (solid_flags[i+1][j] == 1) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0)) ||

							  ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 1) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0)) ||

							  ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 1) &&
							   (solid_flags[i+1][j] == 1) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0));

				if(bool_type_6)
				{
					boundary_locations->part_number[partnumber].boundary_type[5].boundary_number[type_6_counter].i_index = i;
					boundary_locations->part_number[partnumber].boundary_type[5].boundary_number[type_6_counter].j_index = j;
					boundary_locations->part_number[partnumber].boundary_type[5].boundary_number[type_6_counter].type = 6;
					type_6_counter += 1;
				}


				bool_type_7 = ((solid_flags[i-1][j] == 1) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0)) ||

							  ((solid_flags[i-1][j] == 1) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 1)) ||

							  ((solid_flags[i-1][j] == 1) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 1)) ||

							  ((solid_flags[i-1][j] == 1) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0));

				if(bool_type_7)
				{
					boundary_locations->part_number[partnumber].boundary_type[6].boundary_number[type_7_counter].i_index = i;
					boundary_locations->part_number[partnumber].boundary_type[6].boundary_number[type_7_counter].j_index = j;
					boundary_locations->part_number[partnumber].boundary_type[6].boundary_number[type_7_counter].type = 7;
					type_7_counter += 1;
				}


				bool_type_8 = ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 1) && (solid_flags[i+1][j+1] == 1) &&
							   (solid_flags[i+1][j] == 1) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0)) ||

							  ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 1) && (solid_flags[i+1][j+1] == 1) &&
							   (solid_flags[i+1][j] == 1) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0)) ||

							  ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 1) && (solid_flags[i+1][j+1] == 1) &&
							   (solid_flags[i+1][j] == 1) && (solid_flags[i+1][j-1] == 1) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0)) ||

							  ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 1) && (solid_flags[i+1][j+1] == 1) &&
							   (solid_flags[i+1][j] == 1) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0));

				if(bool_type_8)
				{
					boundary_locations->part_number[partnumber].boundary_type[7].boundary_number[type_8_counter].i_index = i;
					boundary_locations->part_number[partnumber].boundary_type[7].boundary_number[type_8_counter].j_index = j;
					boundary_locations->part_number[partnumber].boundary_type[7].boundary_number[type_8_counter].type = 8;
					type_8_counter += 1;
				}


				bool_type_9 = ((solid_flags[i-1][j] == 1) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 1) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0)) ||

							  ((solid_flags[i-1][j] == 1) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 1) && (solid_flags[i+1][j+1] == 1) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 1)) ||

							  ((solid_flags[i-1][j] == 1) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 1) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 1)) ||

							  ((solid_flags[i-1][j] == 1) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 1) && (solid_flags[i+1][j+1] == 1) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0));

				if(bool_type_9)
				{
					boundary_locations->part_number[partnumber].boundary_type[8].boundary_number[type_9_counter].i_index = i;
					boundary_locations->part_number[partnumber].boundary_type[8].boundary_number[type_9_counter].j_index = j;
					boundary_locations->part_number[partnumber].boundary_type[8].boundary_number[type_9_counter].type = 9;
					type_9_counter += 1;
				}


				bool_type_10 = (solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 1) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0);

				if(bool_type_10)
				{
					boundary_locations->part_number[partnumber].boundary_type[9].boundary_number[type_10_counter].i_index = i;
					boundary_locations->part_number[partnumber].boundary_type[9].boundary_number[type_10_counter].j_index = j;
					boundary_locations->part_number[partnumber].boundary_type[9].boundary_number[type_10_counter].type = 10;
					type_10_counter += 1;
				}


				bool_type_11 = ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 1) && (solid_flags[i+1][j+1] == 0) &&
							    (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0)) ||

							   ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 1) && (solid_flags[i+1][j+1] == 1) &&
							    (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0)) ||

							   ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 1) && (solid_flags[i+1][j+1] == 0) &&
							    (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0)) ||

							   ((solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 0) && (solid_flags[i][j+1] == 1) && (solid_flags[i+1][j+1] == 1) &&
							    (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0));

				if(bool_type_11)
				{
					boundary_locations->part_number[partnumber].boundary_type[10].boundary_number[type_11_counter].i_index = i;
					boundary_locations->part_number[partnumber].boundary_type[10].boundary_number[type_11_counter].j_index = j;
					boundary_locations->part_number[partnumber].boundary_type[10].boundary_number[type_11_counter].type = 11;
					type_11_counter += 1;
				}


				bool_type_12 = (solid_flags[i-1][j] == 0) && (solid_flags[i-1][j+1] == 1) && (solid_flags[i][j+1] == 0) && (solid_flags[i+1][j+1] == 0) &&
							   (solid_flags[i+1][j] == 0) && (solid_flags[i+1][j-1] == 0) && (solid_flags[i][j-1] == 0) && (solid_flags[i-1][j-1] == 0);

				if(bool_type_12)
				{
					boundary_locations->part_number[partnumber].boundary_type[11].boundary_number[type_12_counter].i_index = i;
					boundary_locations->part_number[partnumber].boundary_type[11].boundary_number[type_12_counter].j_index = j;
					boundary_locations->part_number[partnumber].boundary_type[11].boundary_number[type_12_counter].type = 12;
					type_12_counter += 1;
				}
			}
		}


	boundary_locations->part_number[partnumber].boundary_type[0].number_of_boundaries  = type_1_counter;
	boundary_locations->part_number[partnumber].boundary_type[1].number_of_boundaries  = type_2_counter;
	boundary_locations->part_number[partnumber].boundary_type[2].number_of_boundaries  = type_3_counter;
	boundary_locations->part_number[partnumber].boundary_type[3].number_of_boundaries  = type_4_counter;
	boundary_locations->part_number[partnumber].boundary_type[4].number_of_boundaries  = type_5_counter;
	boundary_locations->part_number[partnumber].boundary_type[5].number_of_boundaries  = type_6_counter;
	boundary_locations->part_number[partnumber].boundary_type[6].number_of_boundaries  = type_7_counter;
	boundary_locations->part_number[partnumber].boundary_type[7].number_of_boundaries  = type_8_counter;
	boundary_locations->part_number[partnumber].boundary_type[8].number_of_boundaries  = type_9_counter;
	boundary_locations->part_number[partnumber].boundary_type[9].number_of_boundaries  = type_10_counter;
	boundary_locations->part_number[partnumber].boundary_type[10].number_of_boundaries = type_11_counter;
	boundary_locations->part_number[partnumber].boundary_type[11].number_of_boundaries = type_12_counter;

	printf("\n");
	printf("number of boundaries type 1 obstacle %i is %i\n", partnumber, boundary_locations->part_number[partnumber].boundary_type[0].number_of_boundaries);
	printf("number of boundaries type 2 obstacle %i is %i\n", partnumber, boundary_locations->part_number[partnumber].boundary_type[1].number_of_boundaries);
	printf("number of boundaries type 3 obstacle %i is %i\n", partnumber, boundary_locations->part_number[partnumber].boundary_type[2].number_of_boundaries);
	printf("number of boundaries type 4 obstacle %i is %i\n", partnumber, boundary_locations->part_number[partnumber].boundary_type[3].number_of_boundaries);
	printf("number of boundaries type 5 obstacle %i is %i\n", partnumber, boundary_locations->part_number[partnumber].boundary_type[4].number_of_boundaries);
	printf("number of boundaries type 6 obstacle %i is %i\n", partnumber, boundary_locations->part_number[partnumber].boundary_type[5].number_of_boundaries);
	printf("number of boundaries type 7 obstacle %i is %i\n", partnumber, boundary_locations->part_number[partnumber].boundary_type[6].number_of_boundaries);
	printf("number of boundaries type 8 obstacle %i is %i\n", partnumber, boundary_locations->part_number[partnumber].boundary_type[7].number_of_boundaries);
	printf("number of boundaries type 9 obstacle %i is %i\n", partnumber, boundary_locations->part_number[partnumber].boundary_type[8].number_of_boundaries);
	printf("number of boundaries type 10 obstacle %i is %i\n", partnumber, boundary_locations->part_number[partnumber].boundary_type[9].number_of_boundaries);
	printf("number of boundaries type 11 obstacle %i is %i\n", partnumber, boundary_locations->part_number[partnumber].boundary_type[10].number_of_boundaries);
	printf("number of boundaries type 12 obstacle %i is %i\n", partnumber, boundary_locations->part_number[partnumber].boundary_type[11].number_of_boundaries);


	Realloc_boundary_location_struct(boundary_locations, partnumber, 0, type_1_counter);
	Realloc_boundary_location_struct(boundary_locations, partnumber, 1, type_2_counter);
	Realloc_boundary_location_struct(boundary_locations, partnumber, 2, type_3_counter);
	Realloc_boundary_location_struct(boundary_locations, partnumber, 3, type_4_counter);
	Realloc_boundary_location_struct(boundary_locations, partnumber, 4, type_5_counter);
	Realloc_boundary_location_struct(boundary_locations, partnumber, 5, type_6_counter);
	Realloc_boundary_location_struct(boundary_locations, partnumber, 6, type_7_counter);
	Realloc_boundary_location_struct(boundary_locations, partnumber, 7, type_8_counter);
	Realloc_boundary_location_struct(boundary_locations, partnumber, 8, type_9_counter);
	Realloc_boundary_location_struct(boundary_locations, partnumber, 9, type_10_counter);
	Realloc_boundary_location_struct(boundary_locations, partnumber, 10, type_11_counter);
	Realloc_boundary_location_struct(boundary_locations, partnumber, 11, type_12_counter);

}
