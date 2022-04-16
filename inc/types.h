/*
 * types.h
 *
 *  Created on: 24 mei 2017
 *      Author: dharrison
 */

#ifndef TYPES_H_
#define TYPES_H_


typedef struct boundary_location
{
    int i_index;
    int j_index;
    int type;

} b_location;


typedef struct B_location_parts
{
    int i_index;
    int j_index;
    int type;

} B_location_parts;


typedef struct N_boundary_nodes
{
    int type_1;
    int type_2;
    int type_3;
    int type_4;
    int type_5;
    int type_6;
    int type_7;
    int type_8;
    int type_9;
    int type_10;
    int type_11;
    int type_12;

} N_boundary_nodes;



typedef struct B_location_parts_mult_obj
{
    int i_index;
    int j_index;
    int type;

} B_location_parts_mult_obj;


typedef struct boundary_number
{
    B_location_parts_mult_obj *boundary_number;
    int number_of_boundaries;

} boundary_number;


typedef struct boundary_type
{
    boundary_number *boundary_type;

} boundary_type;


typedef struct B_locations_objs
{
    boundary_type *part_number;

} B_locations_objs;




#endif /* TYPES_H_ */
