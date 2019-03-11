/*
 * Collision_and_streaming.h
 *
 *  Created on: 19 mei 2017
 *      Author: dharrison
 */

#ifndef COLLISION_AND_STREAMING_H_
#define COLLISION_AND_STREAMING_H_

void Calculate_equilibrium();
void Calculate_collision();
void periodic_boundaries();
void periodic_pressure_boundaries();

void streaming_internal_nodes();
void streaming_solid_boundaries();
void streaming_solid_boundaries_ind_parts();

void streaming_boundaries_free_slip();
void streaming_boundaries_no_slip();
void streaming_boundaries_no_slip_wet_node();
void streaming_boundaries();

#endif /* COLLISION_AND_STREAMING_H_ */
