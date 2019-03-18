/*
 * export.c
 *
 *  Created on: 19 mei 2017
 *      Author: dharrison
 */


#include "../inc/parameters.h"
#include "../inc/export_functions.h"
#include <stdlib.h>


void open_files()
{
    pfile                    = fopen(data_final_timestep, "w");
    datafile                = fopen(data_time_dependent, "w");
    param_file                = fopen(parameters, "w");
    force_res                = fopen(force_vec_results, "w");

}


void export_data_for_restart(FILE* data_store_for_restart)
{
    data_store_for_restart = fopen(data_store, "w");

    if(data_store_for_restart != NULL)
    {
        /*Export Ux, Uy, rho, fk and fprop data*/
        write_2D_doubles(data_store_for_restart, Nx, Ny, Ux);
        write_2D_doubles(data_store_for_restart, Nx, Ny, Uy);
        write_2D_doubles(data_store_for_restart, Nx, Ny, rho);

        write_3D_doubles(data_store_for_restart, Nx, Ny, 9, fk);
        write_3D_doubles(data_store_for_restart, Nx, Ny, 9, fprop);
    }
    else
    {
        printf("could not open %s\n", data_store);
        exit(10);
    }

    fclose(data_store_for_restart);

}


void export_data_for_restart_during_sim(FILE* data_store_for_restart)
{
    data_store_for_restart = fopen(data_store, "w");

    if(data_store_for_restart != NULL)
    {
        if((timestep % time_interval_data) == 0)
        {
            /*Export Ux, Uy, rho, fk and fprop data*/
            write_2D_doubles(data_store_for_restart, Nx, Ny, Ux);
            write_2D_doubles(data_store_for_restart, Nx, Ny, Uy);
            write_2D_doubles(data_store_for_restart, Nx, Ny, rho);

            write_3D_doubles(data_store_for_restart, Nx, Ny, 9, fk);
            write_3D_doubles(data_store_for_restart, Nx, Ny, 9, fprop);
        }
    }
    else
    {
        printf("could not open %s\n", data_store);
        exit(10);
    }

    fclose(data_store_for_restart);

}


void read_data_for_restart(FILE* data_store_for_restart)
{
    data_store_for_restart = fopen(data_store, "r");

    if(data_store_for_restart != NULL)
    {
        /*Export Ux, Uy, rho, fk and fprop data*/
        read_2D_doubles(data_store_for_restart, Nx, Ny, Ux);
        read_2D_doubles(data_store_for_restart, Nx, Ny, Uy);
        read_2D_doubles(data_store_for_restart, Nx, Ny, rho);

        read_3D_doubles(data_store_for_restart, Nx, Ny, 9, fk);
        read_3D_doubles(data_store_for_restart, Nx, Ny, 9, fprop);
    }
    else
    {
        printf("could not open %s\n", data_store);
        exit(10);
    }

    fclose(data_store_for_restart);

}


void export_time_dep_data(FILE* datafile)
{
    if (datafile != NULL)
    {
        if(((timestep % time_interval_vids) == 0) && (timestep >= min_timestep))
        {
            for(j = Ny - 1;j >= 0 ; --j)
                for(i = 0;i < Nx; ++i)
                {
                    fprintf(datafile,"%f    ", i*dx + 0.5*dx);
                    fprintf(datafile,"%f    ", j*dx + 0.5*dx);
                    fprintf(datafile,"%f    ", Ux[i][j]);
                    fprintf(datafile,"%f    ", Uy[i][j]);
                    fprintf(datafile,"%f\n", vort_field[i][j]);
                }
        }
    }
    else
    {
        printf("could not open %s", data_time_dependent);
        exit(10);
    }

}


void export_time_dep_data_limited(FILE* datafile, int Nx_low, int Nx_high, int Ny_low, int Ny_high)
{
    if (datafile != NULL)
    {
        if(((timestep % time_interval_vids) == 0) && (timestep >= min_timestep))
        {
            for(j = Ny_high - 1;j >= Ny_low ; --j)
                for(i = Nx_low;i < Nx_high; ++i)
                {
                    fprintf(datafile,"%f    ", i*dx + 0.5*dx);
                    fprintf(datafile,"%f    ", j*dx + 0.5*dx);
                    fprintf(datafile,"%f    ", Ux[i][j]);
                    fprintf(datafile,"%f    ", Uy[i][j]);
                    fprintf(datafile,"%f\n", vort_field[i][j]);
                }
        }
    }
    else
    {
        printf("could not open %s", data_time_dependent);
        exit(10);
    }

}


void export_parameters(FILE* param_file)
{
    max_velocity_and_vorticity();

    if (param_file != NULL)
    {
        fprintf(param_file,"%i\n", 0);
        fprintf(param_file,"%i\n", Nx);
        fprintf(param_file,"%i\n", 0);
        fprintf(param_file,"%i\n", Ny);
        fprintf(param_file,"%i\n", (timesteps - min_timestep) / time_interval_vids);
        fprintf(param_file,"%f\n", max_velocity * 1.05);
        fprintf(param_file,"%f\n", max_vorticity * 1.05);
        fprintf(param_file,"%f\n", tau);
        fprintf(param_file,"%f\n", vkin);
        fprintf(param_file,"%f\n", F * 1.05);
    }
    else
    {
        printf("could not open %s", parameters);
        exit(10);
    }

}


