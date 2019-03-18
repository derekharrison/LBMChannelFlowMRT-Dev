/*
 * export.h
 *
 *  Created on: 19 mei 2017
 *      Author: dharrison
 */

#ifndef EXPORT_H_
#define EXPORT_H_

void export_data_for_restart(FILE* data_store_for_restart);
void read_data_for_restart(FILE* data_store_for_restart);

void export_time_dep_data(FILE* datafile);
void export_time_dep_data_limited(FILE* datafile, int Nx_low, int Nx_high, int Ny_low, int Ny_high);

void export_parameters(FILE* param_file);
void export_parameters_limited(FILE* param_file);

void export_force_x_results(FILE* force_res);
void export_force_x_results_ind_part(FILE* force_res);

void export_final_data(FILE* pfile);
void progress_track_temp();

#endif /* EXPORT_H_ */
