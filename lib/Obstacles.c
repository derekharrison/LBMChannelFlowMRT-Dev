/*
 * Obstacles.c
 *
 *  Created on: 24 mei 2017
 *      Author: dharrison
 */


#include <stdlib.h>
#include "../inc/parameters.h"
#include "../inc/obstacle_objects.h"


void Obstacles()
{
    //rectangle(3.0, 3.0, 1.0, 1.0);

    x_coordinate_circle = 13.5 * 30.0;
    y_coordinate_circle = 0.5 * Ny;
    circle_radius       = 15.0;

    circle(x_coordinate_circle, y_coordinate_circle, circle_radius);


    double x_coordinate_circle2 = 17.5 * 30.0;
    double y_coordinate_circle2 = 0.5 * Ny;
    double circle_radius2       = 15.0;

    circle(x_coordinate_circle2, y_coordinate_circle2, circle_radius2);


    double x_coordinate_circle3 = 21.5 * 30.0;
    double y_coordinate_circle3 = 0.55 * Ny;
    double circle_radius3       = 15.0;

    circle(x_coordinate_circle3, y_coordinate_circle3, circle_radius3);


    double x_coordinate_circle4 = 24.5 * 30.0;
    double y_coordinate_circle4 = 0.56 * Ny;
    double circle_radius4       = 10.0;

    circle(x_coordinate_circle4, y_coordinate_circle4, circle_radius4);


    double x_coordinate_circle5 = 22 * 30.0;
    double y_coordinate_circle5 = 0.48 * Ny;
    double circle_radius5       = 13.0;

    circle(x_coordinate_circle5, y_coordinate_circle5, circle_radius5);

}