void export_parameters_limited(FILE* param_file)
{
    max_velocity_and_vorticity();

    if (param_file != NULL)
    {
        fprintf(param_file,"%i\n", Nx_low);
        fprintf(param_file,"%i\n", Nx_high);
        fprintf(param_file,"%i\n", Ny_low);
        fprintf(param_file,"%i\n", Ny_high);
        fprintf(param_file,"%i\n", (timesteps - min_timestep) / time_interval_vids);
        fprintf(param_file,"%f\n", max_velocity * 1.05);
        fprintf(param_file,"%f\n", max_vorticity * 1.05);
        fprintf(param_file,"%f\n", tau);
        fprintf(param_file,"%f\n", vkin);
        fprintf(param_file,"%f\n", F * 1.05);
    }
    else
    {
        printf("could not open %s", parameters);
        exit(10);
    }

}


void export_force_x_results(FILE* force_res)
{
    int t;

    if (force_res != NULL)
    {
        for(t = 0; t < timesteps; ++t)
        {
            fprintf(force_res,"%f\n", force_vec_x[t]);
        }
    }
    else
    {
        printf("could not open %s", force_vec_results);
        exit(10);
    }

}


void export_force_x_results_ind_part(FILE* force_res)
{
    int n, t;

    if (force_res != NULL)
    {
        for(t = 0; t < timesteps; ++t)
        {
            for(n = 0; n < n_particles; ++n)
            {
                fprintf(force_res,"%f    ", force_vec_x_obj[n][t]);
            }
            fprintf(force_res,"\n");
        }
    }
    else
    {
        printf("could not open %s", force_vec_results);
        exit(10);
    }

}


void export_final_data(FILE* pfile)
{
    /*Exporting data to text*/
    if(pfile != NULL)
    {
        fprintf(pfile,"\n\nDensity rho\n");
        write_2D_doubles(pfile, Nx, Ny, rho);

        fprintf(pfile,"\n\nForce calculations\n");
        force_calculations(pfile);

        fprintf(pfile,"\n\nComparison with analytical solution steady poiseulle flow\n");
        compare_analytical_solution_poiseulle(pfile, Nx, Ny, Ux);

        fprintf(pfile,"\n\nComparison with analytical solution unsteady couette flow\n");
        compare_analytical_solution_couette(pfile, Nx, Ny, Ux);

        fprintf(pfile,"\n\nUx\n");
        write_2D_doubles(pfile, Nx, Ny, Ux);

        fprintf(pfile,"\n\nUy\n");
        write_2D_doubles(pfile, Nx, Ny, Uy);

        fprintf(pfile,"\n\nVorticity\n");
        write_2D_doubles(pfile, Nx, Ny, vort_field);

        fprintf(pfile,"\n\nX\n");
        write_2D_doubles(pfile, Nx, Ny, X_coordinates);

        fprintf(pfile,"\n\nY\n");
        write_2D_doubles(pfile, Nx, Ny, Y_coordinates);

        fprintf(pfile,"\n\nfk(:,:,0)\n");
        print_2D_map_of_3D_doubles(pfile, Nx, Ny, 0, fk);

        fprintf(pfile,"\n\nsolids map\n");
        print_2D_int(pfile, Nx, Ny, solid_flags);

        fprintf(pfile,"\n\nUx real\n");
        write_2D_doubles(pfile, Nx, Ny, Ux_real);

        fprintf(pfile,"\n\nUy real\n");
        write_2D_doubles(pfile, Nx, Ny, Uy_real);

        fprintf(pfile,"\n\ndensity real\n");
        write_2D_doubles(pfile, Nx, Ny, rho_real);

        if(check_mass_momentum)
        {
            fprintf(pfile,"\n\nMass Conservation Check\n");
            write_2D_doubles(pfile, Nx, Ny, mass_cons_check);

            fprintf(pfile,"\n\nMomentum x Conservation Check\n");
            write_2D_doubles(pfile, Nx, Ny, momentumx_cons);

            fprintf(pfile,"\n\nMomentum y Conservation Check\n");
            write_2D_doubles(pfile, Nx, Ny, momentumy_cons);
        }

        if(nonneg_stab_check)
        {
            fprintf(pfile,"\n\nNonnegative feq stability check\n");
            write_2D_doubles(pfile, Nx, Ny, feqfl);
        }

    }
    else
    {
        printf("could not open %s", data_final_timestep);
        exit(10);
    }

}


void progress_track_temp()
{
    char file_name_complete[20];
    char* file_name = "sim_trace";
    FILE *file = NULL;

    if((timestep % time_interval_data) == 0)
    {
        sprintf(file_name_complete, "%s_%d", file_name, timestep);

        file = fopen(file_name_complete, "w");

        if (file != NULL)
        {
            fprintf(file, "%s %s\n", "just printed", file_name_complete);
        }
        else
        {
            printf("could not open file %s", file_name_complete);
        }

        fclose(file);
    }

}


void close_files()
{
    fclose(datafile);
    fclose(pfile);
    fclose(param_file);
    fclose(force_res);

}
