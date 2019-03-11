/*
 * moment_and_space_transformations.c
 *
 *  Created on: 18 jun. 2017
 *      Author: dharrison
 */


#include "matrix_operations.h"
#include "parameters.h"
#include <stdlib.h>


void printing_mapping_matrix(double determinant_M, double **M, double **M_inv)
{
	int i, j, k, n;

	double element;

	n = 9;


	/*Print determinant*/
	printf("detA: %.4f\n\n", determinant_M);


	/*Printing transformation matrix*/
	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < n; ++j)
		{
			printf("M[%i][%i]: %.3f\t", i, j, M[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");


	/*Printing inverse of transformation matrix*/
	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < n; ++j)
		{
			printf("M_inv[%i][%i]: %.4f\t", i, j, M_inv[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");


	/*Printing matrix multiplication MM_inv*/
	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < n; ++j)
		{
			element = 0.0;

			for(k = 0; k < n; ++k)
			{
				element += M[i][k] * M_inv[k][j];
			}
			printf("AA-1[%i][%i]: %.4f\t", i, j, element);
		}
		printf("\n");
	}

}


void moment_transformation_set_up_gram_schmidt()
{
	int i, j, k, n;

	n = 9;


	/*Calculating transformation matrix M*/
	for(k = 0; k < n; ++k)
	{
		M[0][k] = 1.0;
		M[1][k] = -4.0 + 3 * (ck[k][0] * ck[k][0] + ck[k][1] * ck[k][1]);
		M[2][k] = 4.0 - 0.5 * 21.0 * (ck[k][0] * ck[k][0] + ck[k][1] * ck[k][1]) + 0.5 * 9.0 * (ck[k][0] * ck[k][0] + ck[k][1] * ck[k][1]) * (ck[k][0] * ck[k][0] + ck[k][1] * ck[k][1]);
		M[3][k] = ck[k][0];
		M[4][k] = (-5.0 + 3.0 * (ck[k][0] * ck[k][0] + ck[k][1] * ck[k][1])) * ck[k][0];
		M[5][k] = ck[k][1];
		M[6][k] = (-5.0 + 3.0 * (ck[k][0] * ck[k][0] + ck[k][1] * ck[k][1])) * ck[k][1];
		M[7][k] = (ck[k][0] * ck[k][0] - ck[k][1] * ck[k][1]);
		M[8][k] = (ck[k][0] * ck[k][1]);
	}


	/*Calculating the determinant of M*/
	determinant_M = Determinant(M, n);


	/*If matrix is singular, exit*/
	if(!determinant_M)
	{
		printf("\nTransformation matrix is singular\n");
		exit(4);
	}


	/*Calculating co-factor M_adj of M*/
	CoFactor(M, n, M_adj);


	/*Transposing M_adj*/
	Transpose(M_adj, n);


	/*Calculating inverse of transformation matrix*/
	for(i = 0; i < n; ++i)
		for(j = 0; j < n; ++j)
		{
			M_inv[i][j] = 1.0 / determinant_M * M_adj[i][j];
		}


	/*Printing M, M_inv and determinant to screen for debugging*/
	//printing_mapping_matrix(determinant_M, M, M_inv);

}


void moment_transformation_set_up_hermite()
{
	int i, j, k, n;

	n = 9;


	/*Calculating transformation matrix M*/
	for(k = 0; k < n; ++k)
	{
		M[0][k] = 1.0;
		M[1][k] = ck[k][0];
		M[2][k] = ck[k][1];
		M[3][k] = (ck[k][0] * ck[k][0] - cs * cs);
		M[4][k] = (ck[k][1] * ck[k][1] - cs * cs);
		M[5][k] = ck[k][0] * ck[k][1];
		M[6][k] = ck[k][0] * ck[k][1] * ck[k][1] - cs * cs * ck[k][0];
		M[7][k] = ck[k][1] * ck[k][0] * ck[k][0] - cs * cs * ck[k][1];
		M[8][k] = ck[k][0] * ck[k][0] * ck[k][1] * ck[k][1] - cs * cs * ck[k][0] * ck[k][0] - cs * cs * ck[k][1] * ck[k][1] + cs * cs * cs * cs;
	}


	/*Calculating the determinant of M*/
	determinant_M = Determinant(M, n);


	/*If matrix is singular, exit*/
	if(!determinant_M)
	{
		printf("\nTransformation matrix is singular\n");
		exit(4);
	}


	/*Calculating co-factor M_adj of M*/
	CoFactor(M, n, M_adj);


	/*Transposing M_adj*/
	Transpose(M_adj, n);


	/*Calculating inverse of transformation matrix*/
	for(i = 0; i < n; ++i)
		for(j = 0; j < n; ++j)
		{
			M_inv[i][j] = 1.0 / determinant_M * M_adj[i][j];
		}


	/*Printing M, M_inv and determinant to screen for debugging*/
	//printing_mapping_matrix(determinant_M, M, M_inv);

}
