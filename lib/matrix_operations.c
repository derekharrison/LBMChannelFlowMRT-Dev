/*
 * MatrixOperations.c
 *
 *  Created on: 18 jun. 2017
 *      Author: dharrison
 *
 */


#include "../inc/memory_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double determinant(double ** A, int n)
{
    double det = 0;

    if(n == 1)
    {
        return A[0][0];
    }

    if(n == 2)
    {
        return A[0][0] * A[1][1] - A[1][0] * A[0][1];
    }

    if(n > 2)
    {
        for(int c = 0; c < n; ++c)
        {

            double ** M = mat2D(n - 1);

            for(int i = 1; i < n; ++i)
            {
                int j_m = 0;
                for(int j = 0; j < n; ++j)
                {
                    if(j != c)
                    {
                        M[i - 1][j_m] = A[i][j];
                        j_m++;
                    }

                }
            }

            double fac = pow(-1, c + 2);

            det = det + A[0][c] * fac * determinant(M, n - 1);

            free_mat2D(M, n - 1);

        }
    }

    return det;
}


double co_factor(double ** A, int n, int i, int j)
{

    double fac = 0;

    double ** M = mat2D(n - 1);

    int i_m = 0;
    for(int r = 0; r < n; ++r)
    {
        int j_m = 0;
        if(r != i)
        {
            for(int c = 0; c < n; ++c)
            {
                if(c != j)
                {
                    M[i_m][j_m] = A[r][c];
                    j_m++;
                }
            }
            i_m++;
        }
    }

    fac = pow(-1, i + j + 2) * determinant(M, n - 1);

    free_mat2D(M, n - 1);

    return fac;
}

void adjoint_mat(double ** A, int n, double ** adj_mat)
{

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            adj_mat[i][j] = co_factor(A, n, i, j);
        }
    }
}

void mat_inverse(double ** A, int n, double ** mat_inv)
{

    double ** adj_mat = mat2D(n);

    adjoint_mat(A, n, adj_mat);

    double det = determinant(A, n);

    if(det == 0)
    {
        printf("\nTransformation matrix is singular\n");
        exit(4);
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            mat_inv[j][i] = 1.0 / det * adj_mat[i][j];
        }
    }

    free_mat2D(adj_mat, n);
}
